// Room: /d/chengdu/npc/xiaoheshang1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("С����", ({ "xiao heshang", "xiao", "heshang" }));
	set("long", "����λ����ĺ��У������ϵ����ӣ������϶���λ�õ���ɮ��\n"); 
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 14);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 1000);
	set("score", 50);

	set_skill("force", 8);
	set_skill("dodge", 8);
	set_skill("unarmed", 8);
	set_skill("parry", 8);

	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
	carry_object(CLOTH_DIR"seng-shoe")->wear();
}

