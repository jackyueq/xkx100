// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("С����", ({ "xiao lanyan", "xiao" }));
	set("gender", "����");
	set("age", 19);
	set("long", "���Ǹ�����������С���ۣ������Ĵ�������\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",2);
}

