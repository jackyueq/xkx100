// Room: /heizhao/xixiang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "���᷿");
	set("long", @LONG
������һ�ƴ�ʦ�ĵ�����ƽ�����������ĵط�����������һЩ
���ţ�ǽ�߿���һЩ���������ϵ���ש���Ѿ��ݳ���ӡ�ˣ���ש��
���ʮ�ֹ⻬��
LONG );
	set("objects", ([
		"/d/shaolin/npc/mu-ren": 6,
	]));
	set("exits", ([
		"east"       : __DIR__"chanyuan",
	]));
	set("coor/x", -5030);
	set("coor/y", -1200);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}