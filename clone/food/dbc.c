// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dbc.c ��ײ�

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ײ�", ({"dbc", "dabaicai"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "һ�����ʿ��˵Ĵ�ײˡ�\n");
                set("unit", "��");
     set("value", 80);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
