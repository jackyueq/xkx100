// Room: /d/gaochang/road.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
#include <ansi.h>;

void create ()
{
	set ("short", "ɳ��С·");
	set ("long",
"ע�⣺�ɴ˴��򱱣�������߲��Թ����򣬲�֪�߷���û������׼
��������뿼������Ƿ�Ҫ���С�
              
                    "HIR"��   ��   ��   ��\n\n\n"NOR

);

	set("outdoors", "gaochang");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"shulin1",
//		"west" : "/d/xingxiu/shanjiao",
		"south" : "/d/hasake/shulin1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/liwenxiu" : 1,
	]));

	set("coor/x", -38000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}