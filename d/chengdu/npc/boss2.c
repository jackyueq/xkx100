// Room: /d/chengdu/npc/boss2.c ���ϰ� 
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "wang yongkan", "wang" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);
	set("gender", "����");
	set("age", 45);
	set("long", "���ϰ������������ĳɶ��ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		ARMOR_DIR"beixin",
		ARMOR_DIR"huwan",
		ARMOR_DIR"huyao",
		ARMOR_DIR"huzhi",
		ARMOR_DIR"other/neck",
		ARMOR_DIR"other/surcoat",
		ARMOR_DIR"other/shield",
		__DIR__"obj/cycle",
		__DIR__"obj/toukui",
		__DIR__"obj/caoxie",
		__DIR__"obj/pixue",
		__DIR__"obj/shoutao",
		__DIR__"obj/tieshou",
		__DIR__"obj/mabudai",
	}));
	
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
