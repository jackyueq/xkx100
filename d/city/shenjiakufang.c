// Last Modified by Sir 9/15/2001
#include <ansi.h>
inherit ROOM;
int do_yuntang(string arg);

void create ()
{
  set ("short", "��ҿⷿ");
  set ("long", @LONG
���߹�һ����խ��С��֮������һ��ֿ��С���������Ķ�����δ��
���̵Ĳ�ƥ��һЩ���¡���ǽ�ڷ��ż��Ŵ����ӣ������Ϸ��ż�ƥ��ʪ��
���Ϻ�һ������һ���Ѿ��յ÷��̵��ٶ�����������������(yuntang)��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baiyipu",
]));

  setup();
}
void init()
{
        add_action("do_yuntang","yuntang");
}

int do_yuntang(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("gongzuo/yunbu"))
           return notify_fail("������û���ٲ��Ĺ�����\n");

        if(me->is_busy())
             return notify_fail("����æ���ٲ��أ�\n");
             
        if ( (int)me->query("jing")<10)
           return notify_fail("��̫���ˣ���Ϣһ�°ɡ�\n");
           
        if ( (int)me->query("qi")<10)
           return notify_fail("��̫���ˣ���Ϣһ�°ɡ�\n");   

        if (me->query_temp("gongzuo/yunbu")==6)
           return notify_fail("�����Ѿ��ٺ��ˣ�����ٺõĲ�����ȥ�ɣ�\n");
   
  message_vision("$N�����ٶ��������ڲ����������ƶ���ֻ������������ð����ɫ��������\n",me);
        
        if (random(10)>7)
        {
  message_vision(RED"$N����������֮���𽥿�ʼ�������ģ�ֻ���á��ꡱ��һ��$N���ֱ��ٶ�����һ�¡�\n"NOR,me);     
       me->receive_damage("qi", 10);
         }   
      me->start_busy(2);            
      me->add("jing",-(2+random(5)));
      me->add("qi",-(5+random(5)));
      me->add_temp("gongzuo/yunbu",1);      
  if ( (int)me->query_temp("gongzuo/yunbu")==6)
 {
  message_vision(CYN"��ƥ����������ƽ����$N����ƥ���ú����һ�ߡ�\n"NOR,me);
      me->set_temp("gongzuo/yunbuok",1);
      ob=new("/d/city/obj/bu.c");
      ob->move(me);      
 }
                 
  return 1;
} 
