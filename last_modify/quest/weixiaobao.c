// /quest/wei.c
//last modified by sega ,ȡ��Ǯ������
// Modified by Zeratul Jan 5 2001

inherit NPC;
inherit F_SKILL;
#include <ansi.h>;
#include </quest/quest.h>

int time_period(int timep,object me);
void create()
{
	set_name("ΤС��", ({ "wei xiaobao", "wei", "xiaobao" }));
	set("title", HIC"�������Զ�󽫾�"HIY"һ��¹����"NOR);
	set("nickname", HIW"С����"NOR);
	set("gender", "����");
	set("age", 18);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("per", 28);
	set("long", 
"��λ���꽫��ͷ���춥�ӣ�������ӣ�ü����Ц����߯��
�⣬������ҡ���ȣ��������֮�������ֵ��ϴ󵶣�ٲȻ��
��֮��������Τ��С����Ҳ�����㿴��������������������
���Ц������ѧ����Ϸ���вܲٵ�ģ�������ʱ�̲�ס�ո�
Ȥ����һ�䣺������Ϊ�η�Ц����\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);

	set_skill("force", 20);
	set_skill("parry", 20);
	set_skill("hand", 20);
	set_skill("dodge", 20);
	set_skill("shenxing-baibian", 20);
	set_skill("yunlong-shengong", 20);
	set_skill("qianye-shou", 90);

	map_skill("force", "yunlong-shengong");
	map_skill("parry", "qianye-shou");
	map_skill("dodge", "shenxing-baibian");
	map_skill("hand", "qianye-shou");
	prepare_skill("hand", "qianye-shou");
	set("inquiry", ([
			"��ػ�" : "���ң�\n",
			"�½���" : "������ʦ����\n",
			"éʮ��" : "������ʮ�˸�ë�氡������û���ɣ�\n",
			"��������": "��������ò���ʦ����\n",
			"Τ����" : "�������������Խ��Խ���ˣ����ڸ���������ˣ�\n",
			"����"	 : "�����һʵ�ʦ����\n",
			"С����" : "�����һʵ�ʦ����\n",
			"С����" : "������������ˣ������£�\n",
			"����"	 : "��������ý��Ȣ�Ĵ����ţ�\n",
			"˫��"	 : "����ʶ�����󹦸�ɣ��׸������\n",
			"����"	 : "������������ô�������Ϻ鸣���죬���޸����죡\n",
			"����"	 : "������������ô�������Ϻ鸣���죬���޸����죡\n",
			"����"	 : "������������ô�������Ϻ鸣���죬���޸����죡\n",
			"�彣��" : "������������ô�������Ϻ鸣���죬���޸����죡\n",
			"��������": "���ɧ��Ƥ���׺񲻼�˫������ò�������桢�书��
�����������ɲ������������洿�Ʋ����彣��������˹�Ĳ������ᣬ
����һ��֮���ߣ����������������ѣ�\n",
	]) );

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}

void init()
{
	add_action("give_quest", "quest");
}

int give_quest()
{
	mapping quest;
	object me = this_player();
	int combatexp, timep, factor;

	combatexp = (int) (me->query("combat_exp"));
	if(combatexp<1000)
	{
		tell_object(me,"ΤС���������һ���������������裬������û����������\n");
		return 1;
	}
	if(combatexp>100000000)
	{
		tell_object(me,"ΤС���������һ���������������裬�����ү��æ���أ�û�����㣡��\n");
		return 1;
	}

// Let's see if this player still carries an un-expired task
	if( me->query("quest/wei") && !me->query( "quest/wei/finished" ) )
	{
		if( ((int) me->query("quest/wei/time")) > time() )
		{
			tell_object(me,"ΤС������Ц����˵�㲻�аɣ�����������\n");
			return 1;
		}
		else
		{
			tell_object(me,"ΤС��������̾��һ������û��ϵȥ�ñ��Ҳ�ɡ�\n");
			me->add("qi",-(int)(me->query("qi")/5));
			quest_failed( me, "wei" );
		}
	}

	factor=10;
	quest = __DIR__"qwlist"->query_quest();
	timep = random(60) * 10 + 300;

	time_period(timep, me);
	tell_object(me,"�ҵ���"+quest["quest"]+HIW"�����ң��һ�ú�л�㡣\n" NOR);

	quest["quest_type"] = "Ѱ";
	quest["exp_bonus"] = 10 + random(10);
	quest["pot_bonus"] = 2 + random(4);
	quest["score"] = 2 + random(4);

	me->set("quest/wei", quest);
	me->set("quest/wei/time", (int)time()+timep);
	me->set("quest/wei/factor",factor);
	me->delete( "quest/wei/finished" );
//add by sega 4/11/2000
//	me->set("last_quest_time",(int)time());
//	me->add("quests/require", 1);
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60; t /= 60;
	m = t % 60; t /= 60;
	h = t % 24; t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	tell_object(me,HIW "ΤС���Ը�����������" + time + "��");
	return 1;
}

int accept_object(object who, object ob)
{
	int bonus, exp, pot, score, factor, balance, require, abandon;
	mapping quest;

	if (ob->query("money_id"))
	{
		tell_object(who,"ΤС��Ц�������ҿɾͲ������ˡ�\n");
		return 1;
	}
	if ( ( !quest = who->query( "quest/wei" ) ) || who->query( "quest/wei/finished" ) )
	{
		tell_object( who,"ΤС��˵�����ⲻ������Ҫ�ġ�\n" );
		return 0;
	}

	if( ob->query("name") != quest["quest"])
	{
		tell_object(who,"ΤС��˵��������ʲô�������ҽ����������������Ū�ң���\n");
		return 0;
	}
	if ((int) who->query("quest/wei/time") < time() )
	{
		tell_object(who,"ΤС��˵�������Ƿ����û��ָ��ʱ�������\n");
		quest_failed( who, "wei" );
		destruct(ob);
		return 0;
	}
	else
	{
		tell_object(who,"ΤС������ص�ͷ˵����������ʹ��ò���\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=who->query("quest/wei/factor");
		destruct(ob);

		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus = bonus + pot;
//		if( bonus > 300) bonus = 300;
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
		bonus = (int) who->query("score");
		bonus += score;
		who->set("score", bonus);
		tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
			+ "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܣ�"
			+ chinese_number(score)+"�㽭��������\n"NOR);
		tell_object(who,HIW"��ϲ�����һ����ʹ��\n"NOR);

		quest_finished( who, "wei" );
		return 0;
	}
	return 1;
}
