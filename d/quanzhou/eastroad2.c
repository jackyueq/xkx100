// Room: /d/quanzhou/eastroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ�����Թ����
���ڱ��ߣ���ͨ����̨����̨������ǳ����һ��ʢ�¡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"eastroad1",
		"north"  : __DIR__"enyuanxiang",
	]));
	set("coor/x", 1870);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
