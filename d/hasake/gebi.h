#include <ansi.h>

int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/steps",1);
       if (dir == "south") me->add_temp("mark/steps",-1); 
       if (dir == "east") me->add_temp("mark/step", 1); 
       if (dir == "west") me->add_temp("mark/step", -1); 
        
       if(me->query_temp("mark/steps") <= -10 &&
          me->query_temp("mark/step") <= -10){
            me->move("/d/baituo/gebi");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("ͻȻ����ǰ������һ��Сɽ����״�����շ塣\n");
            }       
           
       if(me->query_temp("mark/steps") == -12 ){
            me->move(__DIR__"senlin");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("ͻȻ���߳��˴��ڣ�����һɭ�ִ���\n");
            }       
           
       if(me->query_temp("mark/step") == 11){
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            me->move(__DIR__"gebi5");
            return notify_fail("");
            }  
       if(me->query_temp("mark/steps") == 11 && 
          me->query_temp("mark/step") <-10 ){
            me->move(__DIR__"room-ji");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("���������ˣ��������߳������ˣ�\n");
            }  

       if((me->query_temp("mark/steps") == 7 && me->query_temp("gc_n")) ||
          (me->query_temp("mark/steps") == -7 && me->query_temp("gc_s")) ||
          (me->query_temp("mark/step") == -7 && me->query_temp("gc_w")) ||
          (me->query_temp("mark/step") ==  7 && me->query_temp("gc_e"))){
            me->move(__DIR__"lvzhou");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            me->delete_temp("gc_n");
            me->delete_temp("gc_s");
            me->delete_temp("gc_w");
            me->delete_temp("gc_e");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("������ã����ҵ���һ��ɳĮ���ޣ�\n");
            }
 
       if((me->query_temp("mark/steps") == 7 && ( me->query_temp("mark/step") == 3 || 
           me->query_temp("mark/step") == -3 ) && me->query_temp("gc1_n")) ||
          (me->query_temp("mark/steps") == -7 && ( me->query_temp("mark/step") == 3 || 
           me->query_temp("mark/step") == -3 ) && me->query_temp("gc1_s")) ||
          (me->query_temp("mark/step") == 7 && ( me->query_temp("mark/steps") == 3 || 
           me->query_temp("mark/steps") == -3 ) && me->query_temp("gc1_e")) ||
          (me->query_temp("mark/step") == -7 && ( me->query_temp("mark/steps") == 3 || 
           me->query_temp("mark/steps") == -3 ) && me->query_temp("gc1_w"))){
            me->move(__DIR__"shulin");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
            me->delete_temp("gc1_n");
            me->delete_temp("gc1_s");
            me->delete_temp("gc1_w");
            me->delete_temp("gc1_e");
            tell_room(environment(me), me->name()+"����ƣ�����������ӴӸ��ɳĮ���˹�����\n",  ({ me }));  
            return notify_fail("�ף��㷢�������Ѿ����Ǹ��ɳĮ�ˣ�\n");
            }       
        return ::valid_leave(me, dir);
}

void init()
{
       object me, *ob, *inv, ob1;
       string msg, msg1;
       int i, j;
       me = this_player();
       ob = all_inventory(environment(me));
       msg = YEL"\nͻȻһ�ɼ���ε�������һ��Ƭ��ɳ��ֻ���������������Ƕ���ɳ�������ޱ��޼ʵĴ�ɳĮ֮�У�
���������̵صĴ��ɳ�£���������е�һҶС��һ�㣬ֻ������������ȫ�ް������֮����\n"NOR;
       msg1 = HIR"������Լ��Ѿ���ƣ�����ˣ����ϵĻ�ɳȴԽ��Խ�񡭡�\n"NOR;

       if(ob1 = present("bai shoujuan", me)){
          write(WHT"�����հ��־��ϵ���ʾ���ܿ���߳��˴��ڡ�\n"NOR);
          me->move(__DIR__"caoyuan",1);
          destruct(ob1);
          me->delete_temp("mark/steps");
          me->delete_temp("mark/step");
          tell_room(environment(me), me->name()+"��������شӸ��ɳĮ���˹�����\n",  ({ me }));  
          write("ͻȻ��һ�����񣬰��־�紵���ˣ�\n");
          return;
          }  
       if(userp(me)){ 
         if(me->query_temp("li_meet") == 2){
              message_vision(msg, me); 
              tell_object(me, msg1);
              me->delete_temp("mark/steps");
              me->delete_temp("mark/step"); 
              me->unconcious();             
              me->move(__DIR__"shulin");
              tell_room(environment(me), "ͻȻһ����紵���������������㱳����֣�\n", ({ me }));  
              return;
              }
         else if(me->query("water") < 20) 
              { 
              message_vision(msg1, me);              
                  me->unconcious();
                  me->move(__DIR__"caoyuan"+(1+random(7)));
                  tell_room(environment(me), HIR"ͻȻһ���紵��������һ��������\n"NOR,  ({ me }));  
                  me->delete_temp("mark/steps");
                  me->delete_temp("mark/step");
                  me->delete_temp("gc_n");
                  me->delete_temp("gc_s");
                  me->delete_temp("gc_w");
                  me->delete_temp("gc_e");
                  me->delete_temp("gc1_n");
                  me->delete_temp("gc1_s");
                  me->delete_temp("gc1_w");
                  me->delete_temp("gc1_e");
              return;
              }
         else if(me->query_skill("dodge", 1) <= 150) { 
              me->add("jing", -15);
              me->add("water", -10);
              }
         else {
              me->add("jing", -5);
              me->add("water", -5);
              }
      }
}