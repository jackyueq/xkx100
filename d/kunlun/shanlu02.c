// Room: /d/kunlun/shanlu02.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long",@long
����һ����ɽ��·��·�߻������أ�·���ƺ��ܾ�û�������ˣ���
����Щ�ƾɣ����Ǵ������ĺۼ���ϡ���Կ�������ĻԻ͡�������ɽ�£�
����ɽ���������ɵ����ڡ�
long);
	set("exits",([
		"southdown" : __DIR__"shanlu01",
		"northup"   : __DIR__"shanlu03",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40010);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}