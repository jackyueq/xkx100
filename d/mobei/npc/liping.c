// liping.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("��Ƽ",({"li ping","li","ping"}));
	set("gender","Ů��");
	set("long","������ĸ�ף��������ɹš�\n");
	set("combat_exp", 6000);
	set("age", 43);
	set("max_qi", 800);
	set("qi", 800);
	set("food", 250);
	set("water", 250);
	setup();
	add_money("silver",5);
	carry_object("/clone/cloth/cloth")->wear();
}
