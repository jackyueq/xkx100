// wugui.c

inherit NPC;

void create()
{
        set_name("�ڹ�", ({ "wu gui", "gui" }) );
	set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻ���ڹ꣬����������С�ˡ�\n");
        set("attitude", "peaceful");

	set("limbs",  ({  "ͷ��",  "צ��",  "β��"  })  );
	set("verbs",  ({  "bite"})  );
        set("str", 26);
        set("cor", 30);
        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N��ת�����ˣ�\n", this_object());
        ob = new("/clone/medicine/vegetable/guijia");
        ob->move(environment(this_object()));
        destruct(this_object());
}
