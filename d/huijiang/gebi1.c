// Room: /d/huijiang/gebi1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ȵ�����ɹ��ãã�ĸ�ڣ����֮��ֻʣ�»�ɫ��ɳ���������
��ɳ��һ���������ߡ�ǰ�治Զ��ɳ����΢΢����������ɳĮ�е���
�ݣ��ͺ�����������߳���ƬɳĮ�ˡ�
LONG );
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : "/d/xingxiu/shanjiao",
		"west"      : __DIR__"shamo1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
