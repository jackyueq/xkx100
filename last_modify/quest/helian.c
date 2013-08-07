// /quest/helian.c
// Modified by Zeratul Jan 5 2001

inherit NPC;
inherit F_SKILL;
#include <ansi.h>;
#include </quest/quest.h>

int time_period(int timep,object me);
void create()
{
	set_name("��������", ({ "helian tieshu", "helian", "tieshu" }));
	set("title", HIY"���Ĺ������󽫾�"HIM"����һƷ��"HIR"�ܹ�"NOR);
	set("gender", "����");
	set("age", 35);
	set("str", 25);
	set("dex", 26);
	set("per", 16);
	set("long", "���������ۣ���ʮ��������ͣ�ӥ���ǡ������롣\n");

	set("combat_exp", 500000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("max_qi",2500);
	set("max_jing",1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 200);

	set_skill("claw", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 40);
	set_skill("jiuyin-baiguzhao", 90);
	set_skill("bibo-shengong", 90);
	set_skill("lingxu-bu", 90);

	map_skill("force", "bibo-shengong");
	map_skill("parry", "luoying-shenjian");
	map_skill("dodge", "lingxu-bu");
	map_skill("claw", "jiuyin-baiguzhao");
	prepare_skill("claw", "jiuyin-baiguzhao");
	set("inquiry", ([
		"һƷ��": "һƷ�þ���Ҫ����ԭ�������ԣ�\n",
	]) );

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}

int accept_fight(object me)
{
	command("say �����һƷ����Ұ����Ҫ���ˣ�");
	return 0;
}

void init()
{
	add_action("give_quest", "quest");
	add_action( "cancle_quest", "cancle" );	
}

int cancle_quest()
{
	object me = this_player();
	
	if ( !me->query( "quest/helian" ) || me->query( "quest/helian/finished" ) )
		return notify_fail( "ʲô��\n" );
	if ( me->query( "quest/helian/lock" ) )
		return notify_fail( "���Ѿ�ȡ�������ˣ�\n" );
	switch ( random(3) )
	{
		case 0 :
			lock_quest( me, "helian", "wei" ); 
			tell_object( me, "��������ŭ����ΤС���Ǽһ���Ļ�����ɣ�������ȥ����\n" );
			break;
		case 1 :
			lock_quest( me, "helian", "book" );
			tell_object( me, "��������˵�������������Ҳ���ܰ��������Ҽ������飬�ͱ�����������ˡ�\n" );
			break;
		case 2 :
			lock_quest( me, "helian", "betrayer" );		
			tell_object( me, "��������˵����Ҳ�ã���ͻر��������ͽ��˳������Ӵ�̽һ����ԭ���ֵ���Ϣ��\n" );
			break;
	}
	return 1;
}

int give_quest()
{
	mapping quest ;
	object me = this_player();
	int j, combatexp, timep, factor;
	int *levels = ({
		1000,
		1500,
		2000,
		3000,
		5000,
		8000,
		10000,
		13000,
		17000,
		22000,
		30000,
		45000,
		60000,
		80000,
		100000,
		200000,
		350000,
		600000,
		1000000,
		2000000,
		5000000,
		100000000
	});
	int *expright = ({
		4,
		6,
		8,
		12,
		16,
		20,
		24,
		30,
		40,
		50,
		60,
		70,
		80,
		100,
		120,
		140,
		160,
		180,
		200,
		250,
		300,
		400
	});
	int *potright = ({
		2,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12,
		13,
		14,
		15,
		16,
		19,
		25,
		26,
		30,
		31,
		32
	});
	combatexp = (int) (me->query("combat_exp"));
	if( !(int)me->query("yipin/joined"))
	{
		tell_object(me,"���������������һ���������㲻�Ǳ��õİɣ������ʲô���֣���\n");
	     return 1;
	}
	//Modified by zeratul 2000-12-25
	if(combatexp<10000)
	{
		tell_object(me,"���������������һ������������С��ɫ����Ͷ��һƷ�ã���\n");
	     return 1;
	}

	if ( islocked( me, "helian" ) )
		return 1;
	
	if( me->query("quest/helian") && !me->query( "quest/helian/finished" ) )	
	{
		if( ((int) me->query("/quest/helian/time")) >  time() )
//		if( ((int) me->query("last_quest_time")+30) > time() )
		{
			tell_object(me,"����������������һЦ����������������ˣ�\n");
//			tell_object(me,"���������ܲ�м�������һ��˵������Ҫ��û���£����õ�����ó������ñ����ȥ��\n");
			return 1;
		}
		else
		{
			tell_object( me, "��������������̾��һ�����������Ҿ��ٸ���һ�λ���ɡ�\n" );
			quest_failed( me, "helian" );
/*
			switch ( random(3) )
			{
				case 0 :
					lock_quest( me, "helian", "wei" ); 
					tell_object( me, "��������˵���������ﲻҪ�㣬ȥΤС�������ɡ�\n" );
					break;
				case 1 :
					lock_quest( me, "helian", "book" );
					tell_object( me, "��������˵������������è�İ�ʽֻ�����£��������Ҽ����ؼ�ѧ����Ҫ����\n" );
					break;
				case 2 :
					lock_quest( me, "helian", "betrayer" );		
					tell_object( me, "��������˵������������ĥĥ������ô�У���ȥɱ������ͽ��������������\n" );
					break;
			}*/
			
//			tell_object(me,"���������ܲ�м�������һ��˵������Ҫ��û���£��ͱ���������ү��\n");
			me->add("qi",-(int)(me->query("qi")/10));
//			return 1;
		}
	}
	factor=10;
	for (j=0; j<sizeof(levels); j++)
	{
		if (levels[j] > combatexp) break;
	}
	while (1 == 1)
	{
		quest = __DIR__"qslist"->query_quest();
		quest["quest_type"] = "ɱ";
		quest["exp_bonus"] = expright[j];
		quest["pot_bonus"] = potright[j];
		quest["score"] = potright[j];
		me->set("quest/helian", quest);
		if (quest["shen"] < 0) continue;
		if (combatexp < quest["exp"]*3 && combatexp*3 > quest["exp"])
			break;
		if (combatexp > 1000000 && quest["exp"] > 300000) break;
	}
	timep = random(60) * 10 + 600;

	time_period(timep, me);
	tell_object(me,"�����Ұѡ�"+quest["quest"]+"������ɱ�ˣ�����Щ�������ܰ�һƷ����ô�ţ���\n" NOR);

	me->set("/quest/helian/time", (int)time()+timep);
	me->set("/quest/helian/factor",factor);
	me->delete( "quest/helian/finished" );
//	me->set("last_quest_time",(int)time());
//	me->add("quests/require", 1);
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;	     t /= 60;
	m = t % 60;	     t /= 60;
	h = t % 24;	     t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	tell_object(me,HIW "���������Ը�����������" + time + "��");
	return 1;
}

int accept_object(object who, object ob)
{
	int bonus, exp, pot, score, factor, balance, require, abandon;
	mapping quest;

	if (ob->query("money_id"))
/*	{
		if(!who->query("quest"))
		{*/
			tell_object(who,"��������Ц�������ҿɾͲ������ˡ�\n");
			return 1;
/*		}
		require = who->query("quests/require");
		abandon = who->query("quests/abandon");
		if(require == 0) require = 1;
		if(abandon == 0) abandon = 1;
		balance = (int) (abandon/(require-abandon+1));
		if(balance > 10 && ob->value() < 1000000)
		{
			tell_object(who,"��������һ˫�������۾�ֱ�����㣺��ʵ�ڲ����������ʮ����ɲ���һ�����㲻�������ε�������һ����ΥԼ������\n");
			return 1;
		}
		if(balance > 5 && ob->value() < 100000)
		{
			tell_object(who,"��������һ˫�������۾�ֱ�����㣺�����������̫�Ҫ����������ʮ���ƽ�����\n");
			return 1;
		}
		if(balance > 3 && ob->value() < 10000)
		{
			tell_object(who,"��������һ˫�������۾�ֱ�����㣺���������ö������٣���Ҫ����������һ���ƽ���ҡ�\n");
			return 1;
		}
		if( ob->value() < 5000)
		{
			tell_object(who,"��������һ˫�������۾�ֱ�����㣺���Ǯ�ɲ������ǵĿ�����\n");
			return 1;
		}
		else
		{
tell_object(who,"��������Ц�����Ǻã������������������ڡ����ֲ�ʹ�����Ұɣ�\n");
			who->set("quest",0);
			who->add("quests/abandon", 1);
			return 1;
		}
	}

	if(!(quest =  who->query("quest")))
	{
	     tell_object(who,"��������˵�����ⲻ������Ҫ�ġ�\n");
	     return 0;
	}

	if( ob->query("name") != quest["quest"])
	{
		tell_object(who,"��������˵��������ʲô�������ҽ����Ĳ�ʹ���������Ū����\n");
		return 0;
	}

	if ((int) who->query("task_time") < time() )
	{
		tell_object(who,"��������˵�������Ƿ����û����ָ����ʱ���ڻ�����\n");
		destruct(ob);
		return 0;
	}
	else
	{
		tell_object(who,"������������ص�ͷ˵����������ʹ��û�����\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=who->query("quest_factor");
		destruct(ob);

		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) who->query("combat_exp");
		bonus += (int) (exp/4);
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus = bonus + (int) (pot/2);
//		if( bonus > 300) bonus = 300;
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
		bonus = (int) who->query("score");
		bonus += score;
		who->set("score", bonus);
		tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
			+ "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܣ�"
			+ chinese_number(score)+"�㽭��������\n"NOR);
		who->set("quest", 0 );
		tell_object(who,HIW"��ϲ�����һ����ʹ��\n"NOR);
		return 0;
	}
	return 1;*/
}
