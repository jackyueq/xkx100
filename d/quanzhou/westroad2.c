// Room: /d/quanzhou/westroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ��������ǿ�
Ԫ�£��ϱ��Ǽ������ϵ꣬�����������ŵ��š�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"westbridge",
		"east"  : __DIR__"westroad1",
		"north" : __DIR__"kaiyuansi",
		"south" : __DIR__"jishitang",
	]));
	set("coor/x", 1830);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
