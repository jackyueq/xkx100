// wolf2.c
inherit NPC;
#include <ansi.h>

string *first_name = ({ "ͺβ��", "��β��"});
string *name_words = ({ "����", "��ĸ��"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name,({"wolf"}));

	set("race", "����");
        set("long", "һֻ����β�͵Ĵ���ǣ�����һ˫��թ�����۶����㡣\n");
        set("age", 3);
        set("attitude", "peaceful");

        set("max_jing", 700);
        set("max_qi", 700);

        set("str", 25);
        set("con", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 80);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 50);
        set("combat_exp", 200000);
        set_weight(500000);
        set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );

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

