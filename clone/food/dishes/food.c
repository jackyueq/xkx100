// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
inherit F_FOOD;

string *food_name= ({"������˿",
                "��������",
     "÷�˿���",
     "��������",
     "������˿",
     "���ͼ�Ƭ",
     "�峴Ϻ��",
     "�廨����",
     "��˿Ѭ��",
     "�Ǵ��Ź�",
     "������˿",
     "������Ϻ",
     "��Ƥ��Ѽ",
     "�����ض�",
     "��������",
     "������˿",
     "���ͷ�Ƭ",
     "�������",
     "���ʹ೦",
     "��������",
     "���㶬��",
     "��䶹��",
     "���Ŷ���",
     "���ʸ���",
});

void create()
{   string name = "������";
     set_name(name, ({"food"}));
     set_weight(1000);
     if (clonep())
         set_default_object(__FILE__);
     else {
         set("long", "һ�����˴��ѵĻ����ˡ�\n");
         set("unit", "��");
     set("eat_msg", "$N����������Щ" + name + "���ŵ����г���������\n");
         set("value", 250);
         set("food_remaining", 5);
         set("food_supply", 20);
     }
}

void init ()
{
   if (query("name")=="������")
   {
     string name;
     name=food_name[random(sizeof(food_name))];
       set_name(name, ({"food"}));
     set("long", "һ�����˴��ѵ�"+name+"��\n");
     set("eat_msg", "$N����������Щ" + name + "���ŵ����г���������\n");
   }
        if(!wizardp(this_player())) {
           set("no_get", "�ڻ�������ô���ƺ�����ðɣ�\n");
        }
        add_action("do_get", "get");
        add_action("do_eat", "eat");
   ::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();

  return ::do_eat(arg);
}

int do_get (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg)
    return 0;

  if (present(arg,environment(who))==me)
  {
    tell_object(who,"�ڻ�������ô���ƺ�����ðɣ�\n");
    return 1;
  }
  return 0;
}

