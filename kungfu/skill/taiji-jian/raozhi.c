// raozhi.c ����ָ�ὣ��
// Last Modifyed by Winder on Jan. 14 2002

/*
��·����ָ�ὣ��ȫ���Ի���������佣�У�ʹ������˸�޳����������Ե��ܡ�
��������δ������Ƚ�������æ������ܣ������һ�����죬�ǽ�����������
ֱ�����������ϱۡ�
*/

#include <ansi.h>
void remove_effect(object me, object weapon, int sword, int force);
inherit F_SSERVER;
#define PNAME "����ָ�ὣ��"
int perform(object me,object target)
{
	int force, sword;
	object weapon = me->query_temp("weapon");
	string shape = weapon->query("id");
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
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽�������ʹ������ָ�ὣ������\n");

	if( me->query_temp("wudang/raozhi") )
		return notify_fail("���Ѿ���������ע�뽣���ˣ���\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ���δ�㣬�޷����������佣�У�\n");

	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������������ʩչ"+PNAME+"��\n");

	if( me->query_skill_mapped("force") != fskill )
			return notify_fail("�����õ��ڹ��롸��ָ�ὣ���ķ���㣣�\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if(userp(me) && !me->query("wudang/raozhi") )
			return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ����ָ�ὣ����\n");
	}

  if( me->query_temp("taiji"))
    return notify_fail("���Ѿ�����̫���ķ���û��̫�ྫ��ʩչ����ָ�ὣ����\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("�������������񣬾��������Ա��佣�У�\n");

	if( me->query("neili") <= 500 )
		return notify_fail("����������������������Ա��佣�У�\n");

	if( me->query("qi") <= 400 )
		return notify_fail("����������ޣ�����ʩչ����ָ�ὣ����\n");

	if( shape == "iron sword" )
		return notify_fail("������֮���ʵع�춼�Ӳ������������������䣡\n");

	if( weapon->query("ownmake"))
	  return notify_fail("������������ʩչ����ָ�ὣ����\n");

	if( shape == "tie di" || shape == "tie xiao" || shape == "zhu xiao" ||
		shape == "yu xiao")
		return notify_fail("�����״���ʺ�ʩչ����ָ�ὣ����\n");

	if( shape == "xiuhua zhen" || shape == "qijue zhen" ||
		shape == "emei ci" || shape == "duanjian" || shape == "bishou" )
		return notify_fail("����彣̫�̣����ʺ�ʩչ����ָ�ὣ����\n");

	me->add("neili", -100);
	me->receive_damage("qi", 150);

	if( (string)weapon->query("material") != "steel" || weapon->query("rao"))
	{
		message_combatd(HIW"\n�͵���$Nһ����Х���������䡣��������"+weapon->name()+HIW"ȴ�Ѿ���ס����������ѳ���Ƭ����\n"NOR, me);
		destruct(weapon);
		me->reset_action();
		me->start_busy(1);

		return 1;
	}

	force = me->query_skill("force")/2;
	sword = me->query_skill(bskill)/3;

	weapon->add("rigidity", -force);
	weapon->set("rao",1);
	me->add_temp("apply/attack", sword);
	me->set_temp("wudang/raozhi", sword);

	message_combatd(HIG"\n�͵���$Nһ����Х���������䣬�Ǳ�"+ weapon->name() +HIG"���Ƴ���һ��������������ۣ�Ʈ��������\n�����䵱�ɾ���"+ HIW +"����ָ�ὣ��"+ HIG +"��\n"NOR, me);

	call_out("checking", 1, me, weapon, sword, force);
	return 1;
}

void checking(object me, object weapon, int sword, int force)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() || !objectp(weapon))
	{
		remove_effect(me, weapon, sword, force);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIG "\n$N��ָ�ڽ���������һ����ֻ����" + weapon->name() + HIG"��������֮�죬����ͣ������\n"+CYN+"$N˳������һ���������������ջء�\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( environment(weapon) != me || weapon !=me->query_temp("weapon"))
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIR "\n$N��������" + weapon->name() +HIR"���������ջأ�\n"NOR, me);
		return;
        }
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("qi") < (int)me->query("max_qi") / 4 )
	{
	        remove_effect(me, weapon, sword, force);
        	tell_object(me,HIR"\n��΢����Ϣ���������ò��������ջأ�\n" NOR);
		message("vision", CYN+"\n"+ me->name() + weapon->name() + CYN"Ȧת���ջؽ��ơ������Ѳ���֮ǰ��˸�޳�����ò�����\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("sword") != "taiji-jian" &&
		!me->is_busy() )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(CYN "\n$NȦת" + weapon->name()+ CYN"��ͻȻ���У�ʹ����"+ HIW +"��̫������"+ NOR + CYN"��ͬ�Ľ�����\n"NOR, me);
		return; 
	}
	else if( me->query_temp("wudang/raozhi") <= 50 )
	{
		remove_effect(me, weapon, sword, force);
		message_combatd(HIC "\n$N" + weapon->name()+ HIC"Ȧת���ѿ�����һ·"+ HIW +"����ָ�ὣ��"+ HIC +"����ʹ����\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, weapon, sword, force);
} 

void remove_effect(object me, object weapon, int sword, int force)
{
	me->delete_temp("wudang/raozhi");
	me->add_temp("apply/attack", -sword);
  if (objectp(weapon))
  {
  	weapon->add("rigidity", force);
  	weapon->delete("rao");
  }
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
                ��ָ�ὣȫ���Ի���������佣�У�ʹ������˸�޳����������Ե��ܡ�

	����Ҫ��
		̫����180��
		̫������180��
		����̫���񹦺�̫������
		������Ϊ1500
		����500
		��Ѫ400
		���Եѧ��
HELP
	);
	return 1;
}

