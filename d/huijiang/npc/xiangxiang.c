// Room: /d/honghua/npc/xiangxiang.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;
void create()
{
	set_name("���㹫��",({"xiangxiang gongzhu", "gongzhu"}));
	set("gender","Ů��");
	set("long","ľ׿�׵�СŮ���������������㡣\n");
	set("combat_exp",40000);
	set("age",17);
	set("per", 40);

	setup();
	add_money("silver",20);
	carry_object("/clone/cloth/luoyi")->wear();
}
