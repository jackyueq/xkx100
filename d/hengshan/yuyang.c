// Room: /d/hengshan/yuyang.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
�ڶ����ͱ��¶��ϣ���ʯ���ۣ�ɢ�����£�����������£����ж�
�У������ڳԲݵ���ֻ������Ǻ͡��𼦱����������ĺ�ɽʤ��������
���ơ���
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"westdown"    : __DIR__"beiyuedian",
	]));
	set("outdoors","hengshan");
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 3180);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

