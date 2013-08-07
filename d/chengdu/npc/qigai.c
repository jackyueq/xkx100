// Room: /d/chengdu/npc/qigai.c ��ؤ
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("��ؤ", ({ "qigai", "qi" }));
	set("gender", "����");
	set("age", 21);
	set("long", "����һ�����춫���������ؤ��������ؤ����ˡ�\n");
	
	set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",2);
}
