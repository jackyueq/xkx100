// Room: /binghuo/lingsheroad3.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����������е�С·�ϣ�����Ƨ��������е���Ϣ����쳣����
�ܲ�������������գ�������������һ�������ɽ������С�ݵ���
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown"  : __DIR__"lingsheroad2",
		"northup"   : __DIR__"lingshetop",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (random(2) == 1)
	{
		me->receive_damage("qi", 10);
tell_object(me, HIR"��Ȼһ���ʹ��"NOR"��һ�Ų��ڸ������ˣ������ƿڴ��
������ģ��ĸ����˵��ɵģ�����\n");
	}
        return ::valid_leave(me, dir);
}

