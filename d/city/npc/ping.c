// ping.c ƽһָ

#include <ansi.h>;
inherit NPC;

int ask_wu();
int ask_me();
int ask_heal();
int ask_poison();
int ask_over();
int ask_working();
string ask_work();
string ask_me1();
void create()
{
	set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ���˵����������������ѧЩ����֮���ģ�Ҳ��֪���ϲ��ϴ��ڡ�\n");
	set("age", 65);

	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("medicine", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 50);
	set("zhen_count", 1);
	set("shouwu_count", 2);
	set("count", 30);
	set("inquiry", ([
		"������" : (: ask_wu :),
		"����"   : (: ask_me :),
		"��ҩ"   : (: ask_me1 :),
		"������" : (: ask_me1 :),
		"Ǳ�ܵ�" : (: ask_me1 :),
		"�β�"   : (: ask_heal :),
		"�ⶾ"   : (: ask_poison :),
		"work"   : (: ask_working :),
		"����"   : (: ask_working :),
		"��ҩ"   : (: ask_working :),
		"����"   : (: ask_over :),
		"����"   : (: ask_over :),   
		"over"   : (: ask_over :),   
		"���"   : (: ask_work :),
		"����"   : (: ask_work :),
		"��ҽ"   : (: ask_work :),
	]));
	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIW"�ڰ˴�����"NOR);
	create_family("��ľ��", 8, "����");

	setup();
	add_money("gold", 1);
	set("no_get",1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object(BOOK_DIR+"medicine1");
//	carry_object(BOOK_DIR+"medicine5");
}
void init()
{	
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting()&&!ob->query_temp("fengyaoover") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int eff_qi, max_qi, hurt, i;


	tell_object(ob, "\nƽһָ̧ͷ�����㼸�ۡ�\n");
	if (ob->query_condition("drunk"))
	{
		message_vision("ƽһָ��$N˵������λ"+RANK_D->query_respect(ob)+"�����������ģ�һ���Ǻ����ˣ�\n",ob);
	}
	if (ob->query_condition("killer"))
	{
		message_vision("ƽһָ��$N˵������λ"+RANK_D->query_respect(ob)+"���ٸ���ͨ�����أ��㻹�ǿ��߰ɣ���\n",ob);
		return;
	}

	if( !ob || environment(ob) != environment() ) return;
	eff_qi = ob->query("eff_qi");
	max_qi = ob->query("max_qi");
	if(100*eff_qi/max_qi<=50) hurt = 3;
	else if(100*eff_qi/max_qi<=70) hurt = 2;
	else if(100*eff_qi/max_qi<=95) hurt = 1;
	else hurt = 0;
	switch(hurt)
	{
		case 1 : message_vision("ƽһָ�������еض�$N˵������λ"+RANK_D->query_respect(ob)+"�������˵����ˣ��������Ϻõĵ�ҩ����֪�Ƿ�Ҫ��Щ��\n",ob);
			break;
		case 2 : message_vision("ƽһָ��$N˵������λ"+RANK_D->query_respect(ob)+"�������˲��ᣬ��Щ��ҩ��ȥ�ɣ�\n",ob);
			break;
		case 3 : message_vision("ƽһָ����ض�$N˵������λ"+RANK_D->query_respect(ob)+"���ش�Σ���������ӣ��ٺ٣�\n",ob);
			break;
		default: command("look "+ob->query("id"));
			break;
	}
	if(!ob->query_temp("fengyaobegin") &&
		ob->query("combat_exp")>300 &&
		ob->query("combat_exp")<3000)
		say( "ƽһָ��̧��̧��Ƥ��˵����С����ȱ���֣���λ" + RANK_D->query_respect(ob) + "����Ļ�������"CYN" ��"HIR"ask ping about work"NOR CYN"��\n"NOR);
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 ) return chinese_number(value) + "��Ǯ";
	else if( value < 10000 ) return chinese_number(value/100) + "������" + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
	else return chinese_number(value/10000) + "���ƽ�" +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "") +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
}

int ask_wu()
{
	object ob = this_player ( ) ;

message_vision("ƽһָ�������´�����$Nһ�£�ʲô�������ڣ���ʮ���ƽ�����\n",ob);
	ob->set_temp ("������" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("������"))
	{
		if (!(int)who->query_temp("mark/ƽ"))
			who->set_temp("mark/ƽ", 0);
		if (ob->query("money_id") && ob->value() >= 1000)
		{
			message_vision("ƽһָ�����е���ָ��$NһЩ���ڼ���֮�����������˼��\n", who);
			who->add_temp("mark/ƽ", ob->value() / 500);
		}
		else
			message_vision("ƽһָ��$N˵��ҽһ�ˣ�ɱһ�ˣ��Ϸ�Ͳ���Ǯ��\n", who);
		return 1;
	}
	if (query("shouwu_count") < 1)
	{
		message_vision("ƽһָ��$N�����������ˡ�����ȱ����\n", who);
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 100000)
	{
		message_vision("ƽһָ����$N�����ڣ�\n" , who);
		add("shouwu_count", -1);
		this_player()->delete_temp("������" );
		obj=new("/clone/medicine/vegetable/heshouwu");
		obj->move(this_player());
	}
	return 1;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/ƽ")) return 0;
	ob->add_temp("mark/ƽ", -1);
	return 1;
}

int ask_me()
{
	object ob = this_player();
	object me = this_object();
	object where;

	if(me->is_fighting())
	{
		command("say ������û�գ�\n");
		return 1;
	}
	if(me->query("count") < 1)
	{
		command("say ��ҩ�������ˣ��һ�û���ü��䣬��һ�������ɡ�\n");
		return 1;
	}
	if(ob->query("shen")>0)
	{
		command("say ������Щ�������ˣ��ҿɲ��Ҹ��ʣ�\n");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{
		command("say ����㽭��������Ҳ������Ϊ�����ˣ�\n");
		return 1;
	}
		
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
	{
		command("?"+ob->query("id"));
		command("say ��û�����κ��˰���\n");
		return 1;
	}
	else
	{
		message_vision("ƽһָι$N����һ��ҩ�裬Ȼ����ϥ���£�˫������$N�ı��ġ�\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			if (ob->query("family/family_name") != "��ľ��")
				ob->add("score",-200);
		        else ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{
			where = environment(me);
			where->add("no_fight", 1);
			remove_call_out("newyao");
			call_out("newyao",600,me);
		}
		return 1;
	}
}

int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));
	message_vision("��Լ����һ�Ѳ��ʱ�ݣ�ƽһָ������վ��������\n",ob);
	command("say ��������Ѿ�ȫ����,����������\n");
	return 1;
}
int newyao(object me)
{
	object where = environment(me);
	me->add("count",20);
	where->add("no_fight", -1);
	return 1;
}
	
int ask_heal()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting())
        {
		command("say ������û�գ�\n");
		return 1;
	}

	if(ob->query("shen")>0)
	{       
		command("say ������Щ�������ˣ��ҿɲ��Ҹ��ʣ�\n");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{       
		command("say ����㽭��������Ҳ������Ϊ���β���\n");
		return 1;
	}
		
	if( ob->query_condition("ill_kesou") ||
		ob->query_condition("ill_zhongshu") ||
		ob->query_condition("ill_shanghan") ||
		ob->query_condition("ill_dongshang") ||
		ob->query_condition("ill_fashao"))
	{
		message_vision("ƽһָ���$N���ţ���һ˼�������ת���ҩ¨��ȡ����ζ��ҩ����ʼΪ$N��ҩ��\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "��ľ��")
	            ob->add("score",-200);
	        else ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);		
		return 1;
	}
	
	else
	{
		command("?"+ob->query("id"));
		command("say �������ɫ����û����������\n");
		return 1;
	}
	
}
int recover_II(object ob)
{
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
	message_vision("��Լһ�������ƽһָ�������һ��հ��õ��������ڵ���ҩ��\n",ob);
	command("say ����������޴�,����������\n");
	return 1;
}

int ask_poison()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting())
	{
		command("say ������û�գ�\n");
		return 1;
	}

	if(ob->query("shen")>0)
	{
		command("say ������Щ�������ˣ��ҿɲ��Ҹ��ʣ�\n");
		return 1;
	}
	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{
		command("say ����㽭��������Ҳ������Ϊ��ⶾ��\n");
		return 1;
	}
		
	if(ob->query_condition("chanchu_poison") ||
		ob->query_condition("drunk") ||
		ob->query_condition("flower_poison") ||
		ob->query_condition("ice_poison") ||
		ob->query_condition("iceshock") ||
		ob->query_condition("rose_poison") ||
		ob->query_condition("scorpion_poison") ||
		ob->query_condition("slumber_drug") ||
		ob->query_condition("snake_poison") ||
//		ob->query_condition("ss_poison") ||
		ob->query_condition("wugong_poison") ||
//		ob->query_condition("xx_poison") ||
		ob->query_condition("xiezi_poison") ||
		ob->query_condition("zhizhu_poison") ||
		ob->query_condition("zhua_poison") ||
		ob->query_condition("ice_sting"))
	{
		message_vision("ƽһָ���$N���ţ�˫ü���������ι$N����һ��ҩ�裬��ϥ���£�˫������$N�ı��ģ���ʼΪ$N�ⶾ��\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			if (ob->query("family/family_name") != "��ľ��")
				ob->add("score",-300);
			else ob->add("score",-200);    
		}
		me->add("count", -1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);		
		return 1;
	}
	else
	{
		command("?"+ob->query("id"));
		command("say �����Ұﲻ����ʲôæ�ˣ�\n");
		return 1;
	}
}
int recover_III(object ob)
{
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
	message_vision("��Լһ�������$N�³�һ����Ѫ��ƽһָ������վ��������\n",ob);
	command("say �����ڶ������壬����������\n");
	return 1;
}

int ask_over()
{
	object mon, me = this_player();
	int bonus,exp,pot,tempp,kar;

	kar = me->query("kar");
	if (!me->query_temp("fengyaoover"))
	{
		message_vision("ƽһָ���ȵĶ�$N˵������Ŷ�����ٿ�ʲô��Ц������ɲ�������Ժ������\n",me);
		return 1;
	}
	me->delete_temp("fengyaoover");
	if (me->query_temp("fengyaow"))
	{
		if(random(kar)>=11)
		{
			message_vision("ƽһָ����һ������$N˵����������ô��ģ��ҷ�ҩ���������ҵ�������\n�����㻹Ŭ���ķ��ϻ��������Ǯ�ɡ���\n",me);
			exp = 10 + random(20);
			mon = new("/clone/money/silver");
			mon->set_amount(exp);
			tell_object(me,HIW"ƽһָ������" + chinese_number(exp) + "�������� \n"NOR);
			mon->move(me);
			me->delete_temp("fengyaow");
			return 1;
		}
		message_vision("ƽһָ����һ������$N˵��������ô��ģ��ҷ�ҩ���������ҵ�������\n",me);
		return 1;
	}
	message_vision("ƽһָЦ�Ŷ�$N˵�����㻹��������Կ��ԣ�������Ӧ�õõġ���\n",me);
	exp = 10 + random(80);
	pot = 10 + random(50);
	bonus = (int) me->query("combat_exp");
	tempp = bonus;
	bonus += exp;
	me->set("combat_exp", bonus);
	bonus = (int) me->query("potential");
	bonus += pot;
	me->set("potential", bonus);
	mon = new("/clone/money/silver");
	mon->set_amount(exp);
	mon->move(me);
	me->start_busy(3);
	tell_object(me,"�㱻�����ˣ�"HIR+chinese_number(exp)+NOR"�㾭�飬"HIR+chinese_number(pot)+NOR"��Ǳ�ܺ�"HIW+chinese_number(exp)+NOR"��������\n");
	bonus=(int) me->query("potential");
	return 1;
}
int ask_working()
{
	object me = this_player();

	if((int)(me->query("combat_exp")) > 3000 ||
		(int)(me->query("combat_exp")) < 300)
	{
		message_vision("ƽһָ��$N˵����������������֣�С���ͷ����𡣺ǡ������ǡ�������\n",me);
		return 1;
	}
	if (me->query_temp("fengyaobegin"))
	{
		message_vision("ƽһָ��$N˵�������㲻���Ѿ�Ҫ�˹����ˣ�����ȥ�ɣ���\n",me);
		return 1;
	}
	if ((int)(me->query("qi")) < random(30))        
	{
		message_vision("ƽһָ��$N˵���������˰��㣬�������˻��빤������ҩ�ִ��˻�������ġ���\n",me);
		return 1;
	}
	if (me->query_temp("fengyaoover"))
	{
		message_vision("ƽһָ��$N˵������Ŷ�� �����Լ��Ĺ���Ҳ��Ҫ����\n",me);
		message_vision("ƽһָ��$N˵�������ðɣ���Ȼ������Ҳ�Ͳ���ǿ���ˡ���\n",me);
		message_vision("ƽһָ��$N˵����������͵�����ȥ�����ٷִ�ҩ�ɡ���\n",me);
		me->delete_temp("fengyaow");
		me->delete_temp("fengyaoover");
		me->set_temp("fengyaobegin",1);
		return 1;
	}
	message_vision("ƽһָ��$N˵�������ðɣ�����͵�����ȥ���ҷַ�ҩ�ɡ���\n",me);
	me->set_temp("fengyaobegin",1);
	return 1;
}

string ask_me1()
{
	return "��...�Ҳ�֪����";
}

string ask_work()
{
	object ob, me = this_player();

	if (present("yin zhen", me))
		return "�㲻����������ô���������Ҹ��";
	if (query("zhen_count") < 1)
		return "�������ˣ��ҵ������Ѿ������ˡ�";
	if (me->query_skill("medicine", 1) < 50)
		return "��Ҳ����ҽ����Ҳ�ÿ��ǲ����ǿ��ϰ���";
	if (me->query("medicine_count") < 50)
		return "������ҽ���ȵð�ҩ���ã��������ɣ�ĥ�����󿳲񹦣����������Ҳ֪������̰����õġ�";
	ob = new("/clone/misc/yinzhen");
	ob->move(me);
	add("zhen_count", -1);
	if (me->query_skill("acupuncture",1) > 0)
	{
		return "����ҽ������������ȥ�ðɡ��ɱ���û���ҡ�ҽһ��ɱһ�ˡ�����ͷ��";
	}
	else
	{
		me->set_skill("acupuncture", 1);
		return "������ҽ�ɣ����������������ɡ�������Ϳ��Դ�����·�ˡ�";
	}
}
