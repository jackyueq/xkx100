// jumang.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("����", ({ "ju mang", "mang" }) );
	set("race", "����");
	set("age", 70);
	set("long", "һ��������������������\n");
	set("attitude", "aggressive");
	set("str", 150);
	set("con", 150);
	set("combat_exp", 250000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 200);
	setup();
}

void die()
{
	object ob;
	message_vision("$N���������˼��¾Ͳ����ˡ�\n", this_object());
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}

