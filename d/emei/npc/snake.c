// snake.c
inherit NPC;
void create()
{
        set_name("����", ({ "snake", "she" }) );
	set("race", "����");
        set("age", 4);
        set("long", "һֻ�����������Դ����ߣ�β��ɳɳ���졣\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);
        set("combat_exp", 1000);
        set("max_qi",300);
        set("qi",300);
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
        setup();
}
