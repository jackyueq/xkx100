//hongtianza.c ��������֮�������ҡ�
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define PNAME "�����ҡ�"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg,*limbs;
	int i,size,damage;
	int p;
	object my_w,target_w,piece;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	my_w = me->query_temp("weapon");
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
	target_w = target->query_temp("weapon");
//	if( target->is_busy() )
//		return notify_fail(target->name() +"Ŀǰ��ãȻ��֪���룬�ӽ������ɡ�\n");

	if (!objectp(my_w = me->query_temp("weapon"))
		|| (string)my_w->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������ʹ����"+PNAME+"��\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	me->add("neili", -300);
	msg = CYN"$NͻȻ����һ���������ң����ң��������ң��������о޸���Ȼ����$p���б��У�\n"NOR;

	if(target->query_temp("weapon")||target->query_temp("secondary_weapon"))
	{	
		me->start_busy(2);
		if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
		{
			if( target_w->weight() > 2 * random(my_w->weight()) )
			{
				msg += "���$p���е�" +target_w->query("name") + "��$P�ĺ������Ҹ����ţ���Ҳ���ղ�ס���������ַɳ���\n" NOR;
				target_w->unequip();
				target_w->move(environment(target));
				target->reset_action();
				if (!target->is_busy())
				target->start_busy((int)me->query_skill(bskill, 1) / 30);
			}
			else
			{
				msg += HIC"ֻ��$n���е�"+target_w->query("name")+"��Ȼ���Ҷ������Σ������ܵ�$N�ľ����ļ�������$nѸ����ȥ��\n"NOR;
				target_w->unequip();
				target->reset_action();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "һ�ѱ�������Ƭ��\n");
      	piece->set_name( target_w->query("name") + "����Ƭ", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
				if (!target->is_busy())
				target->start_busy((int)me->query_skill(bskill, 1)/40);
				limbs=target->query("limbs");
				me->start_busy(1);
				size=(int)(me->query_skill(bskill, 1)/10);
				damage=random(size)+size;
				damage=damage+me->query_str()/3+random(me->query_temp("apply/damage"));
				for(i=0;i<=random(size);i++)
				{
					msg+=HIB"���͡�����Ƭ����$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
					target->receive_damage("qi",damage,me);
					target->receive_wound("qi",damage/3,me);
				}
				p = (int)target->query("qi")*100/(int)target->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
//				COMBAT_D->report_status(target);
			}
		} else {
			msg+="����$p�����е�"+target_w->query("name")+"һ�࣬��û����$P������ʲô��\n" NOR;
		}
		message_combatd(msg,me,target);
		return 1;
	}
	return notify_fail(target->name() + "Ŀǰ�ǿ��֣�������ʲô��\n");
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ݻٶԷ����������ñ�����Ƭ����

	����Ҫ��
		��������100��
		���Ƹ�100��
		����500
HELP
	);
	return 1;
}

