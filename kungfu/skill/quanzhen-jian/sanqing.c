// sanqing.c  һ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "��һ�������塹"
int perform(object me, object target)
{
  object weapon, ob;
        string msg, string1;
        int count,sword_lvl;
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
    return notify_fail(PNAME"��ʼʱ��������һ�ѽ���\n");

	fskill = "xiantian-qigong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

  if( (int)me->query("neili") < 100 )
    return notify_fail("�������������\n");

  msg =  HIY "$N"HIY"���һ��������ͻ�䣬�����Ƴ�ѩ����â��һ����Ϊ�����������������磡\n" NOR;
// ȫ��һƬ�������������ȣ�ʹ����һ�������塹��������������Ϊ��������Ȼ������

//  me->clean_up_enemy();
 // ob = me->select_opponent();
  message_combatd(msg, me);
  sword_lvl =(int)me->query_skill("sword", 1)/15;
  for(count=1;count<=3;count++)
  {
  	if (flag == 1) target = offensive_target(me);
  	if (!objectp(target)) break;
     me->add_temp("apply/dodge",sword_lvl);
     me->add_temp("apply/attack",sword_lvl);
     me->add_temp("apply/sword",sword_lvl);
    msg =  HIR "��"+chinese_number(count)+"����" NOR;
    message_combatd(msg, me);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
  }
  me->add_temp("apply/dodge",-count*sword_lvl);
  me->add_temp("apply/attack",-count*sword_lvl);
  me->add_temp("apply/sword",-count*sword_lvl);
  
  me->add("neili", -100);
  me->start_busy(random(3));

  if(!target->is_fighting(me)) target->fight_ob(me);
  return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
  write(@HELP

  ʹ�ù�Ч��
    ������������

  ����Ҫ��
    ��������60��
    ȫ�潣��135��
    ����100
HELP
  );
  return 1;
}

