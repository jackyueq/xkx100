// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 4/9/1997
// roubing.c

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�����", ({"roubing", "yang", "bing"}));
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�鿾�ú�������������\n");
    set("unit", "��");
    set("value", 60);
    set("food_remaining", 3);
    set("food_supply", 120);
  }
}


