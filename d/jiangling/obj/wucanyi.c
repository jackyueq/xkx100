// wuchangyi.c
//
#include <armor.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name("�ڲ���", ({ "wucan yi", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "silk");
                set("value", 50000);
                set("armor_prop/armor", 200);
                set("long",
"��һ����ǹ����ı��£����ô�ѩɽ�����ڲϲ�˿֯�ɵġ���
���ڲ���ֻ���������ӣ�����Ҳ�����ã�ֻ��ǰһ�顢��һ��
�Ŀ���һ��");
        }
        setup();
}

