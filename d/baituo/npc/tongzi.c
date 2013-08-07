// tongzi.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
int do_bi(string arg);
void greeting(object);
void init();
void create()
{
	set_name("����ͯ��", ({ "tongzi"}) );
	set("gender", "����" );
	set("age", 16);
	set("long", "���Ǹ���������������ͯ�ӡ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 20);

	set("max_qi", 200);
	set("combat_exp", 10000);
	set("score", 500);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry",20);
	create_family("����ɽ��", 4, "����");
	setup();
}

void init()
{
	object ob;
	add_action("do_bi","bi");

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (((string)ob->query("family/family_name") == "����ɽ��") &&
		ob->query("combat_exp")<10000)
	message_vision("����ͯ�ӳ���$N�е����������ұȻ����С�(bi tongzi)\n",ob);
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ�����ͽ���㻹�ǰ����ͷ�ɡ�\n");
	return;
}

int do_bi(string arg)
{
	object ob=this_player();
	if(!arg||arg!="tongzi") return  notify_fail("��Ҫ��˭�Ȼ�?\n");
	if ((int)ob->query("combat_exp")>10000)
		return notify_fail( "����ͯ��ҡͷ����������书,�Ҳ�������������ˡ�\n");
	say("����ͯ��ͬ�������������\n");
	set("combat_exp",ob->query("combat_exp"));
	command("hit "+(string)ob->query("id"));
	if(query("qi")<40) message_vision("����ͯ�Ӷ�$N�������!\n",ob);
	else message_vision("����ͯ�Ӷ�$NЦЦ����Ŭ���ɡ�\n",ob);

	set("eff_qi",200);
	set("qi",200);
	set("combat_exp",10000);
	return 1;
}

int accept_fight(object ob)
{
	if ((string)ob->query("family/family_name") == "����ɽ��")
	{
		if((int)ob->query("combat_exp")<5000)
			return notify_fail("����ͯ��Ц������ľ���̫���ˣ������ȵ��Ȼ��ɣ�(bi tongzi)\n");
	}
	message_vision("����ͯ�Ӷ�$N�е������ҾͲ������ˣ�\n",ob);
	return 1;
}


