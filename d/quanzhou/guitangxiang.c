// Room: /d/quanzhou/guitangxiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��̳��");
	set("long", @LONG
��̳��˳��ʩ����ǽ���Ѷ�����һ����������ˮ�Ĺ������İ�������
��̳����������ǳ����¡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"xuetang",
		"north"     : __DIR__"jiangjunfu",
		"southwest" : __DIR__"chengtiansi",
	]));
	set("coor/x", 1870);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
