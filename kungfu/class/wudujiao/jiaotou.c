// jiaotou.c
// ɳǧ��
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ɳǧ��", ({ "sha qianli", "sha" }));
	set("nickname", HIG "����" NOR);
	set("long",@LONG
�������嶾�̵Ļ�������ɳǧ���Ŀ��࣬���������ڽ���ת����ļ
���ڣ����ڵ����ǵ����Ź���
LONG
	);
	set("title","�嶾�̻�������");
	set("class", "shaman");
	set("gender", "����");
	set("age", 32);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 16);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 200000);
	set("score", 5000);

	set_skill("force", 70);
	set_skill("wudu-shengong", 80);
	set_skill("dodge", 70);
	set_skill("wudu-yanluobu", 100);
	set_skill("hand", 80);
	set_skill("qianzhu-wandushou", 120);
	set_skill("strike", 80);
	set_skill("wudu-zhang", 120);
	set_skill("parry", 80);
	set_skill("hook", 70);
	set_skill("wudu-goufa", 120);
	set_skill("sword", 70);
	set_skill("qingmang-sword", 100);
	set_skill("five-poison", 80);
	set_skill("literate", 60);
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "hand.qzwd" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�嶾��", 13, "��������");

	setup();

	carry_object("/d/wudujiao/npc/obj/ganggou")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();

	add_money("silver",30);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "����") {
		command("say ��λ������Ҫ����Ц�ˡ�");
		command("say ��λ" + RANK_D->query_respect(ob) +
			"���ǿ�ȥ�ź���ϰɣ�");
		return;
	}

	if ((int)ob->query("shen") > 1000) {
		command("say �����嶾�̵��ӱ����ĺ�������");
		command("say �ҽ̵��ӹ�����������������α����");
		return;
	}

//	command("chat �ٺٺٺ٣���������");
//	command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
//	command("chat �ٺٺٺ٣���������");
	command("recruit " + ob->query("id"));
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	ob->set("title",HIY"�嶾��ͽ"NOR);
 				  }
}