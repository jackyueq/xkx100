// Last Modified by winder on Apr. 25 2001
// guojing.c ����

inherit NPC;
#include <ansi.h>
#include "zzzjob.c"
#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);

void create()
{
	set_name("����", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"����"NOR);
	set("gender", "����");
	set("age", 41);
	set("long", 
		"�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
		"�����߹֡�ȫ�������ڡ�����ؤ�����߹��͡�����ͯ���ܲ�ͨ\n"
		"���˵�ͽ�ܣ���������书��������һ����ɫ���ۣ���̬���࣬\n"
		"�غ����Ŀ��͸��һ�����ϡ����˲��ɵò���һ������֮�顣\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 20);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set_temp("no_kill",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�˿������� �ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....\n",
		"����˵�������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
//		(: random_move :),
	}));
	set("inquiry", ([
		"�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�\n",
		"����ͯ" : "�ܴ��һ��������û��������\n",
		"���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�\n",
		"��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�\n",
		"һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���\n",
		"ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�\n",
		"����"   : "�ض����ҵİ��ޣ�������������\n",
		"�ض�"   : "�ض������ض��ˡ�������ô����\n",
		"��ܽ"   : "���Ů�����ֱ��ֲ�������\n",
		"����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����\n",
		"����²" : "�����ҵ�С���ӡ�\n",
		"���"   : "����ȷʵ�г�Ϣ��\n",
		"����"   : "����������а�ʦ֮�ꡣ\n",
		"�𴦻�" : "������屡���죬������ܡ�\n",
		"�����" : "�����Ҵ�ʦ����\n",
		"���"   : "�����Ҷ�ʦ����\n",
		"������" : "��������ʦ����\n",
		"��ϣ��" : "��������ʦ����\n",
		"�Ű���" : "��������ʦ����\n",
		"ȫ��" : "��������ʦ����\n",
		"��СӨ" : "��������ʦ����\n",
		"ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
		"��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
		"job"    : (: ask_job :),
		"��ʿ"   : (: ask_job :),
		"����"   : (: ask_gonglao :),
		"fangqi" : (: ask_fangqi :),
		"����"   : (: ask_fangqi :),
		"��ϸ"   : (: ask_jianxi :),
		"�س�"   : (: ask_newjob :),
		"job2"   : (: ask_newjob :),
		"����"   : (: ask_newover :),
	]));
	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	set("combat_exp", 25000000);
	set("score", 200000);
	set_skill("force", 400);		// �����ڹ�
	set_skill("huntian-qigong", 400);	// ��������
	set_skill("unarmed", 400);		// ����ȭ��
	set_skill("xianglong-zhang", 400);	// ����ʮ����
	set_skill("dodge", 400);		// ��������
	set_skill("xiaoyaoyou", 400);		// ��ң��
	set_skill("parry", 400);		// �����м�
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("job_over","shoucheng");
}
string ask_newjob()
{
	object *ene;
	object me = this_player();

	if(is_fighting()) 
	{
		ene=query_enemy();
		if(sizeof(ene)>1)
			return "����"+RANK_D->query_respect(me)+ "�Ե�Ƭ�̣����Ⱥ���"+sizeof(ene)+"λ�����д輸�£���\n";
		if(sizeof(ene)==1)
			return "����"+RANK_D->query_respect(me)+ "�Ե�Ƭ�̣����Ⱥ�"+ene[0]->name()+"�д輸�£���\n";
	}
	if(this_object()->query("shadi"))
		return "���ղž�Ԯ��Ӣ����ȥ���ţ��㿴ȥ���æ��Σ���\n";
	if(!me->query("family/family_name"))
		return "��"+RANK_D->query_respect(me)+"�������ɣ���֪��ʦ��˭����\n";
	if(me->query_temp("mark/job_shadi")>0 )
		return "��"+RANK_D->query_respect(me)+"���������������𣡡�\n";
//        if((int)me->query("shen") < 0)
//		return "�������������������أ���\n";
	if ((int)me->query("combat_exp")<100000)
		return "��"+RANK_D->query_respect(me)+ "���޸���֮�������Ǳ��������Ϊ�ã���\n";
	if ( (int)me->query_skill("force") < 20 )
		return "�س��Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(me)+ "�Ļ����ڹ���Ϊ���㣬����ð�գ�\n";
	if ((int)me->query_condition("jobshadi_failed"))
	{
		message_vision("$N����$nҡ��ҡͷ˵������ʧ���˻������ң�\n", this_object(), me);
		return "��"+RANK_D->query_respect(me)+"���Ǳ�������Ϊ�ã���\n";
	}
	if ((int)me->query_condition("jobshadi_limit")>1)
	{
		message_vision("$N����$nҡ��ҡͷ˵���㲻����������\n", this_object(), me);
		return "��"+RANK_D->query_respect(me)+"������ĸ�λȥ����\n";
	}
	if ((int)me->query_condition("guojob2_busy"))
	{
		message_vision("$N����$nҡ��ҡͷ˵�������ɹ������ڹ��ǣ���\n", this_object(), me);
		return "��"+RANK_D->query_respect(me)+"��Ȼ���������\n";
	}
	if (me->query("shen")>0)
	{
		switch( random(2) )
		{
			case 0:
				this_object()->set("shadi", 1);
              			call_out("new_give_job",360,this_object());
                                me->set_temp("mark/job_shadi",1);
				me->set_temp("carry_location","northgate1");
				me->apply_condition("jobshadi_limit",6);
				return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�������Ű����ξ��سǰɡ���";
				break;
			case 1:
				this_object()->set("shadi", 1);
                                call_out("new_give_job",360,this_object());
				me->set_temp("mark/job_shadi",2);
				me->set_temp("carry_location","northgate1");
				me->apply_condition("jobshadi_limit",6);
				return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�������Ű����ξ��سǰɡ���";
				break;
		}	
	}
	else
	{
		switch( random(2) )
		{
			case 0:
				this_object()->set("shadi", 1);
                                call_out("new_give_job",360,this_object());
				me->set_temp("mark/job_shadi",3);
				me->set_temp("carry_location","southgate1");
				me->apply_condition("jobshadi_limit",6);
				return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ��ȸ���Ű����ξ��سǰɡ���";
				break;
			case 1:
				this_object()->set("shadi", 1);
			        call_out("new_give_job",360,this_object());
                         	me->set_temp("mark/job_shadi",4);
				me->set_temp("carry_location","southgate1");
				me->apply_condition("jobshadi_limit",6);
				return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�׻����Ű����ξ��سǰɡ���";
				break;
		}
	}
}

int new_give_job()
{ 
   this_object()->delete("shadi", 1);
} 

int job_over(string arg)
{
	int job_pot,job_exp;
	object me = this_player();

	if(!arg) return 1;

	if(arg!="over") return 1;
	if(me->query_temp("help_killed")>0)
	{
		message_vision(CYN "$N������$n�ļ��˵������"+RANK_D->query_respect(me)+"��Ϊ��ɱ�У���������\n" NOR, this_object(), me);
		job_exp=((int)me->query_temp("killed_mgb"))*80;
		job_pot=job_exp*1/3;
		job_exp=job_exp;
		me->add("combat_exp", job_exp);
		me->add("potential",job_pot);
tell_object(me, "�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��"+chinese_number(job_pot)+"��Ǳ�ܡ�\n");
		me->delete_temp("killed_mgb");	
		me->delete_temp("job_over");
		me->delete_temp("mark/job_shadi");
		me->delete_temp("help_killed");
		me->apply_condition("guojob2_busy",4);
		return 1;
	}
	if(me->query_temp("mark/job_shadi")==0)
	{
		message_vision(CYN"$N����$nһ�ۣ���û����ʲô��ɲ���ɡ���\n",this_object(),me);
		return 1;
	}
	if(me->query_temp("job_over")==0)
	{
		message_vision(CYN"$N����$nһ�ۣ�������û��ɡ���\n"NOR,this_object(),me);
		return 1;
	}
	if(me->query_temp("killed_mgb")<2)
	{
		message_vision(CYN"$N����$nһ�ۣ�����ɱ�˼������ˣ��㻹�����ͣ���\n"NOR,this_object(),me);
		me->delete_temp("job_over");
		me->delete_temp("mark/job_shadi");
		return 1;
	}
	message_vision(CYN"$N��$n˵������"+RANK_D->query_respect(me)+"�����ˣ�ȥ��Ϣһ�°ɣ���\n" NOR, this_object(), me);
	me->delete_temp("job_over");
	me->delete_temp("mark/job_shadi");
	job_exp=((int)me->query_temp("killed_mgb"))*80;
	job_pot=job_exp*1/3;
	job_exp=job_exp;
	tell_object(me, "�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��"+chinese_number(job_pot)+"��Ǳ�ܡ�\n");
	me->apply_condition("guojob2_busy",4);
	me->add("combat_exp", job_exp);
	me->add("potential",job_pot);
	me->delete_temp("killed_mgb");	
	this_object()->delete("shadi", 1);
	return 1;
}
string ask_newover()
{
	object me;
	me = this_player();
	if(me->query_condition("jobshadi_limit") <= 1)
		return "��û��������������Ϲ����ʲô��";
	me->apply_condition("jobshadi_limit", 1);
	me->apply_condition("jobshadi_failed", 6);
	me->delete_temp("mark/job_shadi");
	me->delete_temp("carry_location");
	me->delete_temp("job_over");
	me->delete_temp("start_job");
	this_object()->delete("shadi", 1);
	return "û��ϵ���´μ���Ŭ����";
}
