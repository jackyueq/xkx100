#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void consider();
string ask_me();
string ask_yao();
string ask_gua();

void create()
{
	object ob;
	set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
	set("title", "�һ�����");
	set("nickname", HIY "��а" NOR );
	set("gender", "����");
	set("age", 42);
	set("long", 
		"�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
	set("attitude", "peaceful");
	set("class", "scholar");
	
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
		"��ҩʦ��ͷ��˼����Ȼ���\n",
	}));
	set("inquiry", ([
		"����"         : "���ֱ����Ů���Ĺ����� \n",
		"�����澭"     : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
		"�Ż���¶��"   : "�������Ʋ��ף��˷�������ܻ��аɡ�\n",
		"�޳���"       : (: ask_yao :),
		"������"       : (: ask_gua :),
		"�ؼ�"         : (: ask_me :),
		"����ɨҶ�ȷ�" : (: ask_me :),
	]));

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 3000);
	set("max_jing", 3000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 100);

	set("book_count", 1);
	set("yao_count", 1);
	set("gua_count", 1);
	set("combat_exp", 3000000);
	set("score", 0);
	 
	set_skill("force", 200);		// �����ڹ�
	set_skill("bibo-shengong", 200);	// �̲���
	set_skill("claw", 200);			// ����צ��
	set_skill("hand", 200);			// �����ַ�
	set_skill("finger", 200);		// ����ָ��
	set_skill("tanzhi-shentong", 300);	// ��ָ��ͨ
	set_skill("unarmed", 200);		// ����ȭ��
	set_skill("strike", 200);		// ����ȭ��
	set_skill("luoying-zhang", 300);	// ��Ӣ����
	set_skill("xuanfeng-leg", 300);		// ����ɨҶ��
	set_skill("dodge", 200);		// ��������
	set_skill("anying-fuxiang", 300);	// ��Ӱ����
	set_skill("parry", 200);		// �����м�
	set_skill("sword", 200);		// ��������
	set_skill("luoying-shenjian", 300);	// ��Ӣ��
	set_skill("yuxiao-jian", 300);		// ���｣��
	set_skill("lanhua-shou", 300);		// ������Ѩ��
	set_skill("qimen-wuxing",150);		// ��������
	set_skill("array", 120);		// ������
	set_skill("count",150);			// ��������
	set_skill("literate",150);		// ����ʶ��
	
	map_skill("force"  , "bibo-shengong");
	map_skill("finger" , "tanzhi-shentong");
	map_skill("hand"   , "lanhua-shou");
	map_skill("strike", "luoying-zhang");
	map_skill("unarmed" , "xuanfeng-leg");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "luoying-shenjian");
	map_skill("sword"  , "yuxiao-jian");
	prepare_skill("hand", "lanhua-shou");
	prepare_skill("finger", "tanzhi-shentong");
	
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.tianwai" :),
		(: perform_action, "finger.jinglei" :),
		(: perform_action, "hand.fuxue" :),
		(: exert_function, "roar" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("�һ���", 1, "����");
	setup();
	
	carry_object(__DIR__"obj/yuxiao")->wield();
	carry_object(__DIR__"obj/bupao")->wear();
//	carry_object("clone/book/jiuyin2");
  if (clonep())
  {
		ob = new("/clone/book/jiuyin2");
		if (ob->violate_unique())	destruct(ob);
		else ob->move(this_object());
	}
}

void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if (ob->query("class") == "eunach" ||
		ob->query("class") == "bonze" ||
		ob->query("class") == "lama")
	{
		command("say ��ƽ����������ǲ�������ϣ��Źֵ����ˣ�");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�");
		return;
	}
	if ((int)ob->query_skill("bibo-shengong",1) < 50 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°�!");
		return;
	}
	if ((int)ob->query("shen") >100000 ||
		(int)ob->query ("shen") < -100000 )
	{
		command("say ���һ��������������������������ֳ�������򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] == "�һ���") return 1 ;
	if ((int)ob->query_temp("tmark/��") == 1 )
		message_vision("��ҩʦ���˿�$N��˵��������������˭Ҳ��Ƿ˭��\n�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
	if (!(int)ob->query_temp("tmark/��")) return 0; 
	ob->add_temp("tmark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" )
	{
 		if (!(int)who->query_temp("tmark/��"))
			who->set_temp("tmark/��", 0);
		message_vision("��ҩʦ���˿�$N�������ؼ������˵�ͷ��˵����\n�ѵ��㽫�澭�ͻء����͵Ķ����Ҿ������ˡ�\n��Ϊ����,����Դ�������ѧ�㹦��\n",who);
		who->add_temp("tmark/��", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob, me = this_player();
	
	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("book_count") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(me);
	command("rumor "+me->query("name")+"�õ�����ɨҶ�ȷ�����\n");
	return "�ðɣ��Ȿ������ɨҶ�ȷ������û�ȥ�ú����С�";
}
string ask_yao()
{
	object ob, me = this_player();

	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("yao_count") < 1 || random(3) > 0)
		return "�������ˣ��޳������ɸ����ˡ�";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/wuchangdan");
	ob->move(me);
	return "�ðɣ������޳������ȸ���ɡ�";
}
string ask_gua()
{
	object ob, me = this_player();
	
	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("gua_count") < 1 || random(3) > 0)
		return "�������ˣ������Ը��ɸ����ˡ�";
	if (me->query_skill("count", 1) < 30 ||
		me->query_skill("bibo-shengong", 1) < 30)
		return "������������Ҳûʲô�ã��������������ˡ�";
	add("gua_count", -1);
	ob = new(__DIR__"obj/bagua");
	ob->move(me);
	return "�ðɣ���ö�����Ծ��ȸ���ɡ�";
}
