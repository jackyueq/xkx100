// Room: /d/suzhou/huqiu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ɽ����ɽ���ƶ׻������������ഫ��������а׻�������Ĺ
�ϣ���������ɽǰ�����Ĺȣ���ľ��ï����ɫ�������ɽ���ɿ�㣬
ʯ�������������ۻ롣�С�ɽ���������ɫ���챻��Ϊ�����е�һ��
ʤ����
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"road1",
		"south"      : __DIR__"toumenshan",
	]));
        set("objects", ([
		"/d/hangzhou/obj/shuzhi" : 1,
		"/d/hangzhou/obj/eluanshi" : 1,
	]));
	set("coor/x", 800);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
