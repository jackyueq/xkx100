// Room: /d/quanzhou/yuetai.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��̨�㳡");
	set("long", @LONG
����ƽ̹�⻬��ʯ��㳡���м�͹��һ̨�棬�����һ�ٵ�¯��̨
����Ƕ����ʮ����ʨ��������ʯ��������Ũ��������ζ����������
һ���ֺ��ʯ����
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dongta",
		"west"  : __DIR__"xita",
		"south" : __DIR__"dxbaodian",
		"north" : __DIR__"jietang",
	]));
	set("coor/x", 1830);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
