// Room: /d/yanziwu/path8.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
�ƽ�¥����һ������С����С�����࣬��ľ���ʮ���徻��С
�����������������죬ǰ�濴����ͤԺ���󲻼�¥��Ψ����������
�͵�������
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"yunjin1",
		"east"   : __DIR__"path9",
	]));
	set("coor/x", 1230);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}