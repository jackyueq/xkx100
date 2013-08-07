#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��¡", ({ "duo long", "duo", "long" }));
	set("title", HIY "��ǰ�����ܹ�" NOR);
	set("age", 32);
	set("gender", "����");
	set("long", "��¡����ǰ�������ܹܣ���Ÿߴ���࣬һ����ҹ�������˵á�\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("dex", 30);
	set("combat_exp", 1000000);
	set("shen_type", 1);

	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"��¡�ȵ��������̵ģ������Ҷ����ǣ�\n",
	}));
	setup();
	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(CLOTH_DIR"jinduan")->wear();
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
