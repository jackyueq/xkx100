// Room: /d/nanshaolin/shanlu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�������ڣ��ļ��紺��ֻ����ɽ�컨���������衣����������ɽ·
�ϡ��Ĵ�������˳�ְ�ЩС��о������������ζ������ǰ��û����
���Թ����о���á�
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east" : "/d/fuzhou/puxian",
		"west" : __DIR__"ting",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

