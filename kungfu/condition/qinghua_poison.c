// Last Modified by winder on May. 15 2001
// qinghua_poison.c �黨��
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me, HIM"�����ָ�ϴ���ͻȻ��ʹ���˿�΢ϸ��ʹ����Ȼ����֮����������\n����ظ����ô������ͻ�һ�£����̲�ס��������һ�����˳�����æ\n����ָ���ڿ���˱����\n" NOR );
	tell_room(environment(me), MAG+ me->name()+"ȫ������Ϊǧ��ֻ�Ʒ�ͬʱ��ҧ����֫�ٺ�����ʹ�ѵ����̲�ס�����ŽС�\n" NOR, ({ me }));
	me->receive_damage("qi", 15,"���黨��");
	me->receive_wound("jing", 15,"���黨��");
	if(!me->is_busy()) me->start_busy(2); 
		me->apply_condition("qinghua_poison", duration - 1);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
