// Room: /d/nanshaolin/lwc.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似��
�ϱ����������һ���䳡��
LONG );
	set("exits", ([
		"east"  : __DIR__"lhtang",
		"west"  : __DIR__"lwc5",
		"north" : __DIR__"lwc2",
		"south" : __DIR__"lwc9",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

