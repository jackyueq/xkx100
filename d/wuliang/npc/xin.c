// Npc: /xin.c
// Date: Oct.18 1999 by Winder

inherit NPC;
void create()
{
	set_name("��˫��", ({ "xin shuangqing", "xin", "shuangqing"}));
	set("long",
		"����һλ����ʮ���ҵ�������ã������������촽���ա�\n");
	set("gender", "Ů��");
	set("attitude", "friendly");
	set("class", "taoist");

	set("age", 52);
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 150000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("changquan", 80);
	set_skill("parry", 80);
	set_skill("damo-jian", 80);
	set_skill("sword", 80);

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

