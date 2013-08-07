// Room: /d/chengdu/npc/weibing.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("����", ({ "wei bing", "bing" }) );
	set("long",
"���Ǹ�����ִ��Ѳ�������������˭Ҳ�����׵��������ǡ�\n"
"�����Ҳ��Ҫ�������ǡ� \n");
	set("attitude", "heroism");
	set("pursuer", 1);
	set("vendetta_mark", "authority");
	set("str", 27);
	set("int", 26);
	set("con", 25);
	set("combat_exp", 100000+random(1000000));
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"�����ȵ�������ӣ�����������ӷ����������־͸���\n",
		"�����ȵ������޾��Ҿܲ������ˣ����ˣ�\n"
	}) );

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("blade", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
 
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object(ARMOR_DIR"tiejia")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

int accept_object(object who, object ob)
{
	if( (int)ob->value() >= 500000 )
	{
		say("�����Ǻǵ�Ц��������ɶ�����˵����˵...\n");
		who->set("vendetta/authority", 0);
		who->remove_all_killer();
		return 1;
	} else {
		say("����˵���������Ǯ���������ӺȾƵ��أ�\n");
		return 0;
	}
	return 0;
}

