// Room: /d/hengshan/tongyuangu.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "ͨԪ��");
	set("long", @LONG
ͨԪ�ȹ´����Է��£��ഫΪ�Ź��ϳ���ǰ�޵�֮��������������
��ͨԪ��������Ҳ�ͳ���ͨԪ�ȡ�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"eastup"  : __DIR__"guolaoling",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/chuanbei" : random(2),
	]));
	set("outdoors", "hengshan");
	set("coor/x", 20);
	set("coor/y", 3160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

