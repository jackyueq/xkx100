// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ITEM;

void create()
{
       set_name("����", ({"haigu"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "��");
       set("long", "����һ�����ӵĺ��ǡ�\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}

void init()
{
       object ob;
       object me=this_object();
       if( query("init") == 0 ) {
               ob=new("/u/qingyun/mingjiao/obj/parry_book");
               ob->move(me);
               add("init",1);
       }
}
