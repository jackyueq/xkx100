// /kungfu/class/xueshan/jiumozhi.c �Ħ��
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
        set_name("�Ħ��", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "��������" NOR);
        set("long",@LONG
������ѩɽ�µ����ţ��˳ƴ����������Ħ�ǡ����Է��о�����о���
��һ��������ģ�ͷ��ɮñ��
LONG
        );
        set("title","ѩɽ������");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 1000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 3000000);
        set("score", 500000);

        set_skill("necromancy", 150);
        set_skill("force", 200);
        set_skill("xiaowuxiang", 200);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 150);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 200);
        set_skill("lamaism", 200);
        set_skill("literate", 100);
        set_skill("staff", 200);
        set_skill("xiangmo-chu", 200 );
        set_skill("strike", 200 );
        set_skill("huoyan-dao", 200);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        prepare_skill("strike","huoyan-dao");

        set("no_get",1);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
        }) );
        create_family("ѩɽ��", 1, "����");
        set("class", "lama");

        setup();

        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",50);
}
void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "ѩɽ��")&&(!me->query_skill("longxiang",1))&&(!me->query_skill("xiaowuxiang",1))&&(me->query("combat_exp")>500000))
        {
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + me->query("id"));
        }
        
}
void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") != "����")
	{
		command("say ��ϰ�����ڹ���Ҫ����֮�塣");
		command("say ��λ" +RANK_D->query_respect(ob)+ "������ذɣ�");
                return;
        }

	if ((string)ob->query("class") != "lama")
	{
                command("say �����ػƽ����ڵ����������ࡣ");
		command("say ��λ" +RANK_D->query_respect(ob)+ "������ذɣ�");
                return;
	}

	if ((string)ob->query("family/family_name") != "ѩɽ��")
	{
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�ȷǱ��µ��ӣ�������ذɣ�");
		return;
	}

	if ((int)ob->query_skill("lamaism", 1) < 100) {
		command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
		return;
	}

	command("chat ������������������");
	command("chat ��ѩɽ�����Ǻ�����ˣ����ǿ�ϲ�ɺء�");
	command("chat ������������������");
	command("recruit " + ob->query("id"));

	ob->set("title",HIY"����"NOR);
}
