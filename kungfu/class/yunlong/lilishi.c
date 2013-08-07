// lilishi.c ������

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();
int ask_zhu();
int ask_me();

mixed names = ({
({ "ʷ��ɽ", "������", "������", "�ɻ���","���Ŵ��","ʷ��", }),
({ "ʨ����","������","��Ȼ��","������","��ͨ��","ɳͨ��", }),
({ "�·���","�·�ʩ","ʷ���","������","Ǯ�ཡ","�·���","�·���","�·�ɽ","���ư�","������","����ͬ","�粨��","�˰ٴ�", }),
({ "������","ΤһЦ","����","��ң","Ľ�ݸ�","���˿","������","��Ī��", }),
({ "������","����","������","������","�����","����֮","������", }),
});

void create()
{
	set_name("������", ({ "li lishi", "li" }));
	set("gender", "����");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ���߸����ݵ����ߣ�����������ɫ�����һ\n"
		"��ϡϡ�����ĺ��ӣ�������ɣ�����ӡ����ϵ�\n"
		"�·��������ƣ������������ƣ�����ȥ������˪��\n");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("claw", 50);
	set_skill("hand", 50);
	set_skill("blade", 50);
	set_skill("literate", 50);
	set_skill("wuhu-duanmendao", 50);
	set_skill("yunlong-shengong", 60);
	set_skill("yunlong-shenfa", 60);
	set_skill("yunlong-shou", 50);
	set_skill("yunlong-zhua", 50);
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 10);
	set("chat_chance", 2);
	set("chat_msg", ({
		"������˵��������һ��ð����͵�����ȥ��\n",
		"������ͻȻߺ�ȵ�: ����ܽ������ֻ���ƽ�һ����˭��˭�򰡣�\n",
		"������ͻȻߺ�ȵ�: �����˲�����ֻ���ƽ�һ����˭��˭�򰡣�\n",
		"������ɦ��ɦͷ��˵������ô�õ�������ôû��Ҫ����\n",
		"������ͻȻ˵���������Ž����֣��������ı����ġ�\n",
	}));
	set("inquiry", ([
		"�½���" : "����ܶ����ɲ����װ���\n",
		"��ػ�" : "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" : "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
		"����" : "�����£�\n",
		"�п�" : "�����£�\n",
//		"���帴��" : (: ask_me :),
		"����" : (: ask_zhu :),
		"����ܽ����" : (: ask_zhu :),
		"�����˲���" : (: ask_zhu :),
		"����" : (: ask_weiwang :),
		"��������" : (: ask_weiwang :),
	]) );
	set("party/party_name", HIR"��ػ�"NOR);
	set("party/rank", HIG"��ľ��"NOR"����");
	create_family("������", 2, "����");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	carry_object(__DIR__"obj/tudao")->wield();
	add_money("silver", 20);
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say( "\n������˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}

int ask_zhu()
{
	if (this_player()->query_temp("money_paid"))
	{
		this_player()->delete_temp("money_paid");
		this_player()->set("huanggong\\canenter",1);
		say("������˵���������ڿ���������\n");
		return 1;
	}
	say("������˵����ʲôҲ���Ƚ�Ǯ����\n");
	return 1;
} 

void init()
{
	::init();
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("weiwang")<50)
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
		return 0;
	}
	return 1;
}
/*
int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="li" )
		return 0;
	if(wizardp(ob)) return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �������� (blade)			 - һ����ʦ  90/    \n"+
"  �����Ṧ (dodge)			 - ����似  60/    \n"+
"  �����ڹ� (force)			 - ����似  60/    \n"+
"  �����м� (parry)			 - �������  50/    \n"+
"  ����ȭ�� (unarmed)		       - �������  50/    \n"+
"�������� (yunlong-shenfa)		- ����似  60/    \n"+ 
"���廢���ŵ� (wuhu-duanmendao)	     - һ����ʦ  90/    \n");
	return 1;
}
*/
int ask_me()
{ 
	object ob, me;
	int exp,position;
	string target;
	me = this_player();
	ob = this_object();
	exp = me->query("combat_exp",1);
	if(me->query_condition("gb_mission") ||
		me->query_condition("guanfu_task") ||
		me->query_condition("xx_task") ||
		me->query_condition("xx_task") ||
		me->query_condition("xx_task2") ||
		me->query_condition("dali_songxin"))
	{
		command("say �����ںͽ��������������壬�Ҳ��ܽ���������");
		return 1;
	}
	if(me->query_condition("thd_task2") || me->query_condition("thd_task3"))
	{
		command("say ������ִ����ػ���ľ�õ�����");
		return 1;
	}
/*	if (!me->query_temp("tdh_li") &&
		(me->query_condition("tdh_task_wait")<0))
	{
		command( "say û������������Ҳ��ܽ�����������ػ�һ�����������");
		return 1;
	}
	if (!me->query_temp("tdh_li"))
	{
		command( "say û������������Ҳ��ܽ�����������ػ�һ�����������");
		return 1;
	}
*/
 	if(exp>=850000) position=5;
	else if(exp>=600000) position=4;
	else if(exp>=300000) position=3;
	else if(exp>=150000) position=2;
	else position=1;
	target = names[position-1][random(sizeof(names[position-1]))];
	me->set_temp("tdh_target", target);
	me->apply_condition("tdh_task1",30); 
	me->clear_condition("tdh_task_wait");
	command( "say "+target+"���Ͷ����͢��ɱ�һ����ֵܣ���ȥ�Ѵ�������ͷ�������Լ����飡");
	if(!present("qingmu ling", me))
	{
		new(__DIR__"qml")->move(me);
		message_vision("��������һö��ľ�����$N��\n", me);
		return 1;
	}
	return 1;
}
int accept_object(object who, object ob,object me)
{
/*
	if (!who->query("tdh_pass")) return 0;
	if (ob->query("id") != "head" ) return 0;
	if ( !who->query_temp("tdh_target")) return 0; 
*/
	if (ob->query("money_id") && ob->value() >= 10000) 
	{
		message_vision("\n��������$NһҾ����˵������λ�͹٣�Ҫʲô����˵��\n",this_player());
		who->set_temp("money_paid",1);
		return 1;
	}
	if (who->query_temp("tdh_target") && 
		(who->query_condition("tdh_task1")<0))
	{
		command("say �������ˣ��Ѿ�����Ϊ�����ֵܱ����ˡ�");
		return 0;
	}
	if ( ob->query("victim_name") != who->query_temp("tdh_target")+"���׼�")
	{
		command( "say ��ػ��Թ������������ɱ�޹��أ��´���Ҫ��Υ������Ҿ���������");
		return 0;
	}
	if ( ob->query("victim_user") )
	{
		command("say " + RANK_D->query_rude(who) + "�������ף�");
		return 0;
	}
	if ( ob->query("kill_by") != who)
	{
		command( "say ��ػ�ȫ�Ƕ������صĺ��ܣ�������ð�������˵Ĺ����أ�");
		return 0;
	}
	command("say �������ж�����ʹ�����ֵܴ��ñ��������ģ�");
	who->add("tdh_job",2);
	who->clear_condition("tdh_task1");
	who->delete_temp("tdh_target");
	who->deltet_temp("tdh_li");
	call_out("destroying", 1, ob);
	call_out("ok", 1, who);
	return 1;
} 

void destroying(object obj)
{
	destruct(obj);
	return;
}
#include "tiandihui.h";
