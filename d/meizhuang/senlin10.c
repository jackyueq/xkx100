// /d/meizhuang/senlin2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��ľ԰");
	set("long", @LONG
������÷ׯ�İ�ľ԰����һ�ߵ���������ߵ���һ�������޾���
Сɭ��һ��������������������������������кܶ�в��������ֵ�
������ľ�����������У�ֻ�����Ƭ���־��������һ�飬������ȥ��
�á�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"senlin3",
		"east"  : __DIR__"senlin6",
		"south" : __DIR__"senlin9",
		"north" : __DIR__"senlin7",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jiading" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3500);
	set("coor/y", -1430);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
