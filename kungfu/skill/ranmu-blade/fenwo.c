// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�����ҡ�"
int perform(object me, object target)
{
	object weapon,piece;
	int i;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (weapon->is_unique())
		return notify_fail("������֮�����Ƿ���֮����ʹ�á����ҡ�����û��ʲô���ã�\n");

	fskill = "yijinjing";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�������ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("���"+to_chinese(bskill)+"��������죬ʹ����"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("force") != "yijinjing")
			return notify_fail("û���׽��Ϊ���������޷�ʹ�������ҡ������ģ�\n"); 
	}
	if( (int)me->query_str() < 34)
		return notify_fail("�����������ǿ����ʹ���������ҡ�������\n");
	if( (int)me->query_int() < 34)
		return notify_fail("û�д��ǻ۴��������ʹ�������Ҿ����ġ�\n");
	if(me->query_temp("ranmu")) 
		return notify_fail("����������ʹ�á����ġ�������\n"); 
	if (me->query_temp("fumo"))
		return notify_fail("����������ʹ�á���շ�ħ���񹦡�\n"); 
	if (me->query("max_neili") < 2000)
		return notify_fail("���������Ϊ������\n");
	if (me->query("neili") < 650)
		return notify_fail("�������������\n");
	me->add("neili", -600);
	message_combatd( HIR"\n$N˫�Ƽе���ʮ�����е�"+weapon->name()+HIR"��ʱ����һ�Ż��潫�Լ���Χ��$N"HIR"����һ����ţ�һ��ֱ����$n"HIR"��\n"NOR,me,target);	

//fenwo's damage depends on how many times u pfmd	
	i = me->query("fenwo");
	if(i > me->query_skill("blade")) i = me->query_skill("blade");
	i -= me->query("age");
//and it will not be over ur enable blade skill

	me->add_temp("apply/damage", i);
	me->set_temp("fenwo_hit", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add("fenwo",1);
	weapon->add("fenwo", 1);
	if (weapon && weapon->query("fenwo") >= (3+weapon->query("rigidity")))
	{
		message_combatd(HIY "\nֻ�������ǡ�������$N���е�$n"HIY"�����ܻ������ѳ�����Ƭ��\n"NOR,me,weapon);
		weapon->unequip();
   	seteuid(getuid());
   	piece = new("/clone/misc/piece");
   	piece->set("long", "�ճ���Ƭ��һ�����¡�\n");
   	piece->set_name( "���ѵ�" + weapon->query("name"), ({weapon->query("id"),"piece"}) );
   	piece->move(environment(me));
 		destruct(weapon);
		me->reset_action();
	}
	me->add_temp("apply/damage", -i);
	me->delete_temp("fenwo_hit");
	me->start_busy(2+random(2));
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
        write(@HELP

        ʹ�ù�Ч��
		�ٻ��Լ����У���������

        ����Ҫ��
                ȼľ����150��
                ��������150��
                �׽120��
                ��������34
                ��������34
                ������Ϊ2000
                ����650
HELP
        );
        return 1;
}

