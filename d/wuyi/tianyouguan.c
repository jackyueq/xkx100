// Room: /d/wuyi/tianyouguan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "���ι�");
	set("long", @LONG
���η�����ιۣ�ʼ���촲�����ξ������ؽ����е���ʽ��¥��
������������������Ϊ�ο����裬�;��ĳ�������������̨�����¸�
���춹����ʤ�������ƣ�����Ȫ���侦���꣬��ľŨ�����ຮ����
    ���й�����������������ӣ���������ġ��ഫ�����迣����ˮ��
�Ѿ������壬������������ˮ��ɽ���˼䶴�졣ɽ��֮����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"down"    : __DIR__"tianyoufeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4970);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

