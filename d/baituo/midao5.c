// Room: /d/baituo/midao5.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIR"�ص�"NOR);
	set("long", @LONG
�����������ص���ɽ�����������죬��֪ͨ���δ���ǰ��ĵ�·Խ
��Խ�������Ҫ�����������ˡ�����������ǣ���������һ�ɴ̱ǵ�ζ
������һ�߹��������ͷ�Է��Σ������ж��ˡ�
LONG);		
	set("exits", ([
		"westup"   : __DIR__"midao2",
		"eastdown" : __DIR__"midao6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49930);
	set("coor/y", 20080);
	set("coor/z", -10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <13 && me->query_con() < 33)
	{
		tell_object(me, HIB"���Ȼ�е�����һ����ԭ��������Ŀ������ǡ���ͨ������\n" NOR );	
		tell_room(environment(me),me->name()+"ͻȻ��ɫ��ü�Ϊ�ѿ�������������˿�����\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}
