// d/suzhou/npc/seng.c
inherit NPC;


void create()
{
	set_name("֪��ɮ", ({ "zhike seng", "zhike", "seng" }));
	set("long", "����һλδͨ���ʵ�������У����Ϲ����������Ц��\n");
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);

	setup();

}

