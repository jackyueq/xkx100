// Room: /d/yanziwu/bridge.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����С�ź������Ϫ֮�ϡ�����Ϫˮ������䣬�������񡣺�����
С�����������٣���Ŀ���̣�ʮ�ֿ��ˡ�
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"west"  : __DIR__"path2",
		"east"  : __DIR__"path3",
	]));
	set("objects", ([
		__DIR__"npc/xiaolan" : 1,
	]));
	set("coor/x", 1220);
	set("coor/y", -1290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}