// Room: /d/jiaxing/njroad4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·�����ϱ߿��Ѿ����Կ������ˣ���ˮ����������
ʱ���û�����Ķ��ġ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"north": __DIR__"njroad3",
		"south": __DIR__"njroad5",
	]) );
	set("objects", ([
		"/d/village/npc/boy" : 1,
	]) );

	set("coor/x", 1580);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}