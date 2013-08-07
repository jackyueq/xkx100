//entrance of gaochang.
//bye yuan
#include <ansi.h>

inherit ROOM;
   

void create ()
{
  set ("short", "�߲�����");
  set ("long", @LONG
    ת����һ����ľ��ֻ��һ��ʯɽ��Ƕ�����������Ĵ���,
  ���ſ���������ǧ������˵�ǹŴ��߲�����Ϊ�˵���ǿ�ж���Ƶġ�
  ��������߲���������ʱ�Ѿõľ���������ϵ��Ż�(huan)
  �ƺ�����Ť(niu).����д�ţ�
               ****************
               *              *
               *  �� �� �� �� *
               *              *
               ****************

LONG);

  set("outdoors", "gaochang");
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie3",
]));

  setup();
}

void init()
{
   add_action("do_niu", "niu");
}



void check_trigger()
{
   object room;
   object me=this_player();
   int exp,pot,score;
if( (int)query("left_trigger")==2

   &&   (int)query("right_trigger")==5
   &&   !query("exits/down") ) {
     message("vision", "���ź�Ȼ����������������¶��һ�����µĽ��ݡ�\n", this_object() );
      if( !(room = find_object(__DIR__"dadian")) )
              room = load_object(__DIR__"dadian");

     if( room = find_object(__DIR__"dadian") ) {
           set("exits/down", __DIR__"dadian");
           room->set("exits/up", __FILE__);
        
          message("vision", "���ź�Ȼ����������������¶��һ�����ϵĽ��ݡ�\n",room );
	        if (!me->query("skybook/baima/damen"))
          {
         	 me->set("skybook/baima/damen",1);
  	       exp=500+random(1000);
           pot=exp/2;
           score=pot/2;
           me->add("combat_exp",exp);
           me->add("potential",pot);
           tell_object(me,HIC"��ɹ�����ͨ���߲��������ţ�\n�����������������"+
           	         chinese_number(exp)+"�㾭�顢"+
                     chinese_number(pot)+"��Ǳ���Լ�"+
                     chinese_number(score)+"�㽭��������\n\n"NOR);
          }
     }
     delete("left_trigger");
     delete("right_trigger");
     call_out("close_passage", 10);
   }
}

void close_passage()
{
   object room;

   if( !query("exits/down") ) return;
   message("vision", "���ź�Ȼ���������������������µ�ͨ����ס�ˡ�\n",
     this_object() );
   if( room = find_object(__DIR__"dadian") ) {
     room->delete("exits/up");
     message("vision", "���ź�Ȼ�������������������ϵ�ͨ���ֻ����ر���ס�ˡ�\n",
        room );
   }
   delete("exits/down");
   delete("left_trigger");
   delete("right_trigger");
}


int do_niu(string arg)
{
   string dir;
   object me=this_player();

   if( !arg || arg=="" ) return 0;

   if( arg=="huan" ) {
     write("������Ť���Ż����ƺ��������һ���....\n");
delete("left_trigger");
delete("right_trigger");
     return 1;
   }
   if( sscanf(arg, "huan %s", dir)==1 ) {
     if( dir=="right" ) {
if(query("exits/down")) return notify_fail("�����Ѿ���Ť���ˡ�\n");
        message_vision("$N���Ż�����Ť...����Ȼ������һ���������ƻ�ԭλ��\n", me);
        add("right_trigger", 1);
        check_trigger();
        return 1;
     } else if( dir=="left" ) {
if(query("exits/down")) return notify_fail("�����Ѿ���Ť���ˡ�\n");
        message_vision("$N���Ż�����Ť...����Ȼ������һ���������ƻ�ԭλ��\n", me);
        add("left_trigger", 1);
        check_trigger();
        return 1;
     } else {
        write("��Ҫ���Ż����ı�Ť��\n");
        return 1;
     }
   }
}


void reset()
{
   ::reset();
   delete("left_trigger");
   delete("right_trigger");
}
int valid_leave(object me, string dir)
{
 if(dir=="d" || dir=="down")
{
if(this_player()->query("combat_exp")<100000)
{
  return notify_fail("һ�ɿֲ��ķ�Χ�ӽŵ�������ʹ�����Ȳ�����ֹ���޷��ٲ���\n");
}

}
return ::valid_leave(me,dir);
}
