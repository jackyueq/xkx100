#include <ansi.h>

inherit NPC;

void do_chat();

void create()
{
        set_name("�Ի�", ({"zhao hu", "zhao", "hu"}));
        set("title", HIY "���⸮��ͷ" NOR);
        set("gender", "����");
        set("age", 43);
        set("long", @LONG
����ǿ��⸮���������Ĳ�ͷ�Ի���������ǿ
׳������ȥ�书����
LONG );
        set("combat_exp", 600000);
        set("attitude", "heroism");
        set("max_neili", 3000);
        set("neili", 3000);
        set("max_jing", 1000);
        set("jing", 1000);
        set("max_qi", 2000);
        set("qi", 2000);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set_skill("unarmed", 160);
        set_skill("sword", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("zixia-shengong", 160);
        set_skill("huashan-sword", 160);
        set_skill("huashan-ken", 160);
        set_skill("feiyan-huixiang", 160);
        map_skill("dodge", "feiyan-huixiang");
        map_skill("force", "zixia-shengong");
        map_skill("sword", "huashan-sword");
        map_skill("unarmed", "huashan-ken");
        map_skill("parry", "huashan-sword");

        setup();
        set_max_encumbrance(100000000);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 100);

        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"tiejia")->wear();
}

int do_halt()
{
        object me;

        if (this_player() == query_temp("catch_ob"))
        {
                write(CYN + name() + "�ȵ��������ӣ������ܣ���\n" NOR);
                return 1;
        }

        return 0;
}

int accept_fight(object ob)
{
        message_vision(CYN "$Nҡҡͷ����$n" CYN "�������ҿ�û��Ȥ����\n" NOR,
                       this_object(), ob);
        return 0;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

void init()
{
        object ob;

        add_action("do_halt", "halt");
        ob = this_player();

        if (is_busy() ||
            is_fighting() ||
            ! living(this_object()) ||
            environment()->query("no_fight"))
                return;

        if (ob == query_temp("catch_ob") ||
            ! query_temp("catch_ob") &&
            ob->query_condition("killer"))
        {
                remove_call_out("catch_killer");
                call_out("catch_killer", 1, ob);
        }
}

void catch_ob(object ob)
{
        remove_enemy(ob);
        message_vision(HIY "$N��������$n" HIY "ͷ��һ�ף�Ȼ������$n"
                       HIY "����Ц�����������߰ɣ���\n" NOR,
                       this_object(), ob);
        ob->move(this_object());
        if (is_fighting())
        {
                // Am I in fighting now ?
                message_vision(CYN "$N�������������Ҫ�Ȼ�ȥ��"
                               "���ˣ���������ʰ���Ǽ�������\n" NOR,
                               this_object());
        }

        if (base_name(environment()) != "/d/changan/baihu1")
        {
                set_temp("old_position", base_name(environment()));
                message_vision(HIR "$N��������һ��������$n" HIR
                               "ת����ȥ��\n" NOR, this_object(), ob);
                move("/d/changan/baihu1");
                remove_call_out("return_back");
                call_out("return_back", 1);
        }

        message_vision(HIW "$N����$n" HIW "���˹�������������ӭ����"
                       "������$n" HIW "Ѻ������ȥ�ˡ�\n" NOR, this_object(), ob);
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" +
                            ob->name(1) + HIM "�����⸮�ܲ�ͷ" + name() +
                            "���ù鰸��Ѻ����Ρ�");
        ob->get_into_prison(0, "/d/changan/prison", 30);
        ob->clear_condition("killer");
        ob->remove_killer(this_object());
        remove_killer(ob);
        delete_temp("catch_ob");
        return;
}

void catch_killer(object ob)
{
        if (! ob || environment(ob) != environment() ||
            ! living(this_object()))
                return;

        if (! living(ob))
        {
                catch_ob(ob);
                return;
        }

        if (is_killing(ob->query("id")))
                return;

        if (ob->name() != ob->name(1) &&
            random((int)ob->query_skill("pretending")) > 50)
                return;

        message_vision(HIY "$N����$n" HIY "����һ�����ͻȻ�ȵ������㲻"
                       "�������ӵ�" + ob->name(1) + HIY "�𣿽���ײ����"
                       "�������Ҫ�������ˣ���\n" NOR, this_object(), ob);
        set_temp("catch_ob", ob);
        kill_ob(ob);                       
}

void return_back()
{
        if (! living(this_object()))
                return;

        if (! stringp(query_temp("old_position")))
                return;

        message_vision(CYN "$N���˸���Ƿ���������˼������߿��ˡ�\n" NOR,
                       this_object());
        move(query_temp("old_position"));
        message_vision(CYN "$N����������˹�����\n" NOR, this_object());
        delete_temp("old_position");
}

int attack()
{
        object ob;

        if (objectp(ob = query_temp("catch_ob")) &&
            ! living(ob) &&
            environment(ob) == environment())
        {
                catch_ob(ob);
                return 1;
        } else
                return ::attack();
}

void scan()
{
        object ob;

//        ::scan();

        if (! objectp(ob = query_temp("catch_ob")))
        {
                if (time() - query_temp("born_time") > 900 &&
                    ! is_fighting() && living(this_object()))
                {
                        message_vision(CYN "$N������Σ��㬵����ˡ�\n" NOR,
                                       this_object());
                        destruct(this_object());
                }
                return;
        }
        
        if (environment(ob) != environment() ||
            environment(ob)->query("no_fight"))
        {
                message_vision(CYN "$N�㬵������ߣ����д�����\n" NOR,
                               this_object());
                delete_temp("catch_ob");
                return;
        }

        if (! living(ob))
        {
                catch_ob(ob);
                return;
        }

        if (! is_fighting(ob))
                fight_ob(ob);
}
