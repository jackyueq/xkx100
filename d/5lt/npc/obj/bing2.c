// bing2.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("�춹��", ({ "hongdou bing2","bing2"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ճ�¯���������ڵĺ춹����\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
	setup();
}
