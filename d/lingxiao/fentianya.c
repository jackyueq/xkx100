// Room: /d/lingxiao/fentianya.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
void create()
{
	set("short", "������");
	set("long", @LONG 
������������ǵ����ա������¡�������ȥ��ֻ����������ϣ���
��һ����խ�ֻ��ı��ݣ�ѩ��Ʈ�䣬���ǻ����ǿ������У�����
һ��ҡҡ��׹�ĸо���
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
		"southdown" : __DIR__"sroad6",
		"up"        : __DIR__"bingti",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}

