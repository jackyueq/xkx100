#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"ʯ��"NOR);
	set("long", CYN @LONG
����һ��������ʯ������Χ���Ǽ�Ӳ��ʯ��,�����н���
�ƺ�����һֱ����ȥ�� 
LONG CYN);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "down" : "/d/migong/lev4/dong21"
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
