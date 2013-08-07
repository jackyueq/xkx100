// hu.c ����ţ
#include <ansi.h>;
inherit NPC;

int ask_me();
int ask_book();
int ask_heal();
int ask_poison();

void create()
{
	set_name("����ţ", ({ "hu qingniu", "hu" }));
	set("long", 
		"���������̺ųƼ������ȵĺ���ţ����˵����ͨҽ������������\n"
                "���������Ӳ�ҽ������ʿ��\n");
	set("gender", "����");
	set("nickname","����ҽ��");
	set("age", 50);
	set("no_get", "1");
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("inquiry", ([
		"����" : (:ask_me:),
		"�β�"	: (: ask_heal :),
		"�ⶾ"	: (: ask_poison :),
		"jing" : (:ask_book:),
		"ҽ��" : (:ask_book:),
		"ҽ��" : (:ask_book:),
		"����ţҽ��" : "�ҵĺ���ţҽ���Ѿ������޼���ȥ�ˡ�",
	]) );

	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 80000);

	set("count", 30);
	set("bookcount", 1);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed",90);
	set_skill("medicine",150);
	set_skill("parry", 90);

	set("party/party_name",HIG"����"NOR);
	set("party/rank","����"NOR);
	create_family("����", 35, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	object ob = this_player();
	object me = this_object();
	object where;
	
	if(me->is_fighting() || me->query_temp("busy"))
	{
		command("say ������û�գ�");
		return 1;
	}
	
	if(me->query("count") < 1)
	{
		command("say ��ҩ�������ˣ��һ�û���ü��䣬��һ�������ɡ�");
		return 1;
	}
	
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")
	 && (int)ob->query("eff_jing") == (int)ob->query("max_jing"))
	{
		command("? "+ob->query("id"));     
		command("say ��û�����κ��˰���");
		return 1;
	}
	if(ob->query("score")<500&&ob->query("combat_exp")>100500)
	{       
		command("say ����㽭��������Ҳ������Ϊ�����ˣ�");
		return 1;
	}	
	else
	{
		message_vision("����ţι$N����һ��ҩ�裬Ȼ����ϥ���£�˫������$N�ı��ġ�\n", ob);
		if (ob->query("combat_exp")>100500)
		{
		if (ob->query("family/family_name") != "����")
	            ob->add("score",-300);
	        else ob->add("score",-100);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{  where = environment(me);
		   where->add("no_fight", 1);
		   remove_call_out("newyao");
		   call_out("newyao",600,me);
		 }
		return 1;
	}
}

int recover(object ob)
{
	this_object()->delete_temp("busy");
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("��Լ����һ�Ѳ��ʱ�֣�����ţ������վ��������\n",ob);
	command("say ��������Ѿ�ȫ����,����������");
	return 1;
}
int newyao(object me)
{
	object where = environment(me);
	this_object()->delete_temp("busy");
	me->add("count",30);
	where->add("no_fight", -1);
	return 1;
}
int ask_heal()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting()|| me->query_temp("busy"))
         {
           command("say ������û�գ�");
           return 1;
         }

	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{       
		command("say ����㽭��������Ҳ������Ϊ���β���");
		return 1;
	}
		
	if( ob->query_condition("ill_kesou")
	    || ob->query_condition("ill_zhongshu")
	    ||ob->query_condition("ill_shanghan")
	    ||ob->query_condition("ill_dongshang")
	    ||ob->query_condition("ill_fashao"))
	{
		message_vision("����ţ���$N���ţ���һ˼�������ת���ҩ¨��ȡ����ζ��ҩ����ʼΪ$N��ҩ��\n", ob);
		if( ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "����")
	            ob->add("score",-300);
	        else ob->add("score",-100);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);		
		return 1;
	}
	
	else
	{
		command("? "+ob->query("id"));
		command("say �������ɫ����û����������");
		return 1;
	}
	
}
int recover_II(object ob)
{
	this_object()->delete_temp("busy");
	if (ob->query_condition("ill_kesou"))
		ob->clear_condition("ill_kesou",0);
	if (ob->query_condition("ill_zhongshu"))
		ob->clear_condition("ill_zhongshu",0);
	if (ob->query_condition("ill_shanghan"))
		ob->clear_condition("ill_shanghan",0);
	if (ob->query_condition("ill_dongshang"))
		ob->clear_condition("ill_dongshang",0);
	if (ob->query_condition("ill_fashao"))
		ob->clear_condition("ill_fashao",0);
	message_vision("��Լһ������󣬺���ţ�������һ��հ��õ��������ڵ���ҩ��\n",ob);
	command("say ����������޴�,����������");
	return 1;
}

	
int ask_poison()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting()|| me->query_temp("busy"))
         {
           command("say ������û�գ�");
           return 1;
         }
	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{       
		command("say ����㽭��������Ҳ������Ϊ��ⶾ��");
		return 1;
	}
		
	if( ob->query_condition("chanchu_poison")
	    || ob->query_condition("drunk")
	    ||ob->query_condition("flower_poison")
	    ||ob->query_condition("ice_poison")
	    ||ob->query_condition("iceshock")
	    || ob->query_condition("rose_poison")
	    ||ob->query_condition("scorpion_poison")
	    ||ob->query_condition("slumber_drug")
	    || ob->query_condition("snake_poison")
//	    ||ob->query_condition("ss_poison")
	    ||ob->query_condition("wugong_poison")
//	    || ob->query_condition("xx_poison")
	    ||ob->query_condition("xiezi_poison")
	    ||ob->query_condition("zhizhu_poison")
	    || ob->query_condition("zhua_poison")
	    ||ob->query_condition("ice_sting"))
	{
		message_vision("����ţ���$N���ţ�˫ü���������ι$N����һ��ҩ�裬��ϥ���£�˫������$N�ı��ģ���ʼΪ$N�ⶾ��\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "����")
	            ob->add("score",-400);
	        else ob->add("score",-200);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);		
		return 1;
	}
	
	else
	{
		command("? "+ob->query("id"));
		command("say �����Ұﲻ����ʲôæ�ˣ�");
		return 1;
	}
	
}
int recover_III(object ob)
{
	this_object()->delete_temp("busy");
	if (ob->query_condition("chanchu_poison"))
		ob->clear_condition("chanchu_poison",0);
	if (ob->query_condition("drunk"))
		ob->clear_condition("drunk",0);
	if (ob->query_condition("flower_poison"))
		ob->clear_condition("flower_poison",0);
	if (ob->query_condition("ice_poison"))
		ob->clear_condition("ice_poison",0);
	if (ob->query_condition("iceshock"))
		ob->clear_condition("iceshock",0);
	if (ob->query_condition("rose_poison"))
		ob->clear_condition("rose_poison",0);
	if (ob->query_condition("scorpion_poison"))
		ob->clear_condition("scorpion_poison",0);
	if (ob->query_condition("slumber_drug"))
		ob->clear_condition("slumber_drug",0);
	if (ob->query_condition("snake_poison"))
		ob->clear_condition("snake_poison",0);
//	if (ob->query_condition("ss_poison"))
//		ob->clear_condition("ss_poison",0);
	if (ob->query_condition("wugong_poison"))
		ob->clear_condition("wugong_poison",0);
//	if (ob->query_condition("xx_poison"))
//		ob->clear_condition("xx_poison",0);
	if (ob->query_condition("xiezi_poison"))
		ob->clear_condition("xiezi_poison",0);
	if (ob->query_condition("zhizhu_poison"))
		ob->clear_condition("zhizhu_poison",0);
	if (ob->query_condition("zhua_poison"))
		ob->clear_condition("zhua_poison",0);
	if (ob->query_condition("ice_sting"))
		ob->clear_condition("ice_sting", 0);
	message_vision("��Լһ�������$N�³�һ����Ѫ������ţ������վ��������\n",ob);
	command("say �����ڶ�������,����������");
	return 1;
}
string ask_book()
{
	mapping fam; 
	object ob;
	
	if (query("bookcount") < 1)
		return "�������ˣ��ҵ�ҽ�������˽�ȥ�ˡ�";
	add("bookcount", -1);
	switch (random(4))
	{
		case 0 : ob = new("/clone/book/medicine1"); break;
		case 1 : ob = new("/clone/book/medicine2"); break;
		case 2 : ob = new("/clone/book/medicine3"); break;
		case 3 : ob = new("/clone/book/medicine4"); break;
	}
	ob->move(this_player());
	return "�ðɣ��Ȿҽ�����û�ȥ�ú����С�";
}
