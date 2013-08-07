// /d/yixing/npc/cl_situ.c ˾ͽ��
// Last Modified by winder on Jul. 12 2002

#include <changle.h>

#define OFFICE (BANGS+"clxiaoting")

inherit NPC;

#include <ansi.h>
#include <localtime.h>

#include D_BEAUTY


int ask_join();
string ask_job();
string ask_skills();
string ask_position();
string ask_life();

string *positions = ({
	"������",
	"ʨ����",
	"������",
});

void create()
{
	set_name("˾ͽ��", ({ "situ heng", "situ" }));
	set("nickname", HIY"��צ����"NOR);
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "����");
	set("long","����һ����ĸߴ󣬵���Щ���ݵ������ˣ�˫�ۺܳ�����ץ������������Ҳ����һ����\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 50);
	set("int", 28);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 800);
	set("max_neili", 1000);
	set("neili", 1000);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("claw",  120);
	set_skill("strike", 80);
	set_skill("staff", 80);

	set_skill("poison", 80);
/*
	set_skill("huagong-dafa", 120);
	set_skill("zhaixinggong", 120);
	set_skill("sanyin-zhua",  120);
	set_skill("chousui-zhang", 80);
	set_skill("tianshan-zhang", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "sanyin-zhua");
	map_skill("claw",  "sanyin-zhua");
	map_skill("strike", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("claw",  "sanyin-zhua");
*/
	set("inquiry", ([
		"���" : (: ask_join :),
		"join" : (: ask_join :),
		"����" : (: ask_job :),
		"job" : (: ask_job :),
		"�书" : (: ask_skills :),
		"skills" : (: ask_skills :),
		"���ְ�" : "���ְ����𽭺���ָ�տɴ���������������",
		"������" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
		"�����" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
		"����ʯ" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
		"����" : (: ask_position :),
		"position" : (: ask_position :),
		"����" : (: ask_life :),
		"life" : (: ask_life :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
//	carry_object("/clone/weapon/feizhua")->wield();
}

string ask_job()
{
	object ob = this_player();

	if( (string)ob->query("party/party_name") != HIC"���ְ�"NOR )
		return RANK_D->query_rude(ob) + "Ī����������Ұ�����ܰɡ�";

	return "�йؾ�������������ȥ�ʱ�������";
}

string ask_position()
{
	object *obj, ling, wage, me = this_player();
	string *poss, pos, myfam;
	int i, score, bonus, period, record;

	if( is_fighting() )
		return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

	myfam = (string)query("party/party_name");
	if( (string)me->query("party/party_name") != query("party/party_name") )
		return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

	if( !(ling = present("bang ling", me)) )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

	if( (string)ling->query("owner") != me->query("id") )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

	if( stringp(pos = me->query_temp("bangs/pos")) ) {
		period = uptime() - (int)me->query_temp("bangs/pos_time");
		if( period < 1800 )
			return "������ô�̵�ʱ���ڲ������ж����Ϊ���Ժ����ð���Ѳ��" + pos + "�ɡ�";

		score = (int)ling->query("score");
		bonus = score - (int)me->query_temp("bangs/pos_score");
		me->set_temp("bangs/pos_score", score);
		me->set_temp("bangs/pos_time", uptime());

		if( bonus < period / 10 )
			return pos + "������ֺܲ�ѽ������Щ�����ڸ���";

		command("nod");
//	      bonus *= (score / 1000 + 1);
//	      This line is the old code, if player stays on line and cumulates the
//	      score, it can be very big, for example, online 15 hours can get about 20k score
//	      20000 / 1000 + 1 = 21, if he only ask xiang zhu one
//	      bonus = (20000 - 500) * 21 = 409500, and later bonus /= 3, add_exp = bonus +random(bonus)
//	      So a player can get 200k exp like this.

//	      So instead of multiply, add the bonus, so it won't increase by factors. 
				bonus += (score / 50 +1);
		wage = new("/clone/money/silver");
		record = bonus + random(bonus);
		wage->set_amount(record);
		wage->move(me);
		message_vision("$Nת���ó�һ������ݸ�$n��\n", this_object(), me);
		log_file("test/BangPos", sprintf("%s��%sʱ���Ͻ%s%s����%s������\n", me->query("name"), ctime(time()), myfam, pos, chinese_number(record)));

		bonus /= 3;
		me->add("combat_exp", bonus + random(bonus));
		return pos + "����Ĺ�Ͻ�£�������ֲ���";
	}

	if( (int)me->query("combat_exp") < 10000 )
		return RANK_D->query_rude(me) + "������δ��̫���˰ɡ�";

	if( (score = (int)ling->query("score")) < 500 )
		return "��ƾ����㹦��Ҳ��������֮λ��";

	obj = users();
	poss = positions;
	for(i = 0; i < sizeof(obj); i++) {
		if( obj[i]->query("party/party_name") == myfam ) {
		if( stringp(pos = obj[i]->query_temp("bangs/pos")) )
			poss -= ({pos});
		}
	}

	if( !sizeof(poss) )
		return "�������е�����֮λ������ռ�š�";

	pos = poss[random(sizeof(poss))];
	me->set_temp("bangs/pos", pos);
	me->set_temp("bangs/pos_time", uptime());
	me->set_temp("bangs/pos_score", score);
	
	me->set_temp("apply/short",
   ({ HIR + myfam + pos + "����"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
	log_file("test/BangPos", sprintf("%s��%sʱ����%s%s����\n", me->query("name"), ctime(time()), myfam, pos));
	command("congra");
	return "�Ұ�" + pos + "�и����㣬���Ҫ����������";
}

string ask_life()
{
	object me = this_player();
	string myfam, *beautys, beauty;

	if( is_fighting() )
		return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

	myfam = (string)query("party/party_name");
	if( (string)me->query("party/party_name") != myfam )
		return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

	if( uptime() < (int)query("joytime") + 20 + random(20) ) {
		command("lazy");
		return "�Ϸ�����Դ�û����Ȥ��";
	}

	beautys = keys(info_beauty);
	beauty = beautys[random(sizeof(beautys))];

	command("hehe " + query("id"));
	me->set_temp("bangs/beauty", beauty);
	set("joytime", uptime());
	return "���" + beauty + "��������ô�������Ϸ��⼸�춼û˯�Ⱦ���";
}

int accept_object(object who, object ob)
{
	object ling, room;
	string myfam, beauty;
	int bonus, record;

	myfam = query("party/party_name");
	if( who->query("party/party_name") != myfam ) 
		return notify_fail(name() + "��ŭ�����󵨣���ı������������\n");

	if( !(room = environment()) )
		return notify_fail(name() + "��ŭ�������һ��ܶ���˵�ɣ�\n");

	if( base_name(room) != OFFICE )
		return notify_fail(name() + "��ŭ�������һ��ܶ���˵�ɣ�\n");

	if( !stringp(beauty = who->query_temp("bangs/beauty")) )
		return notify_fail(name() + "��ŭ���������Ϸ��˽�²�������ģ�\n");

	if( !ob->is_character() )
		return notify_fail(name() + "��ŭ���������ö������Լ��ðɣ�\n");

	if( ob->query("gender") != "Ů��" )
		return notify_fail(name() + "��ŭ�����Ϸ������û��Ȥ��\n");

	if( ob->query("name") != beauty )
		return notify_fail(name() + "��ŭ�������Ϸ�Ļ����ǲ�ס��");

	if( userp(ob) )
		return notify_fail(name() + "��ŭ������������Ҹ��˻���������ƭ�Ϸ�");

	if( (int)ob->query("eff_qi")*10 < (int)ob->query("max_qi")*9
	||  (int)ob->query("eff_jing")*10 < (int)ob->query("max_jing")*9 )
		return notify_fail(name() + "��ŭ�����˳�������ӣ��Ϸ���ʲô��Ȥ��");

	command("haha");
	who->delete_temp("bangs/beauty");
	ob->move(this_object());
	call_out("destroy_beauty", 1, ob);
	bonus = info_beauty[beauty] * 100000 / (100000 + (int)who->query("combat_exp"));
	record = bonus + random(bonus);
	who->add("combat_exp", record);
	who->add("shen", -record);
	log_file("test/BangWomen",  sprintf("%-10s��%-20sʱ�Ϲ�%-10s��%-5s�����\n", who->query("name"), ctime(time()), beauty, chinese_number(record)));

	if( ling = present("bang ling", who) ) {
		if( (string)ling->query("owner") == who->query("id") )
			ling->add("score", bonus + random(bonus));
	}

	message_vision("$N˵�����ã��ã��ã�" + myfam + "�������¼�ǧ�����������ְ����Ļ��ģ�",this_object());
	return 1;
}       

void destroy_beauty(object ob)
{
	if( ob )  destruct(ob);
}

#include BANGZHU
