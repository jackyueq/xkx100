// chan.c ̫�������������־�

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�������־�"
int checking(object me, object target, object weapon);

string *number_msg = ({"һ","��","��","��","��","��","��","��","��","ʮ","ʮ��","ǧ��","����"});
string *sword_msg = ({"����","б��","����","�»�","����","ֱ��","����","ǰ��"});
string *chan_msg = ({
CYN"$N����Ԧ����$S����$R��"RED"ԲȦ"CYN"����ǧ���򻯣������޾���Ҫȥ������ס$n��\n" NOR,
CYN"$N����Ԧ����$S����$R��"RED"ԲȦ"CYN"��ǰ�����У�Ҫ��$n����������\n" NOR,
CYN"$N���в��������ң�����Ԧ����$W"CYN"ÿ��һ�У����Ʒų�һ��"RED"ϸ˿"CYN"��Ҫȥ��ס$n��\n"NOR,
CYN"$N����Ԧ����$S����$R��"RED"ԲȦ"CYN"�������ཻ��Ҫ��$n�������У�\n" NOR,
CYN"$N����$W"CYN"�Ӷ�����̫������ɢ��������"RED"ϸ˿"CYN"��Ҫ��$n��������\n"NOR,
CYN"$N����Ԧ����$S����$R��"RED"ԲȦ"CYN"�����°��ݣ�Ҫ��$n����������\n" NOR,
CYN"$N��һ��$W"CYN"����һ����"RED"ԲȦ"CYN"��ÿһ�о����Ի��δ̳����Ի����ջأ���ס$n��\n"NOR,
CYN"$N����Ԧ����$S����$R��"RED"ԲȦ"CYN"�����Ҽ�ˣ�Ҫ��$n�������У�\n" NOR,
});

string *dodged = ({
HIY"����$n��Ȼ������$P����������עһ��ֱ��Ȧ�ģ�����$N��̫�����⣡\n\n" NOR,
HIY"$n΢��$N����ɬ�ͣ���æ���У��߾�ȫ��֮���й��������ӽ���Ȧ�г��˳�ȥ��\n\n"NOR,
HIY"$n΢��$N����ɬ�ͣ���æ���У��߾�ȫ��֮����Ծ���ˣ�Զ���˽�Ȧ��\n\n"NOR,
HIY"$n�������У����е�����$N�й�һ������������һԾ�����ӳ�Ȧ�⡣\n\n"NOR,
});

string *chaned = ({
HIW"���$n����������ɬ�ͣ�ż������һ�У������˵ò��㣬�㱻$W"HIW"������ת����Ȧ�ӡ�\n"NOR,
HIW"���̫������ɢ������ϸ˿Խ��Խ�࣬���ǻ�����һ����˿�ޣ���$n��������������\n"NOR,
HIW"������������ǻ�����һ����˿�ޣ���$n��������������\n"NOR,
HIW"$nԽ��Խ�Ǻ��£�һ���������̫�������������������\n"NOR,
});

int perform(object me, object target)
{
	int cost;
	object weapon = me->query_temp("weapon");
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
		
	if(!weapon || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������ʹ�á������־���\n");

	if(me->query_temp("tjj/chan"))
		return notify_fail("������ʹ�á������־���\n");

	if( target->is_busy() )
		return notify_fail(target->name() +"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( me->query_skill_mapped("force") != fskill )
		return notify_fail("�����õ��ڹ���̫��������·��㣣�\n");

	if( me->query("neili") <= 500 )
		return notify_fail("�������������\n");

	if( me->query("max_neili") <= 700 )
		return notify_fail("���������Ϊ������\n");

	cost = me->query_skill(bskill, 1)/2;
	me->add("neili", -cost);

	message_combatd(CYN"\n$Nʹ��̫������"RED"������"CYN"�־���һ��"+weapon->name()+CYN"�ڻ���һ����ԲȦ��ÿһ�о����Ի��δ̳��������ջء�
���ڽ��ȣ����಻��������������һ�Ŵ���������$n�ս���\n\n"NOR, me, target);
	me->start_busy(1);
	me->set_temp("tjj/chan", 1);
	call_out("check_fight", 0, me, target, weapon);
	me->start_perform(1, "��");
	return 1;
}

int check_fight(object me, object target, object weapon)
{
	string msg;
	object wep;

	if (!me) return 1;
	if(!me->query_temp("tjj/chan")) return 1;

	if( !living(me) || me->query_temp("noliving") || !target)
	{
		me->delete_temp("tjj/chan");
		return 1;
	}
	
	if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword")
	{
		if(!wep)msg = HIY"$N����������ʧ��Բת��̫����ĻҲ��֮��ɢ��$n�������˿�����\n"NOR;
		else msg = HIY "$N����"+wep->name()+HIY"������̫�����⣬$n����ܲ��Ľ�ĻҲ��֮��ɢ��ѹ����Ȼ���ᣡ\n"NOR;
		if(target->is_busy()) target->start_busy(1);
		me->start_busy(1);
		me->delete_temp("tjj/chan");
		message_combatd(msg, me, target);
		return 1;
	} 
	if(environment(me) != environment(target))
	{
		msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��������ɢ����̫�����⡣\n"NOR;
		me->delete_temp("tjj/chan");
		message_combatd(msg, me, target);
		return 1;
	}
	if(!me->is_fighting(target) && !me->is_killing(target->query("id")))
	{
		if(!living(target) || target->query_temp("noliving") )
			msg = HIY"$N��м������$nһ�ۣ�������"+wep->name()+HIY"һ���ڣ�������ɢ���Ľ�Ļ��\n"NOR;
		else
			msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��������ɢ����̫�����⡣\n"NOR;
		if(target->is_busy()) target->start_busy(1);
		me->delete_temp("tjj/chan");
		message_combatd(msg, me, target);
		return 1;
	}

	if(wep != weapon)
	{
		message_combatd(HIY"$N���󻻽������ƶ�ʱ�޷�Բת���⣬$n��ߵ�̫����Ļ���������ʹ$n���˴�Ϣ֮���ᣡ\n"NOR,me, target);
		me->start_busy(1);
		if(target->is_busy() &&
			random(me->query_skill("sword", 1)) <
			(int)target->query_skill("dodge", 1)/2)
		{
		//	target->start_busy(1);
			me->delete_temp("tjj/chan");
			return 1;
		}
		else
		{
			call_out("checking", 1, me, target, wep);
			me->start_perform(1, "��");
		}
	}
	if (userp(me) &&
		(me->query_skill_mapped("sword") != "taiji-jian" ||
		me->query_skill_mapped("parry") != "taiji-jian"))
	{
		message_combatd(HIY"$NͻȻ���У����ƽ�Ļ��ʹ����̫��������ȫ��ͬ����������\n"NOR,me);
		if(target->is_busy()) target->start_busy(1);
		me->start_busy(1);
		me->delete_temp("tjj/chan");
		return 1;
	}
	if( me->query("neili") <= me->query_skill("sword", 1)/2 )
	{
		message_combatd(HIY"$N���н���ɬ�ͣ�ż��һ���̳���Ȼ����������ԭ�������������ˣ�\n"NOR,me);
		if(target->is_busy()) target->start_busy(1);
		me->start_busy(1);
		me->delete_temp("tjj/chan");
		return 1;
	}

	if(!target->is_busy() && !me->is_busy() && random(4)==1 &&
		living(target) && !target->query_temp("noliving") )
	{
		msg = chan_msg[random(sizeof(chan_msg))];
		msg = replace_string(msg, "$S", sword_msg[random(sizeof(sword_msg))]);
		msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
		msg = replace_string(msg, "$W", wep->name());
		message_combatd(msg, me, target);
		checking(me, target, wep);
	}
	else
	{
		call_out("check_fight", 1, me, target, wep);
		me->start_perform(1, "��");
	}
	return 1;
}

int checking(object me, object target, object weapon)
{
	string msg;
	int busy_time, ap, dp, cost;
	cost = 20 * target->query_temp("tjj/"+me->query("id")) + me->query_skill("sword", 1)/2;
	busy_time = (int)me->query_skill("sword", 1)/20;
	ap = me->query("combat_exp")/1000 * me->query_skill("sword",1) * me->query_int();
	dp = target->query("combat_exp")/1000 * target->query_skill("dodge",1) * target->query_int();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;

	me->add("neili", -cost);
	if(random(ap) > dp/2)
	{
		target->start_busy(2+random(busy_time));
		msg = chaned[random(sizeof(chaned))];
		msg = replace_string(msg, "$W", weapon->name());
		message_combatd(msg, me, target);
		call_out("check_fight", 1, me, target, weapon);
		me->start_perform(1, "��");
	}
	else
	{
		me->start_busy(3);
		me->delete_temp("tjj/chan");
		msg = dodged[random(sizeof(dodged))];
		msg = replace_string(msg, "$W", weapon->name());
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
		���ͶԷ�����

	����Ҫ��
		̫����100��
		̫������100��
		����500
		������Ϊ700
HELP
	);
	return 1;
}

