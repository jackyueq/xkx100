// pine_forest10.c ����СϪ
// Last Modified by winder on Aug. 18 2002

#include <localtime.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	mixed *local;
	object *ob;
	local = localtime(time()*60);

	set("short", HIM"���вݵ�"NOR);
	set("long", @LONG
��ǰ����Ȼ���ʣ�������¶��һƬ�յأ��м�һ��Ϫˮ����������
Ϫ���滨��ݣ������ر����ޡ�
LONG
	);
	if( local[LT_MON] > 5 && local[LT_MON] < 10 )
		set("objects", ([
			VEGETABLE_DIR"heshouwu" : 1,
			__DIR__"npc/python" : 1
		]));
	else
		set("objects", ([
			__DIR__"npc/python" : 1
		]));
	set("exits", ([
		"east" : __DIR__"pine_forest"+(random(2)),
		"west" : __DIR__"pine_forest"+(random(2)),
	]));
	set("outdoors", "wudang");
	setup();
}

void init()
{
	object me = this_player();
	
	if ( !objectp(me->query_temp("armor/boots")) )
		me->receive_damage("qi", 10, "������������");  

}

