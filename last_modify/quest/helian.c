// /quest/helian.c
// Modified by Zeratul Jan 5 2001

inherit NPC;
inherit F_SKILL;
#include <ansi.h>;
#include </quest/quest.h>

int time_period(int timep,object me);
void create()
{
	set_name("赫连铁树", ({ "helian tieshu", "helian", "tieshu" }));
	set("title", HIY"西夏国征东大将军"HIM"西夏一品堂"HIR"总管"NOR);
	set("gender", "男性");
	set("age", 35);
	set("str", 25);
	set("dex", 26);
	set("per", 16);
	set("long", "他身穿大红锦袍，三十四五岁年纪，鹰钩鼻、八字须。\n");

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
		"一品堂": "一品堂就是要和中原武林做对！\n",
	]) );

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}

int accept_fight(object me)
{
	command("say 你敢来一品堂撒野！不要命了！");
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
		return notify_fail( "什么？\n" );
	if ( me->query( "quest/helian/lock" ) )
		return notify_fail( "你已经取消任务了！\n" );
	switch ( random(3) )
	{
		case 0 :
			lock_quest( me, "helian", "wei" ); 
			tell_object( me, "赫连铁树怒道：韦小宝那家伙给的活儿轻松，你找他去啊！\n" );
			break;
		case 1 :
			lock_quest( me, "helian", "book" );
			tell_object( me, "赫连铁树说道：你这点能耐也就能帮你掌门找几本破书，就别在这儿丢人了。\n" );
			break;
		case 2 :
			lock_quest( me, "helian", "betrayer" );		
			tell_object( me, "赫连铁树说道：也好，你就回本门清除叛徒，顺便帮老子打探一下中原武林的消息。\n" );
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
		tell_object(me,"赫连铁树对你哼了一声道：“你不是本堂的吧？来这凑什么热闹！”\n");
	     return 1;
	}
	//Modified by zeratul 2000-12-25
	if(combatexp<10000)
	{
		tell_object(me,"赫连铁树对你哼了一声道：“这种小角色还想投机一品堂？”\n");
	     return 1;
	}

	if ( islocked( me, "helian" ) )
		return 1;
	
	if( me->query("quest/helian") && !me->query( "quest/helian/finished" ) )	
	{
		if( ((int) me->query("/quest/helian/time")) >  time() )
//		if( ((int) me->query("last_quest_time")+30) > time() )
		{
			tell_object(me,"赫连铁树对你冷冷一笑道：让你办的事如何了？\n");
//			tell_object(me,"赫连铁树很不屑地瞟了你一眼说道：你要是没本事，就拿点儿费用出来我让别的人去。\n");
			return 1;
		}
		else
		{
			tell_object( me, "赫连铁树对着你叹了一口气：哎，我就再给你一次机会吧。\n" );
			quest_failed( me, "helian" );
/*
			switch ( random(3) )
			{
				case 0 :
					lock_quest( me, "helian", "wei" ); 
					tell_object( me, "赫连铁树说道：我这里不要你，去韦小宝那里混吧。\n" );
					break;
				case 1 :
					lock_quest( me, "helian", "book" );
					tell_object( me, "赫连铁树说道：你那三脚猫的把式只会误事，还是先找几本秘籍学功夫要紧。\n" );
					break;
				case 2 :
					lock_quest( me, "helian", "betrayer" );		
					tell_object( me, "赫连铁树说道：象你这样磨磨蹭蹭的怎么行，回去杀几个叛徒练练身手再来！\n" );
					break;
			}*/
			
//			tell_object(me,"赫连铁树很不屑地瞟了你一眼说道：你要是没本事，就别来烦本大爷。\n");
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
		quest["quest_type"] = "杀";
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
	tell_object(me,"先替我把『"+quest["quest"]+"』给我杀了，看那些南蛮又能把一品堂怎么着？！\n" NOR);

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

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	tell_object(me,HIW "赫连铁树吩咐道：给你在" + time + "内");
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
			tell_object(who,"赫连铁树笑道：那我可就不客气了。\n");
			return 1;
/*		}
		require = who->query("quests/require");
		abandon = who->query("quests/abandon");
		if(require == 0) require = 1;
		if(abandon == 0) abandon = 1;
		balance = (int) (abandon/(require-abandon+1));
		if(balance > 10 && ob->value() < 1000000)
		{
			tell_object(who,"赫连铁树一双尖针般的眼睛直盯着你：我实在不想给你任务！十项完成不了一项。如果你不想完成这次的任务，拿一百两违约金来！\n");
			return 1;
		}
		if(balance > 5 && ob->value() < 100000)
		{
			tell_object(who,"赫连铁树一双尖针般的眼睛直盯着你：你的任务资信太差，要新任务，先拿十两黄金来！\n");
			return 1;
		}
		if(balance > 3 && ob->value() < 10000)
		{
			tell_object(who,"赫连铁树一双尖针般的眼睛直盯着你：你的任务领得多做得少，想要放弃任务，拿一两黄金给我。\n");
			return 1;
		}
		if( ob->value() < 5000)
		{
			tell_object(who,"赫连铁树一双尖针般的眼睛直盯着你：这点钱可不够我们的开销！\n");
			return 1;
		}
		else
		{
tell_object(who,"赫连铁树笑道：那好，咱们买卖不成仁义在。想讨差使再找我吧！\n");
			who->set("quest",0);
			who->add("quests/abandon", 1);
			return 1;
		}
	}

	if(!(quest =  who->query("quest")))
	{
	     tell_object(who,"赫连铁树说道：这不是我想要的。\n");
	     return 0;
	}

	if( ob->query("name") != quest["quest"])
	{
		tell_object(who,"赫连铁树说道：这是什么东西？我叫你办的差使你就这样糊弄？！\n");
		return 0;
	}

	if ((int) who->query("task_time") < time() )
	{
		tell_object(who,"赫连铁树说道：真是废物！你没有在指定的时间内回来！\n");
		destruct(ob);
		return 0;
	}
	else
	{
		tell_object(who,"赫连铁树赞许地点头说道：不错！差使办得还不错！\n");
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
		tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
			+ "点实战经验，"+ chinese_number(pot) + "点潜能，"
			+ chinese_number(score)+"点江湖阅历。\n"NOR);
		who->set("quest", 0 );
		tell_object(who,HIW"恭喜你完成一个差使！\n"NOR);
		return 0;
	}
	return 1;*/
}
