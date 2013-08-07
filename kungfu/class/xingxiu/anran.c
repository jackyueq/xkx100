// /d/xingxiu/npc/anran.c
// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

mapping *quest = ({
  (["name":                "xianrenya",
    "start" :              "/d/xingxiu/xianrenya",
    "place" :              "������",]),
  (["name":                "silk1",
    "start" :              "/d/xingxiu/silk1",
    "place" :              "������������˿��֮·",]),
  (["name":                "shanjiao",
    "start" :              "/d/xingxiu/shanjiao",
    "place" :              "��ɽ����",]),
  (["name":                "xinglongshan",
    "start" :              "/d/xingxiu/xinglongshan",
    "place" :              "��¡ɽ",]),  
  (["name":                "tugu",
    "start" :              "/d/xingxiu/tugu",
    "place" :              "�¹Ȼ��ٹ��",]), 
});    
string ask_job();

void create()
{
	set_name("��Ȼ��", ({ "anran zi", "anran", "zi" }) );
	set("gender", "����" );
	set("nickname", "������������");
	set("age", 31);
	set("location", 1);
	set("unique", 1);
	set("long", "��Ȼ�������޶���ʮ���������е�����
�������������书��Щ������������ǳ��\n");
	set("env/wimpy", 40);
	set("str", 29);
	set("dex", 26);
	set("con", 24);
	set("int", 22);
	set("per", 18);
	set("shen", -7500);

	set_skill("force", 105);
	set_skill("huagong-dafa", 115);
	set_skill("dodge", 110);
	set_skill("zhaixinggong", 160);
	set_skill("strike", 110);
	set_skill("chousui-zhang", 160);
	set_skill("poison", 110);
	set_skill("parry", 110);
	set_skill("staff", 110);
	set_skill("tianshan-zhang", 160);
	set_skill("literate", 70);
	set_skill("claw", 110);
	set_skill("sanyin-wugongzhao", 160);
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("eff_jingli", 1800);
	set("score", -14000);
	set("combat_exp", 750000);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.biyan" :),
	}));
	create_family("������", 2, "����");
	set("attitude", "peaceful");
	set("inquiry", ([
		"������" : "����������е���û��ûС�ġ��Ժ�����ɣ�",
		"��ɱ" : (: ask_job :),
		"����" : (: ask_job :),
		"rob"  : (: ask_job :),
		"job"  : (: ask_job :),
		"����" : "Сʦ����������ϲ������ȥ�����ɡ�",
	]));	
	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/cloth/dao-cloth")->wear();
	add_money("silver", 10);
}
void attempt_apprentice(object ob)
{
	command("consider");
	command("say �������и��˶���רְ��Ҫ��ʦ��ȥ����ʦ�ֵܰɣ�");
	return;
}
int accept_object(object me, object obj)
{
	object ob=this_object();
	if(!me || environment(me) != environment()) return 0;
	if(!objectp(obj)) return 0;
	if(!present(obj, me)) return notify_fail("��û�����������");	
	if(userp(obj))
	{
		command("consider "+(string)me->query("id"));
		command("say ���ø�����������ƭ�ң�");
		return 0;
	}
	if(!me->query_condition("xx_task2"))
	{
		command("shake "+(string)me->query("id"));
		command("say ��ô�òŻ������һ������ұ������ɣ�");
		return 0;
	}
	if(obj->query("id")=="prize" && obj->query("owner")==me->query("id"))
	{
		command("nod "+(string)me->query("id"));
		command("say �����ģ���������������ɵ����磡\n");
		message_vision(HIY"$N��$n"HIY"�𿪣��ó���һ��ѽ����Ʊ���\n"NOR,ob, obj);
	        remove_call_out("del_temp");
                remove_call_out("destroying");
		call_out("destroying", 5, obj, ob, me);
		return 1;
	}
	if(obj->query("money_id"))
	{
		command("pat " + me->query("id"));
		command("say Ǯ���е��ǣ����Ժ��������Լ��ɡ�");
		return 0;
	}
	if(obj->query("owner") != me->query("id"))
	{
		command("hehe "+(string)me->query("id"));
		command("say �����������ɲ�����ɵġ�");
		return 1;
	}
	else return 0;		
}
void destroying(object obj, object ob, object me)
{	
	object n_money;
	int exp,pot;
	if(obj) destruct(obj);
	if(!ob) return;
	if(!me || environment(me) != environment())
	{
		command("say �ף����أ�");
		return;
	}
	command("pat "+me->query("id"));
	message_vision(HIY "$N��$n˵������������ü�Ϊ��ɫ��������õõĲ��֣���ȥ�ɣ�\n"NOR,ob, me);
	n_money = new("/clone/money/gold");
	n_money->move(me); 
	n_money->add_amount(1);
	me->set_temp("job2_exp", 150+(me->query_temp("biaoshi")*(random(50)+50)));
	exp = me->query_temp("job2_exp");
	pot = me->query_temp("biaoshi")*20;
	me->add("combat_exp", exp);
	me->add("potential", pot);
	me->set_temp("prize_reason","����");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",exp);
	me->set_temp("prize_pot",pot);
	tell_room(environment(me),me->name()+"����Ǯ����Ľ��ӣ����ϵļ��ⲻס�ز������۾�ɢ����һ����ֵĹ�â��\n" NOR, ({ me }));	 
	tell_object(me,"�ٺ٣����ˣ��õ�"+chinese_number(me->query_temp("job2_exp"))+"�㾭�顣\n");
	log_file("mission/ms_shangdui",sprintf("%20s����������ɱ��%2i����ʦ���õ���%4i��EXP��%4i��Ǳ�ܡ�\n",
	me->name(1)+"("+ getuid(me)+")", me->query_temp("biaoshi"), me->query_temp("job2_exp"),me->query_temp("biaoshi")*20));
        me->delete_temp("job2_exp");
	me->delete_temp("biaoshi");
        me->clear_condition("xx_task2",1);
        ob->delete_temp("job_asked");
        return;		
}
string ask_job()
{
	object me, ob;
	mapping aquest;
	int exp, j;
	aquest = quest[random(sizeof(quest))];
	me = this_player();
	ob = this_object();
	exp = me->query("combat_exp"); 
 
	if(ob->is_busy() || ob->is_fighting())
		return "û��������æ����һ�ߵ���ȥ��";
	if(!me->query("family"))
		return "���ó��������̬�ȹ������β��������������أ�";
	if(me->query("family/family_name") != "������" &&
		!me->query_temp("ding_flatter"))
		return "������ɵ�̬�ȿ���ȥ��̫��������";
	if(me->query_condition("wait_xx_task"))
		return "�ϴΰ���ʦ�ָ�����������ˣ������͵ȵȰɡ�";
	if(me->query_condition("xx_task2"))
		return "�����ڻ�û�еõ��κ���Ϣ����Ȼ�������ɡ�";
//	if(me->query_condition("job_busy"))
  //      	return "�����ڻ������������Ȼ�������ɡ�";		
	if(ob->query_temp("job_asked") == me->query("id")) 
		return "���ǽ�����ȥ�����������ô���������";
	if(ob->query_temp("job_asked")) 
		return "�ٺ٣��������ˣ�����һ�ΰɡ�";
	if(exp<200000)
		return "�����������ټӰ��������ɡ�";
	if(exp>=750000)
		return "��Ĺ����Ѿ��������ˣ����ø��ҳ�ȥ���£�";
	if(me->query("shen") > -10000)
		return "�ߣ���������ĳ��������ڰ����������㲻��Ҳ�ա�";
	if(exp>=600000) j=6;
	else if(exp>=500000) j=5;
	else if(exp>=400000) j=5;
	else if(exp>=300000) j=4;	
	else j=3;	
  
	me->set_temp("xx_job2", 1);
	me->delete_temp("biaoshi");
	message_vision(CYN "\n$N����һЦ��˵�������������һ�������̶Ӿ������㹻���ͺ���һ��ȥ�����ɡ�\n"NOR, ob, me);
	ob->set_temp("job_asked", me->query("id"));
	ob->set_temp("dest", aquest["name"]);
	ob->set_temp("start_place", aquest["start"]);
	ob->set_temp("place", aquest["place"]);
	me->set_temp("j", j);	
	me->apply_condition("xx_task2", 10 + j);
	me->start_busy(1);
	call_out("going", 30, ob); 
	return "�һ���Щ��Ҫ�죬����ȥ"+ob->query_temp("place")+"���ҡ�\n";
}
void going(object me)
{
	message_vision("$N����ææ�����˳�ȥ��\n", me);
	me->move(me->query_temp("start_place"));
	message_vision("$N����ææ�����˹�����\n", me);
}
void init()
{
	object ob, where, me;
	::init();
	ob=this_object();
	where = environment(ob);
	if(ob->query_temp("dest"))
	{
		if(interactive(me = this_player()) &&
			me->query_temp("xx_job2") &&
			ob->query_temp("job_asked") == me->query("id") &&
			file_name(where) == ob->query_temp("start_place"))
		{
			remove_call_out("waiting");
			call_out("do_back", 120, ob);
			call_out("waiting", 1, ob, me);
		}
		else
		{
			remove_call_out("do_back");
			call_out("do_back", 90, ob);
		}
	}
}
void waiting(object ob, object me)
{	
	if(!ob || !living(me)) return;
	command("nod "+me->query("id"));
	command("say �ã����Ǿ�����������������ɡ�");
	ob->set_temp("wait_target", 1);
	me->set_temp("wait_target", 1);
	remove_call_out("wait_target");
	call_out("wait_target", 30, ob, me);
	return; 
}
void do_back(object me)
{
	me->delete_temp("wait_target");
	me->delete_temp("start_place");
	me->delete_temp("place");
	me->delete_temp("dest");
	message_vision("$Nת��ɽ�𣬼�������Ͳ����ˡ�\n", me);
	me->move("/d/xingxiu/riyuedong1");  
	message_vision("$N����ææ�����˹�����\n", me);
	remove_call_out("del_temp");
	call_out("del_temp", 300, me);		 
}
void del_temp(object me) {me->delete_temp("job_asked");}

int wait_target(object ob, object me)
{
	object obj;
	if(!objectp(present(me, environment(ob))))
	{
		message_vision("$N˵����Ү���Ǽһ���ô�����ˣ�\n", ob);
		remove_call_out("do_back");
		do_back(ob);
		return 1;
	}
	if(!objectp(ob = present("anran zi", environment(me))))
	{
		tell_object(me,"�㷢����Ȼ�Ӳ����ˣ�ֻ�û������ת���뿪��\n");
		tell_room(environment(me),me->name()+"ͻȻһ��ãȻ�ı��飬��������Ҫ�뿪�ˡ�\n", ({ me }));
		me->delete_temp("xx_job2");
		me->clear_condition("xx_task2");
		me->delete_temp("wait_target");
		return 1;
	}
	obj = new("/d/xingxiu/npc/shangdui");
	obj->move(environment(me)); 
	obj->set("arg", ob->query_temp("dest"));
	message_vision(HIY"\nֻ��һ�����շ�����������һֻ�����̶ӳ�������ǰ��\n\n"NOR, ob);
	tell_object(me,"�������ڳ����ˣ�\n"); 
	message_vision(HIY"$N����$n����������������(qiang)�̶ӣ������Ը������ˣ�\n"NOR, ob, me); 
	message_vision("˵��$N�ͳ���ǰȥ���ͼ���������ʦ��׷���ˡ�\n", ob);
	remove_call_out("do_back");
	do_back(ob);
	me->delete_temp("wait_target");
	me->set_temp("rob_start", 1);
}
