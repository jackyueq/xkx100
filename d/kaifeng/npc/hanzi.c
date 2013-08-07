#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�˷���", ({ "cai fan", "cai", "fan" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "һ����ʵ�ͽ���ũ����Щ���ʵ��߲ˡ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("chat_chance", 10);
        set("chat_msg", ({
                CYN "�˷��ӽе��������ʵ��ܲ�ߺ��\n" NOR,
                CYN "�˷��ӽе��������ʵĺ��ܲ�ߺ��\n" NOR,
                CYN "�˷��ӽе��������ʵİײ�ߺ��\n" NOR,
                CYN "�˷��ӽе��������ʵĴ��ߺ��\n" NOR,
                CYN "�˷��ӽе��������ʵ�����ߺ��\n" NOR,
        }) );       

/*        set("vendor_goods", ({
                "/d/beijing/obj/luobo",
                "/d/beijing/obj/huluobo",
                "/d/beijing/obj/baicai",
                "/d/beijing/obj/dacong",
                "/d/beijing/obj/tudou",
        }) );
*/
        setup();
        carry_object("clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/caikuang")->wear();
        add_money("coin", 80);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
