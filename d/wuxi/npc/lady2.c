// lady1.c

inherit NPC;

void create()
{
	set_name("������Ů",({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 16);
	set("long", 
"���Ǹ�ʮ��������绪��ï����Ů��ɽ��������ˮ�����ᡣ\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 400);
//	set("shen", 100);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
}

