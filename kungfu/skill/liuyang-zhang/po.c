#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#include <xiaoyao.h>

inherit F_SSERVER;
#define PNAME "��" HIR "�����" NOR "��"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp, p;
	int lv, cost_neili;
	int mark = 0;
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

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(PNAME "ֻ�ܿ���ʩչ��\n");

	fskill = "bahuang-gong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 200 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹�������ʩչ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����������ʩչ"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("���"+to_chinese(bskill)+"�ȼ�����������ʩչ"+PNAME+"��\n");

	if (userp(me) && (int)me->query("con", 1) < 20)
		return notify_fail("��������ǲ����ߣ�����ʩչ" PNAME "��\n");
		
	if (me->query("max_neili") < 3000)
		return notify_fail("���������Ϊ���㣬����ʩչ" PNAME "��\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("��û�м����˻�����Ψ�Ҷ��𹦣�����ʩչ" PNAME "��\n");

	if (me->query("neili") < 800)
		return notify_fail("�������������㣬����ʩչ" PNAME "��\n");

	msg = HIR "$N" HIR "���˻�����Ψ�Ҷ������������ޣ�ȫ�������ŷ�������һ��"
              "��$n" HIR "ͷ����Ȼ���䡣\n" NOR;

	ap = me->query_skill("force", 1) + me->query_skill(bskill);
	dp = target->query_skill("force", 1) + target->query_skill("parry");

	if (target->query("shen") * me->query("shen") < 0 ||  userp(target))
		ap += ap / 10;
	if (fam_type(me)=="lingjiu") ap += ap/5;

	if (ap /2 + random(ap) +10 > dp)
	{
		damage = 0;
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
                        msg += HIR "��ʱֻ�����ۡ���һ����$N" HIR "һ�ƽ�$n"
                               HIR "ͷ���ĵ÷��飬�Խ��Ľ�������̱����ȥ��\n"NOR;
			msg += "( $n" + eff_status_msg(0) + " )\n";

		 target->receive_wound("jing",target->query("eff_jing"),me);
		 target->receive_wound("qi",target->query("eff_qi"),me);
 		 me->add("neili", -100);
		 me->start_busy(1);
	 	 message_combatd(msg, me, target);
		 target->unconcious();
	 	 return 1;
		} else
		{
	 		me->add("neili", -300);
/*			damage = ap *2/3;
			damage += random(damage/2);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage *9/10, me);
			target->receive_damage("jing", damage / 4, me);
			target->receive_wound("jing", damage / 8, me);*/
			damage = ap;
			damage += random(damage);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage / 2, me);
			target->receive_damage("jing", damage / 4, me);
			target->receive_wound("jing", damage / 8, me);
			p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

			msg += HIR "$n" HIR "��æ�ֵ�������Ȼ������$N"
                               HIR "�ƾ����ˮ��ӿ�����ڣ������������"
                                   "�߹ǡ�\n"NOR;
			msg += "( $n" + eff_status_msg(p) + " )\n";
			
		}
		me->start_busy(3);
	} else
	{
		msg += CYN "$p" CYN "��$P" CYN "�ƾ����ȣ����Ƶֵ���"
                       "ס����������������������������\n" NOR;
		me->add("neili", -200);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˵о�����

	����Ҫ��
		�������20
		�˻�����Ψ�Ҷ���200��
		��ɽ��������200��
		�����Ʒ�200��
		�������3000
		����800
HELP
	);
	return 1;
}