// Room: /d/nanshaolin/lwc5.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ��������䳡����������޴�Ļ�����ʯ���̾͡���
ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ��
��������Ľ��ˣ���λ��ɮ��ɫׯ�ϣ���̤���Է�λΧ�ƣ��������С�
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc1",
		"west"  : __DIR__"lwc6",
		"north" : __DIR__"lwc3",
		"south" : __DIR__"lwc8",
	]));
	set("objects",([
		__DIR__"obj/jin-ren" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1780);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

