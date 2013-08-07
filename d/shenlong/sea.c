// /d/shenlong/sea.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;
#include <ansi.h>
int do_practice(string arg);

string *practice_types = ({
	"blade",
	"club",
	"staff",
	"stick",
	"sword",
	"whip",
	"cuff",
	"strike",
	"parry",
	"dodge",
});
	
int *cost(object, string);

void create()
{
	set("short","��");
	set("long", @LONG
���������ĺ��棬���硸������������ߴ���������һ������һ��
�����ô������ͻȻһ�����˴��������������������У��㻹�Ǿ�����
������ɡ�
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south" : __DIR__"beach",
	]));
	set("outdoors", "shenlong");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
}

int do_practice(string arg)
{
	object *inv, weapon, me = this_player();
	string skillarg, str, multiple, skillname;
	int w, *cost, times, total, skill_special, skill_basic;
	mapping fam, skills, learned;

	skills = me->query_skills();
	learned = me->query_learned();
	skill_basic = me->query_skill(arg, 1);
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
	{
		tell_object(me,"������������书����������似��������\n");
		return 1;
	}
	skill_special = me->query_skill(skillname, 1);

	if( skill_special < 1 )
	{
		tell_object(me,"����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
		return 1;
	}	
	if( skill_basic > skill_special )
	{
		tell_object(me,"��" + to_chinese(skillname) + "�����������޷���������" + to_chinese(arg) + "��\n");
		return 1;
	}
	skill_special = skill_special * me->query("max_jing") * 2 / (1000 + me->query("max_jing"));

	if( me->is_busy() )
	{
		tell_object(me, "��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() )
	{
		tell_object(me, "���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
		return 1;
	}
	if( !arg ) return ("/cmds/skill/enable")->main(me, arg);
	if(sscanf(arg, "%s %d", skillarg, times) != 2 )
		skillarg = arg;
	if( (w = member_array(skillarg, practice_types)) == -1 )
	{
		tell_object(me, "����ܲ����������ϰ��\n");
		return 1;
	}
	if( w < 6 )
	{
		if( !objectp(weapon = me->query_temp("weapon")) )
		{
			tell_object(me, "��û����������ô��ϰ��\n");
			return 1;
		}
		else
			if( weapon->query("skill_type") != skillarg )
			{
				tell_object(me, "�����е��������ʺ���������ϰ�ļ��ܡ�\n");
				return 1;
			}
	}
	if( (int)me->query_skill(skillarg, 1) < 30 )
	{
		tell_object(me, "�㻹����ȥ��ʦ����ѧϰ��\n");
		return 1;
	}
	if(!times || times == 0)
	{
		times = 1;
		multiple="";
	}
	else multiple="����";
	switch(skillarg) {
		case "blade" :
		case "club"  :
		case "staff" :
		case "stick" :
		case "sword" : 
		case "whip"  : str = "����" + weapon->name(); break;
		case "cuff"  : str = "����˫ȭ"; break;
		case "strike": str = "����˫��"; break;
		case "parry" : str = "�����ղ�"; break;
		case "dodge" : str = "������Ծ"; break;
	}		
	message_vision("$N�ں�����" + str + multiple + "��ϰ��" + to_chinese(skillarg) + "��\n", me);

	for(times; times > 0; times--)
	{
		cost = cost(me, skillarg);
		if( (int)me->query("jing") < cost[0] ||
			 (int)me->query("qi") < cost[1] )
		{
			tell_object(me, "���㵱ǰ��״�������㲻�������ϰ��\n");
			return 1;
		}
		me->receive_damage("qi", cost[1]);
		me->receive_damage("jing", random(skill_basic)/2,"ڤ˼������Դ��������ˣ��װ׵��Խ�����һ��");
		me->improve_skill(skillarg, skill_special/8 + random(skill_special/4));

		total = (int)me->query("jing") + (int)me->query("qi");
		if( total < 500 && random(total) < 20 )
		{
			message_vision("ͻȻһ�����˴�����$N���������У���������ˮ��û�ˡ�\n", me);
			for(int i = 0; i < sizeof(inv); i++)
			{
				if( userp(inv[i]) )
					inv[i]->receive_wound("qi", 50 + inv[i]->query("max_qi"), "��������������");
				else destruct(inv[i]);
			}

			me->unconcious();
			me->move("/d/shenlong/beach");
			message("vision","�㷢��һ������ˮ���ܵļһﱻ��ˮ���ϰ��������ɵ��߽�һ����ԭ����"+me->name()+"\241\243\n", environment(me), ({me}));
			return 1;
		}
	}
	
	return 1;
}

int *cost(object ob, string skill)
{
	if( (int)ob->query("potential") > 0 && (int)ob->query("neili") > 10 )
	{
		if( !random(3) ) ob->add("potential", -1);
		else ob->add("neili", -8);
		return ({0, 0});
	}
	else
	{
		switch(skill)
		{
			case "blade" : return ({150, 300});
			case "club"  : return ({200, 250});
			case "staff" : return ({250, 200});
			case "stick" : return ({300, 150});
			case "sword" : return ({350, 100});
			case "cuff"  : return ({350, 200});
			case "strike": return ({200, 350});
			case "parry" : return ({150, 250});
			case "dodge" : return ({250, 150});
		}
	}
	return ({20, 20});
}

