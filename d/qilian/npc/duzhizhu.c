//fushe.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIB"��֩��"NOR, ({ "du zhizhu", "zhizhu" }) );
	set("race", "����");
	set("subrace", "����");
	set("age", random(10));
	set("long", "һֻ�����ڴ�Į��Ե�Ķ�֩�롣\n");
        set("attitude", "aggressive");
	set("str", 20);
	set("cor", 20);
	set("combat_exp", 30000+random(50000));

	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage", 10+random(10));
	set_temp("apply/armor", 15+random(10));
	set_temp("apply/defence",20+random(10));
	setup();
}

