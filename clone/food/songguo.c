// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// songguo.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ɹ�", ({"songguo"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɫ���ɹ���\n");
                set("unit", "��");
                set("food_remaining", 1);
                set("food_supply", 60);
        }
}

