// Last Modified by winder on May. 29 2001
// fang.h ���ֱ���ͽ

void attempt_apprentice(object ob)
{
	mapping fam;
	if(mapp(fam = ob->query("family")) &&
		fam["family_name"]=="��������" &&
		fam["generation"] < 22)
	{
		command("say �����ӷ��ҷ�ȱ���\n");
		return;
	}
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	}
	command("say �����ӷ����գ����գ�");
	command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	if( (string)ob->query("class")!="bonze" )
	{
		ob->set("title", "�������׼ҵڶ�ʮ������");
	}

 				  }
}