// Room: /yangzhou/pingtai3.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��ʯƽ̨");
	set("long", @LONG
ˮ��ʤ��ǰ��ʯƽ̨��Χ��ʯ�����������ˣ���ʯ��ͨ������ƽ̨
���ڴ������������ں���һʮ������ƽ̨�������Գ��С�ˮ��ʤ�š���
����Ҳ����ΪϷ���¶̨��
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northup" : __DIR__"shuiyun",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 100);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}