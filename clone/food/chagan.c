// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("������", ({"cha gan", "gan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�������ɡ�\n");
    set("unit", "��");
    set("value", 120);
    set("food_remaining", 6);
    set("food_supply", 25);
  }
}
