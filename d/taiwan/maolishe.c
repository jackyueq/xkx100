// Room: /d/taiwan/maolishe.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "è����");
	set("long", @LONG
è����λ����ǵ���ϡ��峯���꣬�˵صĺ��˻����٣���ס������
����Ҫ��̩�����ˣ�����������Ϊ����
LONG );
	set("exits", ([
		"eastup"    : __DIR__"dabajianshan",
		"northeast" : __DIR__"zhuqian",
		"southwest" : __DIR__"banxianshe",
	]));
	set("objects", ([
		__DIR__"npc/taiyaren": 1,
	]));

	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -6990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

