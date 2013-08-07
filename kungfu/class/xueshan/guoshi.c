// /kungfu/class/xueshan/guoshi.c  ���Ʋֹ�ʦ

#include <ansi.h>;
#include "xueshan.h";

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
	set_name("���Ʋֹ�ʦ", ({ "gongtangcang guoshi", "guoshi" }));
	set("long",@LONG
���Ʋֹ�ʦ��ѩɽ���е�λ�ϸߵ����
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
	);
	set("title", HIY "������" NOR);
	set("nickname", HIG "��ʦ" NOR);
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 24);
	set("int", 28);
	set("con", 26);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("lamaism", 60);
	set_skill("literate", 50);
	set_skill("force", 100);
	set_skill("xiaowuxiang", 100);
	set_skill("dodge", 100);
	set_skill("shenkong-xing", 150);
	set_skill("parry", 70);
	set_skill("staff", 80);
	set_skill("xiangmo-chu", 120 );
	set_skill("sword",50);
	set_skill("mingwang-jian",70);
	set_skill("unarmed", 90);
	set_skill("yujiamu-quan", 120);


	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "xiangmo-chu");
	map_skill("staff", "xiangmo-chu");
	map_skill("sword", "mingwang-jian");
	set("env/wimpy", 60);
	create_family("ѩɽ��", 4, "������");
	set("class", "lama");

	set("inquiry",([
		"���"  : (: ask_for_join :),
		"����"  : (: ask_for_join :),
	]));

	setup();

	carry_object("/d/shaolin/obj/chanzhang")->wield();
	carry_object("/d/xueshan/obj/c-jiasha")->wear();
	carry_object("/d/xueshan/obj/sengmao")->wear();

	add_money("silver",100);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") != "����") {
		command("say ��ϰ�����ڹ���Ҫ����֮�塣");
		command("say ��λ" + RANK_D->query_respect(ob) +
			"������ذɣ�");
		return;
	}

	if ((string)ob->query("class") != "lama") {
		command("say �����ػƽ����ڵ����������ࡣ");
		ob->set_temp("pending/join_bonze", 1);
		command("say ʩ������������ҷ������(kneel)�ܽ䡣\n");
		return;
	}

	if ((string)ob->query("family/family_name") != "ѩɽ��")	{
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�ȷǱ��µ��ӣ�������ذɣ�");
		return;
	}

	if ((int)ob->query_skill("lamaism", 1) < 40) {
		command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
		return;
	}

	command("say �ã��ʹ���һЩ�书�ɣ�");
	command("recruit " + ob->query("id"));

}

void init()
{
	add_action("do_kneel", "kneel");
	add_action("do_say", "say");
}

int do_say(string arg)
{

	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="���ֳ�ת" )	
	{
		me->move("/d/xueshan/guangchang");
		return 1;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	ob->set("title",HIY "����" NOR);
 				  }
}
