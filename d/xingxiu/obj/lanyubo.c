// lanyubo.c
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIB"����"NOR,({ "lanyu bo", "bo" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ���������ƶ��ɵ�ҩ������Ȼʹ���վ�, ��˿��û���ƺۡ�ҩ���������΢���綾, Ȼ���㹻����͵��֮�ˡ�\n");
		set("value", 20000);
	}
	setup();
}
