// Room: /d/songshan/songyueta.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������Ϊ����ʽש�����ߴ�ʮ���ɣ�����ʮ���棬���Ұ˷����ţ�
ʮ���������ɲ�����ս����������ס�
LONG );
	set("exits", ([
		"east" : __DIR__"songyuesi",
	]));
	set("objects", ([
		__DIR__"npc/dizi" :1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -30);
	set("coor/y", 790);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
