//Edited by fandog, 02/15/2000

inherit NPC;

void create()
{
	set_name("���Ĳ�",({ "kongxin cai", "kid" }) );
	set("gender", "Ů��" );
	set("age", 5);
	set("long", 
"һ������ɰ���СŮ����������ҹ�������Ů����\n");
	set("combat_exp", 20);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

