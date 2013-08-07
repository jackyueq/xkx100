// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("һ�ƴ�ʦ", ({"yideng dashi", "dashi", "yideng"}));
	set("nickname", HIG "����һ��" NOR );
	set("gender", "����");
	set("age", 52);
	set("long", 
		"�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
		"�����ֲ�ɮ�ۣ����������İ�ü���۽Ǵ�����������Ŀ���飬\n"
		"���봹�磬ü����������࣬��һ��Ӻ�ݸ߻�����ɫ��ȴ��һ\n"
		"����֪����ʦһ�����ƣ��������\n");
	set("attitude", "peaceful");
	set("class", "bonze");
	
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 3000);
	set("max_jing", 3000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 100);
	
	set("combat_exp", 3000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 200);
	set_skill("strike", 200);
	set_skill("cuff", 200);
	set_skill("whip", 200);
	set_skill("sword", 200);
	set_skill("axe", 200);
	set_skill("tiannan-step", 300);
	set_skill("kurong-changong", 200);
	set_skill("duanjia-sword", 300);
	set_skill("duanyun-fu", 300);
	set_skill("wuluo-zhang", 300);
	set_skill("jinyu-quan", 300);
	set_skill("feifeng-whip", 300);
	set_skill("six-finger", 300);
	set_skill("sun-finger", 300);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("axe", "duanyun-fu");
	map_skill("whip", "feifeng-whip");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	prepare_skill("finger","six-finger");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.yuqi" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("����μ�", 17, "����");
	setup();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("kurong-changong",1) < 150 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	command("say �����ӷ��Ҿ����������ͽ�ܰɡ�");
	command("recruit " + ob->query("id"));
}
