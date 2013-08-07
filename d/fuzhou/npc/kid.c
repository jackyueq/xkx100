// kid.c
// Last Modifyed by Winder on Sep. 10 2002

inherit NPC;
void create()
{
	set_name("��ͯ",({ "kid" }) );
	set("gender", "����" );
	set("age", 6);
	set("long", "���Ǹ���ƤСͯ��ͷ�����ų���С�衣\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen", 100);
	set("shen_type", 1);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) )
	{
		case 0:
			say("��ͯ�������µ�����λ" + RANK_D->query_respect(ob) + "����Ҫ���������ҵ�����\n");
			break;
		case 1:
			say("��ͯ�������µ�����λ" + RANK_D->query_respect(ob) + "����ʲô�����ٿ��ұ��㡣\n");
			break;
	}
}
