// Npc: /d/gaochang/npc/ghost.c

inherit NPC;

void create()
{
	set_name("�»�Ұ��", ({ "gui", "phost"}));
	set("long",
		"���������������ޣ���翲�����һ����˵�����Ĺ���.\n"
		"�㿴������ͷ�����⡣\n"
	);

	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 100);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("pursuer", 1);
	set("combat_exp", 2000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
}


void init()
{
	object ob = this_player();
	
	::init();

	if (interactive(ob))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}       
}

