// likuilei.c �����
// Modified by Winder June 25. 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
	set_name("�����", ({ "li kuilei", "li" }));
	set("long","������������������췢���룬��״����֮����ֱ�Ǹ����֣���һ�����������Ľ��ۡ���һ�����԰���Ϸ�ģ����ߵߣ�������ѧһ������������ˡ�\n");
	set("nickname","�����Ȱ��ѡ�Ϸ��");
	set("gender", "����");
	set("age", 30);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 200000);
	set("score", 50000);

	set_skill("dramaturgy",150);
	set_skill("blade", 30);
	set_skill("ruyi-dao", 30);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("strike", 30);
	set_skill("parry", 30);
	set_skill("lingboweibu", 100);
	set_skill("beiming-shengong",30);
	set_skill("liuyang-zhang", 30);
	map_skill("parry", "ruyi-dao");
	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("book_count", 1);
	set("env/wimpy", 60);

	create_family("��ң��", 3, "����");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ��ң�ɳ�������");
	command("recruit " + ob->query("id"));
}
