// shifu.c ��ʦ��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��ʦ��", ({ "shi fu", "shifu" }) );
	set("gender", "����" );
	set("age", 42);
	set("long","��λ��ʦ������컨��ӽ������ģ�����һ�ֺ��պ��ˡ�\n���ľ����Ƕ����⡣��ϧ�ش�������������������ⶼ�Ҳ�����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("vendor_goods", ({
		"/d/hangzhou/npc/obj/fish",
		"/d/hangzhou/npc/obj/shrimp",
		"/d/hangzhou/npc/obj/chicken",
		"/d/hangzhou/npc/obj/geng",
		"/d/hangzhou/npc/obj/jiuping",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
