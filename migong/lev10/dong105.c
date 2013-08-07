#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_pick(string arg);

void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ������
��ʯ����Щ��û������ֲ��(zhiwu)�� 
LONG NOR);
	set("exits", ([
		"out" : __DIR__"dong104",
                	]));
                set("item_desc",([
            "zhiwu" : "�е����ĵ�ֲ�����ժ(pick)����������\n"
        ]) );
           set("objects", ([
              __DIR__"npc/boss1" : 1,
             __DIR__"npc/boss2" : 6,
                ]));
	set("no_clean_up", 0);
        set("caocount", 1);
	setup();
	
}
void init()
{
        add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object me=this_player();
        object obn;
              if( !arg || arg != "zhiwu" )
        {
             write("��Ҫ��ʲôѽ!\n");
             return 1;
        }
message_vision("$N����ʯǰվ�������һ������ͻȻԾ��\n", this_player());
         if(query("caocount") > 0)
             {
message_vision("$N����һժ�����ж���һ�\n", this_player());
                 obn = new("/d/migong/obj/haitang");
                 obn->move(me);
                 add("caocount",-1);
             }
             else
message_vision("$N����һ��������ֲ���Ա��������ˡ�\n", this_player());
          return 1;
        }
        
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "out" && objectp(present("bailei", environment(me))))
                return notify_fail(HIY"ȫ�����"NOR"�ȵ��������ҹԹԵ����°�?\n");
      

        return ::valid_leave(me, dir);
}
