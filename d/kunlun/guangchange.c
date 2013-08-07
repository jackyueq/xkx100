// Room: /d/kunlun/guangchange.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�㳡��");
	set("long",@long
������һ��ƽƽ�����Ĵ�㳡���㳡���������ɵĵ�����ϰ�䣬��
������Ȼ�ǹ㳡�������ȥ���������ˣ���������ɽ��·��
long);
	set("exits",([
		"southwest" : __DIR__"shanlu04",
		"west"      : __DIR__"guangchang",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/yulingzi" :  1,
		__DIR__"npc/kl-dizi3" :  2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40040);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}