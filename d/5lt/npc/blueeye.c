// blueeye.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "blueeye" }));
	set("title", "��Ʒ���ϰ�");
	set("shen_type", 1);

	set("gender", "Ů��" );
	set("long", "��������Ц�Ǻǵؿ����㣬����������Ҫ�������˼������ɬŶ����\n");
	set("nickname", HIW"��ѩ�������ÿɰ�"NOR);
	set("age", 20);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");
	set("vendor_goods",({
		__DIR__"obj/bing",
		__DIR__"obj/bing2",
	}));        

	set("inquiry", ([
                 "yoyo": "���һֱ���ڵ���̨��������̨��������ͷ��������ߡ�\n",
	]));                 
	set("combat_exp", 100000);

	setup();

	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}