// he.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include <combat.h>;
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int skl_me, skl_you, extra_me, extra_you, i, damage;
	int FLAG=0;
	object you,ob,*obs,weapon;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/he") &&
  !me->query("can_perform/quanzhen-jian/he") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("��˫����赣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
        if(me->query("neili")<400)
                return notify_fail("�����������ʹ��˫����赡�\n");
	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("xiantian-qigong", 1) < 100 )
			return notify_fail("�����������������죬������˫����赡�\n");
		if( (int)me->query_skill("quanzhen-jian", 1) < 100 )
			return notify_fail("���ȫ�潣��������죬������˫����赡�\n");
	}
	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0;continue;}
			if(environment(obs[i]) != environment(me))
				{FLAG=0;continue;}
			if(obs[i]->query("neili") < 400)
				{FLAG=0;continue;}
			if(!obs[i]->query_skill("yunv-jian"))
				{FLAG=0;continue;}
			if(obs[i]->query_skill("yunv-jian",1) < 100)
				{FLAG=0;continue;}
			if(obs[i]->query_skill("yunv-xinfa",1) < 100)
				{FLAG=0;continue;}
			if (!objectp(ob = obs[i]->query_temp("weapon"))
				|| (string)ob->query("skill_type") != "sword")
				{FLAG=0;continue;}
			if(obs[i]->query_skill_mapped("sword")!="yunv-jian")
				{FLAG=0;continue;}
			if(obs[i]->is_busy())
				{FLAG=0;continue;}
		}
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
	if(FLAG)
	{
	if(obs[0]==me) you=obs[1]; else you=obs[0];
	if(me->query("gender")!="����" || you->query("gender")!="Ů��")
		return notify_fail("˫����赱�����ʹȫ�潣����ͬʱŮʹ��Ů�������ܼ�����\n");
  	if(!userp(target))
		if (!target->accept_hit(me) || !target->accept_hit(you))
			return notify_fail("�����������ɼٱ���֮����ɡ�\n");
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
		msg = HIY + "$Nʩչ��ȫ�潣�����������У�" + HIG + you->name()+"ʩչ����Ů�������ն������\n" + HIR +
		 "˫����赣�������ʱ��þ��ˣ�$n�޷��뵲˫�����̣����ἱ�ˣ����������������������У�\n"NOR ;

		message_combatd(msg, me, target);
		me->add_temp("apply/attack",(skl_you+skl_me)/5);
		me->add_temp("apply/damage",(extra_you+extra_me));
		you->add_temp("apply/attack",(skl_you+skl_me)/5);
		you->add_temp("apply/damage",(extra_you+extra_me));
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
		COMBAT_D->do_attack(you,target, you->query_temp("weapon"), TYPE_REGULAR,msg);
		you->add_temp("apply/attack",-(skl_you+skl_me)/5);
		you->add_temp("apply/damage",-(extra_you+extra_me));
                you->add("neili",-300);
                me->add("neili",-300);
		me->add_temp("apply/attack",-(skl_you+skl_me)/5);
		me->add_temp("apply/damage",-(extra_you+extra_me));
		me->start_busy(2+random(2));
		you->start_busy(2+random(2));
    if (target->query("qi") > 0 && target->query("jing") > 0)
    {
    	msg = HIC"����$n���ܵ��ˣ��������в�ӹ���ֻ���������·��������ų���һ���亹��\n"NOR;
			message_combatd(msg, me, target);
		}
	}
	else
	{
//		msg =HIY"$N"+HIG"����"HIY+you->name()+HIG"ʩչ˫����赣�������û��������ϡ�\n" + NOR;
		msg =HIY"$N��ʩչ˫����赣�����û�к��ʵ���һ����ϡ�\n" + NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}
int help(object me)
{
	write(WHT"\nȫ�潣��֮˫�����"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���������������ͷ���������ͬ����һ��

	����Ҫ��
		����
		��������100��
		ȫ�潣��100��
		����100
	���Ҫ��
		Ů��
		��Ů�ķ�100��
		��Ů����100��
		����100
HELP
	);
	return 1;
}

