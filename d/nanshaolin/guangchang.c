// Room: /d/nanshaolin/guangchang.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void init();
int do_open();
int valid_leave();
string look_gate();

void create()
{
	set("short", "ɽ�Ź㳡");
	set("long", @LONG
��������������ɽ��ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊ
ƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳�����
�㳡��Χ�������ܵ���β���֣��Ľ��ϸ����˼���ʯ�����ּ�����Ϊģ
������ǰ����ǽ���ߣ��������ݣ�����������ɽ�š�
LONG);

	set("exits", ([
		"south" : __DIR__"shifang",
		"north" : __DIR__"shanmen",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
