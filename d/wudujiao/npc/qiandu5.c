// qiandu5.c
inherit NPC;
#include <ansi.h>;

void create()
{
        set_name("ç�����",({"chan chu"}));

        set("race", "Ұ��");
        set("long", "һֻȭͷ��С�����������Ķ���󡡣\n");
        set("age", 1000);
        set("attitude", "peaceful");

        set("max_jing", 500);
        set("max_qi", 500);

        set("str", 30);
        set("con", 50);

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set("combat_exp", 150000);
        set_weight(500000);

        setup();
}
void init()
{
        object me,ob;
        add_action("do_train", "xun");
        if (interactive(me = this_player()) && 
            (string)me->query("family/family_name") != "�嶾��")
        if (interactive(me = this_player()))
        {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
        }
        ::init();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "�嶾��") {
                ob->apply_condition("chanchu_poison", 20
              +(int)ob->query_condition("chanchu_poison") );
              tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
       }
}

#include "qiandu.h";
