
inherit NPC;

void create()
{
    set_name("ţ", ({ "niu" }) );
	set("race", "Ұ��");
	set("age", 5);
    set("long", "һͷ��׳��ţ��\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
    set("verbs", ({ "kick", "bite" }) );

    set("max_qi", 300);
    set("max_jing", 100);
    set("eff_jingli", 100);

    set("combat_exp", 1200);
	
    set_temp("apply/attack", 5);
	set_temp("apply/defense", 10);
    set_temp("apply/damage", 5);
    set_temp("apply/armor", 5);

	setup();
}