// Room: /d/taishan/xianren.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ڰ��������ࡣ���¶��ţ��������������ʯ�νӵֳŶ�
����״��
LONG );
	set("exits", ([
		"northeast" : __DIR__"aishen",
		"south"     : __DIR__"wanghai",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 360);
	set("coor/y", 750);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
