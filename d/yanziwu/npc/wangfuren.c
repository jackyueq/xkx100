// wangfuren.c
inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("������", ({ "wang furen","wang" }) );
	set("gender", "Ů��" );
	set("title", HIM"����ɽׯׯ��"NOR );
	set("age", 35);
	set("long", "������Ƴ�����üĿ�ڱǾ��������ף�����ȴ���з�˪���µĺۼ���\n");
	set("shen_type", -1);
	set("combat_exp", 100000);
	set("per", 30);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 800);

	set_skill("yanling-shenfa", 50);
	set_skill("shenyuan-gong", 50);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("parry", 50);
	map_skill("dodge", "yanling-shenfa");
	map_skill("force", "shenyuan-gong");
	setup();
	carry_object(__DIR__"obj/yellow_cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
