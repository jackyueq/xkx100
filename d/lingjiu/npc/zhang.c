//zhang.c
inherit NPC;

void create()
{
	set_name("�", ({ "zhang" }) );
	set("race", "����");
	set("age", 2);
	set("long", "һͷ�ɰ���⯣�����Ѫ�Ǵ�֮�\n");
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
	message_vision("$N����һ�ţ�$N���ˡ�\n", this_object());
	destruct(this_object());
}
