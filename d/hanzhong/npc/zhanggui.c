// zhanggui.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ƹ�", ({ "zhanggui", "gui" }));
	set("long", "����λ�ͺ������������ˡ�\n");
	set("gender", "����");
	set("age", 45);

	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", 1);

	set("vendor_goods", ({
		FOOD_DIR"kaoya",
		LIQUID_DIR"jiudai",
	}));

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver",20);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
