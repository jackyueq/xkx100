//NPC /d/wuxi/npc/wulai.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
void create()
{
	set_name("����", ({ "wu lai", "wu", "lai" }));
	set("gender", "����");
	set("age", 18);
	set("long", "����һ���������ֺ��е�С�죬һ����а������ϲ��û�����¡�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi", 200);
	set("max_qi", 200);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 10);
	set("max_neili", 10);
	set("combat_exp", 3000);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
