// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ͺ�«", ({"you hulu", "youhulu", "hulu", "hu"}));
  set_weight(700);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��װ�����͵ĺ�«��\n");
    set("unit", "��");
    set("value", 100);
    set("max_liquid", 20);
    set("liquid", ([
      "type" : "oil",
      "name" : "����",
      "remaining" : 12,
   ]));
  }
}

void init ()
{
  add_action ("do_drink", "drink");
  ::init();
}

int do_drink (string arg)
{
  object who = this_player();
  object me = this_object();

  if (me == present(arg,who) &&
      me->query("liquid/name")=="����")
  {
    message_vision ("$N����$n������͹ࡣ\n",who,me);
    call_out ("reacting",1,who,me);
    return 1;
  }
  return ::do_drink(arg);
}

void reacting (object who, object me)
{
  if (who)
    message_vision ("$Nһ����ģ�����³�����\n",who,me);
}
