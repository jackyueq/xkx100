// minghui.c

inherit NPC;

void create()
{
	set_name("����", ({ "ming hui", "hui"}));
	set("long", "�����ü������������Ƕ��۾����ĵ�ֱ���Թ��˻��ǡ�\n");
	set("title", "�ʹ���");
	set("gender", "Ů��");
	set("age", 17);
	set("per", 28);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/cloth1")->wear();
}

