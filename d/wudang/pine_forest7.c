// pine_forest7.c ����
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
	
	switch(random(10)){
	case 8:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 7:
		set("objects", ([ __DIR__"npc/snake" : 1]));
		break;
	case 3:
		set("objects", ([
			__DIR__"obj/songguo" : 1,
			__DIR__"npc/snake" : 1]));
		break;
	case 0:
		set("objects", ([ __DIR__"npc/snake" : 2]));
		break;
	case 4:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(7+random(3)),
		"north" : __DIR__"pine_forest"+(5+random(5)),
		"east" : __DIR__"pine_forest"+(random(10)),
		"west" : __DIR__"pine_forest"+(random(10)),
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

