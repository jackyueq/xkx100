//  tianditongshou ���ͬ��
// Last Modified by Winder on Feb. 18 2001

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "�����ͬ�١�"
int perform(object me, object target)
{
	object weapon;
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

		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ûװ��������ʹ�����ͬ�١���\n"NOR);

		if( !me->query("wudang/yinliting_teach") )
			return notify_fail("��δ������ͤ���ڣ�����ʹ�����ͬ�١�\n");

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

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"����Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_dex() < 30 )
		return notify_fail("�����̫�ͣ�����ʹ�����ͬ�١�\n");

	if( (int)me->query("neili") > 100 || (int)me->query("qi") > 200 )
		return notify_fail("���ͬ����ƴ�����������������ʹ�ã���\n");

	message_combatd(RED"\n$N"RED"��Ȼ����һ�н���$n"RED"��ǰ��ͻȻ��ת���У����ƽ����е��������Լ�\n��С����ȥ����ͼ��$n"RED"ƴ����ʯ��١�\n\n"NOR, me, target);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4
		&& me->query_dex() > (int)target->query_dex()/2)
	{
		message_combatd(HIR"\n$n"HIR"������׺����������ŵ�ȫ���������������������$N"HIR"���е���������\n����С�������ֱ�Ӷ�����$n"HIR"�����壡\n"NOR, me, target);
		tell_object(target, HIR"��о�һ���������Լ����崩�����������˼��㣡\n" NOR);
		me->add("max_neili",-100);
		me->set_temp("last_damage_from", "ʹ�����ͬ�ٺ�"+target->name()+"ͬ���ھ�");
		me->receive_wound("qi", me->query("max_qi") + 200,target);
		target->set_temp("last_damage_from", "��"+me->name()+"ʹ�����ͬ��ɱ");
		target->receive_wound("qi", target->query("max_qi") + 200,me);
		target->start_busy(3 + random(3));
		me->start_busy(3 + random(3));
		target->die();
		me->die();
	}
	else 
	{
		target->start_busy(3 + random(3));
		message_combatd(HIY"\n$n��ǧ��һ��֮�ʣ���æ�ƿ�$N�����Ϸ�����ǿ�ܿ����У����ѱ��ŵ�Ŀ�ɿڴ���\n"NOR, me, target);
		me->add("max_neili",-50);
		me->set_temp("last_damage_from", "ʹ�����ͬ��");
		me->receive_wound("qi", me->query("max_qi") + 200,target);
		me->die();
	}
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		ƴȴһ����������������
		ʹ�����������ˣ����á��貫��һ�����ַ�Ϊ����

	����Ҫ��
		���ǽ���120��
		̫����120��
		������30
		����500
		������ͤ����
HELP
	);
	return 1;
}

