//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ϰ���", ({ "laoban niang", "woman", "boss" }));
	set("title", HIY"��ͨ�ǵ��������"NOR);
	set("nickname", HIW"����һ��"NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "Ů��");
	set("age", 25);
	set("long","һλ����Ů�ˣ���ʩ֬�ۣ�����һ�����ϣ���������̨��æ���ţ�һ�߻��к��ſ��ˡ�\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/jiangling/obj/dongdoufu",
		"/d/jiangling/obj/doupi",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	switch(random(2)) {
	case 0 :
		say("�ϰ���Ц���е�˵������λ" + RANK_D->query_respect(ob) + "����������ȱ��Ȳ�~��\n");
		break;
	case 1 :
		say("�ϰ���˵����Ӵ����λ" + RANK_D->query_respect(ob) + "����ô�£������иռ�õĶ�Ƥ��������Ć~��\n");
		break;
	}
}
