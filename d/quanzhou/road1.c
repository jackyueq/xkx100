// Room: /d/quanzhou/road1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����Ȫ�����涫�����һ���ɵ�����ģ������ȥ�ɴﺣ�⽻ͨʹ
�ڸ���������һ�����ׯ��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"   : __DIR__"chouduan",
		"south"  : __DIR__"road2",
		"north"  : __DIR__"tumenji",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
