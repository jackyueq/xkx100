// sheerkou.c �߶���
#include <ansi.h>
inherit ITEM;

#define max_poison 24
#define least_poison 8

void init()
{
}

void create()
{
	set_name(HIM"�߶���"NOR, ({ "sheer kou", "sk" }) );
	set_weight(600);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("value", 0);
		set("material", "steel");
		set("long", "���Ǵ�˵�й��϶����صİ���--�߶��ڡ�\n");
	}
	setup();
}
