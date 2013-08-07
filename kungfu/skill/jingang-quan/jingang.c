// jingang.c ���ȭ ������ͨ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "��������ͨ��"
void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
	object weapon;	
	string msg;
	int d_count, count, qi, maxqi, skill;
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

//���ֱ�������

	fskill = "hunyuan-yiqi";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"����Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail( HIG"���Ѿ��ڰ�������ˡ�\n"NOR);

	if( (int)me->query_temp("powerup"))
		return notify_fail( HIG"���Ѿ������ڹ������ˣ�û�и��������ʹ�ô�����ͨ��\n"NOR);

	if( (int)me->query("neili") < 500 )
		return notify_fail("���������������\n");

	msg = HIY "$N"HIY"ʹ������ȭ�ľ�����������ͨ����������Ȼ���ӣ�\n" NOR;
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill(bskill, 1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{
		if( (int)me->query_temp("jingang") ) 
	  	return notify_fail( HIG"���Ѿ����˹����ˡ�\n"NOR);
		message_combatd(msg, me, target);
		
		me->add_temp("apply/strength", count * 2);	
		me->add_temp("apply/dexerity", 0-d_count);
		me->set_temp("jingang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

		me->add("neili", -150);
	}
	else
	{
		msg =HIR "$Nƴ����������ʹ���˴���ȭ���ռ�������ȫ�����һ���죬�������ͬ���ھ���\n" NOR;
		message_combatd(msg, me, target);
		me->add_temp("apply/strength", count * 8);
		me->add_temp("jingang", 1);
		me->set("jiali",me->query("jiali")*3);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set("jiali",me->query("jiali")/3);
		me->add_temp("jingang", -1);
		me->add_temp("apply/strength", - count * 8);
		me->set("neili",0);
		me->add("max_neili",-10);

		msg=HIR"$N�þ������һ�����������һ����Ѫ��һͷ�Ե��ڵأ�\n"NOR;
		message_combatd(msg, me, target);

		me->set("jing",0);
		me->set("qi",0);

		me->unconcious();
	}
	return 1;
}

void remove_effect(object me, int aamount, int damount)
{
	if ( (int)me->query_temp("jingang") ) 
	{
		me->add_temp("apply/strength",-aamount);
		me->add_temp("apply/dexerity", damount);
		me->delete_temp("jingang");
		tell_object(me,HIY"��Ĵ�����ͨ������ϣ��������ջص��\n"NOR);
		me->start_busy(random(4));
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��ķ����������������Լ��Ĺ�����
		����֮�ʸ��ɰѹ�������ߵ����£������к���ε�

	����Ҫ��
		��Ԫһ����60��
		����ȭ��150��
		����500
HELP
	);
	return 1;
}

