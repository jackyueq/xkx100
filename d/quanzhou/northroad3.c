// Room: /d/quanzhou/northroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ��������Ƕ�
�����ͨ����������һ�Ӷӵ�ʿ��������ȥ������ɭ�ϡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"duduxiang",
		"south" : __DIR__"northroad2",
		"north" : __DIR__"weiyuanlou",
	]));
	set("coor/x", 1850);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
