// li.c

inherit NPC;

void create()
{
	set_name("��׾����", ({ "li zhuo", "zhuo", "li" }) );
	set("gender", "����");
	set("age", 20);
	set("long",
		"����һ��ʮ���׶������ɵ��ˡ�\n");
	set("combat_exp", 120000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);

        create_family("�����", 5, "����");
	setup();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);
}
