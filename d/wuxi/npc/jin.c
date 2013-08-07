// jin. ���ϰ�

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���ϰ�", ({ "jin laoban", "jin" }));
	set("title", "�ɺ�¥�ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "���ϰ徭Ӫ�洫�������ɺ�¥���ж��ꡣ\n");
	set("combat_exp", 50000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set("vendor_goods", ({
		"/d/city/npc/obj/hdjiudai",
		__DIR__"obj/paigu",
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
