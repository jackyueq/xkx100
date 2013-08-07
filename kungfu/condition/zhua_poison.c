// zhua_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( duration < 1 ) return 0;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "ʹ��������š�\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"��Ȼһ˿��������������, �����Ľ�������֫�ٺ���ԭ�����е���Ѫ��ץ�����ˣ�\n"NOR );
		message("vision", me->name() + HIR "������ͻȻһ�����, ����ҧ�ÿ������졣\n"+me->name()+"��Ȼ����һ������,����¶��ʹ��������Ц�ݡ�\n" NOR, environment(me), me);
	}
	me->receive_wound("qi",25 + random(20));
	me->receive_wound("jing", 25);
	me->set_temp("last_damage_from", "��Ѫ��ץ��������");
  if (me->is_ghost()) return 0;
	me->apply_condition("zhua_poison", duration - random(3));
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
