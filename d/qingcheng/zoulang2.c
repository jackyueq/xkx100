// Room: /qingcheng/zoulang2.c
// Date: Aug. 10 1998 by Winder

inherit ROOM;
void create()
{
	set("short", "�ɷ綫��");
	set("long", @LONG
�������ɷ��������������Ͷ�������ȣ��ɷ�۸ߴ�ɽ��������
����ȥ����ɽ��ţ��Ĺȷ��������챡��ʱʱ��ɢ�ڳ��ִ���֮�䡣��
�źųƣ�����������ġ��������ڴ���ζ��������ϱ����鷿��������
�����ң�����һֱ�����ŵ��Ǳ��ɵĿⷿ��
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"west"  : __DIR__"caochang",
		"south" : __DIR__"shufang",
		"north" : __DIR__"bingqishi",
	]));
	set("objects", ([
		__DIR__"npc/hong" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -840);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if((!myfam || myfam["family_name"] != "�����") && dir != "west" &&
		objectp(present("hong renxiong", environment(me))))
	return notify_fail("��������ס��˵���˴��˱��ɽ��أ���ֹ����\n");

	if( me->query_skill("qingming-xuangong", 1) < 10 && dir != "west" &&
		objectp(present("hong renxiong", environment(me))))
	return notify_fail("��������ס�㣺ʦ���������ڹ�δ��С�ɲ������ڡ�\n");

	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"kufang")) )
		room = load_object(__DIR__"kufang");
	if(objectp(room))
	{
		delete("exits/east");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",this_object());
		message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n", this_object());
		room->delete("exits/west");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",room);
		message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" , room);
	}
}

int do_open(string arg)
{
	object room;
	object ob;

	if (query("exits/east"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "men" && arg != "east" && arg != "door"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("qingcheng key", this_player())))
		return notify_fail("�㲻��������\n");
	message_vision("$N��һ��Կ�״��˿��š�����������ͣ���Կ���ֶ��ˡ�\n", this_player());

	if(!( room = find_object(__DIR__"kufang")) )
		room = load_object(__DIR__"kufang");
	if(objectp(room))
	{
		set("exits/east", __DIR__"kufang");
		message_vision("$Nʹ���ѿ������˿�����\n",this_player());
		room->set("exits/west", __FILE__);
		message("vision","�������˰ѿ����ƿ��ˡ�\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}