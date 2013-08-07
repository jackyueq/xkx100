// Npc: /rong.c
// Date: Oct.18 1999 by Winder

inherit NPC;
void create()
{
	set_name("���Ӿ�", ({ "rong ziju", "rong", "ziju"}));
	set("long",
		"����һλ��ĸߴ��������ˡ�\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "taoist");

	set("age", 40);
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 850);
	set("max_neili", 850);
	set("jiali", 40);
	set("combat_exp", 80000);
	set("score", 100);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("parry", 60);
	set_skill("damo-jian", 60);
	set_skill("sword", 60);

	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	set("inquiry", ([
		"�������"  : "���Ǳ��ɽ��أ��κ����˲������롣�ɷ����ɣ��ɽ���������֮�ء�",
	]));

	create_family("����������", 4, "����");
	setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

