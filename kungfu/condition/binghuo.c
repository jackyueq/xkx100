// binghuo.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) || me->query_temp("noliving") )
		message("vision", me->name() + "���˸��ã������³�һ������֮����\n", environment(me), me);
	else
		message("vision", me->name() + "ҡͷ���Ե�վ��վ���ȣ����ľ�������İߵ㡣\n", environment(me), me);

	me->apply_condition("binghuo", duration - 1);
	if( !duration ) return 0;
	return 1;
}

string query_type(object me)
{
	return "drunk";
}

