// fawang.h for fight and get letter from FaWang

void attempt_apprentice(object ob)
{
	object me = this_object();

	if (ob->query("party/party_name") != HIG "����" NOR)
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	else
	{
		command("say �������ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");
		command("recruit " + ob->query("id"));
//		ob->set("title", HIR"���̻���"NOR);
	}
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
		       	command("say ��ϲ������Ϊ���̻�����");
 				    ob->set("title", HIR"���̻���"NOR);
 				  }
}
#include "mingjiao.h"
