// Room:  /d/luoyang/baiyuan.c
// Last modified by winder 2002.11.11

#include <ansi.h>;
inherit  ROOM;

void  create  ()
{
	set("short",  "��԰");
	set("long",  @LONG
��԰��ư�ڣ���ڶ���ɽ�������÷��ϡ�Ĺǰʯ���̡����ٸ��׹�
Ĺ�����֡��׾�������Ԣ����ɽ���Ժš���ɽ��ʿ����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"westdown" : __DIR__"longmen",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -45);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

