// Room: /d/yanziwu/weichang.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��Χ��");
	set("long", @LONG
������Ľ������Χ��֮����Χ�����󣬵������ï��С�޺ܶࡣ��
��������������ȥ�ĺ�������ʱ�ǰ����Ȥ�������������ǵļ�ͷ��
�����
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"south" : __DIR__"xuanshuan",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
		"/d/hangzhou/npc/maque" : 1,
	]));
	set("coor/x", 830);
	set("coor/y", -1240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

