// Room: /d/mobei/road.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "Ӫ�ʼ�");
	set("long", @LONG
��Ŀ�������Ƕ������������Ӫ�ʣ�һ������һ�����ɹŲ�������
Ϊ����ƽʱ��ס�����ɹŰ�����ⷽ�㡣�����һ��Ӫ��ǰһ�˸߸ߵ�
������Ʈ�ż��ư�ë���������ڴ����Ǵ󺹾Ӵ���
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qinwei1" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yinzhang",
		"south" : __DIR__"road1",
		"east"  : __DIR__"wokuotai",
		"west"  : __DIR__"tuolei",
	]));

	set("coor/x", -210);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
