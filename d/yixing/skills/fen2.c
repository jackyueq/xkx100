// /kungfu/skill/huoyan-dao/fen.c
// /d/yixing/skills/fen.c perform ��
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
#include <armor.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object armor;
	int damage;
	string *limb, type, result, str;

	type = "����";

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�㲻��ս���С�\n");

	if ( objectp(me->query_temp("weapon")) )
		return notify_fail("�㲻�ǿ��֡�\n");

/*
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
*/
	
	if( (int)me->query_skill("huoyan-dao", 1) < 120 )
		return notify_fail("��Ļ��浶��Ϊ������\n");
	if ( me->query_skill_mapped("force") != "xiaowuxiang" &&
		me->query_skill_mapped("force") != "longxiang-banruo")
		return notify_fail("�������ڹ����ԣ�\n");
	if( me->query("neili") <= 500 )
		return notify_fail("�������������\n");
	message_vision(HIR "$N����һ�������������������������Ʊ��ͨ�죬���һ������������$n����Ӱ��������һ�Ż���֮�С�\n\n" NOR, me,target);
//	tell_object(target, BLU "��ֻ��һ���������棬�����ؿ�һ���ʹ��\n"NOR);
	me->add("neili", -100);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		if( target->query_temp("armor/cloth"))
		{
			armor = target->query_temp("armor/cloth");
			if( armor->query("armor_prop/armor") < 150)
			{
				message_vision(HIY"ֻ��$N���ϵ�$n"+HIY+"�ѱ���÷��飬���һ����Ʋ����ڵ��ϡ�\n"NOR, target, armor);
				armor->unequip();
				armor->move(environment(target));
				armor->set("name", "�����" + armor->query("name"));	
				armor->set("value", 0);
				armor->set("armor_prop/armor", 0);
				target->reset_action();
			}
		}
		damage = random((int)me->query_skill("strike"))*5;
		target->receive_damage("qi", damage, me); 
		target->receive_wound("qi", (int)me->query_skill("huoyan-dao", 1), me);
		target->start_busy(1+random(3));
		
		limb = target->query("limbs");
		result = COMBAT_D->damage_msg(damage, type);
		result = replace_string( result, "$l", limb[random(sizeof(limb))]);
		result = replace_string( result, "$p", target->name() );
		message_vision(result, me, target);

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		message_vision("($N"+str+")\n", target);
	}
	else 
	{
		message_vision(HIY "$p�Ͻ�����Ծ�����ɣ��㿪$P�Ĺ�����\n" NOR, me, target);
	}
	me->start_busy(1+random(3));
	return 1;
}
