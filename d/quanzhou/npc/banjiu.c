// banjiu.c

inherit NPC;

void create()
{
	set_name("���",({ "ban jiu", "bird" }) );
	set("race", "����");
        set("gender", "����" );
        set("age", 13);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");
        setup();
}
