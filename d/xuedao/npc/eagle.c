// eagleg.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
        set_name("ͺӥ", ({ "eagle" }) );
	set("race", "����");
        set("age", 3);
        set("long", "һֻ��ɫ��ͺӥ��ͺͷ���𣬺óԸ�ʬ�����������Ἣ�ˡ�\n");
        set("attitude", "peaceful");

        set("combat_exp", 3000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        setup();
}
