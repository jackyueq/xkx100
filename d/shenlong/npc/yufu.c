// yufu.c ���
// Last Modified by winder on Jul. 12 2002

inherit NPC;

void create()
{
	set_name("���", ({ "yu fu","fu" }) );
	set("gender", "����");
	set("age", 35);
	set("long", "�����Դ���Ϊ�������\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  30);
	set("apply/defense", 30);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("coin", 50);
}
