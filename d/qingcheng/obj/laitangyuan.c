// laitangyuan.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����Բ", ({ "lai tangyuan", "tangyuan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������硢��˿˿������Բ��\n");
                set("unit", "��");
                set("value", 0);
                set("food_remaining", 5);
                set("food_supply", 30);
        }
}
