// Room: /d/lingxiao/wave1.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG 
����һ���޴����Ȼ����������Ҳû�뵽������Ȫˮ̶�£���Ȼ��
����һ���������Ķ��츣�ء�վ������·�������ˮ������һ�㣬
����ȫ�Ǿ�Ө��͸�ı��飬����˷������Լ��ĵ�Ӱ����ɼ�����
LONG);
	set("exits",([ /* sizeof() == 1 */
		"up"   : __DIR__"water", 
		"west" : __DIR__"wave2", 
	]));
	if(random(6)>3)
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8950);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
