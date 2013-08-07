// animal: eat_fish.c

inherit NPC;

void create()
{
	set_name("������", ({ "fish", "yu" }) );
	set("race", "����");
	set("age", 3);
	set("long", "����һֻ���β����ܴ���㣬������Ѥ������Ƭ��\n"
	    "һ�ڷ��������ݣ������ӵ����Ŀ�����\n");
	set("attitude", "aggressive");

        set("max_qi",1000);
	set("str", 26);
	set("cor", 30);

	set("combat_exp", 1000000);
	set("max_kee", 6000);
	
 	set_temp("apply/attack", 45);
	set_temp("apply/damage", 60);
	set_temp("armor", 53);
	setup();
}

void die()
{
	object ob;
	message_vision("$N�����³�һ��ҹ���飬��Ƥ����һ����$N���ˡ�\n", this_object());
	ob = new("/d/npc/m_weapon/tan/item/zhenzhu");
	ob->move(environment(this_object()));
	destruct(this_object());
}
