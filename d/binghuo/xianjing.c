// Room: /binghuo/xianjing.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ӵ�խ�ڹ㣬������ɣ��ӵ���Χ���������ľ�������ڿӱ�
���˲��ٴ�ʯ��ֻ����������У����Ͷʯ�Ҵ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"up"   : __DIR__"inhole1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (random((int)me->query_skill("dodge")) <= 20)
	{
		me->receive_wound("qi",30);
		return notify_fail("��ʹ����һ�ģ��붥��������Զ�͵���������ˤ�ı������ס�\n");
	}
	if (random((int)me->query_skill("dodge")) <= 35) 
	{
		me->receive_wound("qi",20);
		return notify_fail("�����һԾ��ȴ�붥����һ�ɶ�Զ�������ǰ׷�������\n");
	}
	if (random((int)me->query_skill("dodge")) <= 60)
	{
		me->receive_wound("qi",10);
		return notify_fail("����������붥ֻ��һ����ˣ��ټӰѾ���\n");
	}

	return ::valid_leave(me, dir);
}


