//duan.c ��������֮������ն��
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>
#define PNAME "������ն��"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
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
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("���"+to_chinese(fskill)+"��ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 70 )
		return notify_fail("���"+to_chinese(sskill)+"������ʹ����"+PNAME+"��\n");
	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");
	me->add("neili", -200);
msg = HIC"$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (!target->is_busy())
		target->start_busy( (int)me->query_skill(bskill) / 30);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
                me->start_busy(1);
		msg += RED "ֻ��$n��$Nһ�����У���ǰ�ѿ�һ��������˿ڣ�Ѫ��������������\n"NOR;
	} else {
		msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
	        me->start_busy(1+random(2));
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
		���˶Է���Ѫ
		���ͶԷ�����

	����Ҫ��
		��������70��
		���Ƹ�70��
		����400
HELP
	);
	return 1;
}

