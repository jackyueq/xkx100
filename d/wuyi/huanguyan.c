// Room: /d/wuyi/huanguyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ͤ��֮�����ഫ������ʮ�����ڴλ��ǳ��ɡ����ǣ���
��ͳ����˼���ɽ�ķ�ˮ�롣�������ƶ����߹�Ȫˮ�������ʣ���Ϊ
����Ȫ�����鶴�ڿ�����ɣ�����С¥����ʩƬ�ߣ����겻�֣��׳ơ�
��Ů��ױ¥����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"sangufeng",
		"south"     : __DIR__"mantingfeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4960);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

