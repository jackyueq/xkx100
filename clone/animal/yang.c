// yang.c ����
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("����", ({ "mian yang", "yang", "sheep" }) );
	set("race", "����");
	set("age", 6);
	set("long", "һͷ��˳��С����\n");
	set("attitude", "peaceful");
	
	set("str", 16);
	set("dex", 15);

	set("combat_exp", 100);

	set_temp("apply/attack", 8);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 4);
	set_temp("apply/armor", 2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ڵ������ˡ�\n", this_object());
	ob = new(__DIR__"obj/yangrou2");
	ob->move(environment(this_object()));
	destruct(this_object());
}

