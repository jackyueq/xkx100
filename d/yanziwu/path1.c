// Room: /d/yanziwu/path1.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����������ɽׯ�е�����С���ϡ�С�����������һ����軨����
�����������ɫ�軨��ʱ�з�ɵ���ϷŪ���䡣�㲻�Ҷ���������ǰ
�С�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"path2",
		"west"   : __DIR__"dukou",
	]));
	set("coor/x", 1210);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}