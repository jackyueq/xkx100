// Room: /d/xiangyang/caodi4.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������������Ĳݵء��ɹű���������������İ���ȫ��
���ˣ����Ｘʮ�ﶼû�����̡�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"southgate2",
	]));
	set("coor/x", -490);
	set("coor/y", -560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}