// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "������",
  "������",
  "ϸ��",
  "��˿��",
  "��˿��",
  "ţ��˿��",
  "�ǽ���",
  "±ζ��",
  "�Ź���",
  "��˿��",
  "��������",
  "������",
  "�����",
  "������",
  "������",
  "������",
  "�ϼ�������",
});

void create()
{
  set_name("��ʽ����", ({"mian tiao", "miantiao", "mian"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���������ڵ�������\n");
    set("unit", "��");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}

void init()
{
  if (query("name")=="��ʽ����")
    set_name(names[random(sizeof(names))], ({"mian tiao","miantiao","mian"}));
  ::init();
}
