// Room: /d/nanshaolin/duanya.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"����ƺ"NOR);
	set("long", @LONG
�����������������Σ��һƬ��������һ���·���죬�����Ǿ���
�޵ء�ֻ����һƬƽ�ء����¿�ȥ�վ��Ѽ���������Ԯ���ұڼ������
̦���们���ͣ�������·���ϡ�
LONG );
	set("exits", ([
		"south"  : __DIR__"xctang",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
