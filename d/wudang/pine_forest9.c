// pine_forest9.c ����
// Last Modified by winder on Aug. 18 2002

inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
������������������գ�������ֻ�о�������ǰ�󵽴�������Ӱ��
������һ�����������ã�������ӫӫ���׹⡣�㾪��֮�䣬һ�Ų��ڸ�
���������ϣ�
LONG
	);
	
	switch(random(11)){
	case 1:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 2:
		set("objects", ([ __DIR__"npc/snake" : 1]));
		break;
	case 9:
		set("objects", ([
			__DIR__"obj/songguo" : 1,
			__DIR__"npc/snake" : 1]));
		break;
	case 12:
		set("objects", ([ __DIR__"npc/snake" : 2]));
		break;
	case 10:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	}	          	

	set("exits", ([
		"south" : __DIR__"pine_forest"+(random(11)),
		"north" : __DIR__"pine_forest10",
		"east" : __DIR__"pine_forest"+(random(9)),
		"west" : __DIR__"pine_forest"+(random(9)),
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

