// Room: /d/baituo/cao1.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","�ݴ�");
	set("long", @LONG
�������Ҳݴԡ��������ȹ�����С���š��������涼�������ߵ���
�ݣ������߳�û��
LONG	);
	set("exits",([
		"west"  : __FILE__,
		"north" : __DIR__"cao2",
		"east"  : __DIR__"ximen",
		"south" : __FILE__,
	]));
	set("objects",([
		__DIR__"npc/jinshe" : random(2),
		__DIR__"npc/snake" : random(2),
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}


