// /quest/shan.c
//last modified by sega 4/13/2000,ȡ��Ǯ�Ĺ���
// Modified by Zeratul Jan 5 2001


inherit NPC;
inherit F_SKILL;
#include <ansi.h>;
#include <quest.h>

int time_period(int timep,object me);
void create()
{
	set_name("����", ({ "shan zheng", "shan", "zheng" }));
	set("nickname", HIB"�����й�"NOR);
	set("age", 63);
	set("str", 25);
	set("dex", 16);
	set("per", 22);
	set("long", 
"����ƽ�������ֻҪ֪����������ʲô������֮�£���Ȼ����
Ҫ�ܡ���������⣬������ͯ�պ׷������֣�����ȴ��ǫ�ͣ�
���ƽ����ϴ�˵�ĳ������顣\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("give_quest", "quest");
	add_action( "cancel_quest", "cancel" );
}

int cancel_quest()
{
	object me = this_player();
	
	if ( !me->query( "quest/shan" ) || me->query( "quest/shan/finished" ) )
		return notify_fail( "ʲô��\n" );
	if ( me->query( "quest/shan/lock" ) )
		return notify_fail( "���Ѿ�ȡ�������ˣ�\n" );
	switch ( random(3) )
	{
		case 0 :
			lock_quest( me, "shan", "wei" ); 
			tell_object( me, "����˵����Ҳ�ã������ȥ����Τ��ү�ɡ�\n" );
			break;
		case 1 :
			lock_quest( me, "shan", "book" );
			tell_object( me, "����˵������Ȼ�㲻ԸΪ�Ϸ�Ч�����ͻ�ȥ���������Ѱ���ؼ��ɡ�\n" );
			break;
		case 2 :
			lock_quest( me, "shan", "betrayer" );		
			tell_object( me, "����˵�������������������ţ�Ҫ���ٻر��������ͽ���Ϸ��಻�������ˡ�\n" );
			break;
	}
	return 1;
}

int give_quest()
{
	mapping quest ;
	object me = this_player();
	int j, combatexp, timep,factor;
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
		5000000,
		9999999,
		100000000,
                
                
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
		350,
		0,
                
                
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
		23,
		25,
		30,
		38,
		0,
                
                
	});
	combatexp = (int) (me->query("combat_exp"));
	
	//Modified by zeratul 2000-12-24
	if( combatexp<10000 )
	{
		tell_object(me,"�����������һ������������С��ɫ���������������\n");
		return 1;
	}
/*	if(combatexp>10000000)
	{
		tell_object(me,"�����������������С�������ͷ�������\n");
		return 1;
	} */
/*
	if ( islocked( me, "shan" ) )
		return 1;
*/
	if( me->query("quest/shan") && !me->query( "quest/shan/finished" ) )
	{
		if( ((int) me->query("quest/shan/time")) > time() )
//		if( ((int) me->query("last_quest_time")+30) > time() )
		{
//			tell_object(me,"������������һЦ����������������ˣ�\n");
			tell_object(me,"���������һ��˵������Ҫ��û���£����õ�����ó������ñ����ȥ�������塣\n");
			return 1;
		}
		else
		{
			tell_object(me,"����������̾��һ�����������Ҿ��ٸ���һ�λ���ɡ�\n");
			quest_failed( me, "shan" );
/*			switch ( random(3) )
			{
				case 0 :
					lock_quest( me, "shan", "wei" ); 
					tell_object( me, "����˵���������������ѹ�����ȥΤ��ү���￴���ɡ�\n" );
					break;
				case 1 :
					lock_quest( me, "shan", "book" );
					tell_object( me, "����˵�����㻹�������ؼ���Ϥһ�µ�����˵�ɡ�\n" );
					break;
				case 2 :
					lock_quest( me, "shan", "betrayer" );		
					tell_object( me, "����˵����������ͽ�Ļ�����Ϸ�������ʺ��㡣\n" );
					break;
			}*/

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
		quest["score"] =  100 + random(50);
		me->set("quest/shan", quest);
		if (quest["shen"] >= 0) continue;
		if (combatexp < quest["exp"]*3 && combatexp*3 > quest["exp"])
			break;
		if (combatexp > 1000000 && quest["exp"] > 300000) break;
	}
	timep = random(60) * 10 + 600;

	time_period(timep, me);
	tell_object(me,"�����Ұѡ�"+quest["quest"]+"������ɱ�ˣ������������塣\n" NOR);

	me->set("quest/shan/time", (int)time()+timep);
	me->set("quest/shan/factor",factor);
	me->delete( "quest/shan/finished" );
	me->set("quest/shan/last_time",(int)time());
	if ( !me->query("quests",1))
	{
		me->set("quests/require", 1);
		me->set("quests/abandon", 1);
	}
	else me->add("quests/require", 1);
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

	tell_object(me,HIW "�����Ը�����������" + time + "��");
	return 1;
}

int accept_object(object who, object ob)
{
	int balance, require, abandon, num;
//	int bonus, exp, pot, score, factor, balance, require, abandon;
	mapping quest;

	if ( !ob->query("money_id") ) return 0;
	if ( !who->query("quest/shan") ||
                who->query("quest/shan/finished") || ob->value() < 10000 )
		tell_object(who,"����Ц�������ҿɾͲ������ˡ�\n");
        else
	{
		require = who->query("quests/require");
		abandon = who->query("quests/abandon");
		if(require == 0) require = 1;
		if(abandon == 0) abandon = 1;

//		balance = (int) (abandon/(require-abandon+1));
		balance=(int)(require-abandon+200);

		if (abandon>(int)(balance*3/2)) num=1;
		else num=0;
		if (abandon>(int)(balance+balance)) num=2;

		who->set("quests/num",num);
		if(num==2 && ob->value() < 1000000)
		{
			tell_object(who, "����һ˫�������۾�ֱ�����㣺��ʵ�ڲ����������ʮ����ɲ���һ�����㲻�������ε�������һ����ΥԼ������\n");
			return 1;
		}
		if(num==1 && ob->value() < 100000)
		{
			tell_object(who, "����һ˫�������۾�ֱ�����㣺�����������̫�Ҫ����������ʮ���ƽ�����\n");
			return 1;
		}
		if( ob->value() < 10000)
		{
			tell_object(who, "����һ˫�������۾�ֱ�����㣺���Ǯ�ɲ������ǵĿ�����\n");
			return 1;
		}
		else
		{
			tell_object(who, "����Ц�����Ǻã������������������ڡ����ֲ�ʹ�����Ұɣ�\n");
			who->set( "quest/shan/finished", 1 );
                        who->delete( "quest/shan/last_time" );
                        who->add("quests/abandon", 1);
			return 1;
		}
	}
/*
	if(!(quest = who->query("quest/shan")))
	{
		tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
		return 0;
	}

	write( ob->query("name") );
	if( ob->query("name") != quest["quest"])
	{
		tell_object(who, "����˵��������ʲô�������ҽ����Ĳ�ʹ���������Ū����\n");
		return 0;
	}

	if ((int) who->query("quest/shan/time") < time() )
	{
		tell_object(who, "����˵�������Ƿ����û����ָ����ʱ���ڻ�����\n");
		destruct(ob);
		return 0;
	}
	else
	{
		tell_object(who,"��������ص�ͷ˵����������ʹ��û�����\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=who->query("quest/shan_factor");
		destruct(ob);

		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) who->query("combat_exp");
		bonus += (int) (exp/3);
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
		who->set("quest/shan", 0 );
		tell_object(who,HIW"��ϲ�����һ����ʹ��\n"NOR);
		return 0;
	}
*/
	return 1;
}
