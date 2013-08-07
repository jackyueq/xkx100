// shangguan.c
// Last Modified by winder on Nov. 17 2001

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ϲٽ���", ({ "shangguan jiannan", "jiannan", "shangguan"}));
	set("long", "����������������ư���ϴ�����-�Ϲٽ��ϡ�\n");
	set("gender", "����");
	set("age", 70);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 35);
	set("int", 30);
	set("con", 28);
	set("dex", 35);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 200);
	set("combat_exp", 1000000);
	set("score", 400000);

	set_skill("force", 200);
	set_skill("guiyuan-tunafa", 200);
	set_skill("dodge", 200);
	set_skill("shuishangpiao", 300);
	set_skill("spear", 200);
	set_skill("tiexue-qiang", 300);
	set_skill("strike", 200);
	set_skill("zhusha-zhang", 300);
	set_skill("tiezhang-zhangfa", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("spear", "tiexue-qiang");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("unwield qiang") :),
		(: command("wield qiang") :),
		(: perform_action, "strike.zhangdao" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	create_family("���ư�", 13, "����");
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
	carry_object(WEAPON_DIR+"spear/yinqiang")->wield();
}

void attempt_apprentice(object me)
{
	if(me->query_skill("guiyuan-tunafa", 1) < 100)
		command("say ��Ĺ�Ԫ���ɷ�����̫���ˡ�\n");
	else
	{
		command( "say �ðɣ��Ҿ��������ˡ������ҵ��书��Ҫ��������Ϲ�ͷһ���������ɽ�����ˡ�");
		command("recruit " + me->query("id"));
	}
}
