// Room: /d/nanshaolin/lwc7.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ������
���ɵ�ľ�ˣ�һЩ����ɮ������Χ����������
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc8",
		"north" : __DIR__"lwc6",
	]));
	set("objects",([
		__DIR__"obj/mu-ren" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1770);
	set("coor/y", -6250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

