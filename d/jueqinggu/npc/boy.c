// Room: /d/jueqinggu/npc/boy.c
// Last Modified by winder on Feb. 17 2001

inherit NPC;

void create()
{
	set_name("ͯ��",({ "boy", "tonger" }) );
	set("gender", "����" );
	set("age", 13);
	set("long", 
"���Ǹ�����������Сͯ��\n");

	set("str", 17);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("shen", 100); 
	set("combat_exp", 12000);
	set("attitude", "peaceful");

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin",40);
}

