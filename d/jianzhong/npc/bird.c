//shendiao.c

inherit NPC;

void create()
{
	set_name("����", ({ "hai yan", "yan" }) );
	set("race", "����");
	set("age", 20);
	set("long", "һֻ�����ں���֮��ĺ��ࡣ\n");
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"�����ھ��κ��˼䰿���š���\n",
		"���༤��ظ質�š���\n",
	}));
        set("qi", 400);
	set("max_qi", 400);
	set("jing", 200);
	set("max_jing", 200);
	set("str", 20);
	set("cor", 20);
	set("combat_exp", 2000);
	setup();
}


