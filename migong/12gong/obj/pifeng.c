#include <ansi.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit SURCOAT;

void create()
{
  set_name(HIM"ʥ������"NOR, ({"shengyu pifeng", "pifeng", "cloth" }));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ�������֮��������͵����硣\n");
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
    set("material", "crimsonsteel");
    set("unit", "��");
    set("value", 1000);
    set("armor_prop/armor", 100);
    set("armor_prop/dodge", 50);
    set("armor_prop/spells", 30);
  }
  setup();
}


