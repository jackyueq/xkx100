// sanqing.c һ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define PNAME "��������"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int extra;
	int count;
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
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail(PNAME"����ʹ�����֣�\n");

	fskill = "linji-zhuang";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("���"+to_chinese(fskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

	extra = me->query_skill(sskill,1) *2/ 15;
 
        msg = HIY "$Nʹ���ط��������������������������һ���������������е�"+ weapon->name()+  HIY"����㹥����һ����\n" NOR;
        message_combatd(msg, me);

        me->add_temp("apply/attack", extra*4);

        msg = HIC "ֻ��$N����һ����"+ weapon->name()+ HIC"����$n"HIC"����磡" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "��һ������"HIR"����$n"HIR"����$n"HIR"ֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
        message_combatd(msg, me, target);
        target->start_busy(2);
        }
        msg =  HIW "$N���һ����"+ weapon->name()+ HIW"����$n"HIW"���Ҽ磡" NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "�ڶ�������"HIM"ɨ��$n"HIM"������,$n"HIM"ֻ����ȫ��һ��ʹ��\n"NOR;   
                message_combatd(msg, me, target);
        target->receive_damage("jing",extra*2,me);
        target->receive_wound("jing",extra*2,me);
        }
        msg = HIY "$N��Хһ�����۹��������֣�ʹ����������߾���--��������$n"HIY"����ǰ��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "���һ������"HIB"ɨ��$n"HIB"������Ѩ,$n"HIB"ֻ����ȫ�������᲻�����ˣ�\n"NOR;   
        message_combatd(msg, me, target);
        target->add("neili",-extra*4);
        }
        me->add("neili", -300);
        me->add_temp("apply/attack", - extra*4);
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
		�ֱ���˫�����Ṧ���ڹ����书��Ϊ

	����Ҫ��
		�ټ�ʮ��ׯ80��
		�ط������100��
		����300
HELP
	);
	return 1;
}
