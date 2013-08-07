// zhu.c ����

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
#include "exam.h"
#include <localtime.h>
int give_quest(object ob);
int now_time();
string ask_buy();
// int ask_degree();

string * degree_desc = ({
BLU "��ä" NOR, BLU "ͯ��" NOR, BLU "���" NOR, CYN "����" NOR, 
CYN "��Ԫ" NOR, CYN "��ʿ" NOR, CYN "��Ԫ" NOR, GRN "��ʿ" NOR, 
GRN "̽��" NOR, GRN "����" NOR, GRN "״Ԫ" NOR, HIY "����Ժʿ" NOR, 
HIY "����˶ʿ" NOR, HIY "���ֲ�ʿ" NOR, HIY "����Ժ����" NOR, 
HIR "����ʿ" NOR, HIR "ѧʿ" NOR, HIR "�ڸ��ѧʿ" NOR, 
HIR "�ڸ��׸�" NOR, MAG "��ѧ����ʦ" NOR, HIW "ʥ��" NOR,
});
string * rank = ({
BLU"��ä"NOR,     BLU"ͯ��"NOR,     BLU"���"NOR,     CYN"����"NOR,
CYN"��Ԫ"NOR,     CYN"��ʿ"NOR,     CYN"��Ԫ"NOR,     GRN"��ʿ"NOR,
GRN"̽��"NOR,     GRN"����"NOR,     GRN"״Ԫ"NOR,     HIY"����Ժʿ"NOR,
HIY"����˶ʿ"NOR, HIY"���ֲ�ʿ"NOR, HIY"���ֱ���"NOR, HIR"����ʿ"NOR,
HIR"ѧʿ"NOR,     HIR"��ѧʿ"NOR,   HIR"�ڸ��׸�"NOR, MAG"����ʦ"NOR,
HIW"ʥ��"NOR,
});
int * nlvl = ({
0,10,20,30,40,50,60,70,80,90,100,
120,140,160,180,200,220,240,260,280,300,
});

void create()
{
	set_name("����", ({ "zhu xi", "zhu" }));
	set("long",
"����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�\n");
	set("gender", "����");
	set("age", 65);
	set("no_get", 1);
	set("gongming/lvl", 20);
	set("gongming/rank","ʥ��");
	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	set("inquiry", ([
//		"ѧλ" : (:ask_degree:),
		"ѧλ" : "ʮ�꺮����һ��������������������￼ȡѧλ(exam)��",
		"����" : (:ask_buy:),
		"��"   : "�����鵽��ʱ�����١�",
		"����" : "�裿�㲻���ҵ��������㣿�ߣ�",
	]));
	set("vendor_goods", ({
		BOOK_DIR"lbook1",
		BOOK_DIR"lbook2",
		BOOK_DIR"lbook3",
	}));
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"����˵��������֮�£�Ī������������֮����Ī��������\n",
		"����˵���������ˣ�С�������ɣ����������δ������֮��\n",
		"����˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
		"����˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
	}) );
}
int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0;
	ob->add_temp("mark/��", -1);
	return 1;
}
int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
		who->add_temp("mark/��", ob->value() / 50);
	if( me->query_skill("literate", 1) > 19){
		tell_object(me,"����������һ�����Ļ�֪ʶ,Ҳ�����Լ����������ˡ�\n");
		return 1;
		}
	return 1;
	}
}
string ask_buy()
{
	return "������в��ٶ����˱ض�����Ӵ��\n";
}

void init()
{
	::init();
	add_action("do_exam","exam");
	add_action("do_answer","answer");
	add_action("do_list","list");
	if(this_player()->query_skill("literate", 1) > 19)
		add_action("do_buy", "buy");
	return;
}
/*
int ask_degree()
{
	int lv;
	object ob = this_player();
	lv = (ob->query_skill("literate") / 5);
	if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
	if (lv < 3) 
	{
		command("say "+ob->query("name")+"�����ǵ�īˮҲ����˼�ʣ��������ѧλ�����ˣ�\n");
		ob->set("degree",degree_desc[lv]);
		return 1;
	}
	if (lv < 10) 
	{
		command("say "+ob->query("name")+"������������ǰ;���ܸ�������ѧλ���㣬�����ú�Ŭ����\n");
		ob->set("degree",degree_desc[lv]);
		return 1;
	}
	else
	{
		command("say ��Ȼ�ǳ���������ǰ�˰���"+ob->query("name")+"���ҷǳ��������л���Ϊ����ѧλ��\n");
		ob->set("degree",degree_desc[lv]);
		return 1;
	}
}
*/
int do_exam()
{
	object ob = this_player();
	int level;
	string rank;

	if(!ob||environment(ob)!=environment()) return 0;
	level=ob->query("gongming/lvl");

	if(level)
	{
		rank=ob->query("gongming/rank");
		if (level>=query("gongming/lvl"))
			return notify_fail("���侪�ȵ���"+rank+"���ˣ���Ҫ����Ц�ˡ�\n");
	}
	if(ob->query_skill("literate",1)<10 ||
		ob->query_skill("literate",1) < nlvl[level+1])
		return notify_fail("����ҡͷ����������Щ�������ɡ�\n");
	if(now_time()==ob->query("gongming/last_check"))
		return notify_fail("����������һ�۵������������ɣ�\n");
	if(ob->query_temp("gongming/answer"))
		return notify_fail("����ָ����������⻹û�ش�ɣ�\n");
	give_quest(ob);
	return 1;
}
int give_quest(object ob)
{ 
	mapping quest;
	string *text,word,pass;
	int i;

	quest=exam[random(sizeof(exam))];
	text=quest["text"];
	i=random(sizeof(text));
	if (random(2)==1)
	{
		if (i!=0)
		{
			word=text[i-1];
			pass="ǰһ��";
		}
		else
		{
			word=quest["author"];
			pass="����";
		}
	}
	else
	{
		if (i!=(sizeof(text)-1))
		{
			word=text[i+1];
			pass="��һ��";
		}
		else
		{
			word=quest["title"];
			pass="��Ŀ";
		}
	}
	ob->set_temp("gongming/answer", word);
	ob->set_temp("gongming/time", time()); 
	if(!ob->query_temp("gongming/count")) ob->set_temp("gongming/count",1);
	else ob->add_temp("gongming/count", 1);
	command("say "+text[i]+"... ...����"+pass+"�ǣ���ش�(answer)��");
	return 1;
}
int do_answer(string arg)
{
	object ob=this_player();
	int lvl;

	lvl = ob->query("gongming/lvl");
	if (!ob->query_temp("gongming/answer"))
		return notify_fail("����Ц�����ҿɻ�û���⣬���˵Щʲô��\n");
	if (!arg)
		return notify_fail("����Ц����������ٻش𣬱𼱡�\n");
	message_vision(HIC"$NӦ�������"+arg+"��\n"NOR, ob);
	if (arg==ob->query_temp("gongming/answer") || wizardp(ob))
	{
		command("nod");
		ob->delete_temp("gongming/answer");
		if (ob->query_temp("gongming/count") < lvl)
		{
//			give_quest(ob);
			remove_call_out("give_quest");
			call_out("give_quest", 2, ob);
			return 1;
		}
		else
		{
			lvl++;
			if(lvl < 10)
				message("channel:chat",HIR"��ϲ�������䣺������"+ob->query("name")+"����"+rank[lvl]+HIR"����ʦ���ǻƼף���\n"NOR, users());
			else
				message("channel:chat",HIY"��ϲ�������䣺������"+ob->query("name")+"����"+rank[lvl]+HIY"������\n"NOR, users());
			ob->set("gongming/rank",rank[lvl]);
			ob->set("gongming/lvl", lvl);
			ob->set("degree", rank[lvl]);
			ob->delete_temp("gongming");
			return 1;
		}
	}
	command("shake");
	command("say ��Ҫ���ģ�����������");
	ob->delete_temp("gongming/answer");
	if(!wizardp(ob)) ob->set("gongming/last_check", now_time());
	return 1;
}
int now_time()
{
	int i;
	object ob=this_player();
	mixed *local;

	local = localtime(time()*60);
	i=local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0);
	return i;
}

