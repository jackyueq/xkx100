// Room: /lingzhou/xiaolu1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲô�˼���
·�߿��Ų�֪����Ұ�������ߵ�������Ȼ�ߴ�ͦ�Ρ�����͸������
���������ǰ߲߰�����Ӱ�ӡ�
LONG );
	set("exits", ([
		"south"     : __DIR__"dalu",
		"north"     : __DIR__"xiaolu2",
	]));
	set("objects", ([
		"/d/city/obj/shuzhi" : 1,
		"/d/wudang/npc/yetu" : 1,
	]));
	set("outdoors", "lingzhou");
	set("coor/x", -17930);
	set("coor/y", 32100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
