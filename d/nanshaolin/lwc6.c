// Room: /d/nanshaolin/lwc6.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似��
�ϱ����������һ�����䳡����������ϰ�书�õ��޺��Ų���
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc5",
		"west"  : __DIR__"luohan5",
		"south" : __DIR__"lwc7",
		"north" : __DIR__"lwc4",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1770);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

