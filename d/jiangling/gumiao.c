//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ش���Ƨ�����ʧ�ޣ�����Ҳ����ף���С��������ǻҳ�
������ȴ��֦�ִ������(lazhu)���ڰ��ϡ�
LONG );
	set("item_desc", ([
		"lazhu": "һ֦�ִ�����������ƺ���Ϊ���ʣ���������˵����\n"
	]) );
	set("exits", ([
		"east" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/foxiang" : 1,
	]));
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_dian", "fire");
	add_action("do_open", "qiao");
	add_action("do_open", "open");
}

int do_dian(string arg)
{
	string dir;
	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="lazhu" )
	{
		if (! objectp(present("tangshi jianpu", me)))
			return notify_fail("�����������\n");
	message("vision", me->name()+"���������������ͻȻ���ַ�������и�����Ү����\n", environment(me));
		me->set_temp("marks/lazhu", 1);
		return 1;
	}
	else 
		return notify_fail("����Ҫ��ʲô��\n");
}
int do_open(string arg)
{
	object foxiang, obj, me = this_player();

	if (!objectp(foxiang = present("dafo xiang", this_object())))
		return notify_fail("��֣����񲻼��ˣ�\n");
	if (foxiang->query("opened"))
		return notify_fail("����������˼Ҵ��ˣ�\n");
	if (me->query_temp("marks/lazhu") )
	{
		message("vision", me->name() + "����ȥ�˰��š��˵ü��£��ǰ��Ž������ˡ�"+me->name()+"����ָ�������������˳���������һ�գ�ֻ�����������ⱦ����������������֪��������֮�У������ж������鱦����\n", environment(me) );
		me->delete_temp("marks/lazhu");
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		foxiang -> set("opened", 1); 
		return 1;
	}
        else {
		write("�ں����������ʲô����\n");
		return 1;
        }
}