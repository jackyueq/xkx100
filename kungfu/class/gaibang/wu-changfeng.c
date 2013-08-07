// wu-changfeng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ⳤ��", ({"wu changfeng", "wu", "changfeng"}));
	set("nickname", "ؤ������");
	set("gender", "����");
	set("age", 50);
	set("long","����һ���������ߣ������õ���һ�ѹ�ͷ���������б�������������\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1300);
	set("max_neili", 1200);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // �����ڹ�
	set_skill("huntian-qigong", 90); // ��������
	set_skill("blade", 200); // ��������
	set_skill("liuhe-blade", 200); // �������ϵ�
	set_skill("hand", 85); // �����ַ�
	set_skill("suohou-hand", 80); // ����������
	set_skill("dodge", 95); // ��������
	set_skill("xiaoyaoyou", 85); // ��ң��
	set_skill("parry", 90); // �����м�
	set_skill("strike",85);  // �����Ʒ�
	set_skill("lianhua-zhang",85); // ������
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 10, "����");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/guitou-blade")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
#include "/kungfu/class/gaibang/gaibang.h"
