// blackcloth.c ����
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����", ({ "hei pao","pao","blackcloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
		        set("long","����һ��ɱ����ϲ�����ĺ�ɫ����");
				set("value", 0);
                set("armor_prop/armor", 50);
        }
        setup();
}

