// Room: /d/5lt/jiulou2.c

inherit ROOM;

void create()
{
	set("short", "�û���¥��¥");
	set("long", @LONG
�����ڴ���������ľ�¥�ϣ�����¥�µķ���ææµµ���������
��죬��ν���ԾƵ��裬�������Ρ�������ԥʲô��������������ɣ�
LONG );
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		  __DIR__"obj/chair" : 4,
	]));
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
