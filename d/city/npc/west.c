// west.c ���Һ�����
inherit NPC;

void create()
{
	set_name("������", ({ "hongniangzi"}));
	set("age", 30);
	set("gender", "Ů��");
	set("title", "����");
	set("long","�����Ǻ����ӣ���Ȼ���Ϲ���������ͷ����������Իٵĳ��ǣ�����������𳤳�Ҳ�Ǻ���������\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("per", 35);
	set("combat_exp", 100000);
	set("shen_type", 1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) ) command( "addin" );
}

