// he.c

inherit NPC;

void create()
{
	set_name("��Ա��", ({ "he yuanwai", "he" }));
	set("shen_type", -1);

	set("gender", "����" );
	set("age", 53);
	set("long", "��Ա�������ݳ�����׸����͵��صĹ����к���Ľ��顣\n");
	set("combat_exp", 400);
	set("attitude", "friendly");
	setup();

	carry_object(__DIR__"obj/choucloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("��Ա����ֵض���˵��������������ô������ؾ��ܵ��ҵ�԰����������\n");
}
