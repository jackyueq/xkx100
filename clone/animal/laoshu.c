// laoshu.c ����
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("����", ({ "lao shu", "shu", "mouse" }) );
	set("race", "����");
	set("age", 2);
	set("long", "һֻ�������С����\n");
	set("attitude", "peaceful");
	
	set_weight(300);

	set("combat_exp", 100);
	set("env/wimpy", 70);

	set_temp("apply/attack", 5);
//	set_temp("apply/damage", 20);
	set_temp("apply/dodge", 20);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	ob = new(__DIR__"obj/shurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

