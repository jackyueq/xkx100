// Room: /d/mobei/caocong1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ݴ���");
	set("long", @LONG
������ߺ������ص����Ķѻ���ͷ��ȴ��һƬ����ɫ����գ�����
Ƭ�ơ�������һ�󻺣�һ�󼱣����½������죬����һ�Ż��Ρ��¹�֮
�£��ݴ���¶��ʯ��һ�ǡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"hill1",
	]));
	set("coor/x", -220);
	set("coor/y", 5240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
