// Room: /heizhao/chanyuan.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�㲽����ڣ�ֻ������Ϸ�ǰ����һյ�͵ƣ�ӳ���ŷ�����
ׯ�ϡ�һ��Сɳ�������������ϰ�����ף���������������Ĵ���
�����񣬾ٽ�ִ�ߣ����������鶯��
LONG );
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/xiaoshami" : 1,
	]));
	set("exits", ([
		"east"       : __DIR__"dongxiang",
		"west"       : __DIR__"xixiang",
		"southdown"  : __DIR__"shiqiao",
		"north"      : __DIR__"houxiang",
	]));
	set("coor/x", -5020);
	set("coor/y", -1200);
	set("coor/z", 50);
	setup();
	"/clone/board/yideng_b"->foo();
}