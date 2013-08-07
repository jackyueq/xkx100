// langren.c

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("�ձ�����", ({ "lang ren", "langren", "lang"}));
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long","���Ǹ���̬�ư��Ķ�����ʿ��ͷ�����ң����ŻҺ�ɫ�ĺͷ���������Űѳ�������ʿ����\n");
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/armor", 35);
	set_temp("apply/damage", 35);
	set_skill("blade", 35);
	set_skill("dodge", 35);

	setup();
	carry_object("/d/taiwan/npc/obj/wodao")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( environment(ob) != environment() ) return;
	say("�ձ���������ص�����һ�ۣ�˵�����й��˶��������û�ðɣ���������\n");
}

