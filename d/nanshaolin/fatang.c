// Room: /d/nanshaolin/fatang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", BLU"����"NOR);
	set("long", @LONG
����һ������ĵ��ã�����ͬʱ���ɼ����˶��������⡣��������
����˵�𾭣��𷨺���伯��ĳ�������������ķ���һ���ŵ����ţ�
�Թ������ߴ���֮�á�
LONG );
	set("exits", ([
		"east"      : __DIR__"huilang5",
		"west"      : __DIR__"huilang1",
		"north"     : __DIR__"kchang",
		"southwest" : __DIR__"jietan3",
		"southeast" : __DIR__"jietan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

