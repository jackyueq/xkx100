
inherit __DIR__"changer.c";

void  create()
{
	set_name("�ϴ���", ({ "old woman" }));
	set("gender", "Ů��");
	set("long","һ��������˪֮ɫ�������š�\n");
	set("age", 50);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/egg",
        	__DIR__"obj/doufu",
        }));	
        set("want_goods", ({
        	__DIR__"obj/liyu",
        	__DIR__"obj/baicai",
        }));	
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

