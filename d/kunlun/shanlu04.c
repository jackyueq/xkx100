// Room: /d/kunlun/shanlu04.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long",@long
�߹���ɽ·������һ�κ�ƽ����ʯ��ɽ·��ǰ�洫��������������
�����쵽�ˣ��㲻�ɵüӿ��˽Ų���ԶԶ��ȥ���ƺ��Ǹ���㳡��Χ��
�����������䡣
long);
	set("exits",([
		"southdown" : __DIR__"shanlu03",
		"north"     : __DIR__"guangchang",
		"northwest" : __DIR__"guangchangw",
		"northeast" : __DIR__"guangchange",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40030);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}