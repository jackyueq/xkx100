// Feb. 6, 1999 by Winder
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����¼�����һ�������صİ�����Ҳ��֪����˭�޽��ġ� 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"andao2",
		"up"    : __DIR__"xiaoting",
	]));
	set("coor/x", 1620);
	set("coor/y", -1770);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
