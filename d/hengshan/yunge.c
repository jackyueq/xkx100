// Room: /d/hengshan/yunge.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�Ƹ��Բ�");
	set("long", @LONG
����ջ�����͵��Ƹ���š�ǰ����ɽ������Է壬��Ҫ��������
�����ӡ������Բ���ˮ�������������ؽ��泩��
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"      : __DIR__"daziling",
		"northdown" : __DIR__"zhandao",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/zhi" : 1,
	]));
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3140);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

