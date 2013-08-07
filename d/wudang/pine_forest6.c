// pine_forest6.c ����
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
	
	switch(random(8)){
	case 1:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 2:
		set("objects", ([ __DIR__"npc/snake" : 1]));
		break;
	case 0:
		set("objects", ([
			__DIR__"obj/songguo" : 1,
			__DIR__"npc/snake" : 1]));
		break;
	case 3:
		set("objects", ([ __DIR__"npc/snake" : 2]));
		break;
	case 4:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(4+random(6)),
		"north" : __DIR__"pine_forest"+(6+random(4)),
		"east" : __DIR__"pine_forest"+(random(6)),
		"west" : __DIR__"pine_forest"+(random(6)),
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

