//cave.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long",
	     "������̶�е�һ��С������������������м���ʯͷ��\n"
	);
	set("objects" , ([
		__DIR__"item/stone" : 1,
	]) );
	set("coor/x", -1510);
	set("coor/y", -1020);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}
