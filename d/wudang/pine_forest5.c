// pine_forest5.c ����
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
	case 3:
		set("objects", ([
			__DIR__"obj/songguo" : 1,
		//	"/d/xingxiu/npc/centipede" : 1
		]));
		break;
	case 4:
		//set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
		break;
	case 5:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(5+random(4)),
		"north" : __DIR__"pine_forest"+(3+random(7)),
		"west" : __DIR__"pine_forest"+(random(6)),
		"east" : __DIR__"pine_forest4",
	]));
	set("outdoors", "wudang");
	setup();
}


void init()
{
	object me = this_player();
	
	if ( !objectp(me->query_temp("armor/boots")) )
		me->receive_damage("qi", 5, "������������");  

}

