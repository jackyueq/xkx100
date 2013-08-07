// Room: /d/gumu/shishi5.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"ʯ��"NOR);
	set("long", @LONG
��ͻȻ������ǰһ����ǰ��ʯ��͸����һ˿΢���Ĺ⣬������һ˿
ϣ����������ֻ����ԶԶ������Ų��Ļ������յ����ĸо�ʹ������ֻ
�п־壬�������ǹ¶���������˼�Ȼ������ֻ�ܿ�����ǰ�С�
LONG	);
	set("exits", ([
		"west"  : __DIR__"shishi4",
		"enter" : __DIR__"lingshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -40);
	set("coor/z", 80);
	setup();
}

int get_object(object ob)
{
	if(userp(ob)) return 1;
	return 0;
}

int valid_leave(object me,string dir)
{
	object *inv = deep_inventory(me);
	object *obj;
	if((int)me->query_skill("yunv-xinfa",1) < 101 && dir == "enter")
		return notify_fail(HIR"\t��Ĺ�صأ�һ����Ӳ������ڡ�\n"NOR);
	obj = filter_array(inv,(:get_object:));
	if( sizeof(obj) && dir =="enter")
		return notify_fail(HIR"\t��Ĺ�صأ�������������˽��룡\n"NOR);
	return ::valid_leave(me, dir);
}
