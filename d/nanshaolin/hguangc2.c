// Room: /d/nanshaolin/hguangc2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡���ɴ���ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ���
����ǰ�и���ʩչ�ڹ���������ӡ�ǡ�����ͨ���󱯵
LONG );
	set("outdoors", "nanshaolin");
	set("no_fight", 1);
	set("exits", ([
		"east"  : __DIR__ "hguangc3",
		"west"  : __DIR__ "hguangc1",
		"south" : __DIR__ "dabeidian",
        ]));
        set("objects",([
//		CLASS_D("shaolin") + "/dao-jue" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
