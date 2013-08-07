// xunwu.h
int do_attack(string arg)
{
	object ob;
	string host_id;
	object me=this_player();
	object who=this_object();
	if(environment(me)->query("no_fight"))
		return notify_fail(who->query("name")+"ȫ��Ť����η����ǰ��\n");
	if(environment(me)->query("no_ansuan"))
		return notify_fail(who->query("name")+"ȫ��Ť����η����ǰ��\n");
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"���������㣡\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail(who->query("name")+"ɵɵ�������㣬�����������˼��\n");
	if(ob->query("id")==me->query("id"))
		return notify_fail(who->query("name")+"��æ��ͷһ�ͣ��ƺ���Ը��ȥ�ɡ�\n");
	if(ob->query("owner")&&ob->query("owner")!=me->query("id"))
		return notify_fail(who->query("name")+"ȫ��Ť����η����ǰ��\n");
	if(!living(ob))
		return notify_fail(who->query("name")+"˵��"+ob->query("name")+"�Ѿ��������㻹Ҫ....����\n");
	message_vision(who->query("name")+"֨֨�ֽ�һ�����˳�ȥ��\n",me);
	fight_ob(ob);
	return 1;
}

int do_stop()
{
	object who=this_object();
	string host_id;
	object me=this_player();
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"���������㣡\n");
	who->set_leader(me);
	message_vision("$N��"+who->query("name")+"�ȵ�������ˣ���������\n",me);
//	if(!is_fighting())
//		return notify_fail(who->query("name")+"����û���˴򶷡�\n");
	command("halt");
	who->delete_temp("kill_name");
	message_vision(who->query("name")+"�ԹԵĻص�$N��ߡ�\n",me);
	return 1;
}

int do_sha(string arg)
{
	object who=this_object();
	int i ;
	object me,ob;
	object* obj;

	if(environment(me)->query("no_ansuan"))
		return notify_fail(who->query("name")+"ȫ��Ť����η����ǰ��\n");
	me = this_player();
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"���������㣡\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("��Ҫ"+who->query("name")+"ɱ˭��\n");
	if(ob->query("id")==me->query("id"))
		return notify_fail( who->query("name")+"��æ��ͷһ�ͣ��ƺ���Ը��ȥ�ɡ�\n");
	if(!environment(ob)->query("no_fight"))
	{
		message_vision(who->query("name")+"֨֨�ֽ�һ�����˳�ȥ��\n",me);
		who->set_leader(ob);
		who->set_temp("kill_name",ob->query("id"));
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
	return 1;
}
int do_guard(string arg)
{
	object who=this_object();
	int i ;
	object me,ob;
	object* enemy;
	me = this_player();
	if(me->query("id")!=(who->query("host_id")))
		return notify_fail(who->query("name")+"���������㣡\n");
	if(!arg)
	ob = this_player();
	if(arg)
	{
		if(!userp(present(arg,environment(me))))
			return notify_fail("��Ҫ"+who->query("name")+"����˭��\n");
	}
	if(arg) ob = present(arg,environment(me));
	if (ob->is_fighting())
	{
		return notify_fail("�Է�����Ը�������ĺ��⣡\n");
	}
	who->set_temp("guard_ob",ob->query("id"));
	message("vision",
		 name() + "������΢��֨��������ʼ����"+ob->name()+"�Ĵ����ߣ�\n"NOR,environment(), this_object() );
	enemy = ob->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	ob->remove_all_killer();
	who->set_leader(ob);
	return 1;
}
int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if(environment(me)->query("no_fight"))
		return notify_fail(ob->query("name")+"η����ǰ��\n");
	if(environment(me)->query("no_ansuan"))
		return notify_fail(ob->query("name")+"η����ǰ��\n");
	if (!arg ) return 0;
	if (arg != ob->query_temp("guard_ob")) return 0;
	message_vision("$Nһ���ֽк�Ȼ������"+me->name()+"����ǰ��\n", this_object());
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
	return 1;
}
