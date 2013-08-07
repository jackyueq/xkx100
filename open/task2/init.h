// init.h ����ɱ�ּ�飬�Լ���ʧ��ʱ��
#define A_TIME 20

void init()
{
	object me, ob, *obs;
	mapping skl;
	string *skillname;
	int i, j, exp, neili, skilllvl;
	me=this_object();

        obs = all_inventory(environment(me)); 
	exp = 0;
	neili = 0;
	skilllvl = 0;
	for (i=0; i<sizeof(obs); i++)
	{
		if( !living(obs[i]) || obs[i]==me ) continue;
		if (exp < obs[i]->query("combat_exp"))
			exp = obs[i]->query("combat_exp");
		if (neili < obs[i]->query("max_neili"))
			neili = obs[i]->query("max_neili");
		skl = obs[i]->query_skills();
		if (!sizeof(skl)) continue;
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}
	}

	if( exp <= 0 ) exp = random(3000) + 1;
//		else exp = exp + random(10000) - 7000; 
		else exp = exp * 6 / 5;
	exp = exp /2 + random(exp/2);
	me->set("combat_exp", exp);

	if( neili <= 0 ) neili = random(100) + 1;
		else neili = neili + random(200) - 100; 
	me->set("max_neili", neili);
	me->set("neili", neili);
	me->set("jiali", (int)(neili/80 + random(neili/80)));

	if( skilllvl <= 0 ) skilllvl = random(3) + 6;
	skilllvl = skilllvl / 2 + random(skilllvl/2);
	me->set_skill("tiyunzong", skilllvl + random(10) - 6);
	me->set_skill("liangyi-jian", skilllvl + random(10) - 6);
	me->set_skill("taiji-jian", skilllvl + random(10) - 6);
	me->set_skill("taiji-shengong", skilllvl + random(10) - 6);
        me->set_skill("wudang-quan",skilllvl + random(10) - 6);
        skilllvl = (int) (skilllvl / 3 * 2);
	me->set_skill("force", skilllvl + random(10) - 4);
	me->set_skill("dodge", skilllvl + random(10) - 4);
	me->set_skill("parry", skilllvl + random(10) - 4);
	me->set_skill("sword", skilllvl + random(10) - 4);
	me->set_skill("unarmed", skilllvl + random(10) - 4);

	me->map_skill("dodge", "tiyunzong");
	me->map_skill("force", "taiji-shengong");
	me->map_skill("sword", "taiji-jian");
	me->map_skill("parry", "liangyi-jian");
        me->map_skill("unarmed", "wudang-quan");

	remove_call_out("do_check");
	call_out("do_check", 0);
	remove_call_out("do_wait");
	call_out("do_wait",A_TIME);
}

void do_check()
{
	object me = this_object();
	object ob;

	if (! living(me) || me->is_fighting() ) {
		remove_call_out("do_check");
		call_out("do_check",0);
	}
	else
	{
		if( !ob = present("ren zhi",environment(me)))
		{
			remove_call_out("do_check");
			call_out("do_check",0);
		}
		else
		{
			if (! environment()->query("no_fight") )
			{
				me->set_leader(ob);
				message_vision("$N����$n���һ��������"+RANK_D->query_rude(ob)+"����������\n",me,ob);
				me->kill_ob(ob);
				command("kill "+ob->query("id"));
				ob -> add("combat_num",1);
			}
			else
			{
				me->set_leader(ob);
				me->kill_ob(ob);
				remove_call_out("do_wait");
				call_out("do_wait",10*A_TIME);
			}
		}
	}

}

void do_wait()
{
	object ob;
	object me = this_object();

	if (me->is_fighting() || !living(me) )
	{
		remove_call_out("do_wait");
		call_out("do_wait",A_TIME);
	}
	else
	{
		if (ob = present("corpse",environment(me)))
		{
			message_vision("$N��Ц�������ʼ������ҿ��Ի�ȥ�����ˡ�\nһ���̳�����$N����Ӱ�ɿ����ʧ�ˡ�\n",this_object());
			destruct(me);
		}
		else
		{
			message_vision("$N���������˵�����������ʲ�����������ˣ��һ��ǻ�ȥ�ɡ�\n$N�������ε���Զ�����˿�ȥ��\n",this_object());
			destruct(me);
		}
	}
}

void killed_enemy(object victim)
{
	object me = this_object();

	if (victim->query("id") == "ren zhi")
	{
		message_vision("$N�����Цһ�������������ڵ����ˣ�˵�գ��������䣬������ʧ��Զ�������ܽǡ�\n",me);
		destruct(me);
	}
}

