// Room: /d/changcheng/fenghuotai1_2.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���̨");
	set("long", WHT @LONG
�����Ƿ��̨�Ķ�¥��վ����������Կ��ĺ�Զ�����ߵĽ�ʿ�Ǿ�
�ǳ��������������ֹ��ū�Ľ����������߽��İ�ȫ������������
����ԼԼ���Կ��������������ľ�ӹ�ء�
LONG
NOR );
	set("outdoors", "changcheng");
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("exits", ([
		"down" :__DIR__"fenghuotai1-1",
	]));
	set("coor/x", -6000);
	set("coor/y", 7000);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}