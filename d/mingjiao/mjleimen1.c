// Room: /d/mingjiao/mjleimen1.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����ſ�");
	set("long", @LONG
ǰ��������̵ġ������š��ˣ�������������������������ĵط���
������״������������ǵ�����ϰ���Լ�ʹ����ƷҲ���������졣
LONG );
	set("exits", ([
		"enter" : __DIR__"sushe",
		"northeast" : __DIR__"mjleimen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -51110);
	set("coor/y", 490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}