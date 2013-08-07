// cenqisi.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���˹", ({ "cen qisi", "cen" }));
	set("nickname", HIG "�嶾��ʿ" NOR);
	set("long",@LONG
�������嶾�̵��һ������˳��嶾��ʿ�����˹������װ���һ��
������ʿ��ģ����û���ܰ���ӹ���š�
LONG
	);
	set("title","�嶾�̻���");
	set("gender", "����");
	set("class", "shaman");
	set("age", 38);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", 120);
	set_skill("wudu-shengong", 120);
	set_skill("dodge", 130);
	set_skill("wudu-yanluobu", 180);
	set_skill("hand", 120);
	set_skill("qianzhu-wandushou", 180);
	set_skill("strike", 120);
	set_skill("wudu-zhang", 180);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("qingmang-sword", 180);
	set_skill("hook", 130);
	set_skill("wudu-goufa", 180);
	set_skill("five-poison", 120);
	set_skill("literate", 100);

	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("hook", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
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

	create_family("�嶾��", 12, "����");

	setup();
	carry_object("/d/wudujiao/npc/obj/ganggou")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();

	add_money("silver",20);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "����")
	{
		command("say ��λ������Ҫ����Ц�ˡ�");
		command("say ��λ"+RANK_D->query_respect(ob)+"���ǿ�ȥ�ź���ϰɣ�\n");
		return;
	}

	if ((int)ob->query("shen") > -5000)
	{
		command("say �����嶾�̵��ӱ����ĺ�������");
		command("say ��λ"+RANK_D->query_respect(ob)+"�Ĵ�������ϧ���ҽ�û��Ե�ְ���\n");
		return;
	}

	if ((string)ob->query("family/family_name") != "�嶾��")
	{
		command("say ��λ" + RANK_D->query_respect(ob) + "���Ǳ��̵��ӣ�������ذɣ�\n");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 60)
	{
		command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
		command("say ��λ" + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��\n");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 60)
	{
		command("say ����嶾�񹦻�ѧ�Ĳ�������");
		return;
	}

//	command("chat �ٺٺٺ٣���������");
//	command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
//	command("chat �ٺٺٺ٣���������");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"�嶾�̵���"NOR);
	return;
}

