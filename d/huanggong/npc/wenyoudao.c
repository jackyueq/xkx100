// wenyoudao.c
#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("���е�", ({ "wen youdao", "wen" ,"youdao"}));
	set("gender", "����");
	set("title", HIC"���鷿̫��"NOR);
	set("age", 16);
	set("long", "һ��������С̫�࣬�����ֵ����з���˾���鷿��\n");

	set("combat_exp", 1000);
	set("shen_type", 0);
	set("per", 20);

	set_skill("unarmed", 10);
	set_skill("blade", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	add_money("silver", random(10));
	carry_object(__DIR__"obj/tjcloth")->wear();
}
	
