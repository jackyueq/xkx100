// Room: /d/mobei/road3
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "Ӫ�ʼ�");
	set ("long", @LONG
��Ŀ�������Ƕ������������Ӫ�ʣ�һ������һ�����ɹŲ�������
Ϊ����ƽʱ��ס�����ɹŰ�����ⷽ�㡣�����е�ͨ�򼸸���Ļ���ֱ�
�������ʹ��ǵ�ס����
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"east"  : __DIR__"road1",
		"west"  : __DIR__"qinwei2",
		"south" : __DIR__"boershu",
		"north" : __DIR__"muhuali",
	]));
	set("coor/x", -220);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
