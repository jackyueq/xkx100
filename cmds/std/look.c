// look.c

// Modified by zeratul,2000.1.29
// �޸��˷�������ͬ��Ʒ��������/inherit/item/combined.c�� /cmds/std/get.c Ҳ������Ӧ���޸ġ�
// Modified by fandog,2000.12.23
// �����˶Է����������ʾ��
// Modified by Winder 2001.5.22
// ����С��ͼ��ʾ�������ӻ�����������С��ͼ��ͬʱ�޸���set.c��unset.c��
// Modified by ahda 2002.6.25
// ����������ʦ���Կ�����ҡ�npc�书�ȼ��Ĺ��� line 394����ʱ�����������Ժ�������¿���ר�ŵ���ʦlook����


#include <room.h>;
#include <ansi.h>;
#include <combat.h>;
#define SETDISPLAY(x,y)  (ESC+"["+x+";"+y+"f")
#define DELLINE ESC+"[K"

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
varargs mixed look_living(object me, object obj, int getstr);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string filter_color(string arg);
string combined(object *inv);
string clean_color(string arg);
object i_have(object env,string name);
string adjust_short(string arg);
string *tough_level_desc = ({
	BLU "����һ��" NOR,
	BLU "��������" NOR,
	BLU "����ҳ�" NOR,
	BLU "��ѧէ��" NOR,
	BLU "����ǿǿ" NOR,
	HIB "�����ž�" NOR,
	HIB "����é®" NOR,
	HIB "��֪һ��" NOR,
	HIB "����ͨͨ" NOR,
	HIB "ƽƽ����" NOR,
	CYN "ƽ������" NOR,
	CYN "��ͨƤë" NOR,
	CYN "��������" NOR,
	CYN "������" NOR,
	CYN "����С��" NOR,
	HIC "����С��" NOR,
	HIC "������Ⱥ" NOR,
	HIC "�������" NOR,
	HIC "�������" NOR,
	HIC "�ڻ��ͨ" NOR,
	HIG "�������" NOR,
	HIG "¯����" NOR,
	HIG "��Ȼ����" NOR,
	HIG "���д��" NOR,
	HIG "���д��" NOR,
	YEL "��Ȼ��ͨ" NOR,
	YEL "�������" NOR,
	YEL "�޿�ƥ��" NOR,
	YEL "����Ⱥ��" NOR,
	YEL "����似" NOR,
	HIY "�����뻯" NOR,
	HIY "��ͬ����" NOR,
	HIY "����Ⱥ��" NOR,
	HIY "�Ƿ��켫" NOR,
	HIY "�����ױ�" NOR,
	RED "��������" NOR,
	RED "һ����ʦ" NOR,
	RED "�������" NOR,
	RED "�񹦸���" NOR,
	RED "������˫" NOR,
	WHT "��������" NOR,
	WHT "���춯��" NOR,
	WHT "������" NOR,
	WHT "������ʥ" NOR,
	WHT "�������" NOR,
	HIW "��ǰ����" NOR,
	HIW "���˺�һ" NOR,
	MAG "��ز�¶" NOR,
	HIM "��ɲ�" NOR,
	HIR "��豹���" NOR 
});
string *heavy_level_desc= ({
	"����",
	"����",
	"����",
	"����",
	"����",
	"����"	
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;
  object *inv;
  
	if( !arg ) result = look_room(me, environment(me));


	else if( objectp(obj=i_have(me,arg)) || objectp(obj=i_have(environment(me),arg)) )
	{
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} 

	else result = look_room_item(me, arg);
  

	return result;
}
object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
}
int look_room(object me, object env)
{
	int i;
	object *inv, room;
	mapping exits;
	string str, *dirs, nature, time = NATURE_D->game_time();

	if( !env )
	{
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}
// ��������
	str = sprintf(HIC+"%s"+NOR+" - %s\n    %s"NOR, env->query("short"), wizardp(me)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),env->query("coor/y"),env->query("coor/z")): "", env->query("long") );
// ��������
	str += sprintf("%s", env->query("outdoors") ? NATURE_D->outdoor_room_description():"");
// ·��ָʾ
	if( mapp(exits = env->query("exits")) )
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if((int)env->query_door(dirs[i],"status") & DOOR_CLOSED)
				dirs[i] = 0;
		dirs -= ({ 0 });
		if ( env->query("outdoors") &&
			!present("fire", this_player()) &&
			!wizardp(this_player()) &&
			((strsrch(time, "��ʱ") >= 0) ||
			 (strsrch(time, "��ʱ") >= 0) ||
			 (strsrch(time, "��ʱ") >= 0) ||
			 (strsrch(time, "��ʱ") >= 0) ))
			str += "    ��ɫ̫���ˣ��㿴�������Եĳ�·��\n";
		else if( sizeof(dirs)==0 )
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 )
			str += "    ����Ψһ�ĳ����� "+BOLD+dirs[0]+NOR+"��\n";
		else
			str += sprintf("    �������Եĳ����� "+BOLD"%s"NOR+" �� "+BOLD+"%s"+NOR+"��\n", implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	str += combined(inv);
	write(str);
// С��ͼ����
	if (!this_player()->query("env/no_map"))
	{
		if( mapp(exits =env->query("exits")) )
		{
			dirs=keys(exits);
			for(i=0; i<sizeof(dirs); i++)
				if( (int)env->query_door(dirs[i], "status") &
					DOOR_CLOSED ) dirs[i] = 0;
			dirs -= ({ 0 });
			if (sizeof(dirs)!=0)
			{
				write(SAVEC);
				write(SETDISPLAY(7,0)+DELLINE);
				write(SETDISPLAY(1,0)+DELLINE);
				write(SETDISPLAY(2,0)+DELLINE);
				write(SETDISPLAY(3,0)+DELLINE);
				write(SETDISPLAY(4,0)+DELLINE);
				write(SETDISPLAY(5,0)+DELLINE);
				write(SETDISPLAY(6,0)+DELLINE);
				write(SETDISPLAY(4,56)+clean_color(env->query("short")));
				for (i=0;i<sizeof(dirs);i++)
					switch(dirs[i])
					{
						case "north":
						write(SETDISPLAY(3,60)+HIY"��"NOR);
						room=load_object(exits["north"]);
						write(SETDISPLAY(2,56)+clean_color(room->query("short")));
						break;

						case "south":
						write(SETDISPLAY(5,60)+HIY"��"NOR);
						room=load_object(exits["south"]);
						write(SETDISPLAY(6,56)+clean_color(room->query("short")));
						break;

						case "east":
						room=load_object(exits["east"]);
						write(SETDISPLAY(4,68)+clean_color(room->query("short")));
						write(SETDISPLAY(4,66)+HIY"��"NOR);
						break;

						case "west":
						room=load_object(exits["west"]);
						write(SETDISPLAY(4,44)+clean_color(room->query("short")));
						write(SETDISPLAY(4,54)+HIY"��"NOR);
						break;

						case "westup":
						room=load_object(exits["westup"]);
						write(SETDISPLAY(4,44)+clean_color(room->query("short")));
						write(SETDISPLAY(4,54)+HIY"��"NOR);
						break;

						case "eastup":
						room=load_object(exits["eastup"]);
						write(SETDISPLAY(4,68)+clean_color(room->query("short")));
						write(SETDISPLAY(4,66)+HIY"��"NOR);
						break;

						case "northup":
						write(SETDISPLAY(3,60)+HIY"��"NOR);
						room=load_object(exits["northup"]);
						write(SETDISPLAY(2,56)+clean_color(room->query("short")));
						break;

						case "southup":
						write(SETDISPLAY(5,60)+HIY"��"NOR);
						room=load_object(exits["southup"]);
						write(SETDISPLAY(6,56)+clean_color(room->query("short")));
						break;

						case "southdown":
						write(SETDISPLAY(5,60)+HIY"��"NOR);
						room=load_object(exits["southdown"]);
						write(SETDISPLAY(6,56)+clean_color(room->query("short")));
						break;

						case "northdown":
						write(SETDISPLAY(3,60)+HIY"��"NOR);
						room=load_object(exits["northdown"]);
						write(SETDISPLAY(2,56)+clean_color(room->query("short")));
						break;

						case "eastdown":
						room=load_object(exits["eastdown"]);
						write(SETDISPLAY(4,68)+clean_color(room->query("short")));
						write(SETDISPLAY(4,66)+HIY"��"NOR);
						break;

						case "westdown":
						room=load_object(exits["westdown"]);
						write(SETDISPLAY(4,44)+clean_color(room->query("short")));
						write(SETDISPLAY(4,54)+HIY"��"NOR);
						break;

						case "northwest":
						write(SETDISPLAY(3,54)+HIY"��"NOR);
						room=load_object(exits["northwest"]);
						write(SETDISPLAY(2,44)+clean_color(room->query("short")));
						break;

						case "southwest":
						write(SETDISPLAY(5,54)+HIY"��"NOR);
						room=load_object(exits["southwest"]);
						write(SETDISPLAY(6,44)+clean_color(room->query("short")));
						break;

						case "northeast":
						write(SETDISPLAY(3,66)+HIY"��"NOR);
						room=load_object(exits["northeast"]);
						write(SETDISPLAY(2,68)+clean_color(room->query("short")));
						break;

						case "southeast":
						write(SETDISPLAY(5,66)+HIY"��"NOR);
						room=load_object(exits["southeast"]);
						write(SETDISPLAY(6,68)+clean_color(room->query("short")));
						break;
					}

				write(SETDISPLAY(1,42)+"��������������������������������������");
				write(SETDISPLAY(2,42)+"��");
				write(SETDISPLAY(3,42)+"��");
				write(SETDISPLAY(4,42)+"��");
				write(SETDISPLAY(5,42)+"��");
				write(SETDISPLAY(6,42)+"��");
				write(SETDISPLAY(7,42)+"��������������������������������������");
				write(SETDISPLAY(2,78)+"��");
				write(SETDISPLAY(3,78)+"��");
				write(SETDISPLAY(4,78)+"��");
				write(SETDISPLAY(5,78)+"��");
				write(SETDISPLAY(6,78)+"��");

				write(REST);
			}
		}
	}	
	return 1;
}
// �����ɫ��ƥ��С��ͼ
string clean_color(string arg)
{
	if(!arg) return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	arg = adjust_short(arg);
	return BBLU+arg+NOR;
}
// С��ͼ���������ͳһ���������
string adjust_short(string arg)
{
	switch (strlen(arg))
	{
		case 14: return arg;
		case 12: return arg;
		case 10: return arg;
		case 9 : return arg;
		case 8 : return arg[0..3]+"  "+arg[4..7];
		case 6 : return arg[0..1]+"  "+arg[2..3]+"  "+arg[4..5];
		case 4 : return arg[0..1]+"      "+arg[2..3];
	}
}

int look_item(object me, object obj)
{
	mixed *inv;

	write(obj->long());
	inv = all_inventory(obj);
	if( sizeof(inv) ) 
		message("vision",sprintf("�����У�\n%s\n",combined(inv)),me);
	return 1;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
	mapping prepare;
	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
		parry_type = "parry";
	}
	else
	{
//		skill_type = "unarmed";
		prepare = ob->query_skill_prepare();
		if (!prepare) prepare = ([]);
		if ( sizeof(prepare) == 0)	skill_type = "unarmed";
		else if ( sizeof(prepare) == 1)	skill_type = (keys(prepare))[0];
		else if ( sizeof(prepare) == 2)	skill_type = (keys(prepare))[ob->query_temp("action_flag")];

		parry_type = "unarmed";
	}

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	return tough_level((int)(attack_points/360));
}
varargs mixed look_living(object me, object obj, int getstr)
{
	int per;
	int spi;
	int age;
	int weight;
	string str, limb_status, pro;
	mixed *inv;
	mapping my_fam, fam;
	int me_shen, obj_shen;
	int equip, wearornot;

	me_shen = (int)me->query("shen");
	obj_shen = (int)obj->query("shen");
	per = obj->query_per();
	age = obj->query("age");

	if( me!=obj && !getstr)
		message("vision",me->name()+"�������㿴����֪����Щʲô���⡣\n",obj);
	str = obj->long();
	if (obj->query_temp("pretend")) 
	{
		message_vision(str,me);
		return 1;
	}
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	if (obj->query_temp("is_riding") && obj != me)
	 if (stringp(obj->query_temp("is_riding")))
		str += sprintf("%s������%s�ϣ���ͷ�����㡣\n", pro, obj->query_temp("is_riding"));
   if (objectp(obj->query_temp("is_riding")))
		str += sprintf("%s������%s�ϣ���ͷ�����㡣\n", pro, (obj->query_temp("is_riding"))->name());
    

	if(wizardp(obj) && !obj->query("no_look_wiz"))
		str+=sprintf(HIY"%sȫ��ɢ����ҫ�۵Ľ�⣬����������֮������ࡣ\n"NOR, pro);

	if( (string)obj->query("race")=="����" && intp(obj->query("age")) )
	{
		if(obj->query("age")>10)      
        	str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
		else
		str += sprintf("%s�������൱С��\n",pro);
	     if ( (obj == me || wizardp(me) ) && !getstr)
//		if(obj == me)
		{
			str += sprintf("%s���书����", pro);
			str += gettof(me,obj);
			str += sprintf("��");
			str += sprintf("�����ƺ�");
			str += getdam(me,obj);
			str += sprintf("��\n");
		}
	}
	if(age > 70 ) per = per/4;
	if(age > 60 ) per = per/3;
	if(age > 50 ) per = per/2;
	if( (string)obj->query("race")=="����")
	{
		if(age<16 ) str += pro+ "�������㣬������С��\n";
		else
		str += pro + PERSONAL_D->query_personal( obj->query("gender") , per );
	}
	else
	{
		if (living(obj))
		{
			if (!obj->query_temp("owner"))
				str += pro+"��һֻδ��ѱ�����������۹������ǽ��ĺ͵��⡣\n";
			else
				str += pro+"��һֻ��"+obj->query_temp("ownername")+"ѱ����������һ������ѱ�����ӡ�\n";
		}
	}
	wearornot = 0;
	if (obj->query_temp("armor/armor") || 
	    obj->query_temp("armor/cloth"))
	wearornot = 1;
/*
	inv = all_inventory(obj);
	for(equip=0; equip<sizeof(inv); equip++)
	{
		if( inv[equip]->query("equipped") 
		 && inv[equip]->query("equipped")!="wielded") wearornot = 1;
	}
*/
	//check about wife and husband
	if((obj->parse_command_id_list())[0]==me->query("couple/couple_id") )
	{
		if( (string)me->query("gender")=="Ů��" )
		{
			str += sprintf("%s������ɷ�\n", pro);
		}
		else{
			str += sprintf("%s��������ӡ�\n", pro);
		}
	}
	if (me->query("jiebai"))
		if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
		{
			if( obj->query("gender")=="Ů��" )
			{
				if (obj->query("mud_age") > me->query("mud_age"))
				str += sprintf("%s�������㡣\n", pro);
				else str += sprintf("%s����Ľ������ӡ�\n", pro);
			}
			else
			{
				if (obj->query("mud_age") > me->query("mud_age"))
				str += sprintf("%s����Ľ����ֳ���\n", pro);
				else str += sprintf("%s�������ܡ�\n", pro);
			}
		}
	if(obj!=me && me->query("born") && me->query("born/hometown")==obj->query("born/hometown") )
	{
		str += sprintf("%s��������硣\n", pro);
	}
	if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
		str += pro+"���Ͼ�Ȼʲô��û��Ү��\n";
	// If we both has family, check if we have any relations.
	if( obj!=me && mapp(fam = obj->query("family"))
	&& mapp(my_fam = me->query("family"))
	&& fam["family_name"] == my_fam["family_name"] && !intp(getstr))
	{
		if( fam["generation"]==my_fam["generation"] )
		{
			if( (string)obj->query("gender") == "����" ||
				(string)obj->query("gender") == "����")
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "�����ʦ����\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "�����ͬ�ų�����\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "�����ʦ����\n";
			else
				str += pro + "�����ʦ�塣\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "�����ͬ������\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "����ĵ��ӡ�\n";
			else
				str += pro + "�����ʦֶ��\n";
		}
	}

	if( obj->query("max_qi") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("%s��ͷ���������ˡ�\n", pro);

	inv = all_inventory(obj);
	if( sizeof(inv) ) {		
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n": "%s���ϴ��ţ�\n%s\n",
				pro, implode(inv, "\n") );
	}
	if (intp(getstr) && getstr==1) return str;
	message("vision", str, me);	

	if( obj!=me && living(obj) && !obj->query_temp("noliving") &&
		(((me_shen < 0) && (obj_shen > 0)) ||
		((me_shen > 0) && (obj_shen < 0))) &&
		(((me_shen - obj_shen) > ((int)obj->query("neili") * 20)) ||
		((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
	{
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		if(obj->query("age") > 15 && me->query("age") > 15)
			if(!wizardp(obj) && !wizardp(me) &&
				obj->query_temp("guardfor")!=me)
				COMBAT_D->auto_fight(obj, me, "berserk");
	}
	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;

	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  ��" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));

		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}
string tough_level(int power)
{
	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
	if( lvl >= sizeof(tough_level_desc))
		lvl = sizeof(tough_level_desc)-1;
	else if (lvl >= sizeof(tough_level_desc) - 1)
		lvl = sizeof(tough_level_desc) - 2;
	return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

	int level;
	
	if (objectp(obj->query_temp("weapon")))
	level = obj->query_temp("apply/damage");
	else
	level = obj->query_temp("apply/unarmed_damage");
	level += obj->query("jiali");
	level = level / 30;
	if( level >= sizeof(heavy_level_desc) )
		level = sizeof(heavy_level_desc)-1;
	return heavy_level_desc[((int)level)];
}

// Combine same objects to a simple description.
string combined(object *inv)
{
	int 	i;
	mapping	inv_mapped;
	string	str, object_id, object_short;
	object 	me=this_player();
	
  string *invid=({});
  string *invname=({});
  int j, k, *count=({});
  object *inv1=({});


	str = "";
	inv_mapped = ([]);
	for(i=0; i<sizeof(inv); i++)
	{
		if( inv[i]==me ) continue;
		if( inv[i]==this_object() ) continue;
		if( inv[i]->query_temp("apply/yinshen")) continue;
		if( inv[i]->query("no_shown")) continue;
		if( !me->visible(inv[i]) ) continue;
    j=member_array(inv[i]->query("id")+"/"+inv[i]->short(),invname);
    if (j== -1 )
    {
    	inv1 +=({ inv[i] });
    	invname += ({ inv[i]->query("id")+"/"+inv[i]->short() });
      count += ({1});
   	}
    else
     count[j]++;
 	}
    for (i=0; i<sizeof(invname);i++) {
		str += "  ";
    if ( count[i]!=1 )
      str += chinese_number(count[i]) + inv1[i]->query("unit");
    str += inv1[i]->short() + "\n";
	}
	return str;
	
}
string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

    ���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
���Կ��Լ������мǣ�������ָ�����ñ�һ���������Ҫ��ö࣬
���������Թ��С���

HELP
);
	return 1;
}


