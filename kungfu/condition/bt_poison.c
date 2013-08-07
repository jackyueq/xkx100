// Last Modified by winder on May. 15 2001
// bt_poison.c ���չ��߶�
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") ) return CND_CONTINUE;
	tell_object(me, HIB "���Ȼ�е����彩ֱ���Ѿ�����ʹ���ˡ�\n" NOR);
	me->receive_wound("qi", 50,"���ڹ���֮������");
	if(userp(me)) me->receive_wound("jing", 60,"���ڹ���֮������");
	else me->receive_wound("jing", 80,"���ڹ���֮������");
	if( me->query("jing") > 301)
		tell_room(environment(me),YEL+me->name()+"ͻȻֻϥ�����������������£����з����������޵ĺɺ�֮����\n" NOR, ({ me }));
	else
		if( me->query("jing") < 450 && me->query("jing") > 301)
			tell_room(environment(me),BLU+me->name()+"��Ȼ����ѻ�������Ц�����Եù������ס�\n" NOR, ({ me }));
		else
			if( me->query("jing") < 300 && me->query("jing") > 201)
				tell_room(environment(me),HIB+me->name()+"��ʱ���Ǹ��Ӻ�Ϳ��ָ���������ҡ���ҧ��\n" NOR,({ me }));
			else tell_room(environment(me), HIR+me->name()+"ͻȻ����һ�ţ����ڵ��ϲ�ͣ�ط�����\n" NOR,({ me }));
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("bt_poison", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
