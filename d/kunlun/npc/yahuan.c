// Last Modified by winder on Jun. 29 2001
// Npc: /d/kunlun/npc/yahuan.c Ѿ��

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("С��", ({ "xiao feng", "feng" }));
	set("title", HIR"��÷ɽׯѾ��"NOR);
	set("gender", "Ů��");
	set("age", 35);

	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", -1);
	setup();
}

