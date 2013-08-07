// Room: /d/taohua/tomb.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;
int do_bai(string arg);

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���İ����������߳�����ֻ���̲������м���һƬ��ɫ���ԣ���
�ص���������һ���׻��ѳɵ�С�����׻�֮����һ�鶫���߸�¡����
���˲ŷ�����һ��ʯ�أ���ǰ��һ��Ĺ��(mubei)��
LONG
	);
	set("exits", ([ 
		"east"  : __DIR__"taohua1",
		"west"  : __DIR__"taohua1",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"taohua1",
	]) );
	set("item_desc",([
		"mubei" : "
��
��
��
Ů
��
��
��
��
��
֮
ڣ\n
"
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 9010);
	set("coor/y", -3100);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_bai", "bai");
	add_action("do_bai", "guibai");
	add_action("do_bai", "gui");
	add_action("do_bai", "knee");
	add_action("do_push", "push");
}

int do_bai(string arg)
{
	object me = this_player();

	if (arg != "mubei")
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N�ڷ�ǰ�򵹣����������ذ����İݡ�\n", me);
	me->set_temp("tomb_knee", 1);
	return 1;
}

void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3 && (int)query("right_trigger")==3 &&
		!query("exits/down") )
	{
		message("vision","Ĺ�ź�Ȼ���������������������������ƶ�����¶��һ�����µĽ��ݡ�\n", this_object() );
		set("exits/down", __DIR__"mudao");
		if( room = find_object(__DIR__"mudao") )
		{
			room->set("exits/up", __FILE__);
			message("vision","Ĺ�ź�Ȼ���������������������������ƶ�����¶��һ�����ϵĽ��ݡ�\n", room );
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
	message("vision","Ĺ�ź�Ȼ����������������������£�������µ�ͨ����ס�ˡ�\n", this_object() );
	if( room = find_object(__DIR__"mudao") )
	{
		room->delete("exits/up");
		message("vision","Ĺ�ź�Ȼ����������������������£�������ϵ�ͨ����ס�ˡ�\n"HIR"���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" NOR , room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="mubei" ) {
		write("�������ƶ�Ĺ�������������������ƶ�....\n");
		return 1;
	}
	if( this_player()->query("neili") <100) {
		write("�������ƶ�Ĺ������������̫��....\n");
		return 1;
	}
	if( sscanf(arg, "mubei %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N��Ĺ��������...����Ȼ��������Ĺ�����ƻ�ԭλ��\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N��Ĺ��������...����Ȼ��������Ĺ�����ƻ�ԭλ��\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("��Ҫ��Ĺ�������Ǹ�����\n");
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
