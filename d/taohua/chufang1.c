// Room: /d/taohua/chufang1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ��һ��������������õĳ�������Ӧ������ÿ�յķ�ʳ������
�������˺͵��ϵ�ζ����������ʦ����æµ�š�ż������Щ�Բ����
��ʳ������ʱʣ�µ������������
LONG
	);

	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	
	set("objects",([
		__DIR__"obj/meat" : 2,
		__DIR__"obj/baozi" : 1,
		__DIR__"obj/rice" : 1,
	]));
	
	set("coor/x", 8970);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}