//lu.c
inherit NPC;

void create()
{
	set_name("÷��¹", ({ "meihua lu", "lu" }) );
	set("race", "����");
	set("age", 2);
	set("long", "һֻ�ɰ���÷��¹������Ѫ�Ǵ�֮�\n");
	set("attitude", "peaceful");
 
	set("str", 30);
	set("con", 26);
	set("combat_exp", 3000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N��������İ������������ڵ��ϣ���ȥ�ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/lurong");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
