// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xueli.c ѩ��

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ѩ��", ({"xue li", "xueli","li"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "����ѩ��ֻ������ѩɽ����֮�ء�\n");
                set("unit", "��");
     set("value", 80);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
