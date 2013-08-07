// yinhuo.c ������֮����
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "������"
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object ob;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ��"PNAME"��\n");	

	if(me->query_temp("pfm_chousui"))
		return notify_fail("������������ѽ��й�����\n");
	fskill = "huagong-dafa";
	bskill = "strike";
	pskill = "poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "douzhuan-xingyi";
	}
	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(pskill, 1) < 110 )
		return notify_fail("�㷢���Լ����ھ۶��������޷�ʹ��"+PNAME+"���й�����\n");
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("�㷢���Լ����õ��ڹ��޷�����"PNAME"������\n");
	if( (int)me->query("max_neili") < 1200)
		return notify_fail("�㷢���Լ�����̫�����޷�����"PNAME"���й�����\n");
	if((int)me->query("neili") < 900)
		tell_object(me,"�㷢���Լ���������̫����ʹ����"PNAME"���й�����\n");	   

	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
		return notify_fail("û�л����ô���������𡹽��й�����\n");
	  message_combatd(HIR"\n$Nҧ��ָ�⣬������Ѫ�䵽���棬��������һ�ģ����һ��ȼ��һ�����ܻ��棡\n\n"NOR,me);
 	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(YEL"\n$N"YEL"����һ����һ�ɾ���ֱ����"HIR"����"YEL"֮�С������ֳַ�һ��ϸϸ��"WHT"����"YEL"��\n����һ��"WHT"��ɫ����"YEL"���Կռʣ�����ڶ�����ɫ�������ޣ����ǹ��죬"RED"��â"YEL"��˸������\n"NOR,me);
	me->start_busy(2);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 4, me, target, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;
	object wep,piece;
	if(!me) return 0;	
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");	

	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->query_temp("noliving") ||
		 me->is_ghost()) return 1;
	if(!living(target) || !target || !me->is_fighting(target) ||
		environment(me)->query("no_fight") ||
		environment(me)!=environment(target))
	{
		message_combatd(HIY"$N�����ٷ����������"WHT"����"HIY"ѹ�ػ���֮�С�\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N�ۿ����Ϩ�𣬳�̾һ����ɢ����Ϣ��˫���´�������\n"NOR,me);
		return 1;
	}

	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_str();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -500);
	me->receive_damage("jing", 50);

	msg = YEL"\nͻȻ����������"GRN"��ɫ���"YEL"����ʱ"WHT"����"YEL"ٿ�����أ�\n��������$n$l��ȥ���������ͣ�ȥ����죡\n"NOR;	

       
	if(random(ap) > dp/3)
	{
		if(objectp(wep = target->query_temp("weapon")))
		{ 
			msg +=HIY"$n������������Ѹ���޳������޿ɱܣ�ֻ�ð���������������Ӳ����\n" NOR;
			if(me->query("neili") < target->query("neili")*2)
			{
				me->start_busy(2);
				msg += HIY "���ֻ��һ�����죬$w"HIY"��$W"HIY"��ײ�������ɻ�����ɢ������\n" NOR;
			}
			else if(me->query("neili") > target->query("neili")*4)
				{
					if(wep->query("rigidity") >= 50)
					{
						me->start_busy(2);
						target->start_busy(2);
						wep->move(environment(target));
						msg += HIW "���ֻ�����ԡ���һ������$w"HIW"������ײ���£�$n�������ѣ�$W"HIW"���ַɳ���\n" NOR;
					}
					else
					{
						me->start_busy(2);
						target->start_busy(2);
						msg += HIW "���ֻ����ž����һ�����죬$n����"+wep->name()+HIW"��$w"HIW"��ϣ���Ƭ��ɢ���䣡\n" NOR;
						wep->unequip();
						target->reset_action();
						seteuid(getuid());
		        piece = new("/clone/misc/piece");
      			piece->set_name( "�ϵ���"+wep->query("name"), ({wep->query("id"),"piece"}) );
       			piece->set("long", wep->query("long")+"��ϧ�Ѿ�����÷����ˡ�\n");
        		piece->move(environment(target));
       			destruct(wep);
					}
				}
				else
				{
					if(wep->query("rigidity") >= 50)
					{
						me->start_busy(2);
						target->start_busy(2);
						msg += HIY "���ֻ��һ�����죬$w��$W��ײ�������ɻ�����ɢ������\n" NOR;
					}
					else
					{
						me->start_busy(2);
						target->start_busy(2);
						wep->move(environment(target));
						msg += HIW "���ֻ�����ԡ���һ������$w"HIW"������ײ���£�$n�������ѣ�$W"HIW"���ַɳ���\n" NOR;
					}
				}
			msg = replace_string(msg, "$W", wep->name());
		}
		else
		{
			damage = i*2+me->query("jiali")*2;
			if(neili > target->query("neili")*2) damage = damage*2;
			if (damage > 1000) damage = 1000;
			target->receive_damage("qi", damage,me);		
			target->receive_wound("qi",damage/2,me);
			target->apply_condition("xx_poison", random(3) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			me->start_busy(2);
			target->start_busy(2);
		}
	}
	else
	{
		me->start_busy(3);
		msg += HIY"\n$pȫ������һ������$w"HIY"��������������˵��������ޱȣ�\n" NOR;
	}
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", WHT"����"NOR);   
//	if(!target->is_killing(me->query("id"))) target->kill_ob(me);    
	message_combatd(msg, me, target);
	return 1;
}  

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˺��Է���Ѫ
		ʹ���������޶�
		����������ֱ���

	����Ҫ��
		������140��
		������140��
		��������110��
		������Ϊ1200
		����900
		��Χ�л��
HELP
	);
	return 1;
}

