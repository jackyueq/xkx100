// lingbo.c �����貨
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h>
inherit F_SSERVER;
#define PNAME "�����貨"
int perform(object me, object target)
{
	string msg;
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
	return notify_fail("��һ��������ô��\n");

	if( me->query("gender") == "����")
		return notify_fail(HIY "һ��������������������Ҳ���ߣ�\n" NOR);
	
	//���ֱ�������

	fskill = "beiming-shengong";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail(HIY"���"+to_chinese(fskill)+"��Ϊ������\n"NOR);

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail(HIY"���"+to_chinese(sskill)+"����������\n"NOR);

	if((int)me->query("neili") < 400)
		return notify_fail(HIY "�������������㡣\n" NOR);

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	if( me->query("gender") == "����")
	       {msg = HIC 
"$N�����������������������ʮ���ԣ�����$n��γ��У��Թ��ԵĽ�
�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�ֻ��$N��̬Ʈ�ݣ�Ӱ���ҷɣ�
$nȴ��һ��ƤëҲմ���ϡ�$N�������ң���ַ��ӵ����쾡����\n" NOR;}
	else   {msg = HIG 
"$N�����������������������ʮ���ԣ�����$n��γ��У��Թ��ԵĽ�
�貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�$N��������������΢���貨��
$nȴ��һ��ƤëҲմ���ϡ�$N�������ң���ַ��ӵ����쾡����\n" NOR;}

	if(
	(fam_type(me)=="xiaoyao" &&
	random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/4) ||
	(fam_type(me)!="xiaoyao" &&
	random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/3))
	{
		msg += HIW "���$p��$PΧ��ת��ͷ���ۻ���\n" NOR;
		target->start_busy( (int)me->query_skill(bskill, 1) / 30);
		me->add("neili", -100);
		me->start_busy(1);
	} else {
		msg += HIG "$pֻ����ǿ�����˿�ȥ��\n" NOR;
		me->add("neili", -100);
		me->start_busy(2);
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
		���ͶԷ�����

	����Ҫ��
		��ڤ��100��
		�貨΢��100��
		����400
		������̫��
HELP
	);
	return 1;
}

