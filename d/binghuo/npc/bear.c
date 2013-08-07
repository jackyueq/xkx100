// bear.c

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(WHT"����"NOR, ({ "bai xiong", "bear","xiong" }) );
	set("race", "����");
        set("age", 20);
        set("long", "һֻ���͵İ��ܣ�����˶���������С�\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 250);
        set_temp("apply/armor", 100);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "���ܳ�����ҡͷ��β�أ���֪����ʲô��˼��\n",
                "���ܺǵ�һ��������Ҫ����������\n",
                "���ܼ��˼����ӣ��������������Ц����ʱһ����š�\n",
        }) );
}

void die()
{
	object ob, corpse;
	message_vision("$N���춯��һ���Һ�������ί���ڵأ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/nostrum/xiongdan");
	ob->move(corpse);
	corpse->move(environment(this_object()));
	destruct(this_object());
}