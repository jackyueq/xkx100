inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("Ƥ����", ({ "pihuo shang", "pihuo", "shang" }) );
        set("gender", "����" );
        set("age", 25);
        set("long",
                "����һλƤ���̣����Լ�Ҳ������Ƥ�á�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 30);

        set("vendor_goods", ({
                "/d/guanwai/npc/obj/piqiu",
        }));
        setup();
        carry_object("/d/guanwai/npc/obj/piqiu")->wear();
}

void init()
{       
        object ob; 

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        ::init();
}
