// Room: /d/mingjiao/huangtulu2.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������ï�������е�һ������С·�����ּ��ܣ����涼�������ĵ�
�о����װ׵ı�ѩ����ҫ�ۡ�������һ��ɽ����Σ��֮�ߣ�ǰ����һ��
С����
LONG );
	set("exits", ([
		"east"  : __DIR__"huangtulu1",
		"enter" : __DIR__"shandong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52050);
	set("coor/y", 800);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "enter") &&
		!wizardp(me) && !objectp(present("xiao zhao", environment(me))))
	{
		return notify_fail("��������ʥ�أ�����ɱ���⡣\n");
	}
	return ::valid_leave(me, dir);
}