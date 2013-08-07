//Edited by fandog, 02/15/2000

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ƹ�", ({ "zhang gui", "boss" }));
	set("shen_type", 1);

	set("gender", "����");
	set("age", 35);
	set("long", "��λ�ƹ��������������人�ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/jiangling/obj/tongluo",
		"/d/jiangling/obj/yumaoshan",
	}));
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
