// cexiang.c ����
// Java Oct.10 1998

inherit ROOM;
void back(object me);
void init();
int do_sleep(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ�Ĺ�еĲ��᷿����������ں����ģ�ʲô������û�У�ֻ
��һ��ϸ��(rope)�����Ҷ���һ��������ϵס������������У����ӵ�
���ϵ�����ڵ�һ�ڶ��ϣ��������ԼĪһ�����ߡ�
LONG );

	set("exits", ([
		"west" : __DIR__"mudao14",
	]));
	set("item_desc", ([
		"rope" : "һ��ϸ�����������ǹ�Ĺ������˯��֮����\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object room, *ob, me=this_player();
	int i, j;

	if( !(room = find_object(__DIR__"rope")) )
		room = load_object(__DIR__"rope");
	if( !arg || arg != "rope" )
	{
		return notify_fail("��Ҫ˯���Ķ���\n");
	}
	if((int)me->query_skill("yunv-xinfa",1) < 10)
	{
		message_vision("$N����Ů�ķ�������죬��������ȥ��\n",me) ;
		return 1;
	}
	me->receive_damage("qi",random(30));
	ob = all_inventory(room);
	j = 0;
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me ) j++;
	if (j > 0)
	{
		message_vision("$N�������𣬷����������ˣ�ֻ�÷����µء�\n",me);
		return 1;
	}
	message_vision("$N�������𣬺������ϣ�����Ϊ����˯�������\n", me);
	me->move(room) ;
	call_out("back", 6 , me);
	return 1 ;
}

void back( object me )
{
	int c_exp,c_skill;
	me->move(__DIR__"cexiang");
	message_vision("$Nһ������������Ծ��������\n",me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("dodge",me->query("int"));
		tell_object(me,"��Ļ����Ṧ������!\n");
	}
}
