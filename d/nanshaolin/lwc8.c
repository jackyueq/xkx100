// Room: /d/nanshaolin/lwc8.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似��
�������������һ���䳡��
LONG );
	set("exits", ([
		"north" : __DIR__"lwc5",
		"east" : __DIR__"lwc9",
		"west" : __DIR__"lwc7",
	]));
	set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1780);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

