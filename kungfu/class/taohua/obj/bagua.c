// /kungfu/class/taohua/bagua.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"������"NOR, ({ "tie bagua", "bagua" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�������Ǵ����������������أ����а���ͼ����\n���һ�����������ռ��������(location)������λ�ĵ��ߡ�\n");
		set("unit", "ö");
		set("value", 1600);
	}
	setup();
}
