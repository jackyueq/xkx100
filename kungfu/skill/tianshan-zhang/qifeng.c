// jianzhang.c  ��ɽ���
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "����ɽ��塹"
string *desc = ({
HIW"\n                  ^����������^          \n" NOR,
HIY  "                ^^^ɽ��������^^^       \n" NOR,
RED  "             ^^^^^^�ع�õ磡^^^^^^  \n" NOR,
HIM  "          ^^^^^^^^^���ӿ�����^^^^^^^^^ \n" NOR,
HIC  "       ^^^^^^^^^^^^��ɽѩ����^^^^^^^^^^^^ \n" NOR,
});
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,i;
        int staff_level;
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
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "huagong-dafa";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	msg = HIY "$Nʹ�������ɾ�������ɽ��塹������Ȼ�ӿ졣\n"NOR;
	message_combatd(msg,me,target);
  staff_level=me->query_skill(bskill);
  for (i=0;i<5;i++)
  {
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		msg = desc[i];
		message_combatd(msg,me,target);
		me->add_temp("apply/attack",staff_level/20);
		me->add_temp("apply/damage",staff_level/20);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
	}
	me->add_temp("apply/attack",-staff_level/20*i);
	me->add_temp("apply/damage",-staff_level/20*i);
	me->add("neili", -250);
	me->start_busy(3);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
        write(@HELP

        ʹ�ù�Ч��
                ������������

        ����Ҫ��
                ������100��
                ��ɽ�ȷ�100��
                ������Ϊ300
                ����500
HELP
        );
        return 1;
}