// leichu.c
inherit NPC;

void create()
{
	set_name("���", ({ "lei chu", "lei", "chu"}) );
	set("gender", "Ů��" );
	set("age", 14);
	set("long", "����һ��С��Ů,��ò������,����ͦ�ܸ�.\n");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("per", 24);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

