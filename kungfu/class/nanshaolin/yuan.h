// Last Modified by winder on May. 29 2001
// yuan.h Ԫ�ֱ���ͽ

int do_nod();
void attempt_apprentice(object ob)
{
        mapping fam;

	if(!mapp(fam = ob->query("family")) || fam["family_name"]!="��������")
	{
		command("say ��ֻ�ձ��ɵ���Ϊͽ��\n");
		return;
	}
	if(fam["generation"] < 21)
	{
		command("say �����ӷ��ҷ�ȱ���\n");
		return;
	}
	ob->set_temp("wait_nod", 1);
	command("say ������������������أ�"+RANK_D->query_respect(ob)+"�������������У��Ҳ�������Ϊͽ����Ը��ô���Ǿ͵��ͷ��(nod)��");
}
int do_nod()
{
	object ob = this_player();

	if(!ob->query_temp("wait_nod")) return 0;
	ob->delete_temp("wait_nod");
	call_out("test", 1, ob);
	return 0;
}
void test(object ob)
{
	object me=this_object();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
//	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
//	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	call_out("check", 1, ob);
}

void check(object ob)
{
	string new_name;

	if (!living(ob) || environment(ob) != environment() ||
		ob->query("max_qi") > ob->query("qi") * 2)
	{
		command("sigh");
		return;
	}
	else
	{
		command("recruit " + ob->query("id"));
		if( ob->query("class") == "bonze")
		{
			new_name=ob->query("name");
			new_name[0..1] = "��";
			ob->set("name", new_name);
			command("say �ӽ��Ժ���ķ�������"+new_name+"�ɣ�\n");
		}
		else ob->set("title", "�������׼ҵڶ�ʮһ����");
	}
	return;
}
