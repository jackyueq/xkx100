// Room: /d/kunlun/yaofang.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
�����������ɵ�ҩ����������������ŨŨ��ҩ�㣬������������װ
������ҩ�ĵĴ�ҩ��ÿ��ҩ�����ϰٸ�װҩ�ĳ��������˸���ҩ����
������һ���޴��ɼľ�񣬹������ŷ���ӡ�ķ�����һλ����Ů������
��æµ��ָ����ִ�۳���ҩƷ����ҩ������
LONG );
	set("exits", ([
		"southeast" : __DIR__"jiuqulang6", 
	]));
	set("objects", ([
		__DIR__"npc/kl-dizi1" : 1, 
	]));
	set("no_clean_up", 0);
	set("coor/x", -120010);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}