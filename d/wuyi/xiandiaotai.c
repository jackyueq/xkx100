// Room: /d/wuyi/xiandiaotai.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�ɵ�̨");
	set("long", @LONG
����λ������Ϫ�����ֳƵ���̨����ˮ���������������͵��ҷ
ֱ�����죬����һ��ͷ�����ҡ���Ϫ���������̡������ɽ�����������
�ѣ��ֶϵ��ͣ��Ĳ�������ָ�ľ�����������ҿ��е������ڡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shijianshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

