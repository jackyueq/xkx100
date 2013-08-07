// qiao-feng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("�Ƿ�", ({"qiao feng", "feng", "qiao"}));
	set("nickname", "���Ƿ�");
	set("gender", "����");
	set("age", 29);
	set("long", 
"������ؤ���ʮ�ΰ������ڽ��������������Ľ�ݸ�����Ϊ�����Ƿ壬��Ľ�ݡ���
����һ����ͨ�Ĵֲ����ӣ�������һ���������һϵ��������������࣬���
ʮ�ֿ��࣬����һ�������ֿ���ʮ�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

        set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 3000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // �����ڹ�
	set_skill("huntian-qigong", 200);    // ��������
	set_skill("unarmed", 200);           // ����ȭ��
	set_skill("dodge", 200);      	     // ��������
	set_skill("xiaoyaoyou", 300);        // ��ң��
	set_skill("parry", 200);             // �����м�
	set_skill("strike", 200);            // �����Ʒ�
	set_skill("xianglong-zhang", 300);   // ����ʮ����
	set_skill("hand", 200);              // �����ַ�
	set_skill("suohou-hand", 300);       // ����������
	set_skill("blade", 200);             // ��������
	set_skill("liuhe-blade", 300);       // �������ϵ�
	set_skill("staff", 200);             // �����ȷ�
	set_skill("fengmo-staff", 300);      // ��ħ�ȷ�
	set_skill("stick", 200);             // ��������
	set_skill("dagou-bang", 300);        // �򹷰���
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	set_skill("training", 100);          // Ԧ����
	set_skill("lianhua-zhang",85); // ������
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("hand",  "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "dagou-bang");
	map_skill("stick", "dagou-bang");
	map_skill("staff", "fengmo-staff");
//	prepare_skill("hand",  "suohou-hand");
	prepare_skill("strike", "xianglong-zhang");

	set("inquiry",([
		"�ؼ�"     : (: ask_me :),
		"��������" : (: ask_me :),
	]));	
	set("book_count", 1);
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIR"����"NOR);
	set("party/level", 10);
	create_family("ؤ��", 10, "����");

	setup();
	
	carry_object(__DIR__"obj/lvyv_bang")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
//      carry_object(BOOK_DIR"stick_book")->wear();
}

void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "ؤ��")&&(!me->query_skill("huntian-qigong",1))&&(me->query("combat_exp")>500000))
        {
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20)
	{
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "ؤ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α����������أ�");
		return;
	}
	if ((string)ob->query("party/party_name") != HIC"ؤ��"NOR)
	{
		command("say ��ֻ�ձ������Ϊͽ��\n");
		return;
	}
	command("recruit "+ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "ؤ��")
		return RANK_D->query_respect(this_player()) +"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/stick_book.c");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�������������\n");
	return "�ðɣ��Ȿ���������š����û�ȥ�ú����С�";
}

