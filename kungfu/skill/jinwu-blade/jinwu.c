// Last Modified by winder on Jul. 9 2001
// jinwu.c ���ڶ��

/*
�������϶Է������Ĺ��������perform������������Ϊ�˱��ֶ��¾Ž���
��һ����ĵ�һ��λ���صضԷ�����һ�������������ڳ�����������������
ϣ���Ժ����ʦ��Ҫ������Щ�趨���Ͼ���weapon�书�У����ܳ�Խlonely-sword�ĵ�λ��
*/

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��"+HIR"���ڶ��"NOR+"��"

int perform(object me,object target)
{
	string msg;
	object weapon, weapon2,*inv;
	int skill, ap, dp, neili_wound, qi_wound,equip,skill1,skill2,skill3,skill4;
	int temp;
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

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	fskill = "bingxue-xinfa";
	bskill = "blade";
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

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ�������޷����á�"+HIR"���ڶ��"NOR+"����\n");

	if( me->query("neili") < 400 )
		return notify_fail("��������������޷����á�"+HIR"���ڶ��"NOR+"����\n");

	skill  = me->query_skill(sskill,1);
	skill1 = me->query_skill("xueshan-sword",1);
	skill2 = me->query_skill(fskill,1);
	skill3 = me->query_skill(bskill,1);
	skill4 = me->query_skill("strike",1);
	msg = HIY"$N����Ծ��,ʹ��"+HIR"�����ڶ�ء�"HIY"������"NOR+weapon->name()+HIY"�Ӱ���лӵ�ֱ��������\n��������������ߣ��������ǳ�ɳ����ܲ���Ҷ�����缤�����Ŷ��裬\n��$n�Ӷ��˱ܵĿ�϶�������ʵʵ��\n"NOR;
	message_combatd(msg, me, target);
	msg = "";

	ap = random(me->query_skill(bskill) + skill);
	dp = target->query_skill("dodge")/3;
	if (target->query_skill_mapped("parry") == "xueshan-sword")
	{
                msg += HIR "$n" HIR "��æ��æ��"HIW"ѩɽ����"HIR"�����ֵ�����֪$N"
                       HIR "��������ѩɽ�������ǰ㣬\n" + weapon->name() +
                       HIR "��â��ʱ�ֱ�����������ȫ����$n" HIR "����"
                       "�н��У�\n" NOR;
		ap = ap * 2;
		temp = 1;
	}	
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-250);
		msg += HIC"$n���޿ɱܣ�ֻ��һ�ɸ���֮���ľ������������ʹ��ֱ����Ϣ��\n$n�������˸�����ȴֻ��"NOR""+weapon->name()+""HIC"����һ��������ͣϢ��һ���������š�\n"NOR;
		qi_wound = me->query_skill("blade",1)*2+me->query_str()*10;
		qi_wound *= 2;
		if (temp != 1) //�Ը���ѩɽ����
		{
			qi_wound = random(qi_wound);
			if(qi_wound > target->query("qi")) qi_wound = 100;
		}
		target->receive_damage("qi", qi_wound);
		target->receive_wound("qi", target->query("max_qi")/3);
		target->start_busy(2+random(1));
		me->start_busy(1+random(1)); 

		if(me->query("str")>=20	&& 		//����������벻С��20
			objectp(weapon2 = target->query_temp("weapon")) &&
			me->query_str() >= 45 &&	//����������벻С��45
			me->query("max_neili") > 2500 &&//��������������2800
			!me->query("betrayer") &&	//����û�ѹ�ʦ
			(me->query("neili") - me->query("max_neili")) > 300  &&
//����������������������300����������������250��ʵ�ʱ������550
			skill > 200 &&			//���ڵ����������200��
			skill1 > 200 &&			//ѩɽ�����������200��
			skill2 > 200 &&			//��ѩ�ķ��������200��
			skill3 > 200 &&			//���������������200��
			skill4 > 200 &&			//�����Ʒ��������200��
			me->query("family/master_id") == "bai zizai")
	//ʦ�������ǰ����� 
		{
			inv = all_inventory(target);
			for(equip=0; equip<sizeof(inv); equip++)
			{
				if(inv[equip]->query("weapon_prop") &&
					((string)inv[equip]->query("equipped")=="wielded"))
				{
					msg += HIW "$N����δ�������е��Ʋ���������$n����"NOR+inv[equip]->query("name")+HIW"һ�����ϡ�\nֻ������һ����$n���ϵ�"NOR+inv[equip]->query("name")+HIW"�ѱ��������룬�����˵��ϣ�\n"NOR;
					message_combatd(msg, me,target);
					inv[equip]->unequip();
					seteuid(getuid());
    			piece = new("/clone/misc/piece");
		    	piece->set_name("�ϵ���" + inv[equip]->query("name"),({inv[equip]->query("id"),"piece"}));
			    piece->move(environment(target));
					piece->set("long","һ���������������жϿ����ƿ����룬�����Ǳ�����һ�������ġ�\n");
				  destruct(inv[equip]);
				}
			}
			return 1;
		}
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg += HIW"����$n�������Ա�һ�����ܹ���$N���ɱ��һ����\n"NOR;
		me->start_busy(2+random(2));
	}
	message_combatd(msg, me, target);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����ֱֳ����ĵ���֮����

	����Ҫ��
		��Ϊ�����ڵմ�����
		���ڵ���100��
		��ѩ�ķ�100��
		������Ϊ1000
		����400
HELP
        );
        return 1;
}

