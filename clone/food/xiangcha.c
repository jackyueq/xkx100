// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

//xiangcha.c
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ľ����", ({"cha zhong", "chazhong", "cha", "teapot", "tea"}));
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һֻ�ľ���ѡ�\n");
    set("unit", "ֻ");
    set("max_liquid", 2);
}
  
  set("liquid", ([
       "type": "water",
       "name": "����ɽ���",
       "remaining": 2,
       ]) );
  setup();
}

