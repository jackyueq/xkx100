// Room: /d/quanzhou/luanshigang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
������ľ��ɭ����ʯ��ᾣ��¶����������Ҫ�������������̾�
�ĵط���
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"shisun",
		"east"  : __DIR__"diaoqiao",
	]));
	set("objects", ([
		"/d/wudang/npc/tufei1" : 1,
		"/d/wudang/npc/tufei2" : 1,
		"/d/wudang/npc/tufeitou" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
