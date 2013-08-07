// zhi.h ־�ֱ���ͽ���Ƽ������ֱ�

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("quanzhen xin2", ob) ) 
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
        
	if (obj->query("id")=="quanzhen xin1" && ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say �ã�"+ob->query("name")+"����Ը�����Ϊʦ��");
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
		obj=new("/d/quanzhen/obj/tuijianxin-2");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڱ����������г���ͷ�أ�\n");
		return 1;
	}

	return 1;  
}

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");
	string name, new_name;
	name = ob->query("name");

	if ((int)ob->query_skill("xiantian-qigong",1) < 30 ) {
		command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
	}
	if ((int)ob->query("shen") < 1000) {
		command( "say �����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮�£���һ������Ϊͽ��\n");
		return;
	}
        if (ob->query("gender")=="����" && me->query("gender")=="Ů��") {
                command("say �Ҳ�����ͽ���㻹��ȥ���Ҽ�λʦ��Ϊʦ�ɡ�\n");
                return;
        }
	if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "ȫ���")
	{
		command("say �ҽ�Ϊ�������ڣ�" + RANK_D->query_respect(ob) + "��Ҫѧ�գ��������ұ����Ĵ����Ӱɡ�");
		return;
	}
	if ( ob_fam["generation"] == 0 )
	{
		command("say �����ٷ��㻹�������Ĵ�����ѧ��������ɡ�");
		return;
	}
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"��ƶ������ҵ���");
		return;
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 1))
	{
		command("say �Һ�"+ob_fam["master_name"]+"��ͽ�ܣ���������");
		command("recruit " + ob->query("id"));
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say ��"+ob_fam["master_name"]+"���������ҵģ��ã��á�");
			command("say ƶ�������ǿ���֮�ţ���Ͱ���ѧ�հɣ�");
			if(ob->query("class") == "quanzhen") 
			{
				new_name = name[0..1] + "��" + name[4..5];
				ob->set("name", new_name);
				command("say �ӽ��Ժ���ĵ��Ž���"+new_name+ "����������ȫ������ֱ������ˡ�");
			}
			else command("say ��û�г��ң�����������㣬�Ժ���ɱ����ˡ�");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
			return;
		}
	}
	return;
}

