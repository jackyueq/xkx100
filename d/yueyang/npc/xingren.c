// xingren.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "xing ren", "ren" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���ҴҸ�·�����ˣ�û�����㡣\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",2);
}
