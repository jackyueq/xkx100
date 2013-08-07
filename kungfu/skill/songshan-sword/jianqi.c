// Last Modified by Winder on May. 21 2001
// jianqi.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��������"
int perform(object me, object target)
{
	object weapon;
	int damage, sword;
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
		weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽����������á�����������\n");
		
	if (weapon->query("unique") )
		return notify_fail("������֮�����Ƿ���֮����ʹ�á�������û��ʲô���ã�\n");

	if( me->query_temp("ss_jianqi") )
		return notify_fail("���ʹ�꡸��������Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

	fskill = "hanbing-zhenqi";
	bskill = "sword";
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

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("���"+to_chinese(bskill)+"��Ϊ����������δ������"+PNAME+"��\n");

	if( (int)me->query_str() < 30 )
		return notify_fail("��ı��������ߣ��޷�ʹ��"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("force") != fskill )
			return notify_fail("�����õ��ڹ��롸�������ķ���㣣�\n");
	}

	if( me->query("max_neili") <= 2000 )
		return notify_fail("���������Ϊ���㣬����������ʩչ����������\n");

	if( me->query("neili") <= 600 )
		return notify_fail("�����������������������ʩչ����������\n");

	message_combatd(GRN "\nˢ��һ���죬$NǱ��������"+weapon->name()+GRN"һ������һ��ʹ�ý����ݺᣬ��Ȼ����ɽ�ȡ���������֮�ˣ��޲����죡\n\n" NOR, me);

	damage = me->query_skill(bskill, 1);
	damage = damage/6;
	sword = me->query_skill(bskill, 1)/3;
	if ( userp(me) )
	{
		me->add("neili", -300);
		if ( damage > weapon->query("weapon_prop/damage") * 2)
			damage = weapon->query("weapon_prop/damage") * 2;
		else weapon->add("rigidity", 1);
	}

	me->set_temp("ss_jianqi", 1); 
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);
	
	call_out("remove_effect1", sword/2, me, weapon, damage);
	call_out("remove_effect2", sword*2/3, me);

	return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
	object piece;
	if (!me) return;
	me->add_temp("apply/attack", -damage);

	if (!objectp(weapon))
	{
		me->set_temp("apply/damage", 0);
		return;
	}
	me->add_temp("apply/damage", -damage);
	message_combatd("\n$Nһ�ס���ɽ������ʹ�꣬����"+weapon->name()+"�ϵĹ�â����Ҳ��ʧ�ˡ�\n", me);		
	weapon->add("jianqi", 1);
	if (weapon && weapon->query("jianqi") >= (3+weapon->query("rigidity")))
	{
		message_combatd(HIW"\nֻ�����ꡱ��һ����$N���е�$n"HIW"������������ѳ�����Ƭ��\n"NOR,me,weapon);
		weapon->unequip();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "һ�ѱ�������Ƭ��\n");
      	piece->set_name( "���ѵ�" + weapon->query("name"), ({weapon->query("id"),"piece"}) );
      	piece->move(environment(me));
     		destruct(weapon);
		me->reset_action();
	}
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("ss_jianqi");
	tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á��������ˡ�\n"NOR); 
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		������ע��������ɱ����

	����Ҫ��
		��������150��
		��ɽ����150��
		��������150��
		��������30
		������Ϊ2000
		����600
HELP
	);
	return 1;
}

