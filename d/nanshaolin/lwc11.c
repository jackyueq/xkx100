// Room: /d/nanshaolin/lwc11.c
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
		"north" : __DIR__"lwc12",
		"east"  : __DIR__"banruo5",
		"west"  : __DIR__"lwc15",
		"south" : __DIR__"lwc19",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1870);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

