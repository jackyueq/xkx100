// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({"huasheng", "dou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����������\n");
                set("unit", "��");
                set("value", 20);
                set("food_remaining", 4);
                set("food_supply", 10);
        }
}

