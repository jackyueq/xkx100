// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xianyao.c        

inherit ITEM;
inherit F_FOOD;

void create()
{
  string *names = ({
    "����",
    "����",
    "����",
    "�ɴ�",
    });
  string *ids = ({
    "long gan",
    "feng sui",
    "xiong zhang",
    "xing chun",
    });
  int i = random(4);

  set_name(names[i],({ids[i]}));
  set_weight(300);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "����");
    set("value", 10000);
    set("food_remaining", 20);
    set("food_supply", 100);
    set("no_get",1);
    set("no_drop",1);
    set("no_sell",1);
  }
  set("long", "һ�������ϲ��е��������ʣ���"+names[i]+"��\n");
}

