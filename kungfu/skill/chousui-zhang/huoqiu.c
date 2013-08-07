// huoqiu.c ������֮����
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
	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("�㷢���Լ���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("�㷢���Լ���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(pskill, 1) < 150 )
		return notify_fail("�㷢���Լ����ھ۶��������޷�ʹ��"+PNAME+"���й�����\n");
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("�㷢���Լ����õ��ڹ��޷�����"PNAME"������\n");
	if( (int)me->query("max_neili") < 2500)
		return notify_fail("�㷢���Լ�����̫�����޷�����"PNAME"���й�����\n");
	if((int)me->query("neili") < 1500)
		return notify_fail("�㷢���Լ���������̫����ʹ����"PNAME"���й�����\n");	   
	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
		return notify_fail("û�л����ô����"PNAME"���й�����\n");
	  message_combatd(HIR"\n$N"HIR"ҧ��ָ�⣬������Ѫ�䵽���棬��������һ�ģ����һ��ȼ��һ�����ܻ��棡\n\n"NOR,me);
 	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(HIR "\n$N"HIR"������ȣ�������ʢ��������ͻȻ����һ�������"RED"����"HIR"���ڿ��й�µµ��Ѹ��ת����\n\n"NOR,me);

	me->start_busy(2);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 4, me, target, ob);
	return 1;
}
int check_armor(object target)
{
	object *inv;
	int i, j;
	inv = all_inventory(target);
	j=0;

	for(i=0; i<sizeof(inv); i++)
		if( (string)inv[i]->query("equipped")=="worn" ) j++;
	return j;
}
int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;
	object *inv;
	object piece;
	if(!me) return 0;
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");
	damage = (i+me->query("jiali"))*2;

	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->query_temp("noliving") ||
		 me->is_ghost()) return 1;
	if(!target || !me->is_fighting(target) ||
		environment(me)->query("no_fight") ||
		environment(me)!=environment(target))
	{
		message_combatd(HIY"$N�����ٷ����������"RED"����"HIY"ѹ�ػ���֮�С�\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N�ۿ����Ϩ��ɢ����Ϣ�����¾����˫�֡�\n"NOR,me);
		return 1;
	}

	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_con();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -500);
	me->receive_damage("jing", 100);

	msg = WHT"\n��ʱ$N�������ް��Ѫɫ��һ�ڿ���Ѫ��ס��"RED"����"WHT"����ȥ��" HIR"\n����һʢ�������������죬��������𻨣�"RED"����"HIR"��Ȼ�����$n���������\n"NOR;

	if(random(ap) > dp/3)
	{
		inv = all_inventory(target);
		if(check_armor(target) >= 1)
		{
			if(me->query("neili")>target->query("neili")*2)
			{
				if(me->query_str()>random(target->query_str()))
				{
					me->start_busy(3);
					target->start_busy(2);
					msg += HIY "���Ҽ�����¶�������𻨱��䣬ը����$p�Ļ��ߣ�\n" NOR;
					for(i=0; i<sizeof(inv); i++)
						if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique"))
						{
							inv[i]->unequip();
							seteuid(getuid());
							piece = new("/clone/misc/piece");
							piece->move(environment(target));
							piece->set("name", "�����" + inv[i]->query("name"));
              destruct(inv[i]);
						}
					target->reset_action();
					damage = damage * 3;
					//if (damage > 2000) damage = 2000;
					damage = damage-target->query_temp("apply/armor");
					target->receive_damage("qi", damage,me);
					target->receive_wound("qi",damage/2,me);
					target->apply_condition("xx_poison", random(5) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					me->start_busy(2);
					target->start_busy(1);	       
				}
				else
				{
					me->start_busy(3);
					target->start_busy(3);
					msg += HIY "ֻ��������Ȼ���£����Ľ�������ֱ͸$p�Ļ��ߣ�\n" NOR;
					for(i=0; i<sizeof(inv); i++)
						if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique"))
						{
							inv[i]->set("name", "���ѵ�" + inv[i]->query("name"));
							inv[i]->set("value",0);
							if(inv[i]->query("armor_prop/armor"))
							{
								inv[i]->unequip();
								inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
							  inv[i]->wear();
							}
						}
					target->reset_action();
					damage = damage * 3;
					//if (damage > 1800) damage = 1800;
					damage = damage - target->query_temp("apply/armor");
					target->receive_damage("qi",damage,me);
					target->receive_wound("qi",damage/2,me);
					target->apply_condition("xx_poison", random(5) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					me->start_busy(2);
					target->start_busy(1);
				}
			}
			else
			{
				me->start_busy(3);
				target->start_busy(3);
				msg += HIY "�����ٹ���������Ľ��������������ײ��$p���\n" NOR;		  
				damage = damage * 2;
				//if (damage > 1800) damage = 1800;
				target->receive_damage("qi", damage,me);
				target->receive_wound("qi", damage/2,me);
				target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
				p = (int)target->query("qi")*100/(int)target->query("max_qi");
				msg += damage_msg(damage, "����");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				me->start_busy(2);
				target->start_busy(1);
			}
		}
		else
		{
		//target has no armor, so, hehe...
			damage = damage*2 + random(damage);
			if(neili > target->query("neili")*2) damage = damage*2;
			//if (damage > 2800) damage = 2800;
			target->receive_damage("qi", damage,me);   
			target->receive_wound("qi", damage/2,me);	     
			target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			me->start_busy(2);
			target->start_busy(1);
		}
	}
	else
	{
		me->start_busy(2);
		msg += HIY "\n$p�ۿ���Ҫ�����У�ð��һ���������š���ȫ����ϥ�Ǵ����ȥ�������ܹ�$w"HIY"��\n" NOR;
	}
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", RED"����"NOR);       
	message_combatd(msg, me, target);
	if(!target->is_killing(me->query("id"))) target->kill_ob(me);
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
		����Է�����

	����Ҫ��
		������180��
		������180��
		��������150��
		������Ϊ2500
		����1500
		��Χ�л��
HELP
	);
	return 1;
}

