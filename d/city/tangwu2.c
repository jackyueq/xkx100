// Room: /d/city/tangwu2.c
// Last Modified by winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
��ǽ����һ�ſ��ӻ����������һ�����㡣������ǽ����һ��ܣ�
ϡϡ�������ż����顣�м���ż���ľ���͵��ӣ�ȴû��һ��ѧͯ����
�ֻ��һ���������ڱ��������ñ����ڶ��Զ��ţ����ϰ���һ�ѽ��
(chi)��
LONG
	);
	set("exits",([ /* sizeof() ==  */
		"south" : __DIR__"zizheng",
	]));
	set("objects", ([ /* sizeof() == */
		__DIR__"npc/wuguxian" : 1,
	]));
	set("item_desc" , ([ /* sizeof() == */
		"chi" : "����������˻ҳ����������δ���ˡ�\n",
	]));
	set("coor/x", -30);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
