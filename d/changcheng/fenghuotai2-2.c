// Room: /d/changcheng/fenghuotai2-2.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���̨");
	set("long", WHT @LONG
�����Ƿ��̨�Ķ�¥��վ����������Կ��ĺ�Զ�����ߵĽ�ʿ�Ǿ�
�ǳ��������������ֹ��ū�Ľ����������߽��İ�ȫ��
LONG
NOR  );
	set("outdoors", "changcheng");
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("exits", ([
		"down" :__DIR__"fenghuotai2-1",
	]));
	set("coor/x", -10010);
	set("coor/y", 8000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}