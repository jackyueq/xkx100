// /d/shenlong/jushi.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;
#include <ansi.h>

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
void dropoff(object);

void create()
{
	set("short", "��ʯ");
	set("long", @LONG
��վ�������ϵľ�ʯ�ϣ�����ɽ��������ͷ�����ҡ���ʯҡҡ��
�Σ����������У�˫������վ�����������ܣ�һƬ�ž�����ʯ��������
����Ԩ���ƺ��ڴ˺�����������
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"southwest" : __DIR__"luanshi",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me = this_player();
	int lvl = (int)me->query_skill("dodge", 1);

	if( interactive(me) && !random((int)me->query_skill("dodge", 1)) )
	{
		call_out("dropoff", 1, me);	     
		return;
	}

	add_action("do_practice",  "practice");
	add_action("do_practice",  "lian");
	add_action("do_jump", "jump");
}

int do_practice(string arg)
{
	object weapon, me = this_player();
	string skillarg, str, multiple;
	int w, *cost, times;

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
		tell_object(me, "�㻹����ȥ����ʦ�����ѧϰ��\n");
		return 1;
	}
	if( (int)me->query_skill(skillarg, 1) > 100 )
	{
		tell_object(me, "���Ѿ������������ʱ����ϰ������ˡ�\n");
		return 1;
	}		
	if(!times || times == 0)
	{
		times = 1;
		multiple="";
	}
	else    multiple="����";
	switch(skillarg)
	{
		case "blade" :
		case "club"  :
		case "staff" :
		case "stick" :
		case "sword" : 
		case "whip"  : str = "����" + weapon->name();  break;
		case "cuff"  : str = "����˫ȭ"; break;
		case "strike": str = "����˫��"; break;
		case "parry" : str = "�����ղ�"; break;
		case "dodge" : str = "������Ծ"; break;
	}		
	message_vision("$N�ڿ����" + str + multiple + "��ϰ��" + to_chinese(skillarg) + "��\n", me);

	for(times; times > 0; times--)
	{
		cost = cost(me, skillarg);
		if( (int)me->query("jing") < cost[0] ||
			(int)me->query("qi") < cost[1] )
		{
			tell_object(me, "���㵱ǰ��״�������㲻�������ϰ��\n");
			return 1;
		}
		me->receive_damage("jing", cost[0]);
		me->receive_damage("qi", cost[1]);	     
		me->improve_skill(skillarg, random((int)me->query_int()));

		if( !random((int)me->query_skill("dodge", 1)) )
		{
			dropoff(me);
			return 1;
		}
	}
	return 1;
}

int do_jump(string arg)
{
	object *inv, me = this_player();
	int mydodge = me->query_skill("dodge", 1);

	if( !arg || arg != "down" )
		return notify_fail("��Ҫ��ʲô��\n");

	tell_object(me, "����һ���������漴ֱ����ȥ��\n");
	message("vision", me->name() + "����һ������ֱ�亣�\n", environment(me), ({me}));
      
	if( random(mydodge - 30 ) < 10 )
	{
		for(int i = 0; i < sizeof(inv); i++)
			if( userp(inv[i]) )
				inv[i]->receive_wound("qi", 50 + inv[i]->query("max_qi"), "��������������");
			else    destruct(inv[i]);
		me->unconcious();
		me->move("/d/shenlong/beach");
		message("vision","�㷢��һ������ˮ���ܵļһﱻ��ˮ���ϰ��������ɵ��߽�һ����ԭ����" + me->name() + "\241\243\n", environment(me), ({me}));
		return 1;
	}

	me->move("/d/shenlong/sea");
	tell_object(me, "��һ���۱㷢����վ���ں�ˮ�\n");
	message("vision", "ֻ��" + me->name() + "�Ӹߴ�����������\n", environment(me), ({me}));
	return 1;
}

void dropoff(object me)
{
	object *inv = all_inventory(me);

	tell_object(me, "��ʯһ�������㲻�ȵ��º����ˡ�\n");
	message("vision", me->name()+"ʧ�������ȥ��\n",environment(me),({me}));
	for(int i = 0; i < sizeof(inv); i++)
		if( userp(inv[i]) )
			inv[i]->receive_wound("qi", 50 + inv[i]->query("max_qi"), "��������������");
		else    destruct(inv[i]);

	me->move("/d/shenlong/sea");
	me->unconcious();
	me->move("/d/shenlong/beach");

	message("vision","�㷢��һ������ˮ���ܵļһﱻ��ˮ���ϰ��������ɵ��߽�һ����ԭ����" + me->name() + "\241\243\n", environment(me), ({me}));
}

int *cost(object ob, string skill)
{
	if( (int)ob->query("potential") > 0 && (int)ob->query("neili") > 10 ) {
		if( !random(3) ) 
		ob->add("potential", -1);
		else ob->add("neili", -5);
		return ({0, 0});
	}
	else
	{
		switch(skill)
		{
			case "blade" : return ({10, 25});
			case "club"  : return ({15, 20});
			case "staff" : return ({20, 15});
			case "stick" : return ({25, 10});
			case "sword" : return ({30,  5});
			case "cuff"  : return ({30, 15});
			case "strike": return ({15, 30});
			case "parry" : return ({10, 20});
			case "dodge" : return ({20, 10});
		}
	}
	return ({15, 15});
}
