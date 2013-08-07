// zhang3.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("������", ({ "zhang laosan", "zhang" }));
	set("gender", "����");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ��������ͷ,һ˫С�۾��������⡣\n");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 50);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("yixingbu", 40);
	set_skill("shenlong-bashi", 50);
	map_skill("parry", "shenlong-bashi");
	map_skill("dodge", "yixingbu");

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	set("inquiry", ([
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
	]) );
	set("chat_chance", 3);
	set("chat_msg", ({
		"������˵�����������ͨ���ӣ��ڵ��������ٱ�����һ���٣��԰ٵ���\n",
		"������˵�����������Ŀ��磬�����ķ���\n",
		"������˵�����ҵ���ɱ�л��̣�������׼���Σ�����ʥְ��\n",
		"������˵�����ҽ̵��ӻ��̶�����ͬ�����á�\n",
		"�����������е���������ѵ��ʱ�����ģ������˵У����²��ɣ�\n",
		"��������Ȼ�����е�����־���Ŀɳɳǣ����������ޱ��ף�\n",
		"��������Ȼ�����е����������������������������ǰ˷���\n",
		"��������Ȼ�����е����˷����˳�Ӣ����������ͬ���¹⣡\n",
		"�����������е������������ɸ����������룡\n",
	}) );
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIW"������"NOR"����");
	set("party/level", 2);
	create_family("������",2,"����");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",5);
}

void init()
{
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") == HIY "������" NOR)
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+"�����ز���ʶ����ƾʲôҪ�����أ� \n"); 
		return 0;
	}
	return 1;	
}

#include "/kungfu/class/shenlong/shenlong.h";
