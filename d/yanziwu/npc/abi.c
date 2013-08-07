// abi.c

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("����", ({ "abi", "bi" }));
	set("long",
		"���Ǹ������µ�Ů�ɣ�Լʮ��������ͣ������������ᣬ\n"
		"������������һ�ſɰ��Ĺ��������������°���ź��˵��\n"
		"���������壬����һ��֮��˵���������ʡ���Ǳ�һ��ϸ\n"
		"ϸ�ĺ��룬�������ġ�\n");
	set("gender", "Ů��");
	set("age", 16);
	set("per", 28);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);
	set_skill("strike", 40);
	set_skill("finger", 40);
	set_skill("murong-sword", 30);
	set_skill("murong-blade", 30);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 30);
	set_skill("yanling-shenfa", 30);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");

	set("combat_exp", 10000);
	set("inquiry",([
		"����ɽׯ" : "�ҲŲ���ȥ����ɽׯ��������̫�Ե��ˣ�\n",
		"������" : "����ֻ��������������ǹ��ӣ�Ҳ��֪�����������ˣ�\n",
		"����"     : "��С����ֻ����һ�꣬�����ϲ��������档\n",
	]) );
	create_family("����Ľ��", 33, "����");
	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object("clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/green_cloth")->wear();
	carry_object(__DIR__"obj/flower_shoe")->wear();
}
