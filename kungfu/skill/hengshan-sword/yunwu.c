// yunwu.c ��ɽ���� �ٱ�ǧ�ú�ɽ����ʮ��ʽ
// Last Modified by ahda on Sep.1 2001

#include <ansi.h>
#define PNAME "��ɽ����ʮ��ʽ"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int qi_wound;
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
		return  notify_fail("��Ҫ��˭ʹ����һ������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");		

	if( target->is_busy()||target->query("id")=="gongping zi")
		return notify_fail(target->name()+ "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	if( userp(me) && (me->query("family/master_id") != "mo da") )
		return notify_fail("�㲻��Ī��ĵ��ӣ�����ʹ�þ��У�\n");

	fskill = "huiyan-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("���"+to_chinese(fskill)+"�Ĺ�����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("���"+to_chinese(bskill)+"����������ʵ��Ŀǰ������ʹ��"+PNAME+"��\n");

	if((int)me->query_str() < 40)
		return notify_fail("����������,����ʹ����һ������\n");

	if((int)me->query("neili") < 500)
		return notify_fail("���������ڲ���������ʹ��"PNAME"��\n");

	if((int)me->query("max_neili") < 2500)
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�ú�ɽ����ʮ��ʽ��\n");


	msg = HIC"$N����"+weapon->name()+"���ⶸ�����͵ط��̣�ֱָ$n"HIC"�ؿڡ�
��һ�³��п켫������������ã����ǡ��ٱ�ǧ�ú�ɽ����ʮ��ʽ���еľ��У�\n";

	if(random(me->query("combat_exp")/3) > (int)target->query("combat_exp")/4)
	{                                             
		msg += HIY "$p��֮�£�������ˣ��͵�һ�����ؿ��Ѹ���������һ�������Ŀ��ӣ�\n�������ѣ��ؿڼ���Ҳ�������ˣ�������Ȼ���أ�ȴ�Ѿ�ŭ������������ʧ��\n"+ HIR "$Pһ����ռ�Ȼ����������������һ�������������ߣ�����������������ȣ�\nһ�����Ѫ�ӳ����佦�˳�����\n" NOR;
		qi_wound = (int)target->query("max_qi",1);
		target->receive_damage("qi", qi_wound/2,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
		me->start_busy(3);
		me->add("neili", -500);
	}
	else
	{
		msg += HIM "����$p������$P����ͼ��������������������ض㿪��$P��һ����\n" NOR;
		me->start_busy(3);
		me->add("neili", -200);
	}
	message_combatd(msg, me, target);
	if(!target->is_killing(me)) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP
	
	ʹ�ù�Ч��
		�������˶Է���Ѫ
	
	����Ҫ��
		�����ķ�180��
		��ɽ����200��
		��������200��
		����2500
		��������40
HELP
	);
	return 1;
}

