// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("��", ({"fan", "rice"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����׷���\n");
    set("unit", "��");
    set("value", 90);
    set("food_remaining", 10);
    set("food_supply", 25);
  }
}
