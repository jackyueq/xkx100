// fen.c �����Ի�
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "�������Ի�"

int perform(object me,object target)
{
	string msg;
	object weapon,  *inv,piece;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
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

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("���������˹���\n");

	fskill = "longxiang";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 600 )
		return notify_fail("��������������޷��˹���\n");
 
	skill = me->query_skill(bskill, 1);
	msg = HIC "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n"HIC"���ؿڻ�ȥ��\n"NOR;

	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-600);

		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		if(target->query("qi")>100)
			qi_wound = target->query("qi") - 100;
		else 
		{ 
			qi_wound= target->query("qi");
			qi_wound= qi_wound - target->query("qi")/10;
		}

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
		target->add("neili", -neili_wound);
	 	target->start_busy(1);
		me->start_busy(1+random(3));

 		inv = all_inventory(target);
    msg += HIR"$n"HIR"ֻ������ǰһ�ڣ�һ������������������ۡ���һ�����һ����Ѫ��\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
msg += HIR "$n"HIR"�ŵ�һ�ɽ�ζ���������ϵ�"+inv[equip]->query("name")+HIR"�ѱ��յò��Ʋ����������˵��ϣ�\n"NOR;
			inv[equip]->unequip();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
      	piece->set_name( inv[equip]->query("name") + "����Ƭ", ({inv[equip]->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(inv[equip]);
			}
		}
		target->reset_action();
	}
	else
	{
msg += HIG "ֻ��$n"HIG"���Ų�æ������һ���������$N"HIG"�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-600);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ������
		�ٻٶԷ���װ������

	����Ҫ��
		С���๦60��
		���浶120��
		����600
HELP
	);
	return 1;
}

