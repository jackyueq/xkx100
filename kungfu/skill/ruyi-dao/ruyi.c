// ruyi.c ����������
// Last Modified by winder on Oct. 28 2000

#include <ansi.h>
#define PNAME "��������������"
#include <combat.h>
#include <xiaoyao.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;
	int extra;

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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail(HIY "������õ�����ʩչ��\n" NOR);

	fskill = "beiming-shengong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");
	if((int)me->query("neili") < 400)
		return notify_fail(HIY "�������������㡣\n" HIY);

	extra = me->query_skill("ruyi-dao",1)/6;
	if (fam_type(me)=="xiaoyao")	extra *= 2;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        me->add("neili", -200);
        
        msg = HIY "$Nһ����Ц��ֻ���������⣬�������أ��Ĺ�ʲô�Ƿ����裬����һ��������"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIB"$N�������������δ������������һ����"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR"$N���浶ת��˳������һ����"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIW"$N������ת������һ���ֻ�ת������"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->start_busy(1);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��������

	����Ҫ��
		���⵶60��
		��ڤ��60��
		����400
HELP
	);
	return 1;
}

