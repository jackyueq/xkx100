// Room: /d/5lt/5laofeng.c

inherit ROOM;

int do_jump();

void create()
{
        set("short", "���Ϸ�");
        set("long", @LONG
��е���������ԭ���ѵ������Ϸ�ķ嶥�������ʯ��ᾣ����
�ĵط�һʯ׿������ͻȻ����������ȥ(jump)һ�����ֵĳ嶯��
LONG );
        set("exits", ([ /* sizeof() == 1 */
	    "westdown"  : __DIR__"shanlu",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -110);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump()
{
	object me;
	int i, ging_cost, qi_cost;
	
	me = this_player();
	i = (int)me->query_skill("dodge", 0) + random(5);
	ging_cost = 500 / (int)me->query("int");
	qi_cost = 400 / (int)me->query("int");
	
	if (me->is_busy() || me->is_fighting())
        	{
        		tell_object(me,"����æ���ء�\n");
        		return 1;
        	}

	if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N����һԾ���ڿ��а��˸�����˵����ơ�\n", me);
	me->start_busy(5);
	message_vision("ֻ�����须��һ��$N�ӿ�������������\n", me);
	if ( i < 60)
		me->die();
	else if( i < 135)
		me->unconcious();
	else {
		message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
		if( i > 210 && me->query_skill("dodge",1)<230)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
	}

	return 1;
}