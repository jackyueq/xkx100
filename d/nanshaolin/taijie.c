// Room: /d/nanshaolin/taijie.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "̨��");
	set("long", @LONG
������һ�����ϵ�̨�ף�ȫ������������ʯ������ɣ�̨�������
�����ϵ���ŷ��ϵ����Ծ��䡣����һ����Ҳû�У��Եúܼž�����
�����е�ɮ��Ҳ��������������
LONG );
	set("exits", ([
		"northup" : __DIR__"lxting",
		"south"   : __DIR__"houdian",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

