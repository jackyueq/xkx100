// Room: /d/kunlun/shanlu03.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long",@long
����һ����ɽ��·��ɽ�䴩�������޽У�·���ƺ��Ѻܾ�û������
�ˣ��Ե���Щ�ƾɣ����Ǵ������ĺۼ���ϡ���Կ�������ĻԻ͡�����
��ɽ�£�����ɽ���������ɵ����ڡ�
long);
	set("exits",([
		"southdown" : __DIR__"shanlu02",
		"northup"   : __DIR__"shanlu04",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40020);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}