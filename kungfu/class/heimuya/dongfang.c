// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void consider();

void create()
{
	object ob;
	set_name("��������", ({"dongfang bubai", "dongfang", "bubai", "dong"}));
	set("nickname", HIY "�书���µ�һ" NOR );
	set("gender", "����");
	set("class", "eunach");
	set("shen_type", -1);
	set("age", 42);
	set("long", "������������̽������ݴ��书���µ�һ����˴�ž��ǡ��������ܡ���\n");
	set("attitude", "peaceful");

	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("no_get",1);

	set("chat_chance", 1);
	set("chat_msg", ({
		"��������̾�˿����������� ���� �ҵ����硭����ô�����������Һù����� ������������������¶������ã��\n",
	}));
	set("inquiry", ([
		"����ͤ"   : "���ֱ���Ұ��˵����֣�������ѽ�� \n",
		"��������" : "������ܰ���ȡ�ÿ��������ϲᣬ��һ������л�㡣\n",
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 400);

	set("combat_exp", 3000000);
	set("score", 0);

	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 200);            // �����ڹ�
	set_skill("finger", 200);           // ����ָ��
	set_skill("unarmed", 200);          // ����ȭ��
	set_skill("dodge", 200);            // ��������
	set_skill("parry", 200);            // �����м�
	set_skill("dagger", 200);           // �����̷�
	set_skill("sword", 200);            // ��������
        set_skill("shigu-bifa", 300);       // ʯ�Ĵ�Ѩ�ʷ�
	set_skill("piaoyibu", 300);         // Ʈ�ݲ���
	set_skill("bixie-jian", 250);       // ��а����
	set_skill("wuyun-jian", 300);       // �������ҽ�
	set_skill("xuantian-zhi", 300);	    // ��������ָ
	set_skill("kuihua-xinfa", 200);	    // �����ķ�

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "bixie-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "bixie-jian");
	map_skill("parry", "bixie-jian");

	prepare_skill("finger", "xuantian-zhi");

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIM"�ڰ˴�����"NOR);
	create_family("��ľ��", 8, "����");

	setup();
	if (clonep())
	 {
	 	ob=new(WEAPON_DIR"treasure/zhen");
	 	if ( ob->violate_unique() )
	 	{
	 		destruct(ob);
	 		ob=new(WEAPON_DIR"changjian");
	 	}
	 	ob->move(this_object());
	 	ob->wield();
	 }
  carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 150)
	{
		command("say ���ҽ̵��ڹ��ϣ�" + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö��µ㹦��");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�\n");
		return;
	}
	if (ob->query("gender") != "����" )
	{
		command("say Ҫ���񹦣������Թ���");
		return;
	}
	if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000)
	{
		command("say �Һ�ľ�������������������������ֳ�������򽻵�������ذɣ�\n");
		return;
	}
	command("say �ܺã��ܺá�\n");
	command("recruit " + ob->query("id"));
}

