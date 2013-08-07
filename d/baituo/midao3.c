// Room: /d/baituo/midao3.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIR"�ص�"NOR);
	set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ��������ʯ�ڷ�
����ʪ������������ˮԴ��
LONG);	
	set("exits", ([
		"westdown" : __FILE__,
		"north"    : __DIR__"midao4",
		"south"    : __DIR__"midao4",
		"eastup"   : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -49950);
	set("coor/y", 20080);
	set("coor/z", -10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <10 && me->query_con() < 30)
	{ 
		tell_object(me, HIB"���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );
		tell_room(environment(me),me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}

int valid_leave(object me, string dir)
{
	if ( dir == "north") me->add_temp("mark/steps",1);
	if ( dir == "westdown") me->add_temp("mark/step",1);
	if ( dir == "south") me->add_temp("mark/steps",-1);
	if ( dir == "eastup") me->add_temp("mark/step",-1);
	if ((me->query_temp("mark/steps") == 3) &&
		(me->query_temp("mark/step") ==4))
	{
		me->move(__DIR__"tianjing");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("�������ţ�ͻȻ����ǰ���������һЩ������\n");
	}
	if ((me->query_temp("mark/steps") == -3) &&
		(me->query_temp("mark/step") ==-4))
	{
		me->move(__DIR__"midao2");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("�������ţ�ͻȻ����ǰ��ĵ�·��Щ�仯��\n");
	}
	if ((me->query_temp("mark/steps") == 10) ||
		(me->query_temp("mark/step") == 10) ||
		(me->query_temp("mark/steps") == -10) ||
		(me->query_temp("mark/step") == -10))
	{
		me->move(__DIR__"midao7");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("�������ţ�ͻȻ����ǰ��ĵ�·��Щ�仯��\n");
	}
	return ::valid_leave(me,dir);
}
