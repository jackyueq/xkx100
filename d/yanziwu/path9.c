// Room: /d/yanziwu/path9.c
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
		"north"  : __DIR__"path10",
		"west"   : __DIR__"path8",
	]));
	set("coor/x", 1240);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}