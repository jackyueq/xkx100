// Room: /d/hengshan/huixiantai.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "���Է�ɽ��");
	set("long", @LONG
�����ڼ��Է�ɽ��С·�ϣ�����ɽ��������ӹģ���ǰ����Ư����
ԶԶ����ǰ����Ƿ嶥�ˡ�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"southdown"  : __DIR__"beiyuedian",
		"eastup"     : __DIR__"square",
	]));
	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 3200);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

