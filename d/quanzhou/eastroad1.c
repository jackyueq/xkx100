// Room: /d/quanzhou/eastroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ������ߵ���
������ʿ�����أ��Է�����ϴ�١�����������Թ��ٵ���̨��
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"eastroad2",
		"west"  : __DIR__"guangchang",
		"north" : __DIR__"liangcang",
	]));
	set("coor/x", 1860);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
