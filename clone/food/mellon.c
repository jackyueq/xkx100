// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���ܹ�", ({"hami gua", "mellon","gua"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "��������Ĺ��ܹϡ��\n");
                set("unit", "��");
     set("value", 100);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
