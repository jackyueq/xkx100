// Room: /d/yanziwu/path3.c
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
		"north"  : __DIR__"path4",
		"west"   : __DIR__"bridge",
	]));
	set("coor/x", 1230);
	set("coor/y", -1290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}