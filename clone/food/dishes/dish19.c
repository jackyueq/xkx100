// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "���ʸ���";
  set_name(name, ({"sanxian fuzhu", "fuzhu", "zhu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����˴��ѵ�"+name+"��\n");
    set("unit", "��");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
