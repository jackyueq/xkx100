#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";


inherit F_SSERVER;
#define PNAME "��" HIR "������" NOR "��"
#include <xiaoyao.h>
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

	fskill = "beiming-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 250 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹�������ʩչ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����������ʩչ"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("���"+to_chinese(bskill)+"�ȼ�����������ʩչ"+PNAME+"��\n");

	if (userp(me) && (int)me->query("dex", 1) < 20)
		return notify_fail("������������������ʩչ" PNAME "��\n");
		
	if (me->query("max_neili") < 4000)
		return notify_fail("���������Ϊ���㣬����ʩչ" PNAME "��\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("��û�м�����ڤ�񹦣�����ʩչ" PNAME "��\n");

	if (me->query("neili") < 800)
		return notify_fail("�������������㣬����ʩչ" PNAME "��\n");

    msg = HIM "$N" HIM "��������һ���������ֻӳ�����Ե��ʱϼ�����������"
	      "��ɫ�����$n" HIM "ϯ�������\n" NOR;

	ap = me->query_skill("dodge", 1) + me->query_skill(bskill);
	dp = target->query_skill("dodge", 1) + target->query_skill("parry");

	if (target->query("shen") * me->query("shen") < 0 ||  userp(target))
		ap += ap / 10;

	if (ap * 2 / 3 + random(ap) +10 > dp)
	{
		damage = 0;
		lv = me->query_skill(sskill, 1);
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
			msg += HIM "ֻ��$n" HIM "һ����Х��$N" HIM "����ɫ��"
			       "���Ѿ���ע��$p" HIM "���ڣ���ʱ��$p" HIM "��"
			       "Ϊһ̲Ѫˮ��\n" NOR ;
			msg += "( $n" + eff_status_msg(0) + " )\n";

		 target->receive_wound("jing",target->query("eff_jing"),me);
		 target->receive_wound("qi",target->query("eff_qi"),me);
		 me->start_busy(1);
		 me->add("neili",-100);
		 message_combatd(msg, me, target);
		 target->unconcious();
		 return 1;
		} else
		{
			damage = ap;
			damage += random(damage);

			target->receive_damage("qi", damage, me);
			if (fam_type(me)=="xiaoyao")
			{
				target->receive_wound("qi", damage / 2, me);
				target->receive_damage("jing", damage / 4, me);
				target->receive_wound("jing", damage / 8, me);
			}
			me->add("neili",-1 * (damage /3+50));
			p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

			msg += HIM "$n" HIM "ֻ��΢΢һ㶣�$N" HIM "����ɫ�ƾ��������"
			       "�룬$p" HIM "���������ú�¯һ�㣬��Ż������Ѫ��\n" NOR;
			msg += "( $n" + eff_status_msg(p) + " )\n";
			
			me->start_busy(3);
		}
	} else
	{
		msg += CYN "$p" CYN "��״��ʧɫ����ȫ���Ʋ�͸$P"
		       CYN "���а��أ���������Ծ����������������\n" NOR;
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
		������20
		��ڤ��250��
		��ɽ��÷��200��
		�����ַ�200��
		�������4000
		����800
HELP
	);
	return 1;
}