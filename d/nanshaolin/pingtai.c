// Room: /d/nanshaolin/pingtai.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ƽ̨");
	set("long", @LONG
�����Ǵ��۱���ǰ��һ��ƽ̨������ȫ�µ����ĵ㣬���е��ش��
�����ڴ˾��С������ǽ������������������
LONG );
	set("exits", ([
		"north"     : __DIR__"daxiong",
		"east"      : __DIR__"jnlwang",
		"west"      : __DIR__"liuzu",
		"southdown" : __DIR__"dxshijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/daku" : 1,
	]));
	set("valid_startroom",1);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	"/clone/board/nshaolin_b"->foo();
}

