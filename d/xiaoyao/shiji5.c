// shiji5.c
// Modified by Winder June.25 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ж����ż���ˮ����Ȼ���������ǰ�沢�й���͸�롣�ߵ�ʯ��
�ľ�ͷ��ǰ���Ǹ���������Ķ�Ѩ��̽ͷ����һ������ȥ�����ŭ����
ӿ��ˮ���ļ�������һ���󽭡�����ɽʯ���������Ρ�룬�������ƣ�
���ǵ������׽��ϡ�
LONG );
	set("exits", ([
		"westdown" : __DIR__"shiji4",
		"out"      : "/d/wanjiegu/riverside1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -21010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
