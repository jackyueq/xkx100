// Room: /d/hengshan/huixiantai.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����̨");
	set("long", @LONG
�߳���������ܿ���һ��ʯ�ߣ������ھ����������һ��С�ң�
���ǻ���̨��̨������Ⱥ�ɵ����������飬����ʤ����
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown"  : __DIR__"beiyuedian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 3180);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

