// dashouyin.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <condition.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage, p;
	string msg;
  if (me->is_ghost()) return 1;
	damage = me->query_condition("dashouyin") +2;
	damage *= me->query_con();
	
	tell_object(me,"ͻȻ��о��ؿ���ʹ�쳣���ղű�����ӡ���е��߹Ǵ�����Ҫ�ѿ����Ƶģ���ѪҲ�ӿ������˳�����\n");
	tell_room(environment(me),HIR + me->name()+"ͻȻһ�Բ�����˫�����أ��ŵ��㵹���������������۵�һ���³�����Ѫ����\n" NOR,({ me }));
	me->receive_damage("qi", damage,"����ӡ��������");
	me->receive_wound("qi", damage/2,"����ӡ��������");
	p = (int)me->query("qi")*100/(int)me->query("max_qi");
	msg = "( $N"+eff_status_msg(p)+" )\n";
	if( living(me) && !me->query_temp("noliving")) message_vision(msg, me);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("dashouyin", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
