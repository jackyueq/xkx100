// Room: /d/hengshan/sanjiaodian.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "���̵�");
	set("long", @LONG
������ȫ����ߴ������̵Ҳ�����������ĵ������ż���
ȫ����ÿ��������ʯ��ľ�����ܣ����ǡ��������ɡ����Ž��漣��
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"down"   : __DIR__"xuankong1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
