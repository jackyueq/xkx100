//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"��ʫѡ��"NOR, ({"tangshi book","book","tangshi"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ֽҳ���ƵĹ��飬���滹���ż�����Ь���廨��ֽ����\n");
                set("unit", "��");
                set("material", "paper");
        }
        setup();
}

