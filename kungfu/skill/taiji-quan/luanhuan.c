// luanhuan.c ̫��ȭ���һ�����
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "���һ�����"
int perform(object me, object target)
{
	string *circle, msg;
	int foo;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		//�������־���
		
	if( me->query("combat_exp") < 500000 )
		return notify_fail("��ʵս���鲻�㣬����ʹ�á��һ�������\n");

	fskill = "taiji-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷��˹��˵С�\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if( me->query_skill_mapped("force") != fskill )
		return notify_fail("�����õ��ڹ��롸�һ�������·��㣣�\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( userp(me) && !me->query_temp("taiji") && (int)me->query("jiali") )
		return notify_fail("���ⲻ������̫��Բת��ʹ�Ͼ�������������Ի�Ȧ��Բ��\n");
	}
	
	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("���������Ϊ�������޷��˹��˵С�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�����ڵ�����̫�����޷��˹��˵С�\n");

	if( (int)me->query("qi") < 200 )
		return notify_fail("�����ڵ�����̫����ÿһ�����԰������\n");

	if( (int)me->query("jing") < 200 )
		return notify_fail("�����ڵľ���̫����Ի�Բ��Ȧ��\n");

	circle = ({
		 "$N��˫����������������˫�ֳ�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ������",
		 "$N�����֡�ʹ��ʱ���಻�ϣ���������пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ������",
		 "$N�Ҽ�б��������ƾ�ջ��˼���Ȧ�ӡ�"
	});
	msg = WHT"\n"+ circle[random(sizeof(circle))] +"\n";
	me->receive_damage("jing", 50);
	me->receive_damage("qi", 50);

	foo = me->query_temp("taiji") ? 260 : 220;
	if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / foo )
	{
		msg += HIY"���$N�Ի���֮�����Ƶ�$n����$P������Ȧ�ڡ�\n"NOR;
		me->start_busy(1);
		call_out("zhen", 1, me, target); 
	}
	else
	{
		msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
		me->start_busy(1+random(2));
	}

	message_combatd(msg, me, target);

	return 1;
}

int zhen(object me, object target)
{
	int damage, tjsg, tjq, fooo;
	string *zhen, msg, result, str, type;

	if( !me->is_fighting(target) || !living(target) ) return 0;

	tjsg = (int)me->query_skill("force");
	tjq = (int)me->query_skill("unarmed");

	zhen = ({
		 "����$N˫��һȦһת��ʹ�������Ͼ����еġ��귭�����������������ѽ�$nȦס��",
		 "$N����ʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$n��ס��"
	});

	fooo = me->query_temp("taiji") ? 120 : 179;
	if( random(me->query_skill("taiji-quan", 1)) > fooo )
	{
		type = "����";
		msg = HIY"\nֻ��$N����������������Ŀ�����������ֱۣ�˫��������£������������ɽ��ȴ�����������������գ�ʹ������������ˮ�������ޱȣ�\n"NOR
		"$nֻ�����̸�·��ȫ����$P˫�Ƶ�����֮�£��޿����ܣ��޿ɵ�����\n";
	}
	else
	{
		type = "����";
		msg = "\n"+zhen[random(sizeof(zhen))] +"�漴Ǳ���񹦣���ͼ����������$p��\n";
	}

	if( target->query("neili") <= 0 )
	{
		msg += "$pֻ��ǿ���˾���$P�࿹��������Ȼ�����Լ�������Ȼ�ݽߺľ���\n";
		if( type == "����" )
			msg += RED "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		else 
			msg += RED "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n"NOR;

		target->receive_damage("qi", (int)target->query("qi")+1, me);
	}
	else if( random((tjq + tjsg) * me->query_int() / 100) >
		(target->query_skill("parry") + target->query_skill("dodge")) * target->query_int() / 200 )
	{
		me->start_busy(1+random(2));
		target->start_busy(3);
		
		damage = tjsg + tjq/2;		
		damage = damage/2 + random(damage);

		if( type == "����" )
			damage = damage + tjq/2;
		if( me->query("neili") > target->query("neili")*2 )
			damage = damage + tjsg/2; 

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);

		result = COMBAT_D->damage_msg(damage, type);
		result = replace_string( result, "$p", target->name() );
		msg += result;

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
	}
	else if( random(tjsg) > target->query_skill("force")/2 )
	{
		me->start_busy(1+random(2));
		target->start_busy(2+random(1));
		
		damage = (int)me->query_skill("taiji-shengong", 1);
		damage = damage/2 + random(damage);
		
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		me->add("neili", -damage/10);

		msg+= HIR"$pֻ��ǿ���˾���$N�࿹��";
		if( damage < 100 ) 
			msg += "����ܵ�$P�����������ƺ�һ����\n"NOR;
		else if( damage < 200 ) 
			msg += "�����$P���������𣬡��١���һ������������\n"NOR;
		else if( damage < 400 ) 
			msg += "�����$P������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
		else 
			msg += "�����$P������һ����ǰһ�ڣ��������ɳ�������\n"NOR;
	}
	else if( me->query("neili")*2 < target->query("neili") ) 
	{
		me->start_busy(3);
		target->start_busy(1+random(2));
		
		damage = (int)target->query_skill("force")/2;
		damage = damage/2 + random(damage);
		
		me->receive_damage("qi", damage, me);
		me->receive_wound("qi", damage/3, me);
		target->add("neili", -damage/10);
		
		if( damage < 100 ) 
			msg += HIY "����$P�ܵ�$p�����������ƺ�һ����\n"NOR;
		else if( damage < 200 ) 
			msg += HIY "����$P��$p���������𣬡��١���һ������������\n"NOR;
		else if( damage < 400 ) 
			msg += RED "����$P��$p�����������ؿ������ܵ�һ���ش�����������������\n"NOR;
		else 
			msg += HIR "����$P��$p������������ǰһ�ڣ��������ɳ�������\n"NOR;
	}
	else
	{
		me->start_busy(3);
		target->start_busy(3); 
		me->receive_damage("qi", 50);
		me->add("neili", -300);
		target->receive_damage("qi", 50);
		target->add("neili", -300);
		msg += HIY"$pֻ��ǿ���˾���$P�࿹���������Ӷ���һ�Σ������˿�������\n"NOR;
	} 

	message_combatd(msg, me, target);
	return 1;
}

/*
������$N˫��һ�ϣ�һ�С�˫����硹��˫ȭ����$n��������������һ���ྡྷ����������࣬���ʤ����
*/
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ

	����Ҫ��
		̫����150��
		̫��ȭ150��
		����500000
		������Ϊ2000
		����200
		��Ѫ200
		����200
		�����˼�����̫���ķ�
HELP
	);
	return 1;
}
