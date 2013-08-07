// wg_chen.c

inherit NPC;
string do_getling();
void create()
{
	set_name("���е�", ({ "chen youde", "chen" }));
	set("title", "������ݹ���");
	set("gender", "����");
	set("nickname", "��������");	
	set("age", 50);
	set("str", 30);
	set("dex", 26);
	set("long", "�����Ͻ����ӣ�������ϣ�����������վ�����������һ��������\n�����������Ϊ�����������˷ַ��Ƽ��\n");
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("qi", 2500);
	set("max_qi", 2500);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
	set("inquiry",  ([
	    "����" : "�Ǻǣ���ȥ�����ܹܰɣ����ᰲ����ġ�",
	    "����" : "�������䳡���������ģ���ȥ�����ɡ�",
	    "�Ƽ���" 	:(:do_getling:),
//	    		"job" : (: ask_job :),
	    "ling" :	(:do_getling:),
	]));
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("axe", 80);
	set_skill("blade", 80);
	set_skill("claw", 80);
	set_skill("club", 80);
	set_skill("cuff", 80);
	set_skill("dagger", 80);
	set_skill("finger", 80);
	set_skill("hammer", 80);
	set_skill("hand", 80);
	set_skill("hook", 80);
	set_skill("leg", 80);
	set_skill("spear", 80);
	set_skill("staff", 80);
	set_skill("stick", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("throwing", 80);
	set_skill("unarmed", 80);
	set_skill("whip", 80);
	set_skill("changquan", 40);
	set_skill("sanshou", 40);
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	setup();
	carry_object("clone/cloth/cloth")->wear();
}



int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 100000)
    {
        message_vision("���е�����$N˵������书Ӧ���������������ٳ�����������û
�������ˡ�\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/yangzhou_paied",1);
        message_vision("���е¶�$N˵���ã���λ" + RANK_D->query_respect(who) 
+ "��ѧʲô�أ�\n" , who);
        return 1;
    }
    else
        message_vision("���е���ü��$N˵��Ǯ�Ҳ��ں�������Ҳ����Ҳ̫���˵���ɣ�\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}
string do_getling()
{
	object ob=this_player();
	object me=this_object();
	object obj;
	if (!ob->query("family"))
		return "��λ"+RANK_D->query_respect(ob)+"��ûѡ��ȥ����ѧ�հɣ��������ѧһЩ������Ҳ�á�";
	if (ob->query("combat_exp")<20000)
		return "��λ"+RANK_D->query_respect(ob)+"�ƺ�̫������Щ�����Ƕ�����һ��ʱ����˵��";
	if (ob->query("combat_exp")>800000)
		return "����������������д����¼���ˣ�";
	if (present("ling", ob))
		return "�����ϲ����и�������";
	if (ob->query_temp("getling"))
		return "�Ҹող��ǲŸ������Ƽ����ˡ�";
	if (ob->query("teachwg/force")>=100 && ob->query("teachwg/dodge")>=100 && ob->query("teachwg/parry")>=100)
		return "�ҿ����Ƽ������Ҳû�ã��������˰ɡ�";
	command("smile");
	command("say ��λ"+RANK_D->query_respect(ob)+"�������ã��кܶ�����������������̵��µ����ŵ��ӡ�");
	obj=new(__DIR__"obj/ling");
	obj->move(me);
	ob->set_temp("getling",1);
	command("give ling to "+ob->query("id"));
	return "�������п��Ƽ��������ȥ��һ���õ��ϵġ�";
}


