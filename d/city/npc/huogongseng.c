//NPC /d/city/npc/huogongseng.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
void create()
{
	set_name("��ɮ", ({ "huogong seng", "seng" })); 
	set("long", "һ��������ר�����µĻ�ɮ������ʮ�ֵ�ǿ׳��\n");
	set("gender", "����");
	set("class", "bonze");
	set("title", "�����º���");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 15);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 200);
	set("max_jing", 200);
	set("neili", 30);
	set("max_neili", 30);
	set("combat_exp", 3000);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);

	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();
}
