// /d/meizhuang/jianyu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"÷ׯ����"NOR);
	set("long", @LONG
����ںڰ������������ֲ�����ָ��Ψһ�Ĺ�������ǽ�Ϻ�������
�����͵ơ����Ϻ�ǽ�ϲ����˰���ɫ��Ѫ�ۣ�ɢ�����������������ϴ�
���Ĵ�Ϣ���������ĵ�����ص�������ë����Ȼ���ӵ��ε�ǽ����͸��
�������⡣������һ�Ƚ��յ����š�
LONG
	);
	set("item_desc", ([
		"door" : "�����ƺ���ǰ���˶���ʲô�ֽš�\n",
		"��"   : "�����ƺ���ǰ���˶���ʲô�ֽš�\n",
	]) );
	set("objects", ([
		CLASS_D("heimuya")+"/ren" : 1,
	]) );
	set("valid_startroom","1");

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", -10);
	setup();
}

void init()
{
	add_action("do_push", "push");
}

void check_trigger()
{
	object room;
	if( (int)query("trigger")==8 && !query("exits/out") )
	{
		message("vision","�����ű����Ƶ��ѿ���һ����϶���պÿ����������ȥ��\n", this_object() );
		set("exits/west", __DIR__"midao4");
		if(!( room = find_object(__DIR__"midao4")) )
			room = load_object(__DIR__"midao4");
		message("vision", "������ͻȻ�ѿ�һ��խ�졣\n", room );
		room->set("exits/east", __FILE__);
		delete("trigger");
		call_out("close_passage", 5);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/west") ) return;
	message("vision","��������ѽѽһ���죬���һ���ֹ����ˡ�\n", this_object());
	if( room = find_object(__DIR__"midao4") )
	{
		message("vision", "��������ѽѽһ���죬���һ���ֹ����ˡ�\n", room);
		room->delete("exits/east");
	}
	delete("exits/west");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" )
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}

	if( arg=="door" || arg == "��")
	{
		add("trigger", 1);
		write("�������������Ž����ŵ����ţ��ƺ���һ���ɶ�....\n");
		check_trigger();
		return 1;
	}
}

void reset()
{
	::reset();
	delete("trigger");
}

