// Room: /d/tiezhang/shanjiao.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
�����ѵ���ɽ���£��˴���������������ɽ����أͻŭ��ȷ�����
��ָ�����ڰ��֮�С�����һ���ȼ�ͦ�Σ�����ָ�죬�����Ʊ�������
����ɽ������һƬ���֣�������ѩ������������������������缫�ҡ�
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
		"northup"   : __DIR__"shanmen",
		"southeast" : __DIR__"road3",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -2040);
	set("coor/y", -2010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
