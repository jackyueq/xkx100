#include <ansi.h> 
#include <armor.h>
 
inherit SHIELD;
 
void create()
{
	set_name(HIR"��Ƥ��"NOR, ({ "hupi shield", "shield", "dun" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	
else {
		set("material", "leather");
		set("unit", "��");
		set("long", "����һ���û�Ƥ���ƶ��ɵĶܡ�\n");    set("value", 1000000);
		set("armor_prop/armor", 80);
		}
	setup();
}