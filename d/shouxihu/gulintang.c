// Room: /yangzhou/gulintang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short","������");
	set("long",@LONG
�ն�����֪���ݣ�Ϊ�����ʦŷ���޶��������á�ȡ��ʫ�䡰���
���񻣬���ֺϷ��衱�С����֡�����Ϊ�������������á��ң�Ϊ����
���顣
�ꡣ
LONG );
	set("exits", ([
		"east"  : __DIR__"daxiongbaodian",
		"south" : __DIR__"pingshantang",
		"north" : __DIR__"ouyangci",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}