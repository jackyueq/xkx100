// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// chicken.c
 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({ "chicken" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ������Ŀ�����\n");
                set("unit", "ֻ");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

