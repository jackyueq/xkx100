// Room: /d/mobei/road1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "Ӫ�ʼ�");
	set("long", @LONG
��Ŀ�������Ƕ������������Ӫ�ʣ�һ������һ�����ɹŲ�������
Ϊ����ƽʱ��ס�����ɹŰ�����ⷽ�㡣�����е�ͨ�򼸸���Ļ���ֱ�
�������ʹ��ǵ�ס����������ԯ�ţ��������ӭ����չ��
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qinwei1" : 1,
	]));
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"road",
		"east" : __DIR__"road2",
		"west" : __DIR__"road3",
		"south" : __DIR__"yuanmen",
	]));
	set("coor/x", -210);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
