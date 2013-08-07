// Room: /d/5lt/zhensuo2.c

inherit  ROOM;
int do_pull(string arg);

void  create  ()
{
	set  ("short",  "������¥");
	set  ("long",  @LONG
������ǲ��ü򵥵�ҽ�����ҡ����ż���С�����������κ�����Ϣ�����л�ʿ
��ʱ�ظ���������ͷ�����㾫�����������΢Ц���Ƕ�����������õı���
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"down"  :  __DIR__"zhensuo",
	]));
	set("item_desc", ([
		"chuang" : "����һ��ո�µ����ܴ����������ƺ�����Щʲô��\n" ,
		"��"     : "����һ��ո�µ����ܴ����������ƺ�����Щʲô��\n" ,
		"xia"    : "����ϸ����һ��ľϻ�����������ƺ�����һ���顣\n",
		"ľϻ"   : "����ϸ����һ��ľϻ�����������ƺ�����һ���顣\n",
	]));
	set("coor/x", -140);
	set("coor/y", -30);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_move", "move");
        add_action("do_move", "nuo"); 
        add_action("do_pick", "pick");
}

int do_move(string arg)
{
	object me = this_player();

	if (!arg||arg!="chuang") return notify_fail("��ҪŲ��ʲô��\n");
	if (me->query("neili") < 200)
	{
		message_vision("$N��ס��������һŲ�����ܴ��Ʒ粻����\n", me);
		me->set("neili", 0);
		return 1;
	}
	if ( query("chuang") )
		return notify_fail("���ܴ��Ѿ�Ų���ˣ���Ų�͵�¥��ȥ�ˣ�\n");
	message_vision("$NŲ�����ܴ������º������һ��ľϻ(xia)��\n", me);
	set("chuang", 1);
	return 1;
}

void reset()
{
	::reset();
	set("get_available" , 1);
}

int do_pick(string arg)
{
	object me,obj;

	me = this_player();
	if( !arg || arg!="book" ) return notify_fail("��Ҫ��ʲô��\n");
	if ( query("get_available") )
	{
		obj = new (BOOK_DIR+"medicine5");
		obj->move(me);
		add("get_available", -1);
		message_vision("$N��ľϻ��ȡ��һ���顣\n",me );
	}
	else
		return notify_fail("��Ҫ�����Ǳ��飬ȴ�����㿴�����ۣ���ʵ����ʲô��û�С�\n");
	return 1;
}
