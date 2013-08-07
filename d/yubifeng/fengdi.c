// /yubifeng/fengdi.c
// Last modified by winder 2003.9.2

int do_climb(string arg);

inherit ROOM;

void create()
{
	set("short", "��ʷ���");
	set("long", @long
�������ֺó������˰��ʱ����ʼ���꣬һ�����֣�����һ��ɽ��
���¡�ɽ��(feng)�����ߣ�������һ���ʹܰ�������Ⱥɽ֮�У�����
�쳣������ǧ�𣬷�ͬС�ɡ�Ī˵���ˣ�����Գ��Ҳ�ǲ�����ȥ��	
long );
	set("exits", ([
		"west" : __DIR__"songlin5",
	]));
	set("item_desc", ([
		"feng" : "ɽ�帲�Ǽ������ྦྷӨ���������֣�����������\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_climb(string arg)
{
	object me = this_player();
	int n;

	n = me->query_skill("dodge", 1);

	if ( !arg || arg != "feng")
	{
		write("��Ҫ��ʲôѽ��\n");
		return 1;
	}
	message_vision("$N������һ����������ڻ���ǽ���������±���������\n",me);
	if(n > 140 && me->query("qi") > 1400)
	{
		message_vision("\n .... \n\n .... \n\n$N���˰��죬��������������$N����վ�ڷ嶥������Ⱥ�壬��������һ������\n\n", me);
		me->move(__DIR__"fengding");
	}
	else
	{
		message_vision("$N����һ�ᣬ̫���ˣ����λ���������\n", me);
		me->receive_damage("qi",15);
		me->receive_wound("qi",10);
	}
	return 1;
}
