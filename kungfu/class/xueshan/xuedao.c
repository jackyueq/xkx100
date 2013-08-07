// /kungfu/class/xueshan/xuedao.c  Ѫ������
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	object ob;

	set_name("Ѫ������", ({ "xuedao laozu", "xue dao", "laozu" }));
	set("long",@LONG
���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š�
LONG
	);
	set("title",HIR"Ѫ���ŵ��Ĵ�����"NOR);
	set("gender", "����");
	set("age", 85);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 3000000);
	set("score", 180000);

	set_skill("lamaism", 150);
	set_skill("literate", 80);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("dodge", 200);
	set_skill("longxiang", 200);
	set_skill("shenkong-xing", 300);
	set_skill("hand", 200);
	set_skill("dashou-yin", 300);
	set_skill("mingwang-jian", 300);
	set_skill("xue-dao", 300);

	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");
	map_skill("sword", "mingwang-jian");
	prepare_skill("hand", "dashou-yin");
	set("chat_chance_combat", 80);  
	set("chat_msg_combat", ({
		(: perform_action, "blade.shendao" :),
		(: exert_function, "shield" :),
		(: command("unwield flood blade") :),
		(: command("wield flood blade") :),
	}) );

	create_family("ѩɽ��", 4, "����");
	set("class", "lama");

	setup();
	 if (clonep())
	 {
	 	 ob=new(WEAPON_DIR"treasure/xblade");
	 	 if ( ob->violate_unique())
	 	  {
	 	  	destruct(ob);
	 	  	ob=new("/clone/weapon/blade");
 	  	}
 	  	ob->move(this_object());
 	  	ob->wield();
	 	}
  carry_object("/d/xueshan/obj/y-jiasha")->wear();
	add_money("gold",2);
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "����")
	{
		command("say �Ҳ���Ůͽ�ܡ�\n");
		return;
	}
	if ((string)ob->query("family/family_name") != "ѩɽ��")
	{
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�ȷǱ��ŵ��ӣ�������ذɣ�\n");
		return;
	}
	if ((int)ob->query("shen") > -100000)
	{
		command("say ���ǲ����������������ɱ�˶����ᣡ\n");
		return;
	}
	if ((int)ob->query_skill("longxiang", 1) < 60)
	{
		command("say ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�\n");
		return;
	}
	command("haha");
	command("nod");
	command("recruit " + ob->query("id"));

	ob->set("title", HIR "Ѫ���ŵ��������" NOR);
}
