// Room: /d/kunlun/zhengyuanqiao.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Զ��");
	set("long",@long
�����źųơ����»ƺӵ�һ�š������Ƽ�Ϊ��ΰ���������򣬶���
��ԭ���ƺ�ˮ���ŵ���к��������¡���졣
long);
	set("exits",([
		"west"      : __DIR__"shanlu",
		"southeast" : "/d/mingjiao/shanjiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" :  1,
		"/d/city/npc/bing" :     3,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -60000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}