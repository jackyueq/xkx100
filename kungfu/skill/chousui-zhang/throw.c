// throw.c ������ʩ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "����ʬ����"

inherit F_SSERVER;
int perform(object me, object target)
{
	object obj;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	//�������־���
	
	fskill = "huagong-dafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("���"+to_chinese(fskill)+"������죬ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili") < 600) 
		return notify_fail("��������Ϊ̫����ʹ����"PNAME"��\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("����������̫����ʹ����"PNAME"��\n");

	if ( !(objectp(obj=present("corpse", environment(me))) ||
		objectp(obj=present("corpse", me)) ||
		objectp(obj=present("skeleton", environment(me))) ||
		objectp(obj=present("skeleton", me)) ) )
		return notify_fail("����Χû��ʬ�塣\n");

	msg = BLU"\n$N"BLU"һ����Ц������ͻ����˳��Ю��һ��ʬ������$n"BLU"��һ����������ĳ����������ܣ�������Ż��\n"NOR;

	me->start_busy(1);
	me->add("neili", -200);
	if( random( (int)me->query_skill("strike")) >
		random(target->query_skill("dodge",1) )/2 )
	{
		msg += CYN "$n���˹���������������޴룬�����޼���ֻ��ɢ���Ŷ����ʬ�壬�������Լ����ϡ�\n"NOR;
		target->receive_damage("qi",(int)me->query_skill("strike",1),me);
		target->receive_wound("qi",15 + random(10),me);
		target->receive_wound("jing", 10,me);
		target->apply_condition("fushi_poison", random(me->query_skill("strike",1)/10) + 1 + target->query_condition("fushi_poison"));
		target->start_busy(1 + random(2));
	} else {
		msg += HIB"$n���Ʋ��ã���æ����ֱ�𣬸�ʬ�������ӹ���û�д��С�\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
		destruct(obj);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���������Ѫ
		ʹ�Է��ж�

	����Ҫ��
		������40��
		������40��
		��Χ��ʬ��
		������Ϊ600
		����400
HELP
	);
	return 1;
}

