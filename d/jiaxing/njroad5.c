// Room: /d/jiaxing/njroad5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·���ϱ߾���Ǯ�����ˣ��Ǳߵ����¾ۼ���һЩ��ɢ
�Ĵ���
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"north": __DIR__"njroad4",
		"south": __DIR__"jiangpan1",
	]) );

	set("coor/x", 1580);
	set("coor/y", -1070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}