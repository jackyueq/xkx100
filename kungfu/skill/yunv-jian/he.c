// he.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include <combat.h>;
inherit F_SSERVER;
#define PNAME "��˫����赣�"
int perform(object me, object target)
{
	string msg;
	int skl_me, skl_you, extra_me, extra_you, i, damage;
	int FLAG=0;
	object you,ob,*obs,weapon;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
 		return notify_fail("��ʹ�õ��������ԡ�\n");

        if(me->query("neili")<400)
                return notify_fail("�����������ʹ��˫����赣�\n");

	fskill = "yunv-xinfa";
	bskill = "sword";
	pskill = "quanzhen-jian";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "shenyuan-gong";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"������죬������"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬������"+PNAME+"��\n");

	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0;continue;}
			if(environment(obs[i]) != environment(me))
				{FLAG=0;continue;}
			if(!obs[i]->query_skill("quanzhen-jian"))
				{FLAG=0;continue;}
			if(obs[i]->query_skill("quanzhen-jian",1) < 100)
				{FLAG=0;continue;}
			if(obs[i]->query("neili") < 400)
			  {FLAG=0;continue;}
			if (!objectp(ob = obs[i]->query_temp("weapon"))
				|| (string)ob->query("skill_type") != "sword")
				{FLAG=0;continue;}
			if(obs[i]->query_skill_mapped("sword")!="quanzhen-jian")
				{FLAG=0;continue;}
		}
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
	if(FLAG)
	{
//		if(target->query("owner"))
//			return notify_fail("�����������ɼٱ���֮����ɡ�\n");
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	  if(me->query("gender")!="Ů��" || you->query("gender")!="����")
		return notify_fail("˫����赱���Ůʹ��Ů������ͬʱ��ʹȫ�潣�����ܼ�����\n");
  	if(!userp(target))
		if (!target->accept_hit(me) || !target->accept_hit(you))
			return notify_fail("�����������ɼٱ���֮����ɡ�\n");
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
		msg = HIY + "$Nʩչ����Ů�������ն������" + HIG + you->name()+"ʩչ��ȫ�潣�����������У�\n" + HIR +
		 "˫����赣�������ʱ��þ��ˣ�$n�޷��뵲˫�����̣����ἱ�ˣ����������������������У�\n"NOR;

		message_combatd(msg, me, target);
		me->add_temp("apply/attack",(skl_you+skl_me)/5);
		me->add_temp("apply/damage",(extra_you+extra_me));
		you->add_temp("apply/attack",(skl_you+skl_me)/5);
		you->add_temp("apply/damage",(extra_you+extra_me));
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
		COMBAT_D->do_attack(you,target, you->query_temp("weapon"), TYPE_REGULAR,msg);
		you->add_temp("apply/attack",-(skl_you+skl_me)/5);
		you->add_temp("apply/damage",-(extra_you+extra_me));
		me->add("neili",-300);
		you->add("neili",-300);
		me->add_temp("apply/attack",-(skl_you+skl_me)/5);
		me->add_temp("apply/damage",-(extra_you+extra_me));
//		you->kill_ob(target);
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
		if( (int)me->query("neili") < 350 )
			return notify_fail("����������㣬�޷�ʹ��˫���ϱڡ�\n");
		if( (int)me->query_skill(pskill, 1) < 100 )
			return notify_fail("���ȫ�潣��������죬����ʹ��˫����赡�\n");
		if( (int)me->query_skill("hubo", 1) < 100 )
			return notify_fail("���˫�ֻ���������죬����һ�˶�ʹ˫����赡�\n");
		msg = HIY "$N���ִ���ȫ�潣�����⣬����"+weapon->name()+HIY"����Ů������ʽ��˫ʽ���ͬʱ�̳���\n"NOR;
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
			damage = (int)me->query_skill("yunv-jian", 1) + (int)me->query_skill("quanzhen-jian",1);
			damage = damage + (int)me->query_skill("force",1) ;
			//(��Ů����+ȫ�潣������+�����ڹ�)
			damage = damage/2 + random(damage);
			target->receive_wound("qi", damage);
			target->start_busy(random(4));
			me->start_busy(2+random(2));
			me->add("neili", -350);

			msg += HIR "$n"HIR"����$N"HIR"���з��裬��ʽ������������Ϊ��һ���в�ȥ������֪����Ǻã�\n"NOR;
			msg += HIR "һ��֮�£�$N"HIR"�Ľ����Ѿ���ʽ���룡\n"NOR;
		}
		else
		{
			me->start_busy(3);
			msg += CYN"����$p������$P����ͼ�����Լ���ȫ�����»����ܲ�͸�磬��$P�޼ƿ�ʩ��\n"NOR;
		}
		message_combatd(msg, me, target);
	}	
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���������������ͷ���������ͬ����һ��
		���û�л�飬����100�����һ������ܳ���

	����Ҫ��
		Ů��
		��Ů�ķ�100��
		��Ů����100��
		����100
	���Ҫ��
		����
		��������100��
		ȫ�潣��100��
		����100
HELP
	);
	return 1;
}

