#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{      
       set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط���,
����������խ��С��ͨ�����¸��
�� 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong101",
                "down" : "/d/migong/lev11/dong21"
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
