// yi.c
#include <ansi.h>

inherit NPC;
int ask_lvzhuweng();

void create()
{
	set_name("��ʦү", ({ "yi shiye", "yi", "shiye"}));
	set("long",
"��ʦү�Ǹ�����СС����ʮ����ĺ��ӣ��������һ��ϡϡ��
��ĺ��ӣ������������ࡣ\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 14);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 500);

	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	set("inquiry", ([
		"������"     : (: ask_lvzhuweng :),
		"����������" : (: ask_lvzhuweng :),
		"����"       : "�����и������̣����ú��٣����ú��\n",
	]));

	set("chat_chance", 30);
	set("chat_msg", ({
		"�����и������̣����ú��٣����ú��\n",
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold",1);
}
int ask_lvzhuweng()
{
	object me = this_player();
	message_vision(CYN"��ʦү�͵���Բ�����ۣ���$N˵������Ҳ��ȥ��ʶ�������������һ��ȥ�ɡ�\n"NOR,me);
	set_leader(me);
	return 1;
}
