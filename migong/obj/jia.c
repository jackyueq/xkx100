#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"��ϱ���"NOR, ({ "baojia", "jia" , "tiancan baojia" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������˿�Ƴɵı���\n");
		set("material", "cloth");
		set("unit", "��");
        set("value",1000000);
		set("armor_prop/armor", 800);
	}
	setup();
}
