// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "�ǹ�",
  "ˮ����",
  "������",
  "������",
  "������",
  "������",
  "������",
  "��÷��",
  "������",
  "����",
  "����",
  "������",
  "����",
  "������",
  "������",
  "����",
  "������",
  "С�ڱ�",
  "С�ָ�",
  "С����",
  "��÷",
  "��÷",
  "�ӻ�÷",
  "�һ�÷",
  "�÷",
  "�����ɿ���",
  "�����ɿ���",
  "�����ɿ���",
  "����ɿ���",
  "�Ϲ��ɿ���",
 });

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"candy", "tang guo", "tang", "guo"}));
  set_weight(400);
  set("long","һС��"+name+"��\n");
  set("unit", "С��");
  set("value", 20);
  set("food_remaining", 2);
  set("food_supply", 2);
}
