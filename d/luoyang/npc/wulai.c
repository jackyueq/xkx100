// wulai.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "wu lai", "wulai" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ֺ��е���������Ǯ�ĵ����ۺ��ס���ɫ�Ұ���\n");
	set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
