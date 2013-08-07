// /d/yixing/skills/chan2.c  �������־�
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg, skill, spskill, spforce;
	object weapon;

	mapping forces = ([
		"sword" : "taiji-shengong",
		"stick" : "huntian-qigong",
		"whip"  : "hunyuan-yiqi",
	]);

	mapping skills = ([
		"sword" : "taiji-jian",
		"stick" : "dagou-bang",
		"whip"  : "riyue-bian",
	]);

	if( me->is_busy() ) {
		tell_object(me, "����һ��������û����ɣ�����ʩ���⹦��)\n");
		return 1;
	}

	if( me->query("neili") <= 300 ) {
		tell_object(me, "�������������\n");
		return 1;
	}

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) ) {
		tell_object(me, "ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		return 1;
	}

	if( target->is_busy() ) {
		tell_object(me, target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
		return 1;
	}

	if( !(weapon = me->query_temp("weapon")) ) {
		tell_object(me, "������û�����������ʹ�ò��־���\n");
		return 1;
	}

	skill = (string)weapon->query("skill_type");
	if( member_array(skill, keys(skills)) == -1 ) {
		tell_object(me, "��ʹ�õ���������ʹ��ʩչ���־���\n");
		return 1;
	}

	spskill = skills[skill];
	if( me->query_skill_mapped(skill) != spskill ) {
		tell_object(me, "�����ڲ���ʹ��" + to_chinese(spskill) + "��\n");
		return 1;
	}

	if( (int)me->query_skill(skill) < 100 ) {
		tell_object(me, "���" + to_chinese(spskill) + "������죬����ʹ�á������־���\n");
		return 1;
	}

	spforce = forces[skill];
	if( (int)me->query_skill(spforce, 1) < 80 ) {
		tell_object(me, "���" + to_chinese(spforce) + "��Ϊ����������ʹ�á������־���\n");
		return 1;
	}

	if( me->query_skill_mapped("force") != spforce ) {
		tell_object(me, "�����õ��ڹ�������\n");
		return 1;
	}

	me->add("neili", -80);

	switch(spskill) {
	case "taiji-jian":
		msg = CYN "$Nʹ��̫�������������־�����������������ͼ����$n�Ĺ��ơ�\n";
		break;
	case "dagou-bang":
		msg = CYN "$Nʹ���򹷰����������־����ó���ɽ��Ӱ����$n��û��\n";
		break;
	case "riyue-bian":
		msg = HIY "$Nʹ�����±޷���������ƾ����������ޣ���������ŵ���$n��ȫ���ȥ��\n";
		break;
	}

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		switch(spskill) {
		case "riyue-bian":
			msg += "���$p��$P���˸����ֲ��������������Ӱ�������У�\n" NOR;
			break;
		case "taiji-jian":
			msg += "���$p��$P���˸����ֲ�����\n" NOR;
			break;
		case "dagou-bang":
			msg += "���$p��$P���˸���æ���ң�һʱ�޷����н�����\n" NOR;
			break;
		}
		target->start_busy(1 + random( (int)me->query_skill(spskill, 1) / 20));
	} else {
		switch(spskill) {
		case "riyue-bian":
			msg += "����$p������$P�ı޷�ȥ·�����ݵ����˿�ȥ��\n" NOR;
			break;
		default:
			msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
			break;
		}

		me->start_busy(1 + random(3));

	}

	message_vision(msg, me, target);
	return 1;
}

