//NPC /d/city/npc/kanmenseng.c
#include <ansi.h>
inherit NPC;
void greeting(object ob);
void create()
{
	set_name("����ɮ", ({ "kanmen seng", "seng" })); 
	set("long", "һ������ɮ�ˣ�ȴ��һ����ƣ̬��һ˫�۾��������ǳ����ˣ������úܡ�\n");
	set("gender", "����");
	set("class", "bonze");
	set("title", "�����º���");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 15);
	set("int", 14);
	set("con", 15);
	set("dex", 16);
	set("qi", 200);
	set("max_qi", 200);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 10);
	set("max_neili", 10);
	set("combat_exp", 2000);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();
}
