// bing.c �ٱ�

inherit NPC;

void create()
{
	set_name("���", ({ "yi bing", "bing" }));
	set("age", 22);
	set("gender", "����");
	set("long","�����ǹ������վ�ı�ʿ����Ȼ����ս��Ƣ���ã�Ҳ�����������Ŷ��\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(ARMOR_DIR"junfu")->wear();
}
