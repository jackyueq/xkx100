// Room: /huanghe/weifen.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "μ������");
	set("long", @LONG
�ںӺ�μ�ӻ���ƺӣ���������ˮ�ƣ�Ҳ�����˸������ɳ������
�Ӷ��ǽ����������¡�
LONG );
	set("exits", ([
		"south" : __DIR__"huanghe1",
		"north" : __DIR__"huanghe_1",
		"southwest" : __DIR__"road5",
		"northeast" : __DIR__"dukou2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -1000);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}