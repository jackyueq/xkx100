// south.c �ϼҳ�ԲԲ

inherit NPC;

void create()
{
	set_name("��ԲԲ", ({ "chenyuanyuan"}));
	set("age", 40);
	set("gender", "Ů��");
	set("title", "�ϼ�");
	set("long","�����ǳ�ԲԲ����Ȼ������Ϊ���˴�����ɽҲ������һ����ϵ�����������ǵı���ȴҲ��С��\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("per", 40);
	set("combat_exp", 10000);
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

