// da.h ���ֱ���ͽ
void attempt_apprentice(object ob)
{
	object me=this_object(); 
	mapping ob_fam, my_fam;
	string name, new_name;
	my_fam =me->query("family");
	name = ob->query("name");

	if(!(ob_fam=ob->query("family")) || ob_fam["family_name"]!="��������")
	{
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"��ƶɮ����ҵ���");
		return;
	}
	if( ob->query_skill("force", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"����Ļ����ڹ�����Ҫĥ����ƶɮ��ʱ������Ϊͽ��");
		return;
	}
	if( ob->query_skill("zhanzhuang-gong", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"�����վ׮������Ҫĥ����ƶɮ��ʱ������Ϊͽ��");
		return;
	}
	if( ob_fam["generation"]==(my_fam["generation"]+1) )
	{
		command("say "+ob_fam["master_name"]+"��ͽ����ô�ܵ���������ˣ���������");
		command("recruit "+ob->query("id"));
	}
	if( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		command("say ���ĵ�һ����֮�ţ������ϻ��󳩡�");
		command("recruit " + ob->query("id"));
		if( ob->query("class") == "bonze")
		{
			name = ob->query("name");
			new_name = "Ԫ" + name[2..3];
			ob->set("name", new_name);
			command("say �����ķ�������"+new_name+"��\n");
		}
		else ob->set("title", "�������׼ҵڶ�ʮ����");
	}
	else
		command("say "+RANK_D->query_respect(ob)+"�����Ǵ��ıĳ����ģ��㲻��Խ����ʦ��");
	return;
}

