// Room: /d/huashan/jzroad2.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��м�һ��С·�����߶��Ǻ�ɭɭ�ļ��ɸߵ�������
������ˣ����Կ������ߺøߵ�һ����ɽ��
LONG );
	set("exits", ([
		"west" : __DIR__"jzroad1",
		"east" : __DIR__"jzroad3",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);
	set("coor/x", -940);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
