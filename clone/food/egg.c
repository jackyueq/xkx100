// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 4/9/1997
// egg.c

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ˮ��", ({"egg", "dan"}));
  set_weight(60);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һֻ����ļ�����\n");
    set("unit", "ֻ");
    set("value", 50);
    set("food_remaining", 1);
    set("food_supply", 60);
  }
}


