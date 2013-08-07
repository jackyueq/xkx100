#include <ansi.h>
#include <command.h>

inherit ROOM;

int do_start();
int do_say(string msg);
int do_stop();

private string filename;

void create()
{
        set("short", "��ʦ������");
        set("long",
"����һ����Ļ����ң����澲���ĵģ�ֻ���������������������\n"
"��������ʱ���������������ˣ�Χ��Բ������������ԭ����"+MUD_NAME+
"\n����ʦ����ǰ�����ᡣǽ�϶��Ÿ����(pad)��\n");
        set("item_desc", ([
                "pad" : "\n�����ҵ�ʹ�÷�����\n"
"start  :       ��ʼ���顣\n"
"stop   :       �������顣\n\n"
        ]));
        set("no_fight",1);
        set("exits", ([
                "down" : __DIR__"wizard_room", ])
        );
        set("coor/x",-1);
	set("coor/y",1);
	set("coor/z",20);
	setup();
	call_other("/clone/board/wizcode_b", "???");
	
}

void init()
{
        add_action("do_say", "say");
        add_action("do_say", "'");
        add_action("do_start", "start");
        add_action("do_stop", "stop");
}

int do_start()
{
        string str;
        object* ob,me;
        int i;
        me = this_player();
        if(wiz_level(me) < 4 )
                return notify_fail("��û���ٿ������Ȩ����\n");

        set("meeting_trigger", 1);

        ob = users();
        for ( i=sizeof(ob); i>0; i-- ) {
                if( wiz_level(ob[i-1]) < 1) continue;
                ob[i-1]->set_temp("meeting",1);
                message_vision("$N���ˡ�\n",ob[i-1]);
        if (file_name(environment(ob[i-1])) == "/d/wizard/meeting_room") continue;
        //       if(environment(ob[i-1])==find_object("/d/wizard/meeting_room") continue;

                ob[i-1]->move("/d/wizard/meeting_room");
                tell_object(ob[i-1],
                sprintf(HIG"%s(%s)�����㣺��ʦ���������ٿ����뵽��ʦ�����ҿ��ᡣ
\n"NOR,
                        me->query("name"),me->query("id")) );
                message_vision("$N���ˡ�\n",ob[i-1]);
        }
        str = me->query("id");
        if( !str )
                return notify_fail("Put meeting record to where??\n");

        message_vision(HIW"\n$N�������������������ڿ�ʼ����\n"NOR, me);
        add_action("do_fail", "update");
        add_action("do_fail", "call");
        add_action("do_fail", "home");
        add_action("do_fail", "quit");
        add_action("do_fail", "exit");
        filename = "meeting/" + str;
        return 1;
}
int do_say(string msg)
{
        if( !msg ) return 0;
        else
        "/cmds/std/say.c"->main(this_player(), msg);
        if ((int)query("meeting_trigger") == 1)
        log_file(filename,sprintf("%s(%s)��" + msg + "\n",this_player()->name(1)
,this_player()->query("id")) );
        return 1;
}

int do_stop()
{
        int i;
        object *ob,me;
        me = this_player(); 
        ob = users();
        if( !wizardp(me) )
                return notify_fail("��û��Ȩ����ֹ���顣\n");
        if ( (int)query("meeting_trigger") == 0 )
                return notify_fail("����û�н����κλ��顣\n");
        delete("meeting_trigger");
        message_vision(HIW"\n$N�������������������ڽ�������\n"NOR, this_player()
);
          for ( i=sizeof(ob); i>0; i-- ) {
                  if( wiz_level(ob[i-1]) < 1) continue;
                  ob[i-1]->delete_temp("meeting");
                }
        remove_action("do_fail", "goto");
        remove_action("do_fail", "update");
        remove_action("do_fail", "call");
        remove_action("do_fail", "home");
        remove_action("do_fail", "quit");
        remove_action("do_fail", "exit");
        return 1;
}

int do_fail()
{
        write("���ڽ��л��飡\n");
        return 1;
}


int valid_leave(object obj, string dir)
{
    obj = this_player();
    if (obj->query_temp("meeting"))
      return notify_fail(HIY"���������һ����ë����׷�˳��������ỹû���꣬�����������ܣ���\n"NOR);
    else  return 1;
}

