// shuke.c

inherit NPC;

void create()
{
	set_name("���",({ "shuke" }) );
	set("gender", "����" );
	set("age", 26);
	set("long", 
"���Ǹ��������ͣ�һ��רע�����飬�Խ������˵��Ӷ�������\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("str", 20);
	set("per", 20);
	set("dex", 20);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}

