// Room: /d/chengdu/wangjianglou1.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long",@LONG
�����������������¥�ˣ�¥���ǳɶ��ĸ��Ϻӡ����治���԰�
����һƬ���֣������пھ�����Ѧ�ξ�����һ����Ů����֮�ء�¥����
Ұ��������Զ�����ٳǡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"up"    : __DIR__"wangjianglou2",
		"east"  : __DIR__"wanliqiao",
		"north" : __DIR__"funanhe3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


