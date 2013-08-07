#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);
int do_climb(string arg);

void create()
{
	set("short", "ׯ������");
	set("long", @LONG
���������ʿׯ�ʳǵľɾӡ��Դ�������͢ץ�ߺ���������û
����ס�ˡ�һ�ȴ��� (men)�����ţ���Χ�Ǹ߸ߵ�Χǽ(wall)��һ�ж�
�ܸɾ�����û�л����ٻҳ���
LONG );
	set("outdoors", "huabei");
	set("exits", ([
		"south" : __DIR__"zhuang2",
	]));
	set("item_desc", ([
		"men" : "�����������ŵģ����������(break)����\n",
		"wall" : "ǽ�ܸߣ����ܷ�����ȥ(climb)��\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", 100);
	set("coor/y", 4700);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_break", "break");
	add_action("do_climb", "climb");
}

int do_break(string arg)
{
	int n;
	object me = this_player();

	n = me->query("neili");
	if( !arg || arg!="men" )
	{
		write("��Ҫ��������˵Ķ�����\n");
		return 1;
	}
	message_vision("$N�ߵ���ǰ������һ������˫��ͬʱ�ĳ���\n", me);
	if (n>=200)
	{
		message_vision("$Nֻ��һ�����죬$N�������ˣ�\n", me);
		set("exits/north", __DIR__"zhuang4");
		me->set("neili",n-200);
		remove_call_out("close");
		call_out("close", 5, this_object());
	}
	else
	{
		message_vision("$N���һ���������������ʲôҲû����������$N����������ǿ��\n", me);
		me->set("neili",0);
	}
	return 1;
}

int do_climb(string arg)
{
	int n;
	object me = this_player();

	n = me->query_skill("dodge");
	if( !arg || arg!="wall" )
	{
		write("��Ҫ����������\n");
		return 1;
	}
	message_vision("$N��ǽǰվ��������һ��������ȻԾ��\n", me);
	if (n>=80)
	{
		message_vision("ֻ��$N�����ǽ��һ�㣬����ȻƮ��Ժ�С�\n", me);
		me->move(__DIR__"zhuang4");
	}
	else
		if (n>=50)
		{
			message_vision("ֻ��$N˫����ǽ��һ�ʣ���ǿ����Χǽ������Ժ�С�\n", me);
			me->move(__DIR__"zhuang4");
		}
		else
		{
			message_vision("$N�߸�Ծ�𣬿ɻ���һ����أ��������Ṧ�����á�\n", me);
		}
		return 1;
}

void close(object room)
{
	message("vision","��֨ѽһ���ֺ�����,�����й�\n", room);
	room->delete("exits/north");
}
