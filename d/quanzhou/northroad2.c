// Room: /d/quanzhou/northroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ�����������
��һ�����ӣ���ͨ��������
LONG );
	set("outdoors", "quanzhou");
	set("objects", ([
		"/d/city/npc/liumang" : 1,
	]));
	set("exits", ([
		"south"     : __DIR__"northroad1",
		"north"     : __DIR__"northroad3",
		"northwest" : __DIR__"chenghuangxiang",
	]));
	set("coor/x", 1850);
	set("coor/y", -6510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
