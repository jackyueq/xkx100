// deer.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("÷��¹", ({ "deer" }) );
	set("race", "����");
	set("age", 5);
	set("long", "һֻƯ����÷��¹��\n");
	set("attitude", "peaceful");
	
	set("combat_exp", 800);

	set("chat_chance", 6);
	set("chat_msg_combat", ({
		"\n÷��¹һת������¹�ǳ��㶥������\n",
	}) );
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	setup();
}

	
