// xiaolu.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("½��Ӣ", ({ "lu guanying", "lu" }));
	set("long", "
���ǹ���ׯ��ׯ��½��Ӣ�������������������׳����
���ж�֮�����Ķ��ţ�ǫ������һ�������ӵܷ緶��
����������̫��Ⱥ�������죬��֪�����Ǽ١�\n");
	set("gender", "����");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 26);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 150000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("bibo-shengong", 50);
	set_skill("dodge", 50);
	set_skill("anying-fuxiang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("yuxiao-jian", 50);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("sword", "yuxiao-jian");
	map_skill("parry", "yuxiao-jian");

	set("inquiry", ([
		"����ׯ" : (: ask_me :),
	]));

	set("book_count", 1);
        create_family("�һ���", 3, "���� ����ׯ��ׯ��");
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

init()
{
	add_action("do_decide", "decide");
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say �����书���������ɽݡ�");
           command("say ��λ"+RANK_D->query_respect(ob)+"�����ǰ�������ׯһ���ˡ�");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say �����ڽ���������������"+ RANK_D->query_respect(ob)+"��ذɡ�");
           return;
        }
        if (ob->query("gender") == "����")
        {
           command("say ʦ�������᲻�в�Ů�Ķ����ˣ���λ"+RANK_D->query_respect(ob)+"�Ͽ���ɡ�");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say ʦ�����ɮ�ֵ��ˣ���λ"+RANK_D->query_respect(ob)+"������ذɡ�");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say �һ���ֻ�ն����������ӣ���λ"+RANK_D->query_respect(ob)+"�Ƿ�ȥ������������");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "�������£���Ŭ�����顣");
        command("recruit " + ob->query("id"));
}


string ask_me()
{
	object me = this_player();
	me->set_temp("guiyun/decide",1);

        if((string)me->query("family/family_name") != "�һ���")
	   return "����ׯ�������¾Ӵ������"+RANK_D->query_respect(me)+"����(decide)���ҿ�����һ���Ϊ������\n";
        command("say ��λ"+ RANK_D->query_respect(me)
	       + "�������ã�����������Ҫ��ׯ���£�������������һ�̰ɡ�\n");
//      message_vision(HIC"½��Ӣһ���֣�һ����ʻ����ͣ����ǰ��\n$N��æ������У�ֻ��һ�����ı��죬��������ȥ��\n\n"NOR,me);
//	ob = load_object("/d/guiyun/dayuan");
//	ob = find_object("/d/guiyun/dayuan");
//	message("vision", "Զ��һ������ʻ����������һ��"+me->query("name")+"���������˳�����\n", ob);
//    	tell_object(me, "ֻ��������˵������λ"+ RANK_D->query_respect(me) + "�Ѿ����ˣ����³��ɡ�\n"NOR );
	me->move("/d/guiyun/dayuan");           
}

int do_decide()
{
	object ob, me;
	me = this_player();
	if (!me->query_temp("guiyun/decide"))
	{
		message_vision("$N��$n��ֵ�˵������Ҫ�������\n", this_object(), me);
		return 1;
	}
	me->delete_temp("guiyun/decide");
	ob = new(__DIR__"obj/xin");
	ob->move(me);
	message_vision("$N˫�ֱ�ȭ������������ׯ�������ˡ�\n", me);
	message_vision("$N˵�����ã�\n", this_object());
	message_vision("$N��$nһ�����š�\n", this_object(), me);
	message_vision("$N˵������λ"+RANK_D->query_respect(me) + "���ȵ���ׯ�̺����գ��Ժ���ͼ����\n", this_object());
	return 1;
}
