// Room: /yangzhou/chongyanting.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","����ͤ");
	set("long",@LONG
����̨�ϲ࣬��һ����ͤ����ʯͤ�����������ǣ��ϸ�����������
�ͱ�����
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north"     : __DIR__"pingtai5",
		"southeast" : __DIR__"guanshaoting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}