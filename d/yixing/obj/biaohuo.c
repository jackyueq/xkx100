// /d/yixing/obj/biaohuo.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"����"NOR, ({"hong biao", "biao"}));
	set("weight", 20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ݺ��ڣ���װ�ǳ���ϸ����֪װ��ʲô������\n");
		set("unit", "��");
		set("value", 30);
	}
	setup();
}
