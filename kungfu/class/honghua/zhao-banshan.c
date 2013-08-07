// Last Modified by winder on Sep. 12 2001
// zhaobanshan.c �԰�ɽ

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("�԰�ɽ", ({ "zhao banshan", "zhao", "banshan" }));
	set("nickname", HIM"ǧ������"NOR);
	set("title", HIR"�컨��"HIG"������"NOR);
	set("long","���Ǻ컨��������ң�\n����ͺ�������ʮ���£���һ�����ֵ�����Ц��������һ���ܴ���ĸо���\n��ԭ����������̫�������Ŵ���ӡ�\n����������������һ�ְ��������̫����������ƥ�С�\n�����������ɢ֮��Ͷ��컨�ᡣ�ܵñ��컨���ϵ�������ͤ��ʶ��\n");
	set("gender", "����");
	set("class", "swordman");
	set("age", 52);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2000);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 100000);

	set_skill("force", 150);
	set_skill("honghua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("youlong-shenfa", 200);
	set_skill("throwing", 180);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("cuff", 150);
	set_skill("zhuihun-jian", 220);
	set_skill("wuying-feidao", 220);
        set_skill("hanxing-bada",220);
	set_skill("baihua-cuoquan", 220);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	map_skill("throwing", "wuying-feidao");
	prepare_skill("cuff", "baihua-cuoquan");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "cuff.cuo" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("�컨��", 2, "����");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
        carry_object("/clone/weapon/jili")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="zhao banshan")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000)
	{
		command("say �Һ컨����ͽ���ϡ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "ƽʱ��Ҫ����һЩ��������֮�£�");
		return;
	}
	command("say �ã�����������˻��������������ˣ�");
	command("recruit " + ob->query("id"));
}


