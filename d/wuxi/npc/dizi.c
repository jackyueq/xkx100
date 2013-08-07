// dizi.c
inherit NPC;
int do_bi(string arg);
void greeting(object);
void init();
void create()
{
	set_name("��ݵ���", ({ "wuguan dizi", "dizi"}) );
	set("gender", "����" );
	set("age", 16);
	set("long", "���Ǹ�������������ݵ��ӡ�\n");
	set("attitude", "friendly");
	set("shen_type", 0);

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
	if (ob->query("combat_exp")<10000)
	message_vision("��ݵ��ӳ���$N�е����������ұȻ����С�(bi dizi)\n",ob);
}

int do_bi(string arg)
{
	object ob=this_player();
	if(!arg||arg!="dizi") return  notify_fail("��Ҫ��˭�Ȼ���\n");
	if ((int)ob->query("combat_exp")>10000)
		return notify_fail("��ݵ���ҡͷ����������书���Ҳ��������������\n");
	say("��ݵ���ͬ�������������\n");
	set("combat_exp",ob->query("combat_exp"));
	command("hit "+(string)ob->query("id"));
	if(query("qi")<40)
		message_vision("��ݵ��Ӷ�$N�������!\n",ob);
	else
		message_vision("��ݵ��Ӷ�$NЦЦ����Ŭ���ɡ�\n",ob);

	set("eff_qi",200);
	set("qi",200);
	set("combat_exp",10000);
	return 1;
}

int accept_fight(object ob)
{
	message_vision("��ݵ��Ӷ�$N�е������ҾͲ������ˣ�\n",ob);
	return 1;
}


