// fumo.c ����ȭ perform ��շ�ħ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "����շ�ħ��"
int perform(object me, string arg)
{
	object target;
	string msg;				   
	int i,z;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ��"PNAME"��\n");

	fskill = "yijinjing";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if(me->query_skill_mapped("force") != fskill)
			return notify_fail("��û������"+to_chinese(fskill)+"�ڹ����޷�ʹ��"PNAME"���й�����\n"); 

	if(me->query_temp("fenxin"))
		return notify_fail("����������ʹ�÷��ľ�����������"PNAME"��\n"); 
	if( (int)me->query_str() < 28 )
		return notify_fail("��ı�������ǿ������ʹ��"PNAME"��\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫��������ʹ��"PNAME"��\n");
	if( (int)me->query("neili") < 700 )
		return notify_fail("�������̫�٣��޷�ʹ�ó�"PNAME"��\n");
	if( me->query_temp("fumo")   )
		return notify_fail("������ʹ�ô���ȭ��"PNAME"��\n");

	i = (int)me->query_str() * 2;
	z = (int)me->query_skill("force", 1)/5+(int)me->query_skill(bskill,1)/4;
	msg = HIR"$NͻȻȫ��������죬����Ĭ���շ�ħ���������׽�񹦣�����һ���ɫ��ȫ�������ʹ���������һ����\n" NOR;
	message_combatd(msg, me, target); 
	me->add_temp("apply/strength", i);
	me->set_temp("fumo", 1);
	me->add("neili", - 600);

	call_out("check_fight", 1, me, i, z);
	me->start_busy(1);
	return 1;
}
void remove_effect(object me, int i)
{
	if(me->query_temp("fumo"))
	{
//		me->delete_temp("apply/strength");
		me->add_temp("apply/strength",-i);
		me->delete_temp("fumo");
		tell_object(me,HIR"��ġ���շ�ħ���˹���ϣ���ɫҲ�ÿ����ˡ�\n"NOR);
	}
}
void check_fight(object me, int i, int z)
{
	if (!me) return;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon") )
	{
		remove_effect(me, i);
		return;
	}
	if (z < 1 || !me->is_fighting())
	{
		remove_effect(me, i);
		return;
	}
	call_out("check_fight", 1, me, i, z-1);
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʹ������ǿ������һ�бе�������

	����Ҫ��
		�������28
		�׽100
		����ȭ120
		����1000
HELP
	);
	return 1;
}

