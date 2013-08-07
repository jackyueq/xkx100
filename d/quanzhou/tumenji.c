// Room: /d/quanzhou/tumenji.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "Ϳ�ż�");
	set("long", @LONG
����Ȫ�����涫�����һ���ɵ�����ģ�����ϱ���Ȫ�������ĺ�
����ׯ�������Ǹ����У����߱���ȥ���ۿڵ���Ҫͨ����Ϳ��ˮ�ء���
LONG );
	set("outdoors", "quanzhou");
	set("objects", ([
		"/d/taishan/npc/tangzi": 1,
	]));
	set("exits", ([
		"east"  : __DIR__"tumenshuiguan",
		"west"  : __DIR__"jishi",
		"south" : __DIR__"road1",
		"north" : __DIR__"qingjingsi",
	]));
	set("coor/x", 1860);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
