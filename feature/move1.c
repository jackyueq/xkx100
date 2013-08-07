// move.c

#pragma optimize

#include <dbase.h>
#include <ansi.h>

static int weight = 0;
static int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
	encumb += w;
	if( encumb < 0 )
		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
	if( encumb > max_encumb ) this_object()->over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
	if( !interactive(this_object()) ) return;
	tell_object(this_object(), "��ĸ��ɹ����ˣ�\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
	if( !environment() ) {
		weight = w;
		return;
	}
	if( w!=weight ) environment()->add_encumbrance( w - weight );
	weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

varargs int move(mixed dest, int silently)
{
	object ob, env, *inv, me = this_object(), where = environment();
	mapping exits;
	string str, *dirs, time = NATURE_D->game_time();
	int i;

	// If we are equipped, unequip first.
	if( query("equipped") && !me->unequip() )
		return notify_fail("��û�а취ȡ������������\n");

	// Find the destination ob for moving.
	if( objectp(dest) )
		ob = dest;
	else if( stringp(dest) ) {
		call_other(dest, "???");
		ob = find_object(dest);
		if(!ob) return notify_fail("move: destination unavailable.\n");
	} else
		return notify_fail(sprintf("move: invalid destination %O.\n", dest));

	// Check if the destination ob can hold this object.
	// Beforce checking it, we check if the destination is environment of
	// this_object() (or environment of its environment). If it is, then
	// this could be like get something from a bag carried by the player.
	// Since the player can carry the bag, we assume he can carry the this
	// object in the bag and encumbrance checking is unessessary.
	env = me;
	while(env = environment(env)) if( env==ob ) break;
	if( !env && (int)ob->query_encumbrance() + weight()
		> (int)ob->query_max_encumbrance() )
	{
		if( ob==this_player() )
			return notify_fail(me->name() + "�������̫���ˡ�\n");
		else
			return notify_fail(me->name() + "��" + ob->name() +"����̫���ˡ�\n");
	}

	// Move the object and update encumbrance
	if( environment() ) environment()->add_encumbrance( - weight());
	move_object(ob);
	if( !me) return 0;
	ob->add_encumbrance(weight());

	// If we are players, try look where we are.
	if( interactive(me)			// are we linkdead?
		&& living(me)			// are we still concious?
		&& !me->query_temp("noliving")	// are we still concious?
		&& userp(me)			// are we still concious?
		&& !silently )
	{
		if( query("env/brief") )
		{
			tell_object(me, HIC+environment()->query("short") + NOR + " -\n");
		}
		else
		if( query("env/brief1") )
		{
			str = HIC+environment()->query("short") + NOR + " -\n";
			inv = all_inventory(environment());
			for(i=0; i<sizeof(inv); i++)
			{
				if( inv[i]==me ) continue;
				if( inv[i]->query("no_shown")) continue;
				if( !me->visible(inv[i]) ) continue;
				str += "  " + inv[i]->short() + "\n";
			}
			tell_object(me, str);
		}
		else
		if( query("env/brief2") )
		{
			str = HIC+environment()->query("short") + NOR + " -\n";
			inv = all_inventory(environment());
			for(i=0; i<sizeof(inv); i++) {
				if( inv[i]==me ) continue;
				if( inv[i]->query("no_shown")) continue;
				if( !me->visible(inv[i]) ) continue;
				str += "  " + inv[i]->short() + "\n";
			}
			if( mapp(exits = environment()->query("exits")) )
			{
				dirs = keys(exits);
/*				for(i=0; i<sizeof(dirs); i++)
					if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED ) dirs[i] = 0;
				dirs -= ({ 0 });
*/
				if ( environment()->query("outdoors") &&
					!present("fire", me) &&
					!wizardp(me) &&
					((strsrch(time, "��ʱ") >= 0) ||
					 (strsrch(time, "��ʱ") >= 0) ||
					 (strsrch(time, "��ʱ") >= 0) ||
					 (strsrch(time, "��ʱ") >= 0) ))
					str += "    ��ɫ̫���ˣ��㿴�������Եĳ�·��\n";
				else if( sizeof(dirs)==0 )
					str += "    ����û���κ����Եĳ�·��\n";
				else if( sizeof(dirs)==1 )
					str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
				else
					str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
					implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
			}
			tell_object(me, str);
		}
		else
			command("look");
	}

	return 1;
}

void remove(string euid)
{
	object default_ob;

	if( !previous_object()
	||	base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() can only be called by destruct() simul efun.\n");

	if( userp(this_object()) && euid!=ROOT_UID ) {
		log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
			euid, this_object()->query("id"), ctime(time())));
		error("��(" + euid + ")���ܴݻ�������ʹ���ߡ�\n");
	} else if( this_object()->query("equipped")) {
		if(	!this_object()->unequip() )
			log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
	}

	// We only care about our own weight here, since remove() is called once
	// on each destruct(), so our inventory (encumbrance) will be counted as
	// well.
	if( environment() )	environment()->add_encumbrance( - weight );
	if( default_ob = this_object()->query_default_object() )
		default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
	if( userp(this_object()) ) {
		tell_object(this_object(), "һ��ʱ�յ�Ť�����㴫�͵���һ���ط�....\n");
		move(VOID_OB);
	}
}
