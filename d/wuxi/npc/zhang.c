// zhang.c ������ 

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "niren zhang", "zhang" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
"�����ŵ��ϰֽ������ţ���үүҲ�������ţ����������洫���������գ�Զ��������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 4000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/daafu",
		__DIR__"obj/xiaoafu",
		__DIR__"obj/niren",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
