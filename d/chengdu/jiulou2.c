// Room: /d/chengdu/jiulou2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "���Ӿ�¥��¥");
	set("long", @LONG
�����ڳɶ�������ľ�¥�ϣ�����¥�µķ���ææµµ���������
��죬��ν���ԾƵ��裬�������Ρ�������ԥʲô��������������ɣ�
LONG );
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		  __DIR__"obj/chair" : 4,
	]));
	set("coor/x", -8030);
	set("coor/y", -3020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
