// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"gua zi", "guazi", "zi", "seed"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ������Ĺ��ӡ�\n");
    set("eat_msg", "$Nץ��һ�Ź���������һ�ӣ�ž��һ�����졣\n");
    set("unit", "��");
    set("value", 130);
    set("food_remaining", 25);
    set("food_supply", 1);
  }
}

