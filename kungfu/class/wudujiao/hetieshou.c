// hetieshou.c ������
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
int ask_me();
int ask_box();
string ask_ling();

void create()
{
	object ob;
	set_name("������", ({ "he tieshou", "he" }));
	set("nickname", HIG "�嶾����" NOR);
	set("long",@LONG
��������һ��һ��ۺ�ɴȹ��Ц���绨����Ů�������ü���ѩ�ף�üĿ�续��
����һ˫���۵����㣬�ֽ��϶����������Ľ���˭���뵽�������嶾�̵Ľ�
�������֣�������ʿ�������޲������ľ���
LONG
	);
	set("title","�嶾�̽���");
	set("gender", "Ů��");
	set("class", "shaman");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 36);
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("box_count",1);
	set("ling_count",1);
	set("tieshao_count",1);

	set_skill("force", 200);
	set_skill("wudu-shengong", 200);
	set_skill("dodge", 200);
	set_skill("wudu-yanluobu", 300);
	set_skill("hand", 170);
	set_skill("qianzhu-wandushou", 250);
	set_skill("strike", 170);
	set_skill("wudu-zhang", 250);
	set_skill("parry", 190);
	set_skill("whip", 200);
	set_skill("wudu-whip", 300);
	set_skill("hook", 200);
	set_skill("wudu-goufa", 300);
	set_skill("sword", 200);
	set_skill("qingmang-sword", 300);
	set_skill("five-poison", 200);
	set_skill("literate", 100);
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("whip", "wudu-whip");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");

	set("no_get",1);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "unarmed.qzwd" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("�嶾��", 11, "����");

	setup();
	set("inquiry", ([
		"�򶾿�"    : (: ask_me :),
		"����"      : (: ask_me :),
		"��ɳ��Ӱ"  : (: ask_box :),
		"�嶾��"    : (: ask_ling :),
	]) );
  if (clonep())
  {
  	ob=new(WEAPON_DIR"treasure/jinfenggou");
  	if ( ob->violate_unique() )
  	 {
  	 	 destruct(ob);
  	 	 ob=new("/clone/weapon/hook");
  	 	}
  	 	ob->move(this_object());
  	 	ob->wield();
  }
	carry_object("/clone/armor/treasure/skirt")->wear();

	add_money("silver",50);
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

int ask_me()
{
	object ob;
	if ((string)this_player()->query("family/master_id")!="he tieshou")
	{
		command("say �򶾿��˱���ʥ�أ������̳���֮����˲��ý��롣");
		return 1;
	}
	if(query("tieshao_count")< 1 )
	{
		command("say �������ˣ��������Ѿ��������ˡ�");
		return 1;
	}
	command("say �򶾿��������쳣��ǧ��ҪС�İ���\n");
	command("say ��ֻ�������ҵ���������ƾ�����ɽ��붴�У�");
	ob = new("/d/wudujiao/npc/obj/tieshao");
	ob->move(this_player());
	add("tieshao_count",-1);
	remove_call_out ("give_tieshao");
	call_out ("give_tieshao", 900); // 15 ����
	return 1;
}
int ask_box()
{
	object ob;
	if ((string)this_player()->query("family/master_id")!="he tieshou")
	{
		command("say ���˱����ر������ײ�����˵ġ�");
		return 1;
	}
	if(query("box_count")< 1 )
	{
		command("say �������ˣ���ɳ��Ӱ���Ѿ��͸������ˡ�");
		return 1;
	}
	command("smile");
	command("say ��ô����Ҫ���˴���𣿿ɱ��������嶾�����簡��");
	command("say ��ɳ��Ӱ����ȥ�ɣ������ǳ��������嶾�̵�������");
	ob = new("/d/wudujiao/npc/obj/hanshasheying");
	ob->move(this_player());
	add("box_count",-1);
	ob->set("own_name",this_player()->query("id"));
	remove_call_out ("give_hssy");
	call_out ("give_hssy", 900); // 15 ����
	return 1;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "����")
	{
		command("say ��λ������Ҫ����Ц�ˡ�");
		command("say ��λ" + RANK_D->query_respect(ob)+"���ǿ�ȥ�ź���ϰɣ�");
		return;
	}

	if ((int)ob->query("shen") > 1000)
	{
		command("say �����嶾�̵��ӱ����ĺ�������");
		command("say ��λ" + RANK_D->query_respect(ob) + "�Ĵ�������ϧ���ҽ�û��Ե�ְ���");
		return;
	}

	if ((string)ob->query("family/family_name") != "�嶾��")
	{
		command("say ��λ" + RANK_D->query_respect(ob) + "���Ǳ��̵��ӣ�������ذɣ�");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 120)
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

//	command("chat �ٺٺٺ٣���������");
	command("chat �ðɣ���Ȼ��˱���������������ͽ�ܡ�");
	command("chat ����һ�죬Ҫ�������˶�֪�������嶾�̵�����������");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"�嶾�̳���"NOR);
	return;
}
void give_hssy()
{
	set("box_count",1);
}
void give_tieshao()
{
	set("tieshao_count",1);
}
void give_wuduling()
{
	set("ling_count",1);
}
string ask_ling()
{
	mapping fam;
	object *allob,env,ob,me=this_player();
	string *sname;
	int i, count, here = 0;

	if (query("ling_count") < 1)
		return "�������ˣ��嶾���Ľ����������ء�\n";
	if (!(fam = me->query("family")) || fam["family_name"] != "�嶾��")
		return RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��";

	if (me->query("duchong_cun") == 1)
		return "��Ķ��治���ڶ����Ǻúõ�ô��";

	env = environment(me);
	allob = all_inventory(env);
	count = 0;
	for(i=0; i<sizeof(allob); i++)
		if(allob[i] != me && allob[i]!=this_object() )
		{
			if(allob[i]->query("host_id") == me->query("id"))
			{
				here = 1;
			}
			count++;
		}
	if (here == 1)
		return "��Ķ��治�Ǵ���������𣡣�";
	if (me->query("duchong_cun") == 0 && count >= 1)
		return "�����˶����ӣ����ͷ�����ɣ�";

	if (!me->query("du/id"))
		return "��û������ɣ�";

	add("ling_count",-1);
	ob = new(__DIR__"obj/wudu-ling");
	ob->move(me);
	message_vision("$N���һ���嶾�\n",me);
	remove_call_out ("give_wuduling");
	call_out ("give_wuduling", 600); // 10 ����

	return "�ðɣ�ƾ�����嶾����ȥҪ����Ķ��档";

}

