// Room: /d/mobei/road2
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "Ӫ�ʼ�");
	set ("long", @LONG
��Ŀ�������Ƕ������������Ӫ�ʣ�һ������һ�����ɹŲ�������
Ϊ����ƽʱ��ס�����ɹŰ�����ⷽ�㡣�ϱ�������Ӫ�������Ӫ��ǰ
˩�˼�����Ȯ�������Ӫ���������ס����
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"road1",
		"east"  : __DIR__"qinwei",
		"south" : __DIR__"shuchi",
		"north" : __DIR__"chahe",
	]));
	set("coor/x", -200);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
