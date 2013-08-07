// wang.c ������

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
	set_name("������", ({"wang chongyang", "wang"}));
	set("gender", "����");
	set("age", 66);
	set("class", "quanzhen");
	set("nickname",HIW"����ͨ"NOR);
	set("long",
		"������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ������������ˡ�������Ʈ\n"
		"Ʈ�����ۻ��䣬üĿ��񳣬����Щ�ɷ���ǵ�ζ����������һ\n"
		"ǻ��Ѫ����Ч���������������ϧ��͢���ܣ������Ļ����䣬\n"
		"�ִӵ��¾����������������Ĵ�����ִ�ȫ��̡�\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),	      
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.sanqing" :),		
		(: command("unwield changjian") :),		
		(: command("wield changjian") :),
		(: perform_action, "finger.qiankun" :),		
		(: perform_action, "strike.ju" :),
	}));

	set("qi", 6500);
	set("max_qi", 6500);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 500000);

	set_skill("array", 150);
	set_skill("force", 200);
	set_skill("xiantian-qigong", 200);    //��������
	set_skill("sword", 200);
	set_skill("quanzhen-jian", 300);  //ȫ�潣
	set_skill("dodge", 200);
	set_skill("jinyan-gong", 300);   //���㹦
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("strike", 200);
	set_skill("haotian-zhang", 300);    //�����
	set_skill("cuff", 200);
	set_skill("chunyang-quan", 300);    //����ȭ
	set_skill("whip", 200);
	set_skill("duanyun-bian", 300);    //���Ʊ�
	set_skill("literate", 140);
	set_skill("taoism", 150);
	set_skill("finger", 200);
	set_skill("sun-finger", 200);  //һ��ָ
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger","sun-finger");
	map_skill("whip", "duanyun-bian");
	map_skill("strike", "haotian-zhang");
	map_skill("cuff", "chunyang-quan");
	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "haotian-zhang");

	create_family("ȫ���", 1, "�ƽ�");

	set("book_count",1);
	set("inquiry", ([
		"ȫ���" :  "��ȫ��������µ����������ڡ�\n",
		"�����澭" : (: ask_jiuyin :),
		"һ��ָ" : (: ask_zhipu :),
		"�λ�ү" : (: ask_duan :),
	]) );

	setup();

	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(__DIR__"obj/whiterobe")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	string new_name;
/*
	if (!ob->query("qixing"))
	{
		command("say ��Ҫ�ȹ����������������ѧ�ա�");
		return;
	}
*/
	if (ob->query("class") != "quanzhen")
	{
		command("say �㲻����������֮ʿ�����ԣ���ذɡ�");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say ������ʲ����������������Ǽ���ͽ��ѧϰ�ɡ�");
		return;
	}
	if ((int)ob->query_skill("xiantian-qigong",1) < 140 )
	{
		command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
		return;
	}
	if ((int)ob->query("shen")<100000)
	{
		command( "say �ұ����˷ݵ�����������������������ܶ�Ϊ����֮�٣����ܳ����²���\n");
		return;
	}
	command("say �ðɣ��������ʣ����ɴ����²����Ҿ����������ͽ���ˡ�");
	command("recruit " + ob->query("id"));
	new_name=ob->query("name");
	if(new_name[2..3]=="־")
	{
		new_name=new_name[0..1]+"��"+new_name[4..5];
		ob->set("name", new_name);
		command("say �ӽ��Ժ���ĵ��Ž���"+new_name+ "����������ȫ��̴��ֱ������ˡ�");      
	}
}

string ask_jiuyin()
{
	mapping fam;
	int lvl_force;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "ȫ���")
		return RANK_D->query_respect(this_player()) +"�뱾�̺��޹ϸ��⻰�Ӻ�˵��";
	if (!(lvl_force = this_player()->query_skill("force",1)) ||
		lvl_force < 50)
		return RANK_D->query_respect(this_player()) +"�Ļ����ڹ�������֮ǳ��ǿ���澭�ϵ��ϳ��书�к����档";
	return "�����澭��������ѧ���ڣ����ѽ�����ʦ���ܲ�ͨ���ܣ�\n����....�ڹ�Ĺ�ɵ�ʯ���ڣ��һ�����һЩͼ�Ρ�\n";
}

string ask_duan()
{
	object me=this_player();
	if(me->query_temp("tmark/ָ")==2)
	{
		me->add_temp("tmark/ָ",1);
		return("�λ�ү�ųơ��ϵۡ����Ҵ���һ��ָ��������������ָ����\n");
	}
	else {
		me->set_temp("tmark/ָ",0);
		return("���ʶλ�ү����ô��Ī��������Ϊ�ѣ�\n");
	}
}

string ask_zhipu()
{
	object ob,me=this_player();
	if(me->query_temp("tmark/ָ")==3)
	{
		me->set_temp("tmark/ָ",0);
		if(query("book_count")>0)
	{
			ob=new(BOOK_DIR"sun_book");
			ob->move(me);
			add("book_count",-1);
message("channel:rumor",MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"����һ��ָ������\n"NOR, users());
			return("�ðɣ���������࣬��־���ᣬ�Ȿָ���׾ͽ������ˡ�\n");
		}
		else return("�������ˣ�ָ�����Ѿ�����ȡ���ˡ�\n");
	}
	else {
		me->set_temp("tmark/ָ",0);
		return  RANK_D->query_respect(me) + "��������ҽ��������ɣ�\n";
	}
}
