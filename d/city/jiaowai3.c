// Room: /d/city/jiaowai3.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С����������Զ����
�в������֣�������ת��ʹ���ʱ���⾡����
    �������˺ܶ���֦ʯ�顣
LONG );
	set("exits", ([
		"north" : __DIR__"jiaowai2",
		"south" : __DIR__"jiaowai4",
	]));
	set("objects", ([
		__DIR__"obj/shitou": 2,
		"/clone/medicine/vegetable/chantui" : random(2),
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}