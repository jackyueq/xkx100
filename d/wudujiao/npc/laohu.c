// laohu1.c
inherit NPC;
#include <ansi.h>

string *first_name = ({"��", "ĸ"});
string *name_words = ({ "�ϻ�"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name,({"lao hu"}));

	set("race", "����");
        set("long", "һֻ�ߴ����͵Ĵ��ϻ���������̫�����´��\n");
        set("age", 5);
        set("attitude", "peaceful");

        set("max_jing", 1000);
        set("max_qi", 1000);
        set("str", 30);
        set("con", 50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 50);
        set("combat_exp", 300000);
        set_weight(50000);

        setup();
}
void init()
{
        object me,ob;
        if (interactive(me = this_player()))
        {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
        }
        ::init();
}


void die()
{
	object ob, corpse;
	message_vision("$N�������춯�ص�һ����Х����ص��ڵ��ϣ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/hugu");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
