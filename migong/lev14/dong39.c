#include <room.h>
#include <ansi.h>
inherit ROOM;


void create()
{
		set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š������ǽ���ƺ���Щ�ɶ���
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong04",
		"west" : __DIR__"dong40",
                	]));
	set("no_clean_up", 0);
	setup();
	}

void init()
{
add_action("do_break", "break");
}
int do_break(string arg)
{
      if(  arg == "wall" )
    { 
message_vision(
"$N����һ������˫��ͬʱ�Ƴ���
ֻ������һ�������ڱ�������������·��һ��·��\n", this_player());
            set("exits/enter", __DIR__"dong103");
          remove_call_out("close");
        call_out("close", 10, this_object());
    }
    else 
   {
        write("��Ҫ����ʲô?\n");
            }

     return 1;
}
void close(object room)
{
    message("vision","������ʯ��ϡ�ﻩ��̮������������ס�˶�Ѩ��\n", room);
    room->delete("exits/enter");
}