//  /guanwai/npc/diao.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name(HIY"���"NOR, ({ "diao"}));
	set("race", "����");
	set("age", 3);
	set("long", "һֻ������������֦�����ӳ��졣\n");
	set("attitude", "peaceful");

	set("combat_exp", 30000);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 50);

	setup();
}
