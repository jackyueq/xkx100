// po.c �ƽ�ʽ
// Last Modified by winder on Mar. 10 2000
/*
���¾Ž������ܾ�ʽ������zongjue �У������ֱ仯����������
�ܾ���������ϰ��
�ڶ��С��ƽ�ʽ���������ƽ������¸��Ÿ��ɵĽ�����
�����С��Ƶ�ʽ���������ƽⵥ����˫������Ҷ������ͷ������
������ն�����ֵ�����
�����С���ǹʽ���������ƽⳤǹ����ꪡ���ì����ü��������
���������ˡ����ȡ���������ֳ�����֮����
�����С��Ʊ�ʽ���������ƽ�ֱޡ���ﵡ���Ѩ�ӡ����ӡ���ü
�̡�ذ�ס��師�����ơ��˽�鳡���׵�ȵȶ̱��С�
�����С�����ʽ�����ƽ���ǳ�������ޡ����ڹ�������ǹ����
�����������ɴ����ǵȵ�����С�
�����С�����ʽ�����Ƶ���ȭ��ָ���ϵĹ��򣬽���ȭ�̴���
�õ�Ѩ��ħצ��צ����ɳ���ƣ����ȭ�Ź������������ڡ�
�ڰ��С��Ƽ�ʽ������������㰵��������һ��ʱ�������ѧ��
�����֮��������Ҫ����һ�������������˷����������ְ�����
������������Ե��������İ��������˵С�
�������й���po�С�
�ھŽ�������ʽ������Ϊ�Ը�����ϳ��ڹ��ĵ��˶��ã������
֮�����һ�ġ���poqi��ʵ�֡�
pozhong һ�У��ǡ��Ƽ�ʽ���ı��С�
*/

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�ƽ�ʽ"
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage, sk ;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	if(me->query("family/master_id")!="feng qingyang" && userp(me) && !wizardp(me))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");
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
		return notify_fail("���¾Ž�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("û�н�������ô���ö��¾Ž���\n");

	bskill = "sword";

	skill = me->query_skill(sskill,1);

	if( skill < 50)
		return notify_fail("��Ķ��¾Ž��ȼ�����������ʹ�ù��У�\n");
		
	if( me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ�������޷����ù��У�\n");

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷����ù��У�\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))) sk = 1;
	else
	{
		if((string)weapon2->query("skill_type")=="sword") sk=2; //��
		if((string)weapon2->query("skill_type")=="blade") sk=3; //��
		if((string)weapon2->query("skill_type")=="spear" ||     //ǹ
			(string)weapon2->query("skill_type")=="club" || //��
			(string)weapon2->query("skill_type")=="fork" || //��
			(string)weapon2->query("skill_type")=="rake" || //��
			(string)weapon2->query("skill_type")=="stick" || //��
			(string)weapon2->query("skill_type")=="staff") sk=4;//��
		if((string)weapon2->query("skill_type")=="mace" || //��
			(string)weapon2->query("skill_type")=="axe" || //��
			(string)weapon2->query("skill_type")=="dagger" || //ذ
			(string)weapon2->query("skill_type")=="hammer" || //��
			(string)weapon2->query("skill_type")=="hook") sk=5; //��
		if((string)weapon2->query("skill_type")=="whip") sk=6; //���
		if((string)weapon2->query("skill_type")=="throwing") sk=7;//����
	}
// ����
	switch (sk)
	{
		case 1:
			msg = HIC"$N"HIC"ʹ�����¾Ž�֮������ʽ�����������ڽ��⣬����ʹ������$n"HIC"�����Ĵ�ȥ��\n";
			break;
		case 2:
			msg = HIC"$N"HIC"��"+weapon->name()+HIC"������ĬǱ���¾Ž�֮���ƽ�ʽ��, б����̳�һ��������Ʈ��������$n"HIC"������\n";
			break;
		case 3:
			msg = HIC"$N"HIC"ʹ�����¾Ž����Ƶ�ʽ��������΢����"+weapon->name()+HIC"���ϣ�ˢ��һ��������$n"HIC"��ͷ������Ѩ����\n";
			break;
		case 4:
			msg = HIC "$N"HIC"һʽ���¾Ž�����ǹʽ�����������ɵ�˳��"+weapon2->name()+HIC"���䣬����$n"HIC"����ָ��\n";
			break;
		case 5:
			msg = HIC"$N"HIC"ʹ�����¾Ž����Ʊ�ʽ���ƽ�$n"HIC"���ὣ�ó����ؽ�Ӱ����$n"HIC"����˿����$n��ȥ��\n";
			break;
		case 6:
			msg = HIC"$N"HIC"ʹ�����¾Ž�֮������ʽ�����������ǣ�Ѹ���ޱȵص���$n"HIC"������\n";
			break;
		case 7:
			msg = HIC"$N"HIC"�ٽ����㣬������¾Ž�֮���Ƽ�ʽ��, ��$n��������"+weapon2->name()+"�����$n"HIC"������ȥ��\n";
			break;
	}
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill(bskill) + skill;
	dp = target->query_skill(bskill) / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-50);
		switch (sk)
		{
			case 1:
				msg = HIY"$n��ʱ������ǰһ��������һ������������һ�ؽ���ð�˳�����\n"NOR;
				break;
			case 2:
				msg = HIY"$n��ʱ������ǰһ��������һ�飬����"+weapon2->name()+HIY"���ֶ�����\n"NOR;
				break;
			case 3:
				msg = HIY"$n��ͷ��ʹ��˫��ʹ��������������"+weapon2->name()+HIY"����ॡ�һ�����ڵ��ϡ�\n"NOR;
				break;
			case 4:
				msg = HIY"$n��ʱ�󾪣�Ϊ����ָ��æ������"+weapon2->name()+HIY"�����׳���\n"NOR;
				break;
			case 5:
				msg = HIY"$n�پ������͵ؾ�ʹ������"+weapon2->name()+HIY"���ʵ����ַɳ���\n"NOR;
				break;
			case 6:
				msg = HIY"$nֻ����$N��"+weapon->name()+"�˿�ֱ�룬����"+weapon2->name()+HIY"���������ţ��ؾȲ��������ò���֮�ڳ����������мܡ�\n"NOR;
				break;
			case 7:
				msg = HIY"$n��ʱ��������ǵص�"+weapon2->name()+HIY"�������Լ�Ϯ����ȫ���������̱���ø�������Ƶ�\n" NOR;
				break;
		}
		me->start_busy(1+random(2));
		target->receive_damage("qi", damage,me);
		if (!target->is_busy())
		target->start_busy(2);
		if (sk ==1)
		{
			if (!target->query_temp("lonely-sword/pozhang"))
			{
				target->set_temp("lonely-sword/pozhang",1);
				target->start_call_out((:call_other, __FILE__, "remove_effect", target:), skill/30+2);
			}
		}
		else 
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me)) me->add("neili",-30);
		if(sk==1)
			msg = HIG"����$n������$N�Ľ�·��һ�������ţ��ܿ�$N���׺ݳ��֡�\n"NOR;
		else
			msg = HIG"����$n������$N�Ľ�·�����̽�����" + weapon2->name()+ "��÷��겻͸��ʹ$N�ĳ�����ա�\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	return 1;
}
void remove_effect(object me)
{
	if (me->query_temp("lonely-sword/pozhang"))
	{
//	 tell_object(find_player("qingyun"),me->name()+"remove eff from pozhang\n");
	 me->delete_temp("lonely-sword/pozhang");
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����ֱֳ����ĵ���֮���������˵���Ѫ
		����δ�ֱ����ĵ��֣��˵���Ѫ

	����Ҫ��
		��Ϊ������մ�����
		���¾Ž�50��
		������Ϊ500
		����250
HELP
	);
	return 1;
}

