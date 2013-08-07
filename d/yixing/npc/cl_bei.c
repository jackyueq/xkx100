// /d/yixing/npc/cl_bei.c ����ʯ
// Last Modified by winder on Jul. 12 2002

inherit NPC;

#include <ansi.h>
#include <localtime.h>

string ask_job();
string ask_cure();
string ask_salary();

void create()
{
	set_name("����ʯ", ({ "bei haishi", "bei" }));
	set("nickname", "���ֳɴ�");
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "�ܹ�");
	set("long", 
		"����һ�������������ˣ�����ȥ��ɫ�԰ף�˵������������\n"
		"����ͣ�Ŀ����ţ��������ز�һ�㡣\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 40);
	set("combat_exp", 200000);
	set("score", 8000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("cuff",  120);
/*
	set_skill("ding-force",  100);
	set_skill("wuxingbu",   100);
	set_skill("wuxing-quan", 120);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff",  "wuxing-quan");
	map_skill("parry", "wuxing-quan");

	prepare_skill("cuff", "wuxing-quan");
*/
	set("inquiry", ([
		"���ְ�" : "���ְ�ľ������������ܹܡ�",
		"���" : "��ȥ�ʰ����ɡ�",
		"����" : (: ask_job :),
		"job"   : (: ask_job :),
		"�书" : "�������˼ҵ��书����ǿ���ˣ��㻹�������ѧ�ɡ�",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
		"����" : (: ask_cure :),
		"cure" : (: ask_cure :),
		"���" : (: ask_salary :),
		"salary" : (: ask_salary :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

string ask_cure()
{
	object ling, me = this_player();
	string myfam;

	myfam = (string)query("party/party_name");
	if( (string)me->query("party/party_name") != myfam )
		return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";  

	if( time() < (int)me->query("bangs/curetime") + 60 )
		return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";

	if( !(ling = present("bang ling", me)) )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

	if( (string)ling->query("owner") != me->query("id") )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

	if( (int)ling->query("score") < 10 )
		return RANK_D->query_rude(me) + "��Ϊ���г�������֪���̺ô���";

	if( (int)me->query("eff_qi") * 10 > (int)me->query("max_qi") * 8 )
		return "�˲��صĻ���������������ˡ�";

	command("nod");
	ling->add("score", -2);
	me->set("bangs/curetime", time());
	message_vision("$N��һһ����ҩ�ݸ�$n��\n", this_object(), me);
	message_vision("$NС������ذ�һ����ҩ�����˿��ϣ�ֻ�����ƴ�Ϊ��ת����ɫ�������ö��ˡ�\n", me);
	me->receive_curing("qi", 50);
	return "��һ����ҩ��û���ˡ�";
}

string ask_salary()
{
	object wage, ling, me = this_player();
	string myfam;
	int amount;

	myfam = (string)query("party/party_name");
	if( (string)me->query("party/party_name") != myfam )
		return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

//	if( me->query_temp("bangs/pos") )
	if( me->query("bangs/pos") )
		return RANK_D->query_respect(me) + "����һ��֮���ˣ������Ƕ��������͡�";

	if( !(ling = present("bang ling", me)) )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

	if( (string)ling->query("owner") != me->query("id") )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

	if( time() < (int)me->query("bangs/salarytime") + 1800 )
		return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";

	if( (amount = (int)ling->query("score")) < 30 )
		return RANK_D->query_rude(me) + "������ֺܲ�ѽ������Щ�����ڸ���";

	command("nod");
	me->set("bangs/salarytime", time());

	wage = new("/clone/money/silver");
	wage->set_amount(amount);
	ling->delete("score");
	wage->move(me);
	message_vision("$Nת���ó�һ������ݸ�$n��\n", this_object(), me);
	return "��������ֲ�����ݺ������ȥ���ɡ�";
}

#include "guanjia.h";
