// ���������ǽ�֮˫���ϱ�
// Last Modified by Winder on Jun. 23 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��˫����赡�"
int remove_effect(object me);
int remove_effect1(object target);
// ��bug�����
int perform(object me, string arg)
{
	object weapon, weapon1, target;
	int skill, skill1;
	string msg;
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

	if(!arg) return notify_fail("�����˭һ���赣�\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
/*��Ҫ�ж��Ƿ񹥻�ͬһ����*/
	if( !target->is_fighting() ||
		!target->is_character() ||
		!me->is_fighting())
		return notify_fail("���ֻ����ս����ʹ�á�\n");
	if( !living(target) || target->query_temp("noliving") )
		return notify_fail(target->name()+"�Ѿ��޷�ս���ˡ�\n"); 
	if(target==me) return notify_fail("���Լ���赣�\n"); 
	if(me->is_fighting(target))
		return notify_fail("�����ں�"+target->name()+"����ء�\n");
	weapon = me->query_temp("weapon");  
	weapon1 = target->query_temp("weapon");  
	if(!weapon || weapon->query("skill_type") != "sword" ||
		me->query_skill_mapped("sword") != "liangyi-sword" ||
		me->query_skill_mapped("parry") != "liangyi-sword")
		return notify_fail("�������޷�ʹ�á�˫����赡���\n");

	if(!weapon1 || weapon1->query("skill_type") != "sword" ||
		target->query_skill_mapped("sword") != "liangyi-sword" ||
		target->query_skill_mapped("parry") != "liangyi-sword")
		return notify_fail(target->name()+"�����޷�ʹ�á�˫����赡���\n");
	skill = me->query_skill("liangyi-sword", 1);
	skill1 = target->query_skill("liangyi-sword", 1);
	if(skill < 100 )
		return notify_fail("������ǽ����ȼ�����������ʹ�á�˫����赡���\n");
	if((int)me->query_skill("xuantian-wuji", 1) < 100 )
		return notify_fail("��������޼����ȼ�����������ʹ�á�˫����赡���\n");	   
	if((int)me->query("neili") < 500 )
		return notify_fail("����������̫��������ʹ�á�˫����赡���\n");
	if((int)me->query("max_neili") < 1000 )
		return notify_fail("����������̫��������ʹ�á�˫����赡���\n");
	if(me->query_temp("ly_hebi")) 
		return notify_fail("���Ѿ���ʹ�á�˫����赡��ˡ�\n");
	if(target->query_temp("ly_hebi")) 
		return notify_fail(target->name()+"�Ѿ��ں�����ʹ�á�˫����赡��ˡ�\n");
	if(me->query_temp("lyhebi_target"))
	{
		if(me->query_temp("lyhebi_target")==target)
			return notify_fail("���Ѿ����ú�"+target->name()+"˫����赵�׼���ˡ�\n");
		else
		{
			tell_object(me->query_temp("hebi_target"), YEL+me->name()+"������������˫������ˡ�\n"NOR); 
			me->delete_temp("lyprepare_hebi");
			me->delete_temp("lyhebi_target");
		}
	}
	if(target->query_temp("lyprepare_hebi") &&
		target->query_temp("lyhebi_target") ==me)
	{
		message_combatd(MAG"\n $N��$nʹ����ɫ,����"+weapon->name()+MAG+"��$n��"+weapon1->name()+MAG+"���������˫�����ϣ���ʱֻ����������������������\n"NOR, me, target);
		me->delete_temp("lyprepare_hebi");
		me->delete_temp("lyhebi_target");
		target->delete_temp("lyprepare_hebi");
		target->delete_temp("lyhebi_target");
//		me->set_temp("ly_hebi", 1); 
		target->set_temp("ly_hebi", 1); 
		me->add("neili", -200);
		target->add("neili", -200);
		me->add("qi", -50);
		target->add("qi", -50);
		remove_call_out("check_reply");
		me->start_call_out( (: call_other, __FILE__, "check_fight", me, target :), 1);
		target->start_call_out( (: call_other, __FILE__, "check_fight", target, me :), 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (skill+skill1)/2);
		target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), (skill+skill1)/2);
		return 1;
	}
	message_combatd(HIC"\n $N������"+weapon->name()+HIC"һ�ᣬ��ʾ$n��$Pһ������˫����赡�\n"NOR, me, target);
	tell_object(target, YEL"�����Ը���"+me->name()+"����˫���ͱڣ���Ҳ��"+me->name()+"��һ�� ( perform hebi <player's id> ) �����\n"NOR); 
	me->set_temp("lyprepare_hebi", 1);	 
	me->set_temp("lyhebi_target", target);
	me->set_temp("no_unwield", 1);
	target->set_temp("no_unwield", 1);
	call_out("check_reply", 15, me,target); 
	return 1;
}

void check_fight(object me, object target)
{
	object weapon,weapon1;  
	int attack1,attack2,damage1,damage2;

	weapon = me->query_temp("weapon");  
	weapon1 = target->query_temp("weapon");  
//
	if( !me->query_temp("ly_hebi") )
	{
		damage1=(int)me->query_str()*(int)me->query_str()/10;
		damage2=(int)target->query_str()*(int)target->query_str()/10;
		attack1=(int)(me->query_skill("liangyi-sword",1)/5);
		attack2=(int)(target->query_skill("liangyi-sword",1)/5);
		me->set_temp("ly_hebi", 1); 
		me->add_temp("apply/attack", attack1);
		me->add_temp("apply/damage", damage1);
		target->set_temp("ly_hebi", 1); 
		target->add_temp("apply/attack", attack2);
		target->add_temp("apply/damage", damage2);
		remove_call_out("remove_effect");
		call_out("remove_effect", 10, me);
		remove_call_out("remove_effect1");
		call_out("remove_effect", 10, target);
	}
//
	if(!weapon || weapon->query("skill_type") != "sword" ||
		me->query_skill_mapped("sword") != "liangyi-sword" ||
		me->query_skill_mapped("parry") != "liangyi-sword")
		call_out("remove_effect", 0, me);
	if(!weapon1 || weapon1->query("skill_type") != "sword" ||
		target->query_skill_mapped("sword") != "liangyi-sword" ||
		target->query_skill_mapped("parry") != "liangyi-sword")
		call_out("remove_effect", 0, me);
	else
		if((!present(target->query("id"), environment(me))) ||
			!me->is_fighting() ||
			!living(target) || target->query_temp("noliving") || 
			!target->is_fighting() ||
			target->is_ghost() ||
			me->is_ghost() ||
			!living(me) || me->query_temp("noliving") || 
			!target->query_temp("ly_hebi"))
			call_out("remove_effect", 0, me);
	else call_out("check_fight", 1, me, target);
}
int check_reply(object me,object target )
{
	if (me->query_temp("lyprepare_hebi", 1))
	{
		me->delete_temp("lyprepare_hebi");

		me->delete_temp("lyhebi_target");
		me->delete_temp("no_unwield");
		target->delete_temp("no_unwield");
		message_combatd(HIY"�ƺ��Է���$N�İ�ʾû�з�Ӧ��$N��ֻ��ȡ����˫���ϱڵ�����\n"NOR, me);
		return 1;
	}
}
int remove_effect(object me)
{
	int attack1, damage1;
	if(me->query_temp("ly_hebi"))
	{
		damage1=(int)me->query_str()*(int)me->query_str()/10;
		attack1=(int)(me->query_skill("liangyi-sword",1)/5);
		me->delete_temp("ly_hebi");
		me->delete_temp("no_unwield");
		me->add_temp("apply/attack", -attack1);
		me->add_temp("apply/damage", -damage1);
		message_combatd(HIC"˫�������ᣬ$N�Ĺ��ػָ������ˡ�\n"NOR, me);
		return 1; 
	}
}
int remove_effect1(object target)
{
	int attack2, damage2;
	if(target->query_temp("ly_hebi"))
	{
		damage2=(int)target->query_str()*(int)target->query_str()/10;
		attack2=(int)(target->query_skill("liangyi-sword",1)/5);
		target->delete_temp("ly_hebi");
		target->delete_temp("no_unwield");
		target->add_temp("apply/attack", -attack2);
		target->add_temp("apply/damage", -damage2);
		message_combatd(HIC"˫�������ᣬ$N���ػָ������ˡ�\n"NOR, target);
		return 1; 
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����ȼ�������˲ſ���ʹ�ã��ɼ�ǿ����������

	����Ҫ��
		�����޼���100��
		���ǽ���Ч100��
		������� 1000
		���������ǽ���Ϊ�мܼ���
		���������ǽ���Ϊ��������
HELP
	);
	return 1;
}

