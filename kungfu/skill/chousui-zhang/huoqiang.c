// huoqiang.c ������ ��ǽ
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "����ǽ��"

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int start_huoqiang(object me);
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object ob, tar;
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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail("����û������Ը�������ˡ�\n");
	notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	if(environment(me)->query("no_fight"))
		return notify_fail("���������ʩչ������\n");

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
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("�㷢���Լ���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"���й�����\n");
	if( (int)me->query_skill(pskill,1) < 120)
		return notify_fail("�㷢���Լ����ھ۶��������޷�ʹ��"PNAME"���й�����\n");	 
	if( (int)me->query("max_neili") < 1000)
		return notify_fail("�㷢���Լ�����ʵ��̫�����޷�����"PNAME"���й�����\n");
	if((int)me->query("neili") < 800)
		return notify_fail("�㷢���Լ���������ʵ��̫�����ٲ���"PNAME"���й�����\n");
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("�㷢���Լ����õ��ڹ��޷�����"PNAME"������\n");
	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
		return notify_fail("û�л����ô����"PNAME"���й�����\n");
	  message_combatd(HIR"\n$N"HIR"ҧ��ָ�⣬������Ѫ�䵽���棬��������һ�ģ����һ��ȼ��һ�����ܻ��棡\n\n"NOR,me);
 	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}

	message_combatd(BLU"\n$N"BLU"��ɫ�ҵ������ִ򿪷��٣������´����������ϣ����ŵ�ȼ���׷ۣ�ҧ����⣬\nһ��"RED"��Ѫ"BLU"���������ȥ��"HIR"����"BLU"����һ�����漴��Ϊ"RED"����"HIR"��ҫ�������۾�Ҳ����������\n\n"NOR,me);

	me->start_busy(2);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 4, me, target, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg;
	int p;

	if(!me) return 0;
	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->query_temp("noliving") ||
		 me->is_ghost()) return 1;
	if(!target || !living(target) || target->query_temp("noliving") ||
		environment(me)->query("no_fight") ||
		environment(me)!=environment(target))
	{
		message_combatd(HIY"$N�����ٷ�����̧���"HIR"��ǽ"HIY"ѹ�ػ���֮�С�\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N�ۿ����Ϩ��ɢ����Ϣ��\n"NOR,me);
		return 1;
	}
	me->add("neili", -500);
	me->receive_damage("jing", 300);

	msg = BLU"\n$N�͵����Ӽ����������ݰ���ת��ʮ���Ȧ�ӣ�����$P���������\n"HIR"��������"BLU"�Ѷ��ز������ȼ�գ�����һ��"RED"��ǽ"BLU"�㣬������ɽ����֮����$nѹ����\n"NOR;
	if(!target->is_killing(me->query("id"))) target->kill_ob(me);
       
	if(!me->query("owner") && random(me->query_str()) > target->query_dex()/2)
	{
		msg += HIG"����"HIY"ӳ��֮��$p΢һ���ɣ���"HIR"��ǽ"HIY"���ÿ켫����Ҫ�˵����ϣ�$pֻ��˫�������\n������������ͳ�������ķ�Ʈ�𣬾����������Ƕ�"HIG"��ɫ�Ĺ�ǽ��\n\n" NOR;
		target->add("neili", -600);
		target->receive_damage("jing", 200,me);  
		me->set_temp("huoqiang_target", target->query("id"));
		me->set_temp("huoqiang/period", 1);
		target->set_temp("huoqiang_target", me->query("id"));
		target->set_temp("huoqiang/period", 1);
		me->start_busy(me->query_busy()*-1);
		target->start_busy(target->query_busy()*-1);
		me->start_busy((: start_huoqiang :));
		target->start_busy((: start_huoqiang :));
		message_combatd(msg, me, target);
		return 1;     
	}
	else if(random(me->query_str()) > target->query_dex()/3)
		{
//			me->start_busy(4);
			target->start_busy(3);
			msg += HIY"\n$nֻ��Ŀ�ɿڴ���һ��֮�䣬��æԾ�𣬵�һ��"HIW "��"HIY"���䵽��ǰ���͵�һ���죬\n�������϶Ǹ���$n��������һ����У���������������"HIR"���ǽ"HIY"Ҳ�����������С�\n" NOR;
			target->receive_damage("qi", me->query_skill("force"),me);
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(me->query_skill("force"), "����");
			msg += "( $n"+eff_status_msg(p)+" )\n"; 
			msg = replace_string(msg, "$l", "�Ǹ�");
			msg = replace_string(msg, "$w", HIW"��"NOR);
		}
		else
		{
//			me->start_busy(3);
			if(me->query("neili") > 10) me->set("neili", 10);
			msg +=HIY"$nֻ��Ŀ�ɿڴ���һ��֮�䣬"HIR"��ǽ"HIY"���䵽��ǰ����æԾ��"HIR"��ǽ"HIY"������$p����·ɹ���\n" NOR;
		}      
	message_combatd(msg, me, target);
	return 1;
}       

int start_huoqiang(object me)
{
	string msg, tar;
	object target, ob;
	int neili_lost, period, neili, neili2;

	if(!me) return 0;
	if(me->is_ghost()) return 0;
	tar = me->query_temp("huoqiang_target");
	if (!tar) return 0;
	target = present(tar, environment(me));
	if(!target || target->is_ghost() ||
		environment(me)!=environment(target))
	{
		message_combatd(CYN"$N�����ھ�һ�գ���һ˫����㼴���£�ҡҡ�ϻϵ�վ��������\n"NOR, me);
		return 0;
	}
	neili_lost = 30 + target->query_skill("force")/10 + me->query("jiali")/2 + target->query("jiali")/2;
	period = (int)me->query_temp("huoqiang/period"); 
	neili = me->query("neili");
	neili2 = target->query("neili");

	me->add("neili", -neili_lost);
	me->receive_damage("jing", 3+random(5),target);	
	me->improve_skill("force", random(2));

	if(neili < neili_lost)
	{
		message_combatd(HIY"$N�������Ĵ���������֧���أ�\n"NOR, me);
		me->unconcious();
		return 0;
	}
	if( (!living(target) || target->query_temp("noliving") ) &&
		(living(me) && !me->query_temp("noliving")) )
	{
		msg = HIR"$N˫���ĳ���һ��"GRN"����"HIR"�³�������$n��$p�˿�����˿��������أ���վ��������������Ҳ�ޡ�\n"GRN"����"HIR"һ�䵽$p���ϣ���ʱ��ͷ�����Ż𣬿�вҺ����У�ȫ������"RED"����"HIR"֮�С�\n"NOR;
		target->set_temp("last_damage_from",me);
		msg += "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		msg += "( "RED"$n���˹��أ��Ѿ�������в�����ʱ�����ܶ�����"NOR")\n";
		message_combatd(msg, me, target);     
		target->die();     
		return 0;
	}	
	if( (!living(target) || target->query_temp("noliving") ) &&
		(!living(me) || me->query_temp("noliving")) )
	{
		message_combatd(HIW"��ʱ$N���϶����ް��Ѫɫ�������Ѿ������;��ƿ�֮ʱ��\n"NOR,me);
		me->set_temp("last_damage_from",target);
		me->die();
		return 0;
	}
	if(!objectp(ob = present("huo yan", environment(me))))
	{
		message_combatd(HIY"$N�ۿ����Ϩ��Ҳ�����չ���վ��������\n"NOR,me);
		return 0;
	}
	switch(period)
	{
		case 3: 
		case 9:
		case 15:
		case 21: 
		case 27:
		case 33:
		case 39:
		case 45:
		case 51:
		case 57:
		case 63:
		case 69:
		case 75:
		case 81:
		case 87:
		case 93:   
		case 99:     
		case 115:
		case 145:
		case 175:
		case 205:  
			if(neili > neili2)
			{
				msg = random(2)?HIR"������һ�����$N�ķ����ƶ���\n"NOR:HIR"$Nʹ��ȫ������ͼ���ǲ����ƽ��ı����Ƶ���ȥ��\n"NOR;
				message_combatd(msg,target);
			}
			break;
		case 12:       
		case 24:
		case 42:
		case 60:
		case 78:  
		case 96: 
		case 125:
		case 155:
		case 185:
			if(neili > neili2)
			{
				msg = random(2)?HIR""GRN"����"HIR"�𽥽ӽ���$Nʹ��ȫ������ͼ���ǲ����ƽ��ı����Ƶ���ȥ��\n"NOR:HIR "$N�ۿ�"GRN"����"HIR"���Լ�������ȴ���ܿ���ͣ����������Ȼ�������������ʱ�ᱻ���������\n"NOR;
				message_combatd(msg, target);
			}
			break; 
		case 36:
		case 54:
		case 72:	
		case 90:
		case 105:
		case 135:
		case 165:
		case 195:
			if(me->query("jiali") > target->query("jiali"))
			{
				msg = random(2)?HIR"��Ƭ"GRN"����"HIR"�ڿ�����һͣ�ͣ��㻺����$N��ǰ��ȥ��$N�󾪣��������\n��һҧ��һ��"RED"��Ѫ"HIR"���������ȥ������һʢ�����˹�����\n"NOR:HIW "$N��ʱ�������ް��Ѫɫ��һ�ڿ�"RED"��Ѫ"HIW"��ס���������ȥ��Ҫ������ƻأ�\n"NOR;     
				message_combatd(msg, me);
			}
			break;
	} 
	period++;
	me->set_temp("huoqiang/period", period);
	return 1;	
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˺��Է�����
		���˶Է���Ѫ
		��ĶԷ�����

	����Ҫ��
		������150��
		������150��
		��������120��
		������Ϊ1000
		����800
		��Χ�л��
HELP
	);
	return 1;
}

