//ROOM xiaodao1.c

inherit ROOM;

void create()
{
	set("short", "С��");
        set("long",@LONG
һ��С���������۵�ͨ��Զ��, �����������де����֣�΢�紵����
��Ҷ����������������
LONG );
	set("outdoors", "lingjiu");
	set("exits", ([
		"north" : __DIR__"xiaodao2",
		"south" : __DIR__"huayuan",
	]));
	set("objects",([
		"/d/baituo/npc/cungu" : 1,
	]));
	set("coor/x", -51000);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}