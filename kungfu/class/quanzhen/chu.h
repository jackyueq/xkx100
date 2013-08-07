// chu.h ���ֱ���ͽ

int accept_object(object ob, object obj)
{
	object me = this_object();

	if (obj->query("id")=="quanzhen xin2" && ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say �ã�"+ob->query("name")+"����Ը�����Ϊʦ��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say �ⶫ�����ҿ�û��ʲô�á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");
	string name, new_name;
	name = ob->query("name");

	if ((int)ob->query_skill("xiantian-qigong",1) < 70 ) {
		command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
	}
	if ((int)ob->query("shen") < 10000) {
		command( "say �����������ұ����ݣ������ܶ���Щ����֮�£���һ������Ϊͽ��\n");
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
				new_name = name[0..1] + "־" + name[4..5];
				ob->set("name", new_name);
				command("say �ӽ��Ժ���ĵ��Ž���"+new_name+ "����������ȫ���־�ֱ������ˡ�");
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
