// Room: /yangzhou/shuiyun.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","ˮ��ʤ��");
	set("long",@LONG
ˮ��ʤ��λ�ڳ��������������Ŷ�����Ϊ������߱�����Ϊ��԰��
���벿�֡�������麣��м�����������д�ġ�ˮ��ʤ�š��ң���������
��ס��Ÿ�ʫ�伯��(lian)��������ľ��������
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        ��        Ұ
        ��        ��
        ��        ��
        ��        ��
        ˮ        ��
\n"NOR,
	]));

	set("exits", ([
		"east"      : __DIR__"changchunqiao",
		"south"     : __DIR__"lianhuaqiao",
		"southwest" : __DIR__"baitaqingyun",
		"southdown" : __DIR__"pingtai3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}