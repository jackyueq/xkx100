// Room: /d/baituo/midao2.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIR"�ص�"NOR);
	set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ��������ʯ�ڷ�
����ʪ������������ˮԴ�������￪ʼ�Ե��ֳ����������ߣ������ߺ�
����Կ���һ�����⡣
LONG);		
	set("exits", ([
		"westdown" : __DIR__"midao3",
		"eastdown" : __DIR__"midao5",
		"eastup"   : __DIR__"midao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49940);
	set("coor/y", 20080);
	set("coor/z", 0);
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
