// Room: /d/wuyi/shijianshi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�Խ�ʯ");
	set("long", @LONG
����Ϫ�����Խ�ʯ���ഫ�ǵ���غ������Խ�ʱ�����ġ�ʯ������
���Ѻۣ�ƽֱ�����롣�γ�������ֵ���������Ϊ�����ɽ����ҽ���ʯ
����Ƽ�������︽����Ϫ����С�������������ѣ���ֱ���Ǿ���Ϫ����
Ӱһ�㡣
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"xiandiaotai",
		"south" : __DIR__"4qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

