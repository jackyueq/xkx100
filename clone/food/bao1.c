// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�����ڰ���", ({"zhurou bao", "bao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������硢�����ڵ������ڹ������ӡ�\n");
                set("unit", "��");
                set("value", 25);
                set("food_remaining", 2);
                set("food_supply", 40);
        }
}

