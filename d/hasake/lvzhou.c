// ����

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ؽ�����" NOR);
        set("long", @LONG
�ڸ�ڵľ�ͷ������һ�����ޡ������п�ˮ���������Ѿ��ɺ��ˡ�
LONG);
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("objects", ([
                    __DIR__"obj/hamigua" : 2

        ]));
 
        set("exits", ([
              "northwest" : __DIR__"gebi1",
              "southeast" : __DIR__"gebi2",
              "southwest" : __DIR__"gebi3",
              "northeast" : __DIR__"gebi4",
        ]));

        set("outdoors", "hasake");
        set("no_quest",1);
        setup(); 

}

void init()
{
       object me = this_player();
      if(objectp(present("shou juan", me))){
       switch(random(4)) {
       case 0 :
               me->set_temp("gc1_n",1); 
               tell_object(me, HIC "ͻȻ���־����Գ�һ��ָ�����ϸ������\n" NOR);          
               break;
       case 1 :
               me->set_temp("gc1_s",1); 
               tell_object(me, HIC "ͻȻ���־����Գ�һ��ָ�������ϸ������\n" NOR);
               break;
       case 2 :
               me->set_temp("gc1_e",1); 
               tell_object(me, HIC "ͻȻ���־����Գ�һ��ָ�����ϸ������\n" NOR);
               break;
       case 3 :
               me->set_temp("gc1_w",1); 
               tell_object(me, HIC "ͻȻ���־����Գ�һ��ָ�������ϸ������\n" NOR);
               break;
       }
    }             
}