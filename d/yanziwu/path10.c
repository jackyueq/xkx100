// Room: /d/yanziwu/path10.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
һ������С������������ǰ����ֻ��С�����࣬��ľ���裬������
�ʮ���徻��ǰ�濴����ͤԺ���󲻼�¥��Ψ�����������ڵ͵�
������
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"path9",
		"north"  : __DIR__"bridge1",
	]));
	set("coor/x", 1240);
	set("coor/y", -1240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}