// break -������ժ�ǡ�
// Last Modify by sir 5/17/2001
 
#include <ansi.h>
#define PNAME "������ժ�ǡ�"
inherit F_SSERVER;
 
int perform(object me,object target)
{
	string msg;
	object weapon,  target_w;
	int ap, dp, equip;	
	object piece;
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
 
//	if (objectp(weapon = me->query_temp("weapon")))
//		return notify_fail("���������˹���\n");
	// �������־���

	fskill = "baiyun-xinfa";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 800 )
		return notify_fail("��������������޷��˹���\n");
 
	if( me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ�������޷��˹���\n");
 
	msg = HIC"$N"HIC"���绬�����Ե���������һ������֮��˳��Ѫ�����紫��˫���͹�Ѩ�������������֮���ͼ������������$n"HIC"���еı��У�\n"; 

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	target_w = target->query_temp("weapon");

	if (target->query_temp("weapon") ||
		target->query_temp("secondary_weapon"))
	{ 
		if( random(ap) > dp )
		{	
			me->add("neili",-400);
			msg += HIW"ȴֻ����һ�󶡵����죬������Ƭ����һ�أ�\n"NOR;
			target_w->unequip();
			target->reset_action();
      seteuid(getuid());
      piece = new("/clone/misc/piece");
      piece->set("long", "һ�ѱ�����Ƭ��\n");
      piece->set_name( target_w->query("name") + "����Ƭ", ({target_w->query("id"),"piece"}) );
      piece->move(environment(target));
      destruct(target_w);
			me->start_busy(random(2));
		}
		else 
		{
			msg += "����$p�������У����˿�ȥ��\n" NOR;
			me->add("neili",-200);
			me->start_busy(2);
		}   
		message_combatd(msg, me, target);
		if(!target->is_fighting(me)) target->fight_ob(me);
		return 1;
	}
	return notify_fail(target->name() + "Ŀǰ�ǿ��֣�ûʲô��������ġ�\n");
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ٻ��Է�����

	����Ҫ��
		�����ķ�100��
		������80��
		����1000
HELP
	);
	return 1;
}

