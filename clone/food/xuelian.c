// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// xuelian.c ѩ��
#include <ansi.h>
inherit ITEM;

void init();
void eat();

void create()
{
   set_name(HIW "ѩ��" NOR,({"xue lian", "xuelian", "lian"}));
   set_weight(20);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "һ��ѩ������ֻ�����ھ��弫��֮����\n");
     set("unit", "��");
     set("value", 300);
       }
   
   setup();
}

void init()
{
   add_action("do_chi", "eat");
}


int do_chi(string arg)
{   
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");

   if(!arg) return notify_fail("��Ҫ��ʲô��\n");

   if ( (int)this_player()->query("max_atman")>0)
   {
         message_vision(RED "$N����һ��ѩ����������һ��θ���־������˳�����\n" NOR, this_player());
   } 
   else 
   { 
      if(this_player()->query("gender")=="����")
     message_vision(GRN "$N����һ��ѩ������������������ˡ�\n" NOR, this_player());
      else
     message_vision(GRN " $N����һ��ѩ�������������죬�������ޡ�\n" NOR, this_player());
   }   
   destruct(this_object());
   return 1;
}
