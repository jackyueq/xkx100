//htqdating.c
inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
�����Ǻ�����Ĵ��������е�ǹ���֣�������չ�����ڴ������׸�
������������²����꣬һ���������ӡ����ж����Ÿ����պ��ӣ���
�Ǻ���������ʹ��ԫ��
LONG);
	set("exits", ([
		"out" : __DIR__"htqmen",
	]));
	set("objects", ([
		__DIR__"npc/yanyuan": 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 930);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}