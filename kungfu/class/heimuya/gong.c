// gong.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("���ӹ�", ({ "huangzhong gong", "gong" }));
	set("long",
		"������÷ׯ��λׯ�����е�һ�Ļ��ӹ���\n"
		"��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
		"����������Ѯ������еȣ����ݺͰ����ס�\n");
	set("gender", "����");
	set("age", 62);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("env/wimpy", 40);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("luteplaying", 100);      // ��������
	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 150);            // �����ڹ�
	set_skill("unarmed", 150);          // ����ȭ��
	set_skill("dodge", 150);            // ��������
	set_skill("parry", 150);            // �����м�
	set_skill("sword", 150);            // ��������
	set_skill("piaoyibu", 200);         // Ʈ�ݲ���
	set_skill("wuyun-jian", 200);       // �������ҽ�
	set_skill("kuihua-xinfa", 150);	    // �����ķ�

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "wuyun-jian");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jian");

	set("inquiry", ([
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]));

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIY"÷ׯ��ׯ��"NOR);
	create_family("��ľ��", 9, "����");
	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/qin");
		if ( ob->violate_unique())
		{
      destruct(ob);
      ob=new(WEAPON_DIR"changjian");
    }
     	ob->move(this_object());
     	ob->wield();
  }
	carry_object("clone/cloth/male-cloth")->wear();
	carry_object("/d/meizhuang/obj/yaoshi1");
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 120)
	{
		command("say ���ǲ�������ͽ�ġ�");
		command("say ���ҽ̵��ڹ��ϣ�" + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�ö��µ㹦��");
		return;
	}
	command("say �ðɣ��Ϸ���������ˡ�");
	command("recruit " + ob->query("id"));
}

