// ansuan.c ����
//by King 97.05

#include <ansi.h>

mapping default_where = ([
	"n":	"north",
	"s":	"south",
	"e":	"east",
	"w":	"west",
	"nu":	"northup",
	"su":	"southup",
	"eu":	"eastup",
	"wu":	"westup",
	"nd":	"northdown",
	"sd":	"southdown",
	"ed":	"eastdown",
	"wd":	"westdown",
	"ne":	"northeast",
	"nw":	"northwest",
	"se":	"southeast",
	"sw":	"southwest",
	"u":	"up",
	"d":	"down",
]);

mapping default_dirs = ([
	"north":		"����",
	"south":		"�ϱ�",
	"east":			"����",
	"west":			"����",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":		"����",
	"southdown":		"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":		"����",
	"northwest":		"����",
	"southeast":		"����",
	"southwest":		"����",
	"up":			"����",
	"down":			"����",
	"enter":		"����",
	"out":			"����",
]);

mapping default_undirs = ([
	"south":		"����",
	"north":		"�ϱ�",
	"west":			"����",
	"east":			"����",
	"southup":		"����",
	"northup":		"�ϱ�",
	"westup":		"����",
	"eastup":		"����",
	"southdown":		"����",
	"northdown":		"�ϱ�",
	"westdown":		"����",
	"eastdown":		"����",
	"southwest":		"����",
	"southeast":		"����",
	"northwest":		"����",
	"northeast":		"����",
	"down":			"����",
	"up":			"����",
	"out":			"����",
	"enter":		"����",
]);

int main(object me, string arg)
{
	string who, where, dir, undir, where_temp;
	object env, old_env, *ob;
	mapping exits;
	object target;
	int count, i;
	string gen;

	if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
		return notify_fail("ָ���ʽ��ansuan <����> at <����>\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	env = environment(me);
	old_env = env;
	if( where_temp == "leitai" )
		return notify_fail("�����ֹ���㡣\n");
	if( !undefinedp(default_where[where_temp]) )
		where = default_where[where_temp];
	else where = where_temp;

	if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
		return notify_fail("û���������\n");

	if( !objectp(env = find_object(exits[where])) )
	{	call_other(exits[where], "???");
		env = find_object(exits[where]);
	}

	if( env->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	ob = all_inventory(env);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && !ob->query_temp("noliving") && ob[i]!=me)
			count++;
	if (count > 2)
		return notify_fail("������̫���ˣ��㻹��㰵�㣿\n");

	if( !objectp(target = present(who, env)) )
		return notify_fail("�������û�д��ˡ�\n");

	if( !target->is_character() || target->is_corpse())
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if(me->query("id") != target->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("����Ϊ���죬ִ�й��񣬿ɲ���ɱ��ð����\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ����ܰ��㡣\n");

	if( me->is_fighting() )
		return notify_fail("����æ��ս���أ�������˼������ˣ�\n");

	if( !living(target) || target->query_temp("noliving") )
		return notify_fail(target->name()+ "���Ѿ������ˣ��㻹�õ��Ű�����\n"); 

	if((int)target->query("age") <= 15 && userp(target))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

	if( (int)me->query("jing", 1) < 100 )
		return notify_fail("���޷����о��������㲻�˱��ˡ�\n");

	if (userp(me) && target->query("owner") && me->query("id") != target->query("owner"))
			return notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");						

	notify_fail("������ͷ��С����������Ϊ�\n");
	if (!userp(target) && !target->accept_ansuan(me)) return 0;
	if( !undefinedp(default_dirs[where]) )
		dir = default_dirs[where];
	else
		dir = where;

	if( !undefinedp(default_undirs[where]) )
		undir = default_undirs[where];
	else
		undir = where;

	me->delete("env/combatd");
	target->delete("env/combatd");

	if(me->query("gender") == "Ů��")
		gen = "ٻӰ";
	else
		gen = "��Ӱ";

	write( CYN"����Ϣ����������������" + dir + "��" + target->name() + "��ȥ��\n"NOR);
	message("vision", CYN"\nһ��" + gen + "��Ȼ��" + dir + "��ȥ��ת�ۼ��ֻص�ԭ����\n\n"NOR, environment(me), me);
	tell_object(target, CYN"\nһ��" + gen + "��Ȼ��" + undir + "����������\n\n"NOR);
	message("vision", CYN"\nһ��" + gen + "��Ȼ��" + undir + "��" + target->name() + "������\n\n"NOR, environment(target), target);

	count = me->query_str();

	me->set_temp("apply/name", ({gen}));
	me->set_temp("apply/id", ({"none"}));
	me->set_temp("apply/short", ({gen}));
	me->set_temp("apply/long", ({gen}));

	me->move(environment(target));

	me->add_temp("str", count);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon") );

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
	{
		message_vision(CYN"$Nһʱû�з�������$n���˸����ֲ�����\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon") );
	}
	else
	{
		message_vision(CYN"$N����ḻ������ϸ����������$n������\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon") );
	}

	me->add_temp("str", - count);

	if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/5 )
	{
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		tell_object(target, CYN"��һ����ԭ����" + me->name() + "�ڰ����ң�\n"NOR);
		write( CYN "���ã���" + target->name() + "�����ˣ�\n"NOR);
		message_vision(CYN"$N�ȵ���$n����Ұ����ң��Ҹ���û�꣡\n"NOR, target, me);
		if( !target->is_killing(me) ) target->kill_ob(me);
		me->start_busy(3);
	}

	else
	{
		message("vision", CYN"\n" + gen + "ת˲������\n\n"NOR, environment(target), me);
		tell_object(me, CYN"\n�������˻�ԭ����\n\n"NOR);

		me->move(old_env);

		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		tell_object(target, CYN"��һ���񣬿���ʲô��û������\n"NOR);
		message("vision", CYN"" + target->name() + "һ���֣̿�����֪��˭�ڰ�������\n"NOR, environment(target), target);
		write( CYN "������" + target->name() + "��Ȼû��������\n"NOR);
		write( CYN"����˴��֣�һ���޹������ӡ�\n"NOR);
	}

	me->start_busy(3);
	me->add("jing", -50);
	if( userp(me) )
		log_file("ansuan_player", sprintf("[%s] %s ansuan %s\n", ctime(time()), geteuid(me), target->query("id")));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : ansuan <����> at <����>

    ���ָ�����㰵��λ��<����>��<����>��
    �������ɹ�������˷��ֲ����㡣����...:)
HELP
	);
	return 1;
}