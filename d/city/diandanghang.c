// Room: /city/diandanghang.c
// Last Modified by Winder on Nov. 5 2000

#include <ansi.h>;
inherit ROOM;

int do_quit();
void create()
{
	set("short", "�䵱��");
	set("long", @LONG
����һ�ҿ̱������ĵ䵱�С�һ�������о���һ����ī���ã�����
��������������£�����˴����˿Ͷ���Ϊ֮�ᡣ�߸ߵĹ�̨���濪��
һ��С���ڣ�������Ʒ���ͺ͵�������֮�á�̧������ȥ����̨�ϰ���
һ������ (paizi)����̨����ȴ��һ������ˬˬ��Ů���������ʱȫ��
ѪҺ�ϳ壺������������������ֵ��ֻҪ�����࿴��һ�ۡ���
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "
pawn        �� 
redeem      ��
value       ����

����������ī��δ�ɵĲ�����    "HIR"ͣ��\n"NOR,
	]));
	set("objects", ([
//		__DIR__"npc/ake" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"caohebeijie",
	]));

	set("coor/x", -10);
	set("coor/y", 31);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
