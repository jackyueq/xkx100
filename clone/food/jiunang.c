// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 4/9/1997
// jiunang.c ��Ƥ�����

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("��Ƥ�����", ({"jiunang", "wineskin", "skin"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ������װ���̾ƵĴ���ң����װ��ʮ�����ľơ�\n");
     set("unit", "��");
     set("value", 100);
     set("max_liquid", 20);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "���̾�",
        "remaining": 20,
        "drunk_supply": 8,
      ]));
}


