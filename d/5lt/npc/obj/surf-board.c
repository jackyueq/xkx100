// surf-board.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("���˰�", ({"surf board", "board"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ӻ����ͳ�һֻ$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ػ��\n");
        }
        init_dagger(50);
        setup();
}

