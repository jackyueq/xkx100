// yahuan1.c
//
inherit NPC;
void create()
{
	set_name("Ѿ��",({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("long","����֪�����˵�Ѿ�ߣ���Լʮ�ġ����꣬�������ף�һ���������ɫ��\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
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
