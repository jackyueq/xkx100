#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰���
�󵶡��������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һ
ʱ��֪����ʲô�á�
LONG );

	set("exits", ([
		"north" : __DIR__"bingyin1",
		"southwest" :  __DIR__"aobai12",
	]));
	set("objects", ([
		WEAPON_DIR"changbian" : 1,
		WEAPON_DIR"changjian" : 1,
		WEAPON_DIR"gangdao" : 1,
		"/d/xingxiu/obj/tiegun" : 1,
		"/d/city/obj/duanjian" : 1,
	]));

	create_door("north", "����", "south", DOOR_CLOSED);
	set("coor/x", -190);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
