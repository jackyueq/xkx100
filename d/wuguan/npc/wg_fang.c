
inherit NPC;

void create()
{
	set_name("������", ({ "fang xiansheng", "fang", "xiansheng"}));
	set("long", "��λ����������������ض��顣\n");
	set("gender", "����");
	set("age", 35);
	set_skill("literate", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set("combat_exp", 50000);
	setup();
	carry_object("clone/cloth/cloth")->wear();
}

