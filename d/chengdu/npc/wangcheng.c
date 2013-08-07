// Room: /d/chengdu/npc/wangcheng.c ����c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("����", ({ "wang cheng", "wang", "cheng" }));
	set("gender", "����");
	set("age", 21);
	set("long", "�ű��ֵĴ���ӣ�Ϊ����ʵ�Ͽң�����Ϊ����Ŀ�ģ��\n");
	set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	set_skill("unarmed", 25);
	set_skill("dodge", 25);
	set_temp("apply/attack", 12);
	set_temp("apply/defense", 12);

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	add_money("silver",10);
}
