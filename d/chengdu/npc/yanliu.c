// Room: /d/chengdu/npc/yanliu.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>;
inherit NPC;
inherit F_DEALER;

int redeem(string arg);

void create()
{
	set_name("����", ({ "yan liu", "yan" }));
	set("nickname", "��Ǯ��ʹ����ĥ");
	set("long", "���Ǹ����������ļһ\n");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("no_get_from", 1);
	set("no_get", 1);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}

