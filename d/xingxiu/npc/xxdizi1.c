// Room: /d/xingxiu/npc/xxdizi1.c
// Last Modified by Winder on Apr. 25 2001

inherit NPC;

void create()
{
	set_name("�����ɵ���", ({ "xingxiu dizi", "dizi"}));
	set("gender", "����" );
	set("age", 26);
	set("long","���������ɵĶ�ͽ, ��ɱ�����, �޶�����\n");

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("combat_exp", 2000);
	set("shen", -200);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 18);
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 5);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 25);
	set_skill("staff", 20);
	set_skill("parry", 20);
	set_skill("tianshan-zhang", 10);
	map_skill("staff", "tianshan-zhang");
	create_family("������", 3, "����");
	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object(__DIR__"obj/changpao")->wear();
	add_money("silver", 5);
	set("chat_chance", 5);
	set("chat_msg", ({
		"�����ɵ���һ�������˿�����, һ��������̵������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
		"�����ɵ���һ�������˿�����, һ��������̵������ǡ��ޡ��ϡ��ɣ�������御����\n",
		"�����ɵ���һ�������˿�����, һ��������̵������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
	}) );
}

void init()
{
	object ob;
	mapping fam;
	::init();

	ob = this_player();
	if (interactive(ob) &&
		( (fam = ob->query("family")) &&
		fam["family_name"] != "������" ) )
	{
		command("say �󵨿�ͽ�����Ҵ�����ɽ��������Ұ������\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 2, ob);
	}
}
