// Room: /d/nanshaolin/lwc16.c
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
		"east"  : __DIR__"lwc15",
                "west"  : __DIR__"brtang",
		"north" : __DIR__"lwc14",
		"south" : __DIR__"lwc17",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

