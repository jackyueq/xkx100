// abi.c

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("����", ({ "a bi", "bi" }));
	set("long",
		"���Ǹ������µ�Ů�ɣ�Լʮ��������ͣ������������ᣬ\n"
		"������������һ�ſɰ��Ĺ��������������°���ź��˵��\n"
		"���������壬����һ��֮��˵���������ʡ���Ǳ�һ��ϸ\n"
		"ϸ�ĺ��룬�������ġ�\n");
	set("gender", "Ů��");
	set("class", "scholar");
	set("age", 16);
	set("per", 28);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("blade", 50);
	set_skill("strike", 50);
	set_skill("finger", 50);
	set_skill("murong-sword", 50);
	set_skill("murong-blade", 50);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 50);
	set_skill("yanling-shenfa", 50);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("env/wimpy", 60);

	set("combat_exp", 10000);
	set("inquiry",([
		"����ɽׯ" : "�ҲŲ���ȥ����ɽׯ��������̫�Ե��ˣ�\n",
		"������" : "����ֻ��������������ǹ��ӣ�Ҳ��֪�����������ˣ�\n",
		"��Ľ��" : "�Ҽҹ��Ӻ�ؤ���ǰ����������ϳơ���Ľ�ݱ��Ƿ塱��\n",
		"Ľ�ݸ�"   : "��������Ҳ�������������Ҽҹ��ӣ�\n",
		"������"   : "���ǹ���ү�ľ��裬����ɽׯ��ׯ����\n",
		"����"     : "��С����ֻ����һ�꣬�����ϲ��������档\n",
		"�˰ٴ�"   : "���ʵ˴�簡�����������ׯ���ء�\n",
		"��ұǬ"   : "��ұ������Ÿ봫��һ���룬��û�����˶��ö��ˡ�\n",
		"����ͬ"   : "�������̧���ˣ�����������Ǳ���ĺá�\n",
		"�粨��"   : "���ĸ����Ǻ�ˬ�ˣ����Ӳ����˼ƽ�ʲô��\n",
	]) );
	create_family("����Ľ��", 33, "����");
	setup();
	carry_object("/d/yanziwu/npc/obj/goldring")->wear();
	carry_object("/d/yanziwu/npc/obj/necklace")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/yanziwu/npc/obj/green_cloth")->wear();
	carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say ��λ" + RANK_D->query_respect(ob) +
			"����Ľ�ݼҸ�������ΪҪ�£�����־���ᣬ��Ե���š�");
		return;
	}
	command("say �ð��Ҿ�����Ϊͽ�ɡ�");
	command("recruit " + ob->query("id"));
}
