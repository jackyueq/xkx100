// wg_shilu-3.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ�һֱͨ���Ժ��·������Щ��ͨ�Ļ��ݣ���
�ϵ�С�񣬲�ͣ�Ľ��š�
LONG);
	set("exits", ([
		"east" : __DIR__"wg_houyuan",
		"west" : __DIR__"wg_shilu-4",
	]));
	set("objects", ([
		__DIR__"npc/wg_puren1" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 51);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

