// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xbc.c С�ײ�

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("С�ײ�", ({"xbc", "xiaobaicai"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "һ�����ʿ��˵�С�ײˡ�\n");
                set("unit", "��");
     set("value", 80);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
