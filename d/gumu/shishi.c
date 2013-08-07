// shishi.c ʯ��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ʯ�ң����е����ƻ�ʯ����С������վ����ת��ͺܲ�
���ף��Ҷ��ְ����쳤�ֱۣ�������������ʯ�ҽ�������һֻ����Ĳ�
��(budai) ���������Ŵ��ڣ������������֪����ʲô������
LONG );
	set("exits", ([
		"north" : __DIR__"mudao16",
	]));
	set("item_desc", ([
		"budai": "һֻ�ɲ��������滹��������š�\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -60);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_open", "dakai");
	add_action("do_open", "open");
	add_action("do_zhua", "zhua");
	add_action("do_zhua", "catch");
}

int do_open(string arg)
{
	object obj, me=this_player();
	if( !arg || arg != "budai" )
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if (this_object()->query("opened"))
		return notify_fail("�����ѱ����ˡ�����ɶҲû���ˡ�\n");
	message_vision("$N������ʯ�ҽ���������һֻ�������⿪���ڴ��ڵ���������ת����һ�����ɳ�����ֻ��ȸ��\n",me) ;
	this_object()->set("opened", 1);
	obj=new(__DIR__"npc/maque");
	obj->move(this_object());
	obj=new(__DIR__"npc/maque");
	obj->move(this_object());
	obj=new(__DIR__"npc/maque");
	obj->move(this_object());
	return 1;
}

int do_zhua(string arg)
{
	object me=this_player();
	int c_exp, c_skill;

	c_exp=me->query("combat_exp");
	c_skill=(int)me->query_skill("yunv-shenfa", 1);
	if( !arg || arg != "ma que" ) return notify_fail("��Ҫץʲô��\n");
	if( !objectp(present("ma que", environment(me))))
		return notify_fail("����û����ȸ�ɣ�\n");
	if( me->query("qi") < 30 )
		return notify_fail("�����̫���ˣ�����Ъ��ɣ�\n");
	if( me->query_skill("yunv-xinfa", 1) < 10)
	{
		message_vision("$N����Ů�ķ�������죬ץ��ȸҲû�á�\n", me) ;
		return 1;
	}
	me->receive_damage("qi", random(30));
	if( random((int)c_skill/10) + 1 < 2)
	{
		message_vision("$N�˹�ȥ��ץ��������ȸ����쳣���������ˣ�$N�����������۵���ͷ�󺹣���˵׽��������ëҲ������һ����\n", me);
		return 1;
	}
	message_vision("$N�����������ִ������ô�סһֻ��ȸ��\n", me);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("yunv-shenfa", random(me->query("dex")));
		tell_object(me,"�����Ů�������ˣ�\n");
	}
	return 1;
}
