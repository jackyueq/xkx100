// Room: /d/chengdu/chunxilu2.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIY "����·" NOR);
	set("long", @LONG
������һ�����ֵĴ���ϣ�������Ⱥ�����������ɵõ���С͵Ŷ��
�����Ǹ��������ӣ������и�Ǯׯ�����Ϸ�������ʯ�
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"chunxilu3",
		"north" : __DIR__"chunxilu1",
		"east"  : __DIR__"datiepu",
		"west"  : __DIR__"qianzhuang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}

