// qingfengding.c
 
#include <weapon.h>
inherit DAGGER;
 
void create()
{
	set_name("��䶤", ({ "qingfeng ding", "qingfeng", "ding" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������ƵĶ�״������\n");
		set("unit", "��");
		set("value", 0);
		set("damage", 5);	//Here the damage=int_throwing, added by King
	}
	init_dagger(5);
	setup();
}


