// room: well1.c
// Jay 4/8/96

inherit ROOM;
#include <ansi.h>
#define BOOK "/clone/book/lbook9"
int do_use(string arg);
int do_zuan(string arg);


void create()
{
        set("short", "����");
        set("long", @LONG
�����ڸ߲������һ�����ң�ʲôҲ�����塣
LONG );
        set("exits", ([
                "out" : __DIR__"mishi2",
        ]));
        set("no_clean_up", 0);
		set("item_desc", ([
				"hole" : "һ����֪��ǳ��ʯ������֪�ò�����һ�ѿ���\n"
        ]));
        set("count",1);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_search", "search");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             message_vision("$N��ȼ�˻��ۣ�����ǽ������һС��(hole)���ƺ���ʲô���������档\n",me);
         me->set_temp("marks/fire", 1);
         return 1;
       }
}

int do_search(string arg)
{
      object me,ob;
      object book;
      object none;
      me = this_player();
      

			if (!me->query_temp("marks/fire"))
			return 0;
			if (!arg || (arg!="hole" && arg!="С��"))
			return notify_fail("��Ҫ�����\n");
			if (query("count")<1)
				{
					return notify_fail("������ʲôҲû���ˡ�\n");
					}
			if (me->query("cor")<25)
					return notify_fail("��������֣���Ȼ�е㺦�£������뻹�����ˡ�\n");
			add("count",-1);
      book=new(BOOK);
      if (book->violate_unique())
        {
        	destruct(book);
        	book=none;
        }
			if (random(4)>0 && book)
				{
					message_vision("$N������������������һ����������\n",me);
 					message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ�һ��"+book->query("name")+"����\n"NOR, users());
					book->move(me);
				}
			else if(random(4)>1)
				{
					ob=new("clone/money/gold");
					ob->set_amount(random(30));
					message_vision("$N��������������������һЩ�ƽ�\n",me);
					ob->move(me);
					}
			else 
				{
					ob=new("clone/money/silver");
					ob->set_amount(random(30));
					message_vision("$N��������������������һЩ������\n",me);
					ob->move(me);
					}
			
      return 1;
}

