// xiaowu1.c С��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���߽���һ��С�ݣ������С������һ��С���Ų��±�Ķ����ˡ�
���Ϻ����м���������������Ĵֲ�����ϴ�ĸɸɾ�����
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao10",
		"north" : __DIR__"mudao04",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));
	set("coor/x", -3220);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

