// Room: /yangzhou/pingtai1.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ƽ̨");
	set("long", @LONG
�ɷ�ͤ������ɽ��ʯ���ж���һƽ̨��ƽ̨ʯ��Ϊ�����������
��Զ����ͤ�š�����������̨���ѡ���ƽ̨����ɽ��ʯ���������
���
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"westdown" : __DIR__"guanyindian",
		"eastup"   : __DIR__"fengting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 120);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}