// Last Modified by Winder on May. 15 2001
// fruit.c

#include <ansi.h>
#include <dbase.h>

int is_food()
{
	return 1;
}
void init()
{
	if (!query("decay") && userp(environment()))
	{
		set("decay", 1);
		remove_call_out("stats");
		call_out("stats", 280,0);
	}
  add_action("do_eat", "eat");
}
int do_eat(string arg)
{
	mapping gifts;
	object me = this_player();
	object ob = this_object();
	object core;
	string msg, *list;
	int i, temp, sign;

	if( !living(this_player()) || this_player()->query_temp("noliving") )
		return 1;
	if( me->query("jing") < 0 || me->query("qi") < 0 )
		return notify_fail("��̫���ˣ�ʵ��û������ʲô�ˡ�\n");
	if( !this_object()->id( arg ) ) return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if( me->is_fighting() )
		me->start_busy(2);
	if( !query( "fruit_remaining" )  )
		return notify_fail("���������" + ob->name() + "�����˰�������޴����졣\n");
	if( (int)me->query("water") >= (int)me->max_food_capacity() ||
		(int)me->query("food") >= (int)me->max_water_capacity() )
	{
		if ( msg = query( "over_msg" ) ) notify_fail( msg );
		else notify_fail("����ô�ࣿ����̰�ģ�С�ĳ����ˡ���\n");
		return 0;
	}
	add( "fruit_remaining", -1);
	set( "value", 0);
	if ( query( "fruit_remaining" ) )
	{
		me->add("food" ,  query( "food_supply" ) );
		me->add( "water" , query( "water_supply" ) );

// hamlet���뷨��ʳ����츳��Ӱ�� (trill)
// ������food,fruit�ȼӸ�mapping gifts
// ������gifts��Ӱ��

		if ( gifts = query("gifts") )
		{
			list = keys( gifts );
			for( i = 0; i < sizeof( list ); i ++ )
			{
				me->add( "hamlet_food/" + list[ i ],
					query("gifts/" + list[ i ] ) );
				temp = me->query( "hamlet_food/" + list[ i ] );
				sign = ( temp > 0 ) ? 1 : -1 ;
				temp *= sign;
				if (temp >= 500  && random( 2000 - temp ) == 0 && me->query("age")<22)
				{
//������player���С<22���͸���������츳
//���� ֻӰ�������츳�� query_per()������..
//�����������̫�鷳���������Ƕ����������츳ʹ��û����ȷ�ĸ���
//�����ҾͰ������ĳ�������ˡ�����lala����������������������

//ԭ���Ľ������ԳԵ�30 30 35 35 ���츳 ����������
//-- qingyun 2004.10.13
//��������Ǳ��mud�İ�
//ԭ���ǽ����ڲ���Ѹ�ٽ�ʳ������ϣ���Ϊ��������ɳĮ
//���������ͬ�����츳��֪������ 
					if (me->query(list[i])>=30 )
						sign = 0;
					if (me->query("gift/hamlet/"+list[i])>0)
						sign=0;
					if (me->query(list[i])<10 )
						sign = 0;
					if (sign>0)
					{
						me->add("gift/hamlet/"+list[i],1);
						me->add( list[ i ] , sign );
						me->set( "hamlet_food/" + list[ i ], 0);
						tell_object( me, YEL"�������ճ�����ʳϰ�߶���������츳�ĸı䣡\n"NOR );
					}
				}
			}
		}
		if ( msg = query( "eat_msg" ) ) message_vision( msg, me, ob );
		else message_vision( RED"$N����$n���ݺݵ�ҧ�˼��ڣ����޵���ζ���ü��ˣ�\n" NOR, me, ob);
	}
	else
	{
//�Ե����һ�ھͱ�ɸ�ˮ����
		if ( msg = query ("end_msg" ) ) message_vision( msg , me, ob );
		else message_vision(RED"$N�������һ��$n�����������˵���治��\n", me,ob);
		if ( query("core") )
		{
			core = new( "/clone/misc/core.c" );
			core->set_name(query("core"), query("core_id") );
			if ( query("core_unit") )
				core->set("unit", query("core_unit"));
			else core->set("unit", query("unit") );
			if ( query("core_long") )
				core->set("long", query("core_long") );
			core->move( environment( this_object() ) );
		}
		remove_call_out( "stats" );
		destruct( this_object() );
	}
	return 1;
}

int stats( int i )
{
	string base_long, base_name;
	object core, env;
	int life;

//	if( !life = query( "life" )*240  ) return -1;
		if( !life = query( "life" )*20  ) return -1;

	switch ( i )
	{
		case 0:
			set("base_long", query("long") );
			set("base_name", query("name") );
			call_out("stats", life/4, 1);
			break;
		case 1:
			base_long = query("base_long");
			set("long",base_long+"�����������Щ�ߵ㣬�������������ۡ�\n");
			call_out("stats", life/4, 2);
			break;
		case 2:
			base_name = query("base_name");
			base_long = query("base_long");
			set("name","�е����˵�"+base_name );
			set("long",base_long+"����ϧ�Ѿ���ʼ���ˡ�\n");
			call_out("stats", life/4, 3);
			break;
		case 3:
			base_name = query("base_name");
			base_long = query("base_long");
			set("name", "��" + base_name );
			set("long",base_long+"����ϧ�Ѿ����ˣ�ɢ����һ����ζ��\n");
			call_out("stats", life/4, 4);
			break;
		default :
			if ( query("core") )
			{
				core = new( "/clone/misc/core.c" );
				core->set_name(query("core"), query("core_id"));
				if ( query("core_unit") )
					core->set("unit", query("core_unit"));
				else
					core->set("unit", query("unit") );
				if ( query("core_long") )
					core->set("long", query("core_long") );
				if ( env = environment( this_object() ) )
					core->move( env );
			}
			tell_room( environment(this_object()), this_object()->query("name")+"������ȫ�õ��ˡ�\n" );
			destruct( this_object() );
			break;
	}
	return i;
}
