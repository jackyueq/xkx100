// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xueli.c ѩ��

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ݮ", ({"cao mei", "strawberry","caomei"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "�ʺ�Ĳ�ݮ��\n");
                set("unit", "��");
     set("value", 120);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
