// Room: /d/mobei/caocong.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ݴ���");
	set("long", @LONG
������ߺ������ص����Ķѻ���ͷ��ȴ��һƬ����ɫ����գ�����
Ƭ�ơ�������һ�󻺣�һ�󼱣����½������죬����һ�Ż��Ρ��¹�֮
�£��ݴ������Ѱ�ɫ�Ķ�����ģ�����ǹ��档
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/obj/baigu" : 3,
	]));
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hill1",
	]));
	set("coor/x", -200);
	set("coor/y", 5230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
