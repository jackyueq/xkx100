// chen.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���е�", ({ "chen youde", "chen" }));
        set("long", "���е���������ݹݳ���\n");
        set("gender", "����");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("hand", 80);
        set_skill("strike", 80);
        set_skill("finger", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_skill("changquan", 40);
        set_skill("sanshou", 40);
        map_skill("cuff", "changquan");
        map_skill("hand", "sanshou");
        prepare_skill("cuff", "changquan");
        prepare_skill("hand", "sanshou");

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}
int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 3500)
    {
        message_vision("���е�����$N˵������书Ӧ���������������ٳ�����������û
�������ˡ�\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/yangzhou_paied",1);
        message_vision("���е¶�$N˵���ã���λ" + RANK_D->query_respect(who) 
+ "��ѧʲô�أ�\n" , who);
        return 1;
    }
    else
        message_vision("���е���ü��$N˵��Ǯ�Ҳ��ں�������Ҳ����Ҳ̫���˵���ɣ�\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}


