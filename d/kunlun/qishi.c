// Room: /d/kunlun/qishi.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short", "����");
	set("long", @LONG
������ʥ�ԡ��١������塱�����������ƣ�������ÿ�����ص�����
�ű��޵Ĺ��Ρ��˴��������ɵ����ң������ص���ĥ������ʹ�á�
LONG );
	set("exits",([
		"west" : __DIR__"jiashan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119970);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}