// mishi1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����������ң�ǽ�ϵ��͵Ʒ����谵�Ļƹ⡣
LONG );
	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao14",
		"east" : __DIR__"midao14",
		"up" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}