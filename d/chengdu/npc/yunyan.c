// yunyan.c
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;

void create()
{
	set_name("л����", ({ "xie yunyan", "xie", "yunyan" }));
	set("long", "�����ݽ��ģ�Ƥ���⻬���ۣ�һ˫�����������飬��Ŀ������\n");
	set("title", "ǧ������");
	set("gender", "Ů��");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object("/d/city/obj/necklace")->wear();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/goldring")->wear();
}

