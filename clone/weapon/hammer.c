// hammer.c
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name( "����",({ "fa lun" ,"lun" ,"falun" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�����֣�ɮ���������������¡�\n");
		set("material", "wood");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg","$N�����е�$n�Ż����䡣\n");
	}
        init_hammer(5);
	setup();
}

/*#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "hammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ص�������������൱��ʵ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(25);
        setup();
}
*/