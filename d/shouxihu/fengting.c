// Room: /yangzhou/fengting.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
��ͤ�ߴ��۶���Ϊ�����Ľ�ͤ��������ʯ�������߶�����ʯ��ƺ��
�����ﴵĵ�������ܻ����񳯷�ͼ�����ܼ�������̫����Ԫ���⡰��
ͤ���ң�����������ï����׫���(lian)����ɽ���뼹�������а����
����ʮ�ꡣ���ϴ�ͤ���������ܣ�������ԣ����Һ�ɽ�����۵ס�
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"westdown"   : __DIR__"pingtai1",
		"southdown"  : __DIR__"yueguan",
	]));
	set("item_desc", ([
		"lian" : HIY"
        ��        ͤ
        ��        ̨
        ��        ��
        ��        ��

        ��        ��
        ��        ��
        ��        ��
        ��        ˮ
        ��        ȫ
        ��        ��
\n"NOR,
	]));
	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 120);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}