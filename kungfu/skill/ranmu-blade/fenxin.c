// renmu-daofa ȼľ����

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "�����ġ�"
int perform(object me, string arg)
{
	object weapon, target;
	int i, j, z;       
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

	if (weapon->query("id") != "mu dao" || weapon->query("ownmake"))
		return notify_fail("��û��ľ�����޷�ʹ�������ġ�������\n");

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

	if( (int)me->query_skill(fskill, 1) < 170 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 160 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 140 )
		return notify_fail("���"+to_chinese(bskill)+"��������죬ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill("force", 1) < 200 )
		return notify_fail("����ڹ��ȼ�������ʹ���������ġ�������\n");

	if( (int)me->query_str() < 32)
		return notify_fail("�������������ǿ����ʹ���������ġ���\n");
	if( (int)me->query_dex() < 30)
		return notify_fail("�����������Ѹ�ͣ�ʹ���������ġ���\n");

	if(me->query_temp("ranmu")) 
		return notify_fail("����������ʹ�á����ġ�������\n"); 

	if (me->query_temp("fumo"))
		return notify_fail("����������ʹ�á���շ�ħ���񹦡�\n"); 

	if (me->query("neili") < 1000)
		return notify_fail("�������������\n");

	j = me->query_skill("blade", 1)/10;
	z = me->query_skill("force", 1)/10;
	i = me->query_skill("force", 1)/10;
	me->add("neili", -j*8);
	me->add_temp("apply/strength", z);
	me->add_temp("apply/attack", j); 
	me->add_temp("apply/damage", 80);
	me->set_temp("ranmu", 1);
	call_out("check_fight", 1, me, z, j, i);
	message_combatd(HIR "$N"HIR"���ƺ�Ҿ��ͻȻ����һ��������������Ͻ�շ�ħ����\n���е�ľ����ʱ����һ�Ż��棬������������$n����Χס��\n"NOR,me,target);
	return 1;
}

void remove_effect(object me, int j, int z, object weapon)
{
	object piece;
	me->add_temp("apply/strength", -z);
	me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -80);
	me->delete_temp("ranmu");
	tell_object(me, HIR"�㡸���ġ�����������ϣ����ص���");
	if (weapon && weapon->query("id") == "mu dao")
	{
		weapon->unequip();
		seteuid(getuid());
		piece = new("/clone/misc/piece");
		piece->set_name("ľͷ", ({ "mu tou" }));
		piece->set("unit", "��");
		piece->set("long","һ��ľͷ��\n");
		tell_object(me, "�����е�ľ�������һ��ľͷ��\n" NOR);
	  piece->move(me);
	  destruct(weapon);
	}
	else tell_object(me, "��\n" NOR);
}

void check_fight(object me, int z, int j, int i)
{
	object weapon;      

	if (!me) return;
	if(!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id") != "mu dao" ||
		weapon->query("skill_type") != "blade")
	{
		remove_effect(me, j, z, weapon);
		return;
	}
	if (i < 1 || !me->is_fighting())
	{
		remove_effect(me, j, z, weapon);
		return;
	}
	call_out("check_fight", 1, me, z, j, i-1);
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
        write(@HELP

        ʹ�ù�Ч��
                ��������ľ����������������

        ����Ҫ��
                ȼľ����160��
                ��������140��
                �����ڹ�200��
                �׽170��
                ��������32
                ������30
                ����1000
HELP
        );
        return 1;
}

