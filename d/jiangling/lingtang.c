//Edited by fandog, 01/31/2000

inherit ROOM;
#include <ansi.h>;
void create ()
{
	set ("short", "����");
	set ("long", @LONG
����һ�����ã����������ҫ�ۡ������ϵ�ȼ���������򣬰�����
һ������(Pai)����������һƥ������
LONG);
	set("item_desc", ([
		"pai" : HIW"��Ů��˪��֮��λ\n"NOR,
	]));
	set("exits", ([ 
		"south" : __DIR__"feiyuan",
		"west"  : __DIR__"zoulang",
		"east"  : __DIR__"yongdao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
