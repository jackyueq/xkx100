// Room: /d/kunlun/guangchang.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��㳡");
	set("long",@long
������һ��ƽƽ�����Ĵ�㳡���㳡���������ɵĵ�����ϰ�䣬ǰ
�治Զ���Ǹ��޴��ʯ���磬������������ɵ�ǰ���ˣ�����Ͷ�����
Ȼ�ǹ㳡��
long);
	set("exits",([
		"south" : __DIR__"shanlu04",
		"north" : __DIR__"pingfeng",
		"west"  : __DIR__"guangchangw",
		"east"  : __DIR__"guangchange",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/gaozecheng" :  1,
		__DIR__"npc/kl-dizi2" :  2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40040);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}