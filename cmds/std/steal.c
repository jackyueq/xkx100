// steal.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim, thisroom;

	mapping myfam, vtfam;
	int sp, dp;
        thisroom = environment(me);

//	if(1==1)
//	return notify_fail("���ڲ������ԡ�\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("�����ֹ���ԡ�\n");

	if( environment(me)->query("no_steal"))
		return notify_fail("�����ֹ���ԡ�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( me->query_temp("stealing") )
		return notify_fail("���Ѿ����һ��������ˣ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
		return notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

 //       if(arg=="corpse"||arg=="skeleton")
 //               return notify_fail("͵ʲô͵��ֱ�Ӵ�ʬ�����þ����ˣ�\n");
	victim = present(who, environment(me));
	if( !victim || victim==me)
		return notify_fail("�������ԵĶ��������\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");
		
	if (userp(me) && victim->query("owner") && me->query("id") != victim->query("owner"))
			return notify_fail("����Դ������ԡ�\n");					

	if( victim->query("no_steal"))
		return notify_fail("����Դ������ԡ�\n");

	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail("��������㻹�õ���͵��\n"); 
	if(me->query("id") != victim->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("����Ϊ���죬ִ�й�������֪��������\n");
	notify_fail("������ͷ��С����������Ϊ�\n");
	if (!userp(victim) && !victim->accept_hit(me)) return 0;

	if( !ob = present(what, victim) )
	{
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲôֵǮ�Ķ�����͵��\n");
		ob = inv[random(sizeof(inv))];
	}

	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail(victim->name() + "�����ǻ����ֱ��ȡ(get)�����ˡ�\n"); 

	sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
		- (int)me->query("thief") * 20;

	if ( (myfam = me->query("family")) && myfam["family_name"] == "ؤ��" )
		sp = (int)me->query_skill("stealing")*10+(int)me->query("kar")*5
			- (int)me->query("thief") * 20;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() )
	{
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("�㲻����ɫ����������"+victim->name()+"���ȴ��������� ...\n\n");

        thisroom->set_temp("no_sleep",1);
        me->start_busy(2);
	me->set_temp("stealing", 1);
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp,int dp)
{
	mapping myfam, vtfam;
	int steal_level;
	me->delete_temp("stealing");

	if( environment(victim) != environment(me) )
	{
		tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
		return;
	}

	if( !living(victim) || victim->query_temp("noliving") ||
		(random(sp+dp) > dp) )
	{
		if( !present(ob, victim) )
		{
			tell_object(me,"�����˰���û�����Լ�Ҫ͵�Ķ����������Է��Ѿ��Ѷ���ת���ˣ�\n");
			return;
		}
		if( ob->query("no_steal") )
		{
			tell_object(me,"������һ"+ob->query("unit")+ob->name()
			+ "��������ͻȻ�������飬��Ȼ�������֣����ǿ�ϧ�ˡ�\n");
			return;
		}
		if( ob->query_temp("is_rided_by") )
		{
			tell_object(me,"������һ"+ob->query("unit")+ob->name()
			+ "�������㷢�������˼ҵ�������ǿ�ϧ�ˡ�\n");
			return;
		}
		if( !ob->move(me) )
		{
			tell_object(me,"������һ"+ob->query("unit")+ob->name()
			+ "�����Ƕ������̫���ˣ����ò�������\n");
			return;
		}

		tell_object(me, HIW "�����ˣ�\n\n" NOR);
		tell_object(me, "��ɹ���͵��һ"+ob->query("unit")+ob->name() + "��\n");
		steal_level = (int)me->query_skill("stealing",1);

		if( living(victim) && !victim->query_temp("noliving") )
		{
			if ((int)me->query("combat_exp") >
				(steal_level*steal_level*steal_level/10) )
			{
				me->improve_skill("stealing", random(me->query("int")));
			}
			else
			{
				tell_object(me," ����㾭��ҲҪȥ͵�� \n");
			}
			if ( (myfam = me->query("family")) &&
				myfam["family_name"] == "ؤ��" )
			{
//add by Java. Nov 16.1997
				me->start_busy(2);
				me->add("thief", 1);
				me->receive_damage("jing", 10);
				me->receive_wound("jing", 4);
				me->add("combat_exp",1);
				if( random(5) == 1) me->add("potential",1);
				
			}
		}

		if( random(sp) < dp/2 )
			message("vision", "�㿴��" + me->name() + "�������ش�"
			+ victim->name() + "����͵����һ" + ob->query("unit")
			+ ob->name()+"��\n", environment(me),({ me, victim }));
	}
	else
	{
		if( random(sp) > dp/2 )
		{
			tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n���ã�û�б����֡�\n");
			return;
		}
		tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
		message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n" + "$N�ȵ�������ʲô����\n\n", victim, me);
		me->improve_skill("stealing", 1, 1);

		me->delete("env/combatd");
		victim->delete("env/combatd");

		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(3);
		me->add("thief", 1);
		me->receive_damage("jing", 10);
		me->receive_wound("jing", 4);
	}
environment(me)->delete_temp("no_sleep");
}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

    ���ָ�������л���͵���������ϵĶ������ɹ��ˣ���Ȼ����ܻ�
�ø�����Ʒ�����ǣ�����ʧ�㣬������ʧ���ʱ�򣬵���ʧ��ʱ��Ȼ��
�ø������ۣ�������ʲô����......�����Լ�ȥ�����ޡ�
HELP
	);
	return 1;
}

