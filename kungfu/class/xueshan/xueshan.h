// xueshan.h

string ask_for_join()
{
	object me = this_player();

	if( (string)me->query("class")=="lama" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";

	if( (string)me->query("gender") != "����" )
		return "ʩ��������������ǿ�ϲ�ɺأ���ϧ����ֻ����ͽ��\n";

	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	if( !me->query_temp("pending/join_bonze") ) return 0;
	message_vision("$N˫�ֺ�ʮ�����������ع���������\n\n$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n", me, this_object() );
	command("smile");
	me->set("class", "lama");
	return 1;
}

