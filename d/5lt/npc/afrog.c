// afrog.c

#include <ansi.h>;
inherit NPC;

int ask_me();
int ask_heal();
int ask_poison();

void create()
{
	set_name("����", ({ "afrog" }));
	set("title", "����ҽ��");
	set("gender", "����");
	set("long", "����̧ͷ������һ�ۣ��۽���¶��ƽ�͵�Ц�ݣ����ٽ��ŵĲ��˼�������Ҳ��֮ƽ������ࡣ\n");
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);

	set_skill("unarmed", 100);
	set_skill("medicine", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 50);
	set("count", 30);
	set("inquiry", ([
		"����"   : (: ask_me :),
		"�β�"   : (: ask_heal :),
		"�ⶾ"   : (: ask_poison :),
	]));

	set("party/party_name", HIB"��ɽ��"NOR);
	set("party/rank", HIW"�ڶ�������"NOR);
	create_family("��ɽ��", 2, "����");
	setup();

	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
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
		message_vision("����ι$N����һ��ҩ�裬Ȼ����ϥ���£�˫������$N�ı��ġ�\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		        ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{
			where = environment(me);
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
	message_vision("��Լ����һ�Ѳ��ʱ�ݣ�����������վ��������\n",ob);
	command("say ��������Ѿ�ȫ����,����������\n");
	return 1;
}

int newyao(object me)
{
	object where = environment(me);
	me->add("count",20);
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
			ob->add("score",-100);    
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
	message_vision("��Լһ������������������һ��հ��õ��������ڵ���ҩ��\n",ob);
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
		message_vision("�������$N���ţ�˫ü���������ι$N����һ��ҩ�裬��ϥ���£�˫������$N�ı��ģ���ʼΪ$N�ⶾ��\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			ob->add("score",-200);    
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
	message_vision("��Լһ�������$N�³�һ����Ѫ������������վ��������\n",ob);
	command("say �����ڶ������壬����������\n");
	return 1;
}