// Npc: /d/guiyun/npc/yahuan.c Ѿ��
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("Ѿ��", ({ "ya huan", "ya", "huan" }));
	set("gender", "Ů��");
	set("age", 12);
	set("long", "����һ��СѾ�ߣ�������С������δ�㡣\n");
	
	set("combat_exp", 1500 + random(100));
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 15);
	set_skill("dodge", 15);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 12);
	set("max_qi", 130);
	set("max_jing", 130);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 5);

	set("inquiry",([
		"name" : "�ҽ��̶�����С�ͱ�����������Ѿ�ߡ�",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
