inherit NPC;

void create()
{
	set_name("���ҵ���", ({ "fujia dizi", "dizi", "fujia" }) );
	set("gender", "����" );
	set("age", 21);
	set("long",
		"һ���װ����ֵ������ˣ�һ����֪���ǽ����������˵ġ�\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("str", 10);
	set("dex", 10);
	set("con", 10);
	set("int", 10);
	set("attitude", "peaceful");
	set_skill("dodge",20);
	set_skill("unarmed",20);

	setup();
	carry_object(CLOTH_DIR"jinduan")->wear();
	add_money("silver", 20);
}
