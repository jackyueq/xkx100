// Last Modified by winder on May. 29 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���׶����졹"
int perform(object me, object target)
{
	object weapon;
	int damage, club;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/		
	if( !objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("skill_type") != "club" )
		return notify_fail("�������޹����������á��׶����졹����\n");

	if( me->query_temp("sl_leidong") )
		return notify_fail("���ʹ�꡸�׶����졹��Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

	fskill = "yijinjing";
	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ���δ����ʩչֻ���˼�����\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������δ������"+PNAME+"��\n");

	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("�����õ��ڹ���"PNAME"�ķ���㣣�\n");

	if( (int)me->query_str() <=30 )
		return notify_fail("������������޷�ʹ��"PNAME"��\n");

	if( me->query("max_neili") <= 2000 )
		return notify_fail("���������Ϊ���㣬����������ʩչ"PNAME"��\n");

	if( me->query("neili") <= 600 )
		return notify_fail("�����������������������ʩչ"PNAME"��\n");

	message_combatd(BLU"\nͻȻ$N"BLU"���һ�������׶����졹����ɫ৵ı��ͨ�죬�뷢�Էɣ���������"+weapon->name()+BLU"���У����ˡ���һ��������"HIW "��������"BLU"��\n" NOR, me);
	damage = me->query_skill(bskill, 1)+me->query_skill("force", 1);
	damage /= 6;
	club = me->query_skill(bskill)/3;
	if ( userp(me) )
	{
		me->add("neili", -300);
		if ( damage > weapon->query("weapon_prop/damage") * 2)
			damage = weapon->query("weapon_prop/damage") * 2;
		else weapon->add("rigidity", 1);
	}
	me->set_temp("sl_leidong", 1); 
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);
	call_out("remove_effect1", club/2, me, weapon, damage);
	call_out("remove_effect2", club*2/3, me);
	return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
	if (!me) return;
	me->add_temp("apply/attack", -damage);  
	if (!weapon)
	{
		me->set_temp("apply/damage", 0);
		return;
	}
	me->add_temp("apply/damage", -damage);
	message_combatd(HIY"\n$Nһ�ס��׶����졹ʹ�꣬����"NOR+weapon->name()+HIY"�ϵĹ�â����Ҳ��ʧ�ˡ�\n"NOR, me);		
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("sl_leidong");
	tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á��׶����졹�ˡ�\n"NOR); 
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��������˺���

	����Ҫ��
		�׽150��
		Τ����150��
		��������30
		������Ϊ2000
		����600
HELP
	);
	return 1;
}

