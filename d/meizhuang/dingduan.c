// /d/meizhuang/dingduan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��ܶ���");
	set("long", @LONG
����������ܵĶ���������������Կ����������ҵ���������˼�
�߰׹����⣬ȷʵû��ʲôֵ���㻳�ɵĶ��������㷢����ܵĶ�����
�������ʵ�����һ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"mishi",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/hongchou" : 1,
	]));

	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 5);
	setup();
	replace_program(ROOM);
}
