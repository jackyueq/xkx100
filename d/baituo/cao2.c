// Room: /d/baituo/cao2.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","�ݴ�");
	set("long", @LONG
�������Ҳݴԡ������������֡��������涼�������ߵ���ݣ���
���߳�û��
LONG	);
	set("exits",([
		"west"  : __FILE__,
		"north" :__DIR__"zhulin",
		"east"  : __DIR__"cao1",
		"south" : __DIR__"cao1",
	]));
	set("objects",([
		__DIR__"npc/qingshe" : random(2),
		__DIR__"npc/jinshe" : random(2),
		__DIR__"npc/snake" : random(2),
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
