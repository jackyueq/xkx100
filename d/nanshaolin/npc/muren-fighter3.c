// Npc: /d/nanshaolin/npc/muren-fighter3.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("ľ��", ({ "mu ren" }) );
	set("long", "һ��ľ��");
	set("gender", "��е");
	set("age", 20);
	set("attitude", "friendly");

	set("str",30);
	set("int",30);
	set("con",30);
	set("dex",30);
	set("max_qi", 500);
	set("max_jing", 250);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 20000);

	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("club", 50);
	set_skill("weituo-club", 50);
	set_skill("parry", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("parry", "weituo-club");
	map_skill("club", "weituo-club");
	setup();

        carry_object(WEAPON_DIR+"qimeigun")->wield();
}

void init()
{
	object ob = this_player();

	if (query("destructing")) return;
	prepare_skill("club", "weituo-gun");
	if (userp(ob))
	{
		say("\nһ��ľ�˴Ӱ�������ӭͷ����һ����\n");
		COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
	}
	if (!present(ob,environment()) || ob->query("qi") < 0 ||
		ob->query("jing") < 0 || ob->query("jingli") < 0)
	{
		ob->move("/d/nanshaolin/daxiong", 1);
		ob->delete_temp("murenxiang");
		tell_object(ob,"�㱻ľ�˻����ˣ����������ƺ�����̧���˴��۱��\n");
	}
	set("destructing", 1);
	set_ghost(1);
	say("\nľ����������˰�����\n");
	call_out("destruct_me", 1);
}

void destruct_me()
{
	destruct(this_object());
}