// Room: /yangzhou/lianxingsi.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����¾����������¡���ʼ�������ƣ��ؽ���Ԫ����Ԫ��䡣����
����Ѳʱ�����������¡���ɽ�����򶫱�����麣���������Ϊ�����
������裬ǰ�����գ�����Τ�ӣ������������������μ�Ϊ¥��������
���跽�������ð��š�ɽ��������������ǽ��
LONG );
	set("exits", ([
		"northeast" : __DIR__"pingtai4",
		"northwest" : __DIR__"shuixie",
		"southeast" : __DIR__"ouxiangqiao",
		"north"     : __DIR__"yunshange",
		"south"     : __DIR__"baitataji",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}