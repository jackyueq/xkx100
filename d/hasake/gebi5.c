// gebi5.c
#include <room.h>
inherit ROOM;
void create()
{
       set("short","�������");
       set("long", @LONG
��������Ĵ��ڣ�Ҫ�߳����ﲢ�����¡���Զ������ɳ�������
�ذ㴵��������Ҫ��籩�ˡ�
LONG);
        set("exits", ([
                "north" : __DIR__"gebi2",
                "south" : __DIR__"gebi3",
                "east" : __DIR__"gebi4",
                "west" : __DIR__"gebi1",
        ]));
        set("outdoors", "hasake");
        set("no_quest",1);
        setup();
}

void init()
{
       object me = this_player();
       switch(random(4)) {
       case 0 : me->set_temp("gc_n",1); 
       tell_object(me,"ֱ�������㣺��������һƬ���ޡ�\n");break;
       case 1 : me->set_temp("gc_s",1); 
       tell_object(me,"ֱ�������㣺��������һƬ���ޡ�\n");break;
       case 2 : me->set_temp("gc_e",1); 
       tell_object(me,"ֱ�������㣺��������һƬ���ޡ�\n");break;
       case 3 : me->set_temp("gc_w",1); 
       tell_object(me,"ֱ�������㣺��������һƬ���ޡ�\n");break;
       }       
       if(me->query_skill("dodge", 1) <= 150) 
            me->add("jing", -15);
       else me->add("jing", -5);
}