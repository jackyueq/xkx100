// Room: /d/baituo/midao1.c
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
	set("objects", ([
		__DIR__"npc/hama" : 1,
	]));
	set("exits", ([
		"westdown" : __DIR__"midao2",
		"east"     : __DIR__"midao0",
	]));
	set("coor/x", -49930);
	set("coor/y", 20080);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <8 && me->query_con() < 30)
	{ 
		tell_object(me, HIB"���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );
		tell_room(environment(me),me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}
