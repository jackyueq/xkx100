inherit NPC;

void create()
{
	set_name("����", ({ "shi zhe", "shi", "zhe" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "һ�����ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 2000);
	set("str", 10);
	set("dex", 10);
	set("con", 10);
	set("int", 10);
	set("attitude", "peaceful");
	set_skill("dodge",20);
	set_skill("unarmed",20);
	set("chat_chance", 1);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver", 1);
}
