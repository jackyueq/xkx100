#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@LONG
�ⶴ�������ģ���֪������ס��ʲô������ʿ��������ʲ
ôɽ��ľ�֡��ǲ������������أ��������ò������⡣
LONG
	);
	set("exits",([
		"north":__DIR__"maigu",
		"out":__DIR__"dongkou",
	]));
	set("coor/x", -400);
	set("coor/y", -440);
	set("coor/z", 0);
	setup();
}
	