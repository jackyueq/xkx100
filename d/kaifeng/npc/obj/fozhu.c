#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(MAG "��̴��" NOR,({"fo chuan"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("material", "wood");
                set("unit", "��");
		set("armor_prop/armor",10);
        }
        setup();
}
