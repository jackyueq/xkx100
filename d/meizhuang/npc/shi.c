// shi.c
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("ʩ����", ({ "shi lingwei", "shi" }));
	set("long", "���������ӽ����������·��ʩ������������÷ׯ���ܼҡ�\n");
	set("gender", "����");
	set("nickname", HIR"��·��"NOR);
	set("attitude", "friendly");

	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_qi", 3350);
	set("max_jing", 2200);
	set("neili", 1350);
	set("max_neili", 1350);
	set("jiali", 100);
	set("combat_exp", 300000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIW"����"NOR);
	create_family("��ľ��", 10, "����");
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
	"ʩ����������ŵĳ����Ӻ�������һ�ۡ�\n",
	}) );
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

