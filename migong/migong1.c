#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
   ����һ����᫵�ɽ·�����ܶ���ï�ܵĹ�ľ�ԣ�ʱ��ʱ����
һ��Ұ�޵ĺ������
LONG );
	set("exits", ([
		"east" : __DIR__"migong2",
                "west" :"d/sdxl/conglin3",		                          	
		                          	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
