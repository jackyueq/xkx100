// pine_forest1.c ����
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
	
	if (random(2)) 
		set("objects", ([ __DIR__"obj/pine" : 1]));
	else 	                        	
		set("objects", ([ __DIR__"obj/songguo" : 1]));

	
	set("exits", ([
		"north" : __DIR__"pine_road2",
		"south" : __DIR__"pine_forest"+(2+random(4)),
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

