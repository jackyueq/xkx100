// Room: /city/hangou2.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�뿪���ݱ��ţ����Ź��ϵ������򱱶��У������ϳ���ת�꾩�Ĵ�
·��������·�͹������ǲ��еģ����Կ�������������鮵�㣬������
��������Ϊˮ½��ͨ�Ĵ󶼻ᣬ�������ǽ���ͬ�ϱ����˺������ӵ�
��Ҫ���������Թ��еĴ�ֻ�ǳ��ĳ��ܡ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"beimen",
		"east"      : __DIR__"hangou1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 110);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}