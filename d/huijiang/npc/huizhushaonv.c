// Room: /d/huijiang/npc/huizhushaonv.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;
void create()
{
	set_name("������Ů",({"shao nv"}));
	set("gender","Ů��");
	set("combat_exp",4000);
   
	set("age",19);
	setup();
	add_money("silver",1);
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"whip/whip")->wield();
}
