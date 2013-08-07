// ma-dayuan.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���Ԫ", ({"ma dayuan", "ma", "dayuan"}));
	set("gender", "����");
	set("age", 29);
	set("long", 
"������ؤ���ʮ�θ����������½�����ϸ���ǰ���һ�Ѻ��֡�
һ�������������������֡�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

        set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 180);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 150);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�
	set_skill("suohou-hand", 300);       // ����������
	set_skill("blade", 180);             // ��������
	set_skill("liuhe-blade", 180);       // �������ϵ�
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	set_skill("training", 100);          // Ԧ����
	set_skill("strike",85);  // �����Ʒ�
	set_skill("lianhua-zhang",85); // ������
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	prepare_skill("hand",  "suohou-hand");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"������"NOR);
	set("party/level", 10);
	create_family("ؤ��", 10, "����");

	setup();
	
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20)
	{
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "ؤ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
		return;
	}
	if ((string)ob->query("party/party_name") != HIC"ؤ��"NOR)
	{
		command("say ��ֻ�ձ������Ϊͽ��\n");
		return;
	}
	command("recruit "+ob->query("id"));
}

