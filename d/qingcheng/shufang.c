// d/qingcheng/shufang.c
inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����һ��ɸɾ������鷿������һ����̴ľ�������Ϸ��Ų����鼮��
��ǽ�ĵط�����һ����ܣ�����������ȫ�Ǹ��ַ�װ���顣���в�����
����ȥ���ⰻȻ����Ȼ����Ѿá�
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang2",
	]));
	set("objects", ([
		"/clone/book/laozi1": random(2),
		"/clone/book/laozi13": random(2),
		"/clone/book/daodejing-i": (int)(random(4)/3),
		"/clone/book/daodejing-ii": (int)(random(4)/3),
		"/clone/book/cheng18po": (int)(random(4)/3),
	]) );
	set("coor/x", -8070);
	set("coor/y", -850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}