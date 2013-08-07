#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һƬ��ʯ�ѳɵ�ɽ�ԡ�����С��ϡϡ����س�����ʯ����϶�
�Ӳݴ��¶��һ��ʯ��(bei)��һ�ǡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"gumiao",
		"south" : __DIR__"xilingxia",
		"north" : __DIR__"xiaowu",
	]));
	set("outdoors", "jiangling");
	set("item_desc", ([
		"bei": "���ǿ�Ĺ����ֻ¶��һ�ǡ�\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dig", "dig");
}
void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3 && (int)query("right_trigger")==2 && !query("exits/down") )
	{
        message("vision", "Ĺ�����ڵ��ɶ��ˣ�ͻȻ������һ�ݣ�¶��һ�����µĽ��ݡ�\n", this_object() );
        set("exits/down", __DIR__"gumu");
        if( room = find_object(__DIR__"gumu") )
		{
			room->set("exits/up", __FILE__);
            message("vision", "Ĺ��ͻȻ������һ�ݣ�¶��һ�����ϵĽ��ݡ�\n",
				room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 30);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "Ĺ�������ƶ����ֽ����µ�ͨ����ס�ˡ�\n", this_object());
	if( room = find_object(__DIR__"mudao") )
	{
		room->delete("exits/up");
		message("vision", "Ĺ�������ƶ���������£�������ǰһƬ��ڡ�\n"
		HIR "���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" NOR ,
			room );
	}
	delete("exits/down");
}

int do_dig(string arg)
{
        object weapon,me = this_player();
	string dir;

        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("name") != "��ͷ")
        return notify_fail(HIR"��˫���ٳ�Ѫ����ȴʲôҲû���֡�\n"NOR);        
	if( !arg || arg=="" ) return 0;

	if( arg=="bei" )
	{
		write("�������ڳ�Ĺ����������������Щ�ɶ�����\n");
		return 1;
	}
	if( this_player()->query_str() <40)
	{
		write("�������ڳ�Ĺ������������̫С����\n");
		return 1;
	}
	if( sscanf(arg, "bei %s", dir)==1 )
	{
		if( dir=="right" ) {
			message_vision("$N��Ĺ���ұ������ڡ���\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N��Ĺ����������ڡ���\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("������һ�����۵ð�����Ĺ������û��㶯����\n");
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