// cold_poison.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
#include <condition.h>;
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", HIW+me->name()+"ɪɪ������ȫ�����һ�㱡���İ�˪��\n"NOR, environment(me), me);
	}
	else {
		tell_object(me, HIW"��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵��������ţ����еĺ��������ˣ�\n"NOR);
		message("vision", HIW+me->name()+"ȫ���������ظ��ֱ�죬����Ƭ�̣��촽Ҳ���ˣ���ɫ����������ס�\n"NOR, environment(me), me);
	}
	me->receive_damage("qi", 35,"���ں�������");
	if(userp(me)) me->receive_wound("jing", 20,"���ں�������");
	else me->receive_wound("jing", 40,"���ں�������");
	if(!me->is_busy()) me->start_busy(2);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("cold_poison", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
