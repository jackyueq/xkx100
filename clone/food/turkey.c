// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
inherit F_FOOD;

string *names= ({
  "�࿾��",
  "��Ѭ��",
  "�����",
});

string *parts= ({
  "����",
  "��С����",
  "�𼦴�����",
  "�𼦳����",
  "�𼦱�����",
  "�𼦸�����",
  "�𼦾�����",
  "��ƨ����",
  "��ͷ",
  "����",
  "�𼦸�",
  "�𼦳�",
  "���峦",
  "�����߰�����",
  "����ͷ��",
  "���߹�",
  "�𼦾���",
  "�𼦳��",
  "���ȹ�",
});

void create()
{
  string name = "��";
  set_name(name, ({"turkey"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ˶��ĸж��ڻ𼦡�\n");
    set("unit", "ֻ");
    set("value", 950);
    set("food_remaining", 30);
    set("food_supply", 10);
  }
  setup();
}

void init ()
{
  if (query("name")=="��")
  {
    string name;
    name=names[random(sizeof(names))];
    set_name(name, ({"turkey"}));
  }
  set("no_get", "ι�������ô�ҳԻ�������������������ͷ���Ե����ӣ�\n");
  add_action("do_get", "get");
  add_action("do_eat", "eat");
  ::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();
  string part = parts[random(sizeof(parts))];

  me->set("eat_msg", "$N˺��һС��" + part + "���ӵ����г���������\n");
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
    tell_object(who,
     "ι�������ô�ҳԻ�������������������ͷ���Ե����ӣ�\n");
    return 1;
  }
  return 0;
}

