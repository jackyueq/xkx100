// /beijing/npc/shiwei2.c
// Last modified by winder 2003.10.10

inherit NPC;

void create()
{
	set_name("����Ӫ����", ({ "shi wei", "shi", "wei" }));
	set("age", 32);
	set("gender", "����");
	set("long", "����Ӫ���������������Ͻ����еĺ��֣�ǧ���ȥ���ǡ�\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("dex", 30);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 60);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"����Ӫ�����ȵ���������ͽ������֮�У�����������\n",
	}));
	setup();
	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say ���������������ҵģ��ݵù������顣\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
