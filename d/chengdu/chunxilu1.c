// Room: /d/chengdu/chunxilu1.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short",HIY "����·" NOR);
	set("long", 
"������ǳɶ�����������ҵ���ģ����������������������Ե�����\n"
"�������ַǷ��������и����¥����ɫ�Ľ���ӭ��Ʈ�ֻ�������ĸ�\n"
"���ָ�����Ŀ"+BLINK HIR"�����Ӿ�¥��"NOR"�����濴�����Ǹ���ݣ�һ�������Ź��ʵ�\n�˴��������������\n"
      );

	set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"chunxilu2",
		"north" : __DIR__"chunxilu",
		"east"  : __DIR__"jiulou1",
		"west"  : __DIR__"chaguan",
	]));
	set("coor/x", -8040);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


