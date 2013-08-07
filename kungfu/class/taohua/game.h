// ����ǩ��Ϸ��ÿ����1-3�����õ����һ������

#define		MATCHNUM	15	
#define		MAXNUM		3
#define 	obname  ob->query("name")
#define 	REMAIN	me->query_temp("match_game/remain")

int play_game( object me, object ob )
{
	me->set_temp("match_game/turn", 1);
	me->set_temp("match_game/remain",MATCHNUM);
	me->set_temp("match_game/last",0);
	me->set_temp("match_game/playing",1);
	message_vision(obname+"��֪�������ó�������ǩ���������ϡ�\n", me);
	command("say ������"+chinese_number(MATCHNUM)+"����ǩ��ÿ�����������������һ�������ܲ��á�˭�õ����һ�����䡣");
	command("say �����ðɡ�\n");
	add_action("take_match","take");
	write(YEL +"������� take + ���� ���档\n\n"+ NOR);
	return 1;
}


int take_match(string arg)
{
	int n;
	object me = this_player();
	object ob = this_object();
	
	if (me->query_temp("match_game/win") || me->query_temp("match_game/lost"))
		return 	notify_fail("��Ϸ�Ѿ������ˡ�\n\n");
	n = atoi(arg);
	if (!intp(n))
		return notify_fail("��Ҫ��ʲô��\n");
	if (n > MAXNUM || n <= 0)
		return notify_fail("һ��ֻ����һ��"+chinese_number(MAXNUM)+"����ǩ��\n");
	if (n > REMAIN) 
		return notify_fail("ֻʣ��"+chinese_number(REMAIN)+"����ǩ�ˡ�\n");
	me->add_temp("match_game/remain", -n);
	message_vision("$N����"+chinese_number(n)+"����ǩ\n", me);
	if (REMAIN == 0) {
		message_vision(WHT +"û����ǩ�ˣ�$N���ˡ�\n"+ NOR, me);
		message_vision(obname+"Ц�������֣���$N�е�����ñ�ร���������\n\n", me);
		me->set_temp("match_game/lost", 1);
		me->delete_temp("match_game/playing");
		return 1;		
	}
	else {
		message_vision("��ʣ��"+chinese_number(REMAIN)+"����ǩ��\n\n", me);
		for (n = REMAIN; n > MAXNUM; n = n - MAXNUM - 1);
		n = (n + 3) % 4;
		if (n == 0)
		   	n = (REMAIN > MAXNUM ? random(MAXNUM)+1 : random(REMAIN)+1); 
		me->add_temp("match_game/remain", -n);	
		message_vision(obname+"����"+chinese_number(n)+"����ǩ��\n", me);
		if (REMAIN != 0) {
			if (REMAIN == 1) {
				me->set_temp("match_game/lost",1);
				me->delete_temp("match_game/playing");
				message_vision(WHT +"��ʣ��"+chinese_number(REMAIN)+"����ǩ��$N���ˡ�\n"+ NOR, me);
				message_vision(obname+"Ц�������֣���$N�е�����ñ�ร���������\n\n", me);
				return 1;
			}
			else				
				message_vision("��ʣ��"+chinese_number(REMAIN)+"����ǩ����$N���ˡ�\n\n", me);
		}
		else {
			message_vision(HIW +"û����ǩ�ˣ�$NӮ�ˡ�\n"+ NOR, me);
			message_vision(obname+"���˿��������ǩ�ֿ��˿�$N��˵��������Ϲè���������ӣ��������ˡ�\n\n", me);
			me->set_temp("match_game/win", 1);
			me->delete_temp("match_game/playing");
			return 1;
		}
	}
	return 1;
}
