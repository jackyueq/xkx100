// feilong.c  ��ɽ���������������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "�����������"
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;
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

  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"װ��������ʹ��"PNAME"��\n"NOR);
        
	fskill = "zixia-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

  if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

  if ((int)me->query("neili") < 400)
		return notify_fail(HIC"����������������û�ܽ�"PNAME"ʹ�꣡\n"NOR);
 
    msg = HIC "$N"HIC"���������һ�������������̽����˾��ڱۣ�����һ����$n"HIC"���˳�ȥ��\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = target->query("qi");
        target->receive_damage("qi", damage-10,me);
        target->receive_wound("qi", damage*2/3,me);
        msg += HIC"$n"HIC"��æԾ�𣬵����������ֻ��һ���ʹ������������������Ѫ�ɽ���Ƥ�����\n"NOR;
        me->set("neili", 100);
    } else
    {
        me->start_busy(2);
        msg += HIY"����$n"HIY"����һЦ��������ָ��������$N"HIY"�Ľ����ϣ���б����ء�\n"NOR;
        me->add("neili", -200);
    }
    weapon->move(environment(me));
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
		���ַɽ��˵�
		�������˶Է���Ѫ�������������ڿ��콣

	����Ҫ��
		��ɽ����150��
		��ϼ��100��
		����600
HELP
	);
	return 1;
}

