// Room: /d/mobei/hill1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
ϡ��Ĺ�ľ���ݴԡ��¶��Ƚ�ƽ����������һ�����һ�󻺣�����
��һƬ���ƻ����ƶ���������Ƶ��¹��¼����׻�Ư�Ʋ���������Ĳ�
�����ƺ���Щ���������Ű׹⡣
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/kezhene" : 1,
	]));
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"east"      : __DIR__"caocong",
		"northwest" : __DIR__"caocong1",
		"westdown"  : __DIR__"shulin",
	]));
	set("coor/x", -210);
	set("coor/y", 5230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
