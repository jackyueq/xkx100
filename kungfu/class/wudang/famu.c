// famu.c ��ľ��ʿ
// Last Modifyed by Winder on Jan. 14 2002

inherit NPC;

void create()
{
	int age;
	age = 15 + random(30);
	
	set_name("��ľ��ʿ", ({ "famu daoshi", "famu", "daoshi" }));
	set("long", "�����䵱ɽ�ķ�ľ��ʿ����������������\n");
	set("gender", "����");
	set("age", age);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 35);
	set("int", 15);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 2000+age*10);
	set("score", 2000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("cuff", 40);
	set_skill("parry", 40);
	set_skill("sword", 30);
	set_skill("taiji-jian", 40);
	set_skill("taoism", 30);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	create_family("�䵱��", 5, "����");
	set("chat_chance", 6);
	set("chat_msg", ({
		"��ʿ����һ�Ѷ�ͷ�ϵĺ���˵����СС����������ѧ�ʡ�\n",
		"��ʿ˵���������¶�Ҫǡ���ô�������Ҳ�����⡣\n",
		"��ʿ˵����������ʱ��Ҫ̫��̫�죬�������ɵ��»����ˡ�\n",
		"��ʿ˵����������ʱ��Ҳ��Ҫ̫���ˣ������������ᵹ��\n",
	}) );

	setup();
	add_money("coin", age*10);
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}
