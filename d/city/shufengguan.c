// Room: /city/shufengguan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
int pushing();
int halt_pushing();
void create()
{
	set("short", "����");
	set("long", @LONG
���ڳ���ǧ�˰�̬�������ʯ��������ʯң���Ӧ��Ŀ��������
������ʯ�����ָ�����ͬ���ڴ˴�ƾ���������������ɸ��Х��ȫ԰��
�ȫ��ָ�˼䡣�������µ���֮�ʣ����С�������������ɫ��������
�������ݡ�֮�У�����˹���������������¥����
LONG );
	set("exits", ([
		"east"	: __DIR__"hushishanzi",
	]));
	set("objects", ([
		__DIR__"obj/qishayan": random(2),
	]));
	set("coor/x", -11);
	set("coor/y", -47);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
}

void init()
{
	add_action( "push_stone", "push" );
}

int push_stone(string arg) 
{
	object me = this_player();
	object room;
	object parter;
	string target, dir;

	if ( !arg ) return 0;
	if ( me->is_busy() ) return 0;
	
	if ( arg == "stone" || arg == "shitou" || arg == "shi tou" )
	{
		if ( query_temp( "pushed" ) )
		{
			message_vision( "$N����������ʯ�ƿ���һ�ԡ����ˡ������ֿ����ظ�ԭλ��һ�лظ�ԭ״����\n", me );
			delete_temp( "pushed" );
			delete( "exits/down" );
			if ( room = find_object( __DIR__"dixiashi" ) )
				room->delete( "exits/up" );
			return 1;
		}
	}

	write ( arg );
	if ( sscanf( arg, "%s %s", target, dir ) != 2 ) return 0;
	if ( target != "stone" && target != "shitou" && target != "shi tou" )
	return notify_fail( "��Ҫ��ʲô��\n" );
	if ( dir != "east" && dir != "west" )
	return notify_fail( "���������ʯ���Ǳ��ƣ�\n" );
	if ( parter = (object)query_temp( "push_" + dir ) )
	return notify_fail( parter->name() + "�Ѿ��ڰ�����ʯ��������ˡ�\n" );
	if ( me->query_str() <= 30 )
	return notify_fail( "��������������ʯ�����Ƿ����Ʋ�����\n" );
	if ( query_temp( "pushed" ) )
	return notify_fail( "����ʯ�Ѿ����Ƶú���һ���ˡ�\n" );
	if ( !query_temp( "push_" + dir ) )
	set_temp( "push_" + dir, me );
	me->set_temp("direction", dir );
	me->set_temp( "push_marks", 71 );
	message_vision( "$N����������ʯ��һ����������ȥ��\n", me );
	me->start_busy( (:pushing:), (:halt_pushing:) );
	return 1;
}

int pushing()
{
	object ob, me;
	string c_dir, dir;
	int marks, force;

	me = this_player();
	dir = me->query_temp( "direction" );
	marks = me->query_temp( "push_marks" );
	force = me->query( "force_factor" );
	
	if ( dir == "west" )
	{ 
		dir = "east";
		c_dir = "����";
	}
	else
	{
		dir = "west";
		c_dir = "����";
	}
	if ( marks > 70 )
	{
		me->add_temp( "push_marks", -10 );
		me->add( "force", force );
		return 1;
	}
	force *= -1;
	me->add( "force", force );
	if ( me->query( "force" ) < 0 )
	{
		write( "���������ƶ�����ʯ��ͻȻ�е����������ݽߡ�\n" );
		me->unconcious();
		if ( !query_temp( "push_" + dir ) )
			message_vision( "����ʯ�������˻�ԭλ��\n", me );
		remove_call_out( "del_temp" );
		call_out( "del_temp", 1 );
		me->delete_temp( "push_marks" );
		return 0;
	}
	if ( !query_temp( "push_" + dir ) )
	{
		if ( marks > 10 )
		{
			me->add_temp( "push_marks", -10 );
			if ( random(5) > 2 )
				message_vision( "$N�����ƶ�����ʯ������ʯ��������������������������һ����ȥ��\n", me );
			return 1;
		}
		else
		{
			if ( !query_temp( "pushed" ) ) 
			{
				write("�����˺þ�����ʯ��ȴ�޷��������һ�С�");
				message_vision("$Nֹͣ�ƶ�����ʯ������ʯ�������˻�ԭλ��\n", me );
			
			}
			remove_call_out( "del_temp" );
			call_out( "del_temp", 1 );
			me->delete_temp( "push_marks" );
			return 0;
		}
	}
	else
	{
		ob = query_temp( "push_" + dir );
		if ( dir = "east" )
		{
			message_vision( "$N��$n"
			"���Է����ƶ�����ʯ��һ�飬����ʯ������������������������\n" + "���໥�ӽ���һ�ԡ����ˡ�����ӵ��һ�𣡣�\n", me, ob );
			message_vision( "����ʯ�����Ŀ�ʼת������һ����ȥ�������ڵĵ����ֳ�һ���󶴡�\n", me);
			set( "exits/down" , __DIR__"dixiashi" );
			ob->set_temp( "push_marks", 1 );
		}
		remove_call_out( "del_temp" );
		call_out( "del_temp", 2 );
		me->delete_temp( "push_marks" );
		set_temp( "pushed", 1 );
		return 0;
	}
	return 0;	
}

int halt_pushing()
{
	object me = this_player();

	remove_call_out( "del_temp" );
	call_out( "del_temp", 1 );
	me->delete_temp( "direction" );
	me->delete_temp( "push_marks" );
	message_vision( "$Nֹͣ�ƶ�����ʯ������ʯ�������˻�ԭλ��\n", me );
	return 1;
}

void del_temp()
{
	object me = this_player();
	delete_temp( "push_east" );
	delete_temp( "push_west" );
	if ( me->query_temp( "direction") )
		me->delete_temp( "direction" );
}
 