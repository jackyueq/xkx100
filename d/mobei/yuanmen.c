// Room: /d/mobei/yuanmen.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "ԯ��");
	set("long", @LONG
ԯ�Űѱ�Ӫ�;�������ָ�������ԭľ��ԯ�ű�����������ͨ�е�
ÿһ���ˡ��������ӭ����չ��һ��ֱ����ͨ����ľ���Ӫ�ʡ�
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"buluo1",
		"north" : __DIR__"road1",
	]));
	set("coor/x", -210);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
