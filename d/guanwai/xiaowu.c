// /guanwai/xiaowu.c

inherit ROOM;

void create()
{
	set("short", "Сé��");
	set("long", @LONG
����һ���ó���ɽ��ľ�ݳɵ�С�ݣ����ڴ�ɨ�ĺܸɾ������ܵ�ǽ
���Ϲ�������Ƥ��ѩ����һ��СС����������һ��Ӣ�����ꡣ
LONG );
	set("exits", ([
		"south" : __DIR__"baihe",
	]));
	set("objects", ([
		__DIR__"npc/hufei" : 1,
	]));
	set("no_beg", "1");
	set("no_fight", "1");
	set("coor/x", 6140);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
}
