// hong.c �鰲ͨ

#include <ansi.h>;
#include <localtime.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
inherit F_MANAGER;
string ask_tool();

void create()
{
	set_name("�鰲ͨ", ({ "hong antong", "hong", "antong" }));
	set("nickname", HIR "�����ɸ�" NOR);
	set("long","��������ϣ����޴��أ����϶����˰����ƣ���ª֮�������������书����������˵�̸֮ɫ��������̽����鰲ͨ��\n");
	set("gender", "����");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 400000);

	set_skill("force", 200);
 	set_skill("dulong-dafa", 200);
	set_skill("dodge", 200);
	set_skill("yixingbu", 300);
	set_skill("hand", 200);
	set_skill("shenlong-bashi", 300);
	set_skill("strike", 200);
	set_skill("huagu-mianzhang", 300);
	set_skill("finger", 200);
	set_skill("yingxiong-sanzhao", 300);
	set_skill("meiren-sanzhao", 300);
	set_skill("hook", 200);
	set_skill("ruyi-hook", 300);
	set_skill("staff", 200);
	set_skill("shenlong-staff", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("literate", 90);
	set_skill("digging", 200);
	set_skill("leg", 200);
	set_skill("jueming-leg", 300);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("leg", "jueming-leg");
	map_skill("finger", "yingxiong-sanzhao");
	map_skill("hand", "shenlong-bashi");
	map_skill("hook", "ruyi-hook");
	map_skill("staff", "shenlong-staff");
	map_skill("parry", "yingxiong-sanzhao");
	prepare_skill("finger", "yingxiong-sanzhao");
	prepare_skill("hand", "shenlong-bashi");
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIM"����"NOR);
	set("party/level", 3);
	create_family("������",1,"����");
	set("count", 1);

	set("inquiry", ([
		"������" : "\nһ�������벻���������̵�(join shenlongjiao)��\n",
		"���"   : "\nһ�������벻���������̵�(join shenlongjiao)��\n",
		"�鰲ͨ" : "\n�㲻������ǲ��ǣ�\n",
		"����"   : "\n�Ҿ��������̽�����\n",
		"�ں�"   : "\n���겻�ϣ������ɸ����������룡������ʥ��\n",
		"���"   : "\n�����ذ����ǵ�Ҫ���ߡ�\n",
		"����"   : "\n�����ذ����ǵ�Ҫ���ߡ�\n",
		"����"   : (: ask_tool :),
		"tool"   : (: ask_tool :),
		"����"   : (: ask_tool :),
		"������" : (: ask_tool :),
		"qiao"   : (: ask_tool :),
	]) );
	set("no_get",1);
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("say ƾ�����ŧˮ��Ҳ����̫��үͷ�϶�����\n") :),
		(: command("say ���ò��ͷ�����������\n") :),
		(: perform_action, "finger.yingxiong" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang3" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 50);
}

int recognize_apprentice(object me)
{
	if( me->query("learnhong")) return 1;
	if ((int)me->query("shen") > -1000)
	{
		command("say ��Խ����Խ��׵������Ե׵ġ�");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
		return 0;
	}
	if( me->query_temp("pending/flatter") )
	{
		command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
		return 0;
	}
	else
	{
		command("say �Һ鰲ͨ�������������ʥ����ô������");
		message_vision("�鰲ͨ΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
		this_player());
		me->set_temp("pending/flatter", 1);
	return 0;
	}
}

int do_flatter(string arg)
{
	if( !this_player()->query_temp("pending/flatter") )
		return 0;
	if( !arg ) return notify_fail("��˵��ʲô��\n");
	this_player()->set_temp("pending/flatter", 0);
	message_vision("$N����˵����" + arg + "\n", this_player());
	if( strsrch(arg, "���겻��") >=0 && (strsrch(arg, "�����ɸ�") >=0 ||
		strsrch(arg, "��������") >=0 || strsrch(arg, "������ʥ") >=0 ))
	{
		command("smile");
		command("say �⻹��ࡣ\n");
		this_player()->set("learnhong", 1);
		command("recruit " + this_player()->query("id"));
	}
	else
	{
		command("say ����˲����ҷ�����������������㣿!");
		this_object()->set_leader(this_player());
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, this_player()); 
	}
	return 1;
}

// ���겻��,�����ɸ�,��������,������ʥ

void die()
{
	message_vision("\n$N��������ף���Ȼ������ɱ���ң�....��˵���������۵������ˡ�\n", this_object());
	::die();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_flatter", "flatter");
	add_action("do_qiecuo","qiecuo");
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))
		{
			set("combat_exp",500000);
			set("qi",10);
			set("jing",10);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "������" NOR )
	{
		command("say �㲻�Ǳ��̽��ڣ�������������");
		return;
	}
	if ((int)ob->query_skill("dulong-dafa",1) < 60 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɣ�");
		return;
	}
	if ((int)ob->query("shen") > -10000 )
	{
		command( "say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}

string ask_tool()
{
	mapping fam; 
	object ob, me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "������")
		return "��λ"+RANK_D->query_respect(me)+ "�뱾��������������֪�˻��Ӻ�̸��";
	if( present("shenlong qiao", me) )
		return "���������ϲ������������ô����Ҫ�ˣ�����̰�����У�";
	if( me->query_skill("digging", 1) <= 30)
		return "�����Ŷ���Ҳûʲô�ã������������˰ɣ�";
	if( query("count") < 1)
		return "����������Ҫ�Ķ����������������ˣ�";
	ob = new(__DIR__"obj/shenlongqiao");
	ob->move(me);
	add("count", -1);
	return "�ðɣ�����һ�������£������ȥ�ɡ�";
}
#include "/kungfu/class/shenlong/shenlong.h"; 

