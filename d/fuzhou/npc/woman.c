// woman.c

inherit NPC;

void create()
{
	set_name("�ٸ�",({ "woman" }) );
	set("gender", "Ů��" );
	set("age", 25);
	set("long", "���Ǹ������ٸ���˫Ŀ���飬һ���ظ��Ĺ����ҡ�\n");
	set_temp("apply/defense", 6);
	set("combat_exp", 700);
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
			say("�ٸ�����˵������λ" + RANK_D->query_respect(ob) + "����������ƤС����ū�Ҹ���ô�찡��\n");
			break;
		case 1:
			say("�ٸ�������˵������λ" + RANK_D->query_respect(ob) + "��ū�ҵ��Ǹ�����֪���ֵ�������ȥ�ˣ������ҹܽ�һ��С���ɡ�\n");
			break;
	}
}
