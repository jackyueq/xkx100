// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// beans.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"beans", "doudou"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "һ�ѿɰ���С������\n");
                set("unit", "��");
     set("value", 80);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
