// zhong.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h>

inherit F_SSERVER;
#define PNAME "����������"
int perform(object me, object target)
{
	object obj;
	string msg;
  int eff_jing=me->query("eff_jing");
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
		return notify_fail("������ֻ�����ڶ������ϡ�\n");

	if( me->query_temp("weapon") )
		return notify_fail("ֻ�п��ֲ���ʩչ������������\n");

	fskill = "bahuang-gong";
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
		return notify_fail("���"+to_chinese(fskill)+"������죬������"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬������"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
    if (me->query_skill_mapped("force") != "bahuang-gong"&& userp(me))
      return notify_fail("��û�м����˻�����Ψ�Ҷ��𹦣�����ʹ����������\n");
	}

	if( me->query("neili") < 500 )
		return notify_fail("����������㣬��������������\n");

	if( me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ���㣬��������������\n");
	
	if( userp(me) && ((me->query("spi")) + (me->query("cps"))) > 40)
                return notify_fail("����츳���ʺ�����������\n");

	if (!objectp(obj=present("jiudai", me)))
		return notify_fail("������û�оƴ������ܻ�ˮΪ����\n");
		
	if (me->query("owner")) return notify_fail("����npc����ʹ����������\n");

	msg = HIC "$N"HIC"���������а����ڹ�����ת��ڤ����������ʱ�ѽ����о�ˮ�����߰�
Ƭ��������������������ơ� \n";

	me->start_busy(1);
	me->add("neili", -400);
	if((random( (int)me->query_skill("strike", 1))*1.5) > random(target->query_skill("dodge") ) )
	{
// �и��뷨�� ÿ���е�Ѩλ���ǲ��̶��ģ��ⶾ��ʱ����Ҫ�Ҷ���ȷ��Ѩλ����
//            ��Ȼ����������Ѩλ�����ۼӣ�
//            ������ж��� ȱ��Ѩ ־��Ѩ ����Ѩ��
//            ��ô����ⶾ���˲�֪��Ѩλ�ҽ⣬������������
//            - by qingyun
		msg += RED " ���$p�͵����䡰ȱ��Ѩ����΢΢һ��������������һƬѩ��������С��������Ѩ�������ȡ�����Ѩ�����ϱۡ���ȪѨ������Ҳ�����쬵ء���Ȼ��󾱡�����Ѩ�������ġ����Ѩ��
��������־��Ѩ������Ҳ��΢΢һ����\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("force", 1),me);
		target->receive_wound("qi",15 + random(10),me);
		if (fam_type(me)=="lingjiu")
		target->receive_wound("jing",2+eff_jing/3+random(eff_jing/3),me);
		target->apply_condition("ss_poison", random(me->query_skill(bskill, 1)/8) + 1 + target->query_condition("ss_poison"));
		me->start_busy(random(3));
	} else {
		msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
	target->start_busy(1 + random(3));
	if(!target->is_fighting(me)) target->fight_ob(me);
	if ( target->query_condition("ss_poison")) target->kill_ob(me);
	if (userp(me)) destruct(obj);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�������������չ�������
		���ͶԷ�����
		

	����Ҫ��
		�˻�����Ψ�Ҷ���40��
		�ʵ����츳
		��ɽ������60��
		���ϴ��žƴ�
		����400
HELP
	);
	return 1;
}

