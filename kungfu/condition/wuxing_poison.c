// wuxing_poison.c ����֮��

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit,limit1,limit2,limit3,limit4,damage;
  if (me->is_ghost()) return 1;
	damage = me->query("max_qi")/30;
	if(damage < 20) damage = 20;
	limit = me->query("con") + (int)me->query_skill("force",1) / 10;
	if(me->query_temp("nopoison")) return 0;
	if(limit >50) limit =49;
	limit1=50 - limit + 2;
	limit2=50 - limit*2/3;
	limit3=50 - limit/2;
	limit4=50 - limit/4;
	if( duration < limit1 && living(me) && !me->query_temp("noliving") )
	{
		tell_object(me,"�㶾�����ģ����絶�ʣ����ɵô��һ����һ����Ѫ���������\n");
		message("vision", me->name() + "��Ȼ���һ����������Ѫ���粻ֹ��һͷ�Ե��ڵ��ϡ�\n", environment(me), me);
		me->unconcious();
		me->die();
		return 0;
	}
	if( duration > limit4 )
	{
		tell_object(me,"���Ȼ���ø�ʹ��ʣ���ǰһ�󷢺ڣ�һ���ǳ���ʲô�ж��Ķ�����\n");
		message("vision", me->name() + "��Ȼ��ɫ�԰ף�����ĺ���Ӷ�ͷ������\n", environment(me), me);
	}
	if( duration > limit3 && duration < limit4)
	{
		tell_object(me,"����øγ���ϣ�ȫ��ʹ�������һ�ţ������ƺ��Ѿ���ʼ��ɢ�ˡ�\n");
		message("vision", me->name() + "�촽���࣬����ҧ�Ŀ���ֱ�죬�����Ѿ���������һ�š�\n", environment(me), me);
	}
	if( duration > limit2 && duration < limit3)
	{
		tell_object(me,"�������֫�Ѿ���ľ�������Ѿ�����С�������ҽ�ҩ�ɣ���������ġ�\n");
		message("vision", me->name() + "�����ֳ�һ�ɺ�����˫Ŀͻ��������ȫ��ͨ���Ѫ˿��\n", environment(me), me);
	}
	if( duration > limit1 && duration < limit2)
	{
		tell_object(me,"�����һ��������ת�������������ؿڣ����ҽ�ҩ�ɣ���������ġ�\n");
		message("vision", me->name() + "���Ϻ���Խ��ԽŨ�ˣ�ȫ������죬���������һ�ƺ�Ѫ��\n", environment(me), me);
	}
	me->receive_wound("qi", damage,"����֮������");
	me->receive_damage("jing", damage,"����֮������");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("wuxing_poison", duration - 1);
	if( !duration ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
