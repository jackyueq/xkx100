// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ITEM;

void create()
{
        set_name("��Ƭ", ({ "piece" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        				set("long", "һ�Ѳ�֪��ʲô��������Ƭ��\n");
        }
        setup();
}

