// by happ@YSZZ

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
#include "chk_owner.c"

void create()
{
   set_name(HIY"�ƽ�ʥ��"NOR, ({ "huangjin shengyi" }) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
      set("no_sell",1);
       set("value",0);
     set("material", "steel");
     set("armor_prop/armor",1200);
  }
   setup();
}
int query_autoload() { return 1; }
