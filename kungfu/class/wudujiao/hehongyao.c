// hehongyao.c
// �κ�ҩ
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("�κ�ҩ", ({ "he hongyao", "he" }));
	set("nickname", HIG "����ؤ��" NOR);
	set("long",@LONG
�������嶾�̵ĳ��ϣ������Ĺùúκ�ҩ����Ȼ�ǽ����ĳ�����������ȴ��һ���
�ϴ�����ѧ�ġ���˵����������Ϊ�����̳��ˣ����������´�����Ա������˴�
����ʥ�أ�����ǰ�������һ���ƾɵ������������̺ۣ����ù������˫Ŀ��
����Թ��֮ɫ��
LONG
	);
	set("title","�嶾�̳���");
	set("class", "beggar");
	set("gender", "Ů��");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 10);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("wudu-shengong", 200);
	set_skill("dodge", 190);
	set_skill("wudu-yanluobu", 250);
	set_skill("hand", 160);
	set_skill("qianzhu-wandushou", 220);
	set_skill("strike", 160);
	set_skill("wudu-zhang", 220);
	set_skill("parry", 180);
	set_skill("hook", 200);
	set_skill("wudu-goufa", 300);
	set_skill("sword", 200);
	set_skill("qingmang-sword", 300);
	set_skill("five-poison", 160);
	set_skill("literate", 80);

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


	create_family("�嶾��", 11, "����");
	setup();

	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/jiandao");
		if ( ob->violate_unique())
       destruct(ob);
    else
      {
      	ob->move(this_object());
        ob->wield();
      }
		}
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object("/clone/medicine/poison/wuxing");

	add_money("silver",30);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "����")
	{
		command("say ��λ������Ҫ����Ц�ˡ�");
		command("say ��λ" + RANK_D->query_respect(ob) +"���ǿ�ȥ�ź���ϰɣ�");
		return;
	}

	if ((int)ob->query("shen") > -10000)
	{
		command("say �����嶾�̵��ӱ����ĺ�������");
		command("say ��λ" + RANK_D->query_respect(ob) +"�Ĵ�������ϧ���ҽ�û��Ե�ְ���");
		return;
	}

	if ((string)ob->query("family/family_name") != "�嶾��")
	{
		command("say ��λ" + RANK_D->query_respect(ob) +"���Ǳ��̵��ӣ�������ذɣ�");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 100)
	{
		command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 100)
	{
		command("say ����嶾�񹦻�ѧ�Ĳ�������");
		return;
	}

	command("chat �ٺٺٺ٣���������");
	command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
	command("chat �ٺٺٺ٣���������");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"�嶾�̻���"NOR);
	return;
}

