// wg_shilu-2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��ʯ��·�ϣ���������涼��ϰ���ã����������������
�����ģ���������ݴ�����
LONG);
	set("exits", ([
		"southup" : __DIR__"wg_dating",
		"north"   : __DIR__"wg_shilu-4",
		"east"    : __DIR__"wg_xiwutang",
		"west"    : __DIR__"wg_xiwutang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_qzdaotong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

