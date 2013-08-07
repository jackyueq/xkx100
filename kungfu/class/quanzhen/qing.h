// qing.h ���Һ����ֱ���ͽ���Ƽ���־�ֱ�

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("quanzhen letter1", ob) ) 
	{
		command("say �������������ҵ��Ƽ���ȥ��ʦ���� ?");
		return 0;
	}

	if((obj->query("id") == "quanzhen ling")
	&& ob_fam["family_name"] == "ȫ���"
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
	        command("say �ã���Ȼ��������������ɣ����Ǿ�����֤һ���书��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
        
	command("smile");
	command("say �ⶫ�����ҿ�û��ʲ���á�");
	command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok") ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("fight_ok");
	
	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say ������ʤ�����������ȫ�����µ��ӣ���ϲ���ˣ�\n");
		message_vision("$N����$nһ���Ƽ��š�\n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/quanzhen/obj/tuijianxin-1");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + "���ö����ϰ�������ڱ����������г���ͷ�أ�\n");
		return 1;
	}

	return 1;
}

string ask_for_join()
{
	object me = this_player();
	mapping my_fam = me->query("family");

	if( (string)me->query("class")=="quanzhen" )
		return "�����ٷ�����ͬ�����ţ��ιʸ�С�������������Ц��\n";

	if( my_fam["family_name"] == "ȫ���" && my_fam["generation"] <= 4) 
		return "�����ٷ���������֮ʿ��Ӧ��С��ʼ���С�\n";

	if( me->query("betrayer") > 0) 
		return "�����ٷ������Է����޳���������������֮ʿ֮��Ϊ��\n";

	me->set_temp("pending/join_quanzhen", 1);
	return "�����ٷ�ʩ�������������ȫ����ţ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	string name, new_name;
	if( !me->query_temp("pending/join_quanzhen") ) return 0;

	message_vision(
		"$N������������ָ�����������ؿ���ͷȥ��\n\n"
		"$n���˫�֣���$Nͷ���������һ�����١�\n\n",me,this_object());
	name = me->query("name");
	new_name = name[0..1] + "��" + name[2..3];
	command("say �ӽ��Ժ���ĵ����žͽ���" + new_name + "��");
	command("smile");
	me->delete_temp("pending/join_quanzhen");
	me->set("name", new_name);
	me->set("class", "quanzhen");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);

	return 1;
}

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");

	if ((int)ob->query("shen") < 0) {
		command( "say �����������ұ�ѧ���˵Ļ���Ʒ�ʣ����ѿ���ħ��������������Ϊͽ��\n");
		return;
	}
	if (ob->query("gender")=="����" && me->query("gender")=="Ů��")
	{
		command("say �Ҳ�����ͽ���㻹��ȥ���Ҽ�λʦ��Ϊʦ�ɡ�\n");
                return;
	}

	if (ob_fam = ob->query("family"))
	{
		if( ob_fam["generation"] <= my_fam["generation"] &&
		    ob_fam["family_name"] == my_fam["family_name"] )
		{
			command("say "+RANK_D->query_respect(ob)+"�����ƶ���ĸҵ���");
			return;
		}
	}
	if( (string)ob->query("class")!="quanzhen" )
	{
		command ("say �����ٷ�ƶ���������������׼ҵ��ӡ��ˡ�");
	}
	else
	{
		command ("say �����ٷ�ƶ��������Ϊȫ�����ʽ���ӡ�");
	}
	command("recruit " + ob->query("id"));
}

