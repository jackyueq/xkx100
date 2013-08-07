//Room: jiejianyan.c �⽣��
//Date: Sep 22 1997

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�⽣��");
	set("long",@LONG
���������м���ʢ�����䵱�⽣�ң����½⽣��ˮ�������ˡ�����
��ʿ���˶��Ծ��⽣����ʾ���䵱�ɵ��𾴡�ǧ���������������⡣
LONG);
	set("objects", ([
	   CLASS_D("wudang") +"/shan": 1,
	   "/clone/misc/dache" : 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"slxl2",
		"westup"    : __DIR__"pine_road",
//		"westup"    : __DIR__"slxl3",
	]));
	set("coor/x", -2030);
	set("coor/y", -800);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		 && dir == "westup"
		 && objectp(present("zhang cuishan", environment(me))))
	{
		return notify_fail(HIR"�Ŵ�ɽ��������ɫ�˵ȣ����⽣�Ҷ���⽣��ǧ�������������⣡��\n"NOR);
	}
	return ::valid_leave(me, dir);
}
