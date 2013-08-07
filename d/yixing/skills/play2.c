// /d/yixing/skills/play2.c �̺�������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object weapon, room, *inv;
	int i, dp, skill, damage;

	if( (int)me->query("neili") < 800 ) {
		tell_object(me, "�������������\n");
		return 1;
	}

	room = environment(me);
	if( room->query("no_fight") ) {
		tell_object(me, "�����ﲻ�ܹ������ˡ�\n");
		return 1;
	}

	if( !(weapon = me->query_temp("weapon")) ) {
	       tell_object(me, "��ʹ�õ��������ԡ�\n");
	       return 1;
	}

	if( (string)weapon->query("id") != "yu xiao"
	&&  (string)weapon->query("id") != "tie xiao"
	&&  (string)weapon->query("id") != "zhu xiao" ) {
		tell_object(me, "��ʹ�õ��������ԡ�\n");
		return 1;
	}
	
	if( (string)me->query_skill_mapped("force") != "bitao-xuangong" ) {
		tell_object(me, "�����õĲ��Ǳ����������޷�ʩչ�̺���������\n");
		return 1;
	}
	
	if( (skill = (int)me->query_skill("bitao-xuangong", 1)) < 80 ) {
		tell_object(me, "��ı����������δ�����޷�ʩչ�̺���������\n");
		return 1;
	}

   //  modified by aln to give a more reasonable damage
	me->add("neili", -100);
	me->receive_damage("qi", 10);

   //  modified by aln to give a more reasonable busy time
	me->start_busy(1 + random(5 - skill/60));
	message_vision(
		HIG "$N���һ֧���Ǳ���������ŵ����ߴ���������������ת���࣬������˽��������ڷ��ء���\n" NOR, me);

	inv = all_inventory(room);
	for(i = 0; i < sizeof(inv); i++) {
		if( !living(inv[i]) || inv[i] == me ) continue;

		dp = (int)inv[i]->query_skill("force");
		if( random(skill + dp) <= dp * 3 / 2 ) {
	// modified by aln to let enemy kill
	// if you bother them by play, they should kill you
			inv[i]->kill_ob(me);
			continue;
		}

	// modified by aln to give a more reasonable damage
		damage = skill * 40 / ((int)inv[i]->query_con() + 20);

		inv[i]->receive_damage("jing", damage);
		inv[i]->receive_damage("qi", damage);

		message_vision(HIM"$N����ȫ��ƮƮ���ɣ�����¶����㯶���������飬�鲻�Խ��������㵸����......\n"NOR, inv[i]);
		inv[i]->start_busy(damage/100);
	}

	return 1;
}

