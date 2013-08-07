// biyan.c ������֮����
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "�����桹"

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object ob;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ��"PNAME"��\n");	

	fskill = "huagong-dafa";
	bskill = "strike";
	pskill = "poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "douzhuan-xingyi";
	}
	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("�㷢���Լ���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"���й�����\n");
	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");
	if(me->query_temp("pfm_chousui"))
		return notify_fail("������������ѽ��й�����\n");
	if((int)me->query_skill(pskill,1) < 60)
		return notify_fail("�㷢���Լ����ھ۶��������޷�ʹ��"PNAME"���й�����\n");	 
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("�㷢���Լ����õ��ڹ��޷�����"PNAME"������\n");

	if( (int)me->query("max_neili") < 500)
		return notify_fail("�㷢���Լ�����̫�����޷�����"PNAME"���й�����\n");
	if((int)me->query("neili") < 300)
		return notify_fail("�㷢���Լ���������̫����ʹ����"PNAME"���й�����\n");	   
	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
			return notify_fail("û�л����ô����"PNAME"���й�����\n");
	  message_combatd(HIR"\n$Nҧ��ָ�⣬������Ѫ�䵽���棬��������һ�ģ����һ��ȼ��һ�����ܻ��棡\n"NOR,me);
	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(HIC"\n$N����ָ��"HIR"���"HIC"��Ĭ��������ע���Ż��棬���ư��أ������૵Ĳ�֪˵Щʲô������\n"NOR,me);
	me->start_busy(1);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 2, me, target, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;

	if(!me) return 0;
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");

	me->delete_temp("pfm_chousui");
	if ( !living(me) || me->query_temp("noliving") ||
		me->is_ghost()) return 1;

	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) || environment(me)!=environment(target) ||
  	  !living(target) || target->query_temp("noliving") )
	{
		message_combatd(HIY"$N�����������ջأ�ɢ����Ϣ��˫���´�������\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N�ۿ����Ϩ�𣬳�̾һ��ɢ����Ϣ��˫���´�������\n"NOR,me);
		return 1;
	}
	if(target->query_condition("xx_poison") > 100)
	{
		tell_object(me,"�Է��Ѿ����������綾���㲻���ٽ��С����桹�����ˡ�\n");	   
		return 1;
	}
	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry", 1) * target->query_dex();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -200);
	me->receive_damage("jing", 25);

	msg = HIC"\nȻ��$NͻȻ˫����ǰƽƽ�Ƴ�������"RED"����"HIC"΢΢���������£��³�һ��"GRN"����"HIC"������$n��$l��\n"NOR;	
	if(random(ap) > dp/3)//2
	{
		damage = random(i)*2+me->query("jiali")*2;
		if(neili > target->query("neili")*2) damage = damage*2;
		if(damage > 700) damage = 700;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		target->apply_condition("xx_poison",  (me->query_skill("poison", 1)/2) + target->query_condition("xx_poison"));
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		me->start_busy(1);
		target->start_busy(1);
	}
	else	
	{
		me->start_busy(2);
		msg += HIY"\n$pȫ�����һ��һ����������ֵرܿ����Ǽ��ٶ�����$w"HIY"��\n" NOR;
	}       
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", GRN"����"NOR);
	message_combatd(msg, me, target);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˺��Է���Ѫ
		ʹ���������޶�

	����Ҫ��
		������80��
		������80��
		��������60
		������Ϊ500
		����300
		��Χ�л��
HELP
	);
	return 1;
}

