// pine_forest8.c ����
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
                set("objects", (["/kungfu/class/wudang/yin" : 1]));
                break;	
	case 2:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 4:
		set("objects", ([ __DIR__"npc/snake" : 1]));
		break;
	case 6:
		set("objects", ([
			__DIR__"obj/songguo" : 1,
			__DIR__"npc/snake" : 1]));
		break;
	case 8:
		set("objects", ([ __DIR__"npc/snake" : 2]));
		break;
	case 10:
		set("objects", ([ __DIR__"obj/pine" : 1]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(7+random(3)),
		"north" : __DIR__"pine_forest"+(8+random(2)),
		"east" : __DIR__"pine_forest"+(random(8)),
		"west" : __DIR__"pine_forest"+(random(8)),
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

