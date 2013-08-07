// guosc_mis.c
// �����س�����

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object room;
	object* ob_list;
	int i,stat;
		
	room = environment(me);

	me->apply_condition("guosc_mis", duration - 1 );
	if (me->query_temp("guosc_mis_flag"))
	{
		if (me->query_temp("guosc_mis_where")!=environment(me)->query("short"))
		{
			message_vision( HIY"һ���α��ܹ�����$N˵���������سǣ���ȴ�����й䣬��ȥ�����������\n"NOR,me);
		}
		else me->set_temp("guosc_mis_flag",2);
		if (me->query_temp("guosc_mis_flag")==2 && me->query_temp("guosc_mis_where")==environment(me)->query("short"))
		{
			switch( random(8) )
			{
				case 0:
					message_vision( HIY"$N��վ�ڳ�ǽ������ע���ų���"HIR"�ɹű�"HIY"��һ��һ����\n"NOR,me);
					break;
				case 1:
					message_vision(HIY"$Nָ��һ���α�ߺ���Ž�������ʯ�ӳ�ǽ�������������µ�"HIR"�ɹű�"HIY"һʱ���������˲��١�\n"NOR,me);
					break;
				case 2:
					message_vision(HIC"����һ�������죬�Ӽ�������������ʿ��������ɻȣ������"HIR"�ɹű�"HIC"�׷��м����¡�\n"NOR,me);
					break;
				case 3:
					message_vision(HIR"$N��У��Ż𡢷Ż𡣳�����������ȼ�ŵĻ�ѣ��ҽ����У��ɹŵ�ʿ���������ڡ�\n"NOR,me);
					break;
				case 4:
					message_vision(HIC"����һ���ŽǴ������ɹ����ӷ�������һ�ֵĹ��ƣ����м������£��سǵ��α����˲��١�\n"NOR,me);
					me->receive_wound("jing", 50+random(50));
					me->receive_damage("qi", 300+random(100));
					break;
				case 5:
					message_vision(HIR"$N���һ�������С�ġ������ɹű���Ͷʯ������������ʯ���ҽ����У����е��ر��������ڡ�\n"NOR,me);
					me->receive_wound("jing", 50+random(50));
					me->receive_damage("qi", 300+random(100));
					break;
				case 6:
					message_vision(HIR"�����α���У��Ż������Ż��������е��ɹż�ϸ���ؾ������Ĵ��Ż�һƬ�Ȼ����У����еľ�����ʧ���أ�\n"NOR,me);
					me->receive_wound("jing", 50+random(50));
					me->receive_damage("qi", 300+random(100));
					break;
				case 7:
					message_vision(HIR"$N��У�С�İ������ɹż�ϸ���ؾ�����������ٰ��������еľ�ʿһʱ���⣬����������͵Ϯ��\n"NOR,me);
					me->apply_condition("anqi_poison", 3+random(3));
					break;
				case 8:
					message_vision(HIY"�����ɹű�����һ�ּ��������سǵ��α���$N�Ĵ�����ȴ���з�����û���ܵ���ʧ��\n"NOR, me);
					break;
			}
		}
	}
	if(duration <1)
	{
		message_vision( CYN"\nһ���س��α��ܹ���˵�����ɹ�������ʱ�������ˣ�$N���Ի�ȥ�����ˣ�\n"NOR,me);
		if (me->query_temp("guosc_mis_flag"))
		{
			me->set_temp("guosc_mis_flag",3);
		}
		ob_list = children("/d/xiangyang/task/robber1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N̾���������ؾ����и���Э����������\n",ob_list[i]);	
			destruct(ob_list[i]);
                }
		ob_list = children("/d/xiangyang/task/robber2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        message_vision("$N̾���������ؾ����и���Э����������\n",ob_list[i]);    
                        destruct(ob_list[i]);
                }
		ob_list = children("/d/xiangyang/task/robber3");
                for(i=0; i<sizeof(ob_list); i++)
                if(environment(ob_list[i]))
                {
                        message_vision("$N̾���������ؾ����и���Э����������\n",ob_list[i]);
                        destruct(ob_list[i]);
                }

		return 0;
	}
	return 1;
}

string query_type(object me)
{
	return "job";
}

