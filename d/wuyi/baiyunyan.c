// Room: /d/wuyi/baiyunyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ�ھ�����ͷ��ɽ�ϰ����£�����Ѿ�һǧ������ˡ�ȫ��
��Ϊ�Ĳ����Ҷ�������ǽ���������ƺ�ΰ�����ϰ����Ҷ���ֻ����ľ��
�죬�����㡣����ɽ�£�������Ϫ�������ƣ������ɷ��о���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast"  : __DIR__"path9",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -4960);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

