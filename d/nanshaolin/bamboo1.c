// Room: /d/nanshaolin/bamboo1.c
// Last Modified by winder on May. 29 2001
// ����Ҳ��ȥ��Ħ���ĵط���������Ҳ��Ҫ��

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ��
����΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ��ѵ�������
�ڡ�
LONG );

	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __FILE__,
/*
		"northeast" : __DIR__"bamboo"+(random(13)+1),
		"southwest" : __DIR__"bamboo2",
		"northwest" : __DIR__"bamboo"+(random(13)+1),
		"southeast" : __DIR__"bamboo"+(random(13)+1),
		"south" : __DIR__"shanroad6",
*/
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6020);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

