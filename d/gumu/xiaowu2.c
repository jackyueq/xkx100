// xiaowu2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С��Ůι��ѵ�����ķ��ݣ��ݽ��Ϲ��źܶ�������εķ�
������δ���ţ����ŵõ�һ����۵����㡣
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao12",
		"south" : __DIR__"mudao13",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));
	set("coor/x", -3180);
	set("coor/y", -20);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
