// zhaixing.c ժ����

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_book();
string ask_job();

void create()
{
	set_name("ժ����", ({ "zhaixing zi", "zhaixing", "zi" }));
	set("nickname", "�����ɴ�ʦ��");
	set("long", 
		"һ����ʮ�߰���İ��������ˡ�����ĸ��ݣ���ɫ��
�з��ƣ���Ŀȴ��Ӣ�����۹���͸��һ˿����֮����\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);
	set("di_count", 10);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("throwing", 70);
	set_skill("feixing-shu", 80);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 80);
	set_skill("chousui-zhang", 80);
	set_skill("claw", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("parry", 70);
	set_skill("poison", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"������"    : "������룬�Ͱ���Ϊʦ��",
		"���޺�"    : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�",
		"������"    : "����������е���û��ûС�ġ��Ժ�����ɣ�",
		"����"      : (: ask_job :),
		"job"       : (: ask_job :),
		"���ĵ�"    : (: ask_me :),
		"�ؼ�"      : (: ask_book :),
		"��ɽ����"  : (: ask_book :),
	]));
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
	}));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("������", 2, "����");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (query("dan_count") < 1)
		return "�������ˣ�û�����ĵ��ˡ�";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "��Щ���ĵ������õ��˰ɡ�";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ�����ûʲôʣ���ˡ�";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����û�ȥ�úÿ����ɡ�";
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "������")
	{
		say("ժ���Ӷ�"+ob->name()+"������\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1)<90 || ob->query("shen") > -50000)
	{
		command("say ����������������ҲŲ��������ء�");
		return;
	}
	command("say �ðɣ�������Ļ������е�����ˣ��Ҿ�������ɡ�");
	command("recruit " + ob->query("id"));
}
string ask_job()
{
	object me, ob;
	mapping fam;
	int shen, exp;
	me = this_player();
	fam = (mapping)me->query("family");
	shen = me->query("shen");
	exp=me->query("combat_exp",1); 
 
	if(!fam) return "���ó��������̬�ȹ������β��������������أ�";
	if(fam["family_name"] != "������" && !me->query_temp("ding_flatter"))
		return "������ɵ�̬�ȿ���ȥ��̫��������";
	if(exp<500000)
		return "�����������ټӰ��������ɡ�";
	if(exp>=750000)
		return "�������������Ҳ�̫��������Լ�ȥ���������˼Ұɡ�";
	if(me->query_condition("wait_xx_task"))
		return "�ϴθ����ˣ������͵ȵȰɡ�";
	if(interactive(me) && me->query_temp("xx_job"))
		return "����ô�������﷢����";
	if(interactive(me) && me->query_condition("wait_xx_task"))
		return "�����������黹�ã���������Ϊ�����ǡ�";
	if(query("di_count") < 1)  
		return "�����������黹�ã�������������ˡ�";
	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", MAG "����̵�" NOR);
	ob->set("long", MAG"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���Ϻ죬��Ө�ɰ���\n" NOR);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "������")
		me->set_temp("apply/short", ({MAG"�������ſ� "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N�ó�һֻ���ƶ̵ѣ�����$n��\n", this_object(), me);
	return "����������鲻�ѣ����Ҫ���Ϊ�����˼ҷ��ǲ��ǣ�\n";    
}
