// /inherit/char/manager.c

//last modified by sega 4/13/2000
//修改叛徒的属性为师傅的功夫,quest 的等级,呵呵
// Modified by Constant Apr.18.2000
// Modified by Zeratul Jan 5 2001
// Modified by Zeratul Jan 6 2001
// Modified by Constant Jan 11 2001

#include <dbase.h>
#include <login.h>
#include <ansi.h>
#include </quest/quest.h>

int party_quest_betrayer(object me)
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	string *dir, *file, place;
	int i, j;
	object room, obj, weapon, armor, master = this_object();
	        mapping skl;
        string *skillname;
        int  skilllvl;

	me = this_player();

	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}

	if (me->query("combat_exp") <= 10000)
	{
		message_vision(WHT"$N对着$n说：你学艺未精，不宜下山。\n"NOR, master, me);
		return 1;
	}

	if ( islocked( me, "betrayer" ) )
		return 1;

/*	if (master->query_temp("betrayers") > 3)
	{
		message_vision("$N对着$n说：等等吧，下山弟子清理门户还没回山。\n", master, me);
		return 1;
	}
*/
	if ( me->query("quest/betrayer") && !me->query( "quest/betrayer/finished" ) )
	{
		if (time() < (int)me->query("quest/betrayer/time") && !wizardp(me) )
		{
			message_vision("$N对着$n说：我不是叫你去杀"+
				me->query("quest/betrayer/name")+"，怎么空手回来了！？\n", master, me);
			return 1;
		}
		else
		{
			message_vision( WHT"$N对着$n说：你跑到那里闲逛去了？\n"NOR, master, me );
			quest_failed( me, "betrayer" );
/*			switch ( random(2) )
			{
				case 0 :
					lock_quest( me, "betrayer", "wei" );
					message_vision( "$N对着$n说：韦爵爷消息灵通，你去他那里帮忙，顺便打听一下叛徒的消息。\n", master, me );
					break;
				case 1 :
					lock_quest( me, "betrayer", "book" );
					message_vision( "$N对着$n说：你还是先帮我找秘籍吧。\n", master, me );
					break;
			}*/

			me->add("qi",-(int)(me->query("qi")/10));
//			return 1;
		}
	}

	if (!master->query_temp("betrayers")) master->set_temp("betrayers", 1);
	else master->add_temp("betrayers", 1);

	obj = new("/clone/quest/questman");
	obj ->set("owner", me->query("id"));
	if (random(2) == 0)
	{
		name = NAME_D->woman_name();
		obj->set("gender", "女性");
	}
	else
	{
		name = NAME_D->man_name();
		obj->set("gender", "男性");
	}

	obj->set("name", name["name"],({name["id"]}));
	hp_status = me->query_entire_dbase();
	obj->set("str", hp_status["str"]);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
	obj->set("dex", hp_status["dex"]);
	obj->set("age", hp_status["age"]+2);

	obj->set("max_jing",  hp_status["max_jing"]);
	obj->set("eff_jing",  hp_status["max_jing"]);
	obj->set("jing",      hp_status["jing"]);
	obj->set("max_qi",    hp_status["max_qi"]);
	obj->set("eff_qi",    hp_status["max_qi"]);
	obj->set("qi",        hp_status["max_qi"]);
//	obj->set("shen",      -1*hp_status["shen"]);
	obj->set("max_neili", hp_status["max_neili"]);
	obj->set("neili",     hp_status["max_neili"]);
	obj->set("jiali",     hp_status["max_neili"]/20);
	obj->set("combat_exp",hp_status["combat_exp"]);
/* skill */
	skl = me->query_skills();
	skilllvl =10;
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}
	}

	if ( mapp(skill_status = master->query_skills()) )
	{
		skill_status = master->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			obj->set_skill(sname[i], skilllvl);
		}
	}
/* skill map*/
	if ( mapp(map_status = master->query_skill_map()) )
	{
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++)
		{
			obj->map_skill(mname[i], map_status[mname[i]]);
		}
	}
/* skill prepare*/
	if ( mapp(prepare_status = master->query_skill_prepare()) )
	{
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++)
		{
			obj->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
/* family */
	obj->set("family/family_name",master->query("family/family_name"));
	obj->set("family/master_name",master->query("name"));
	obj->set("family/generation",(int)master->query("family/generation")+1);
	obj->set("family/title",master->query("family/title"));
	obj->set("family/master_id",master->query("id"));
	obj->set("family/enter_time",time());
	obj->set("title",master->query("family/family_name")+
		"第"+chinese_number((int)master->query("family/generation")+1)+
		"代叛徒");

/* Move to dest place */
	dir = get_dir("/d/");
	i = random(sizeof(dir));
	file = get_dir("/d/"+dir[i]+"/");
	j = random(sizeof(file));

	if (strsrch(file[j], ".c") == -1 ||
		dir[i]=="death" ||
		dir[i]=="wizard" ||
		dir[i]=="working" ||
		dir[i]=="binghuo" ||
		dir[i]=="xiakedao" ||
		dir[i]=="npc")
	{
		message_vision("$N对着$n说：等等吧，等下山弟子回山后你再来看看。\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000)
	{
		message_vision("$N对着$n说：等等吧，等下山弟子回山再看看。\n", master, me);
		return 1;
	}
	obj->move(room);
	command("sys "+obj->query("name")+"在"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")。\n");

	message_vision("$N对着$n说：本门归山弟子回报，本门叛徒"+obj->query("name")+"在"+to_chinese(dir[i])+"一带出没。你敢去把这叛徒的人头给我取回来么？\n", master, me);
	me->set("quest/betrayer/name", obj->query("name"));
	me->set("quest/betrayer/family", obj->query("family/family_name"));
	me->set("quest/betrayer/time", time() + 500);
	me->set( "quest/betrayer/dest", to_chinese(dir[i]) );
	me->set( "quest/betrayer/obj", obj );
	me->delete( "quest/betrayer/finished" );
	return 1;
}

int accept_quest_betrayer(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, e_bonus, p_bonus, s_bonus;

	me = this_player();

	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}

	if ( islocked( me, "betrayer" ) )
		return 1;

	if ( !me->query( "quest/betrayer" ) || me->query( "quest/betrayer/finished" ) )
		return 0;

/*        if (time() - (int)me->query("quest/betrayer/time") > 100 )
	{
		message_vision(WHT"$N对着$n说：你平时练功勤奋点，清理个门户就不必去这么久了！下次努力点！\n"NOR, master, me);
		destruct(obj);

		me->add("qi",-(int)(me->query("qi")/10));

		return 1;
	}*/
	if (obj->query("userp") == 1)
	{
		message_vision(HIR"$N对着$n说：我叫你杀叛徒，你却去杀玩家！去死吧你！\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "betrayer" );
		master->kill_ob(me);
		return 1;
	}

	master->add_temp("betrayers", -1);
	destruct(obj);

	exp = (int) me->query("combat_exp");
//	e_bonus = (int)exp/10000 + random(exp/10000);
	e_bonus = exp / 1000 + random( exp / 1000 );
//	if (e_bonus > 1000)
//		e_bonus = 850+random(150);
	if ( e_bonus > 400 )
		e_bonus = 200 + random( 200 );
	exp += e_bonus;

	pot = (int)me->query("potential");
	pot -= (int)me->query("learned_points");
	p_bonus = (int)random(e_bonus/10)+10;
	pot += p_bonus;
        pot += (int) me->query("learned_points");
/*
	if (me->query("potential") > me->query("learned_points")+300)
		me->set("potential", me->query("learned_points")+300);
*/
	score = (int) me->query("score");
	s_bonus = 50 + random(score / 200);
	score += s_bonus;

	me->set("combat_exp", exp);
	me->set("potential", pot);
	me->set("score", score);

	message_vision("$N对着$n说：叛徒的人头？不错，你为本门清理了门户！\n", master, me);
	tell_object(me,HIW + master->query("name") + "奖励了你："
		+ chinese_number(e_bonus) + "点实战经验，"
		+ chinese_number(p_bonus) + "点潜能，"
		+ chinese_number(s_bonus) + "点江湖阅历。\n"NOR);

	quest_finished( me, "betrayer" );

	return 1;
}

int cancle_quest_betrayer( object me )
{
	object master = this_object();

	if ( !me->query( "quest/betrayer" ) || me->query( "quest/betrayer/finished" ) )
		return 0;
	if ( me->query( "quest/betrayer/lock" ) )
	{
		tell_object( me, "你已经取消任务了！\n" );
		return 1;
	}
	switch ( random(2) )
	{
		case 0 :
			lock_quest( me, "betrayer", "wei" );
			message_vision( "$N对$n说道：这点小事也办不成，还是下山为韦爵爷跑跑腿吧。\n", master, me );
			break;
		case 1 :
			lock_quest( me, "betrayer", "book" );
			message_vision( "$N对$n说道：那你就帮我找找秘籍吧。\n", master, me );
			break;
	}
	return 1;
}

int party_quest_book(object me)
{
	object book, room, master = this_object();
	string *dir, *file, place;
	int i,j;

	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}

	// Modified by zeratul 2000-12-24
	if (me->query("combat_exp") <= 1000)
	{
		message_vision(WHT"$N对着$n说：你学艺未精，不宜下山。\n"NOR, master, me);
		return 1;
	}

	if ( me->query("quest/book") && !me->query( "quest/book/finished" ) )
	{
		if (time() < (int)me->query("quest/book/time") && !wizardp(me) )
		{
			message_vision("$N对着$n说：我不是叫你去取"+
				me->query("quest/book/book")+"，怎么空手回来了！？\n", master, me);
			return 1;
		}
		else
		{
			message_vision( CYN"$N对着$n说：你跑到哪里闲逛去了？这次可要小心在意些！\n"CYN, master, me );
			quest_failed( me, "book" );
		}
	}

	book = new("/clone/quest/questbook");
	book ->set("name", me->query("family/family_name")+"密籍");
	book ->set("owner", me->query("id"));
	dir = get_dir("/d/");
	i = random(sizeof(dir));
	file = get_dir("/d/"+dir[i]+"/");
	j = random(sizeof(file));

	if (strsrch(file[j], ".c") == -1 ||
		dir[i]=="death" ||
		dir[i]=="wizard" ||
		dir[i]=="working" ||
		dir[i]=="binghuo" ||
		dir[i]=="xiakedao" ||
		dir[i]=="npc")
	{
		message_vision("$N对着$n说：本门密籍？不是好好的么？\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000)
	{
		message_vision("$N对着$n说：等等吧，等我回头清点一下看看。\n", master, me);
		return 1;
	}
	book->move(room);
	command("sys "+book->query("name")+"在"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")。\n");

	message_vision("$N对着$n说：本门秘籍流落江湖，听说最近在"+to_chinese(dir[i])+"一带出现。你去把它取回来吧？\n", master, me);
	me->set("quest/book/book", book->query("name"));
	me->set("quest/book/family", me->query("family/family_name"));
	me->set("quest/book/time", time() + 500 );
	me->set( "quest/book/dest", to_chinese(dir[i]) );
	me->delete( "quest/book/finished" );
	return 1;
}
int accept_quest_book(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, e_bonus, p_bonus, s_bonus;

	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}

	if (obj->query("owner") != me->query("id"))
	{
		message_vision("$N对着$n说：这不是我要你找的书。\n",master,me);
		return 1;
	}

	if ( !me->query("quest/book") || me->query( "quest/book/finished" ) )
	{
		message_vision("$N对着$n说：我没要这书，你去哪里拿来的！\n", master, me);
		destruct(obj);
		return 1;
	}

        if (time() - (int)me->query("quest/book/time") > 1500 )
	{
		message_vision("$N对着$n说：你平时练功勤奋点，就不必去这么久了！下次努力点！\n", master, me);
		destruct(obj);
		quest_failed( me, "book" );
		return 1;
	}

	destruct(obj);

	exp = (int) me->query("combat_exp");
//	e_bonus = (int)exp/20000 + random(exp / 20000);
//	if (e_bonus > 500)
//		e_bonus = 350+random(150);
	e_bonus = exp /500  + random( exp / 500 );
	if ( e_bonus > 40 )
		e_bonus = 20 + random( 20 );

	exp += e_bonus;

	pot = (int)me->query("potential");
	pot -=(int)me->query("learned_points");
//	p_bonus = (int)random(e_bonus/10)+10;
	p_bonus = 2 + random( e_bonus / 10 );
	pot += p_bonus;
        pot += (int)me->query("learned_points");

/*
	if (me->query("potential") > me->query("learned_points")+300)
		me->set("potential", me->query("learned_points")+300);
*/
	score = (int) me->query("score");
	s_bonus = 50 + random(score / 200);
	score += s_bonus;

	me->set("combat_exp", exp);
	me->set("potential", pot);
	me->set("score", score);

	message_vision("$N对着$n说：本门秘籍？不错，你为本门立了一大功！\n", master, me);
	tell_object(me,HIW + master->query("name") + "奖励了你："
		+ chinese_number(e_bonus) + "点实战经验，"
		+ chinese_number(p_bonus) + "点潜能，"
		+ chinese_number(s_bonus) + "点江湖阅历。\n"NOR);

	quest_finished( me, "book" );
	return 1;
}

int party_quest_thief(object me)
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	string *dir, *file, place;
	int i, j, k;
	object room, obj, weapon, armor, master = this_object();
        mapping skl;
        string *skillname;
        int  skilllvl;

	me = this_player();

	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}

	if (me->query("combat_exp") <= 100000)
	{
		message_vision(WHT"$N对着$n说：你学艺未精，无能锄奸。\n"NOR, master, me);
		return 1;
	}

	if ( islocked( me, "thief" ) )
		return 1;

/*	if (master->query_temp("thiefs") > 3)
	{
		message_vision("$N对着$n说：本门清宁，哪来什么奸细？你且退下！\n", master, me);
		return 1;
	}
*/
	if ( me->query("quest/thief") && !me->query( "quest/thief/finished" ) )
	{
		if (time() < (int)me->query("quest/thief/time") && !wizardp(me) )
		{
			message_vision("$N对着$n说：怎么样，奸细"+ me->query("quest/thief/name")+"的人头呢！？\n", master, me);
			return 1;
		}
		else
		{
			message_vision( WHT"$N对着$n说：你让奸细溜走了还有脸回来见我？\n"NOR, master, me );
			switch ( random(3) )
			{
				case 0 :
					if( me->query("yipin/joined") )
					{
						lock_quest( me, "thief", "helian" );
						message_vision( "$N对着$n说：看来你还无法担当此等重任，去赫连铁树那里磨练一下也好。\n", master, me );
						break;
					}
				case 1 :
					lock_quest( me, "thief", "shan" );
					message_vision( "$N对着$n说：看来你还无法担当此等重任，去单正老爷子那里磨练一下也好。\n", master, me );
					break;
				case 2 :
					lock_quest( me, "thief", "betrayer" );
					message_vision( "$N对着$n说：还是先把本门叛徒铲除干净再管别的事吧。\n", master, me );
					break;

			}

			me->add("qi",-(int)(me->query("qi")/10));
			return 1;
		}
	}

	if (!master->query_temp("thiefs")) master->set_temp("thiefs", 1);
	else master->add_temp("thiefs", 1);

	obj = new("/clone/quest/questjianxi");
	obj ->set("owner", me->query("id"));
	if (random(2) == 0)
	{
		name = NAME_D->woman_name();
		obj->set("gender", "女性");
	}
	else
	{
		name = NAME_D->man_name();
		obj->set("gender", "男性");
	}

	hp_status = me->query_entire_dbase();
	obj->set("fname", name["name"]);
	obj->set("str", hp_status["str"]);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
	obj->set("dex", hp_status["dex"]);
	obj->set("age", hp_status["age"]+2);

	obj->set("max_jing",  hp_status["max_jing"]);
	obj->set("eff_jing",  hp_status["max_jing"]);
	obj->set("jing",      hp_status["jing"]);
	obj->set("max_qi",    hp_status["max_qi"]);
	obj->set("eff_qi",    hp_status["max_qi"]);
	obj->set("qi",        hp_status["max_qi"]);
//	obj->set("shen",      -1*hp_status["shen"]);
	obj->set("max_neili", hp_status["max_neili"]);
	obj->set("neili",     hp_status["max_neili"]);
	obj->set("jiali",     hp_status["max_neili"]/20);
	obj->set("combat_exp",2*hp_status["combat_exp"]);
/* skill */
	skl = me->query_skills();
	skilllvl=10;
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}
	}

	if ( mapp(skill_status = master->query_skills()) )
	{
		skill_status = master->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			obj->set_skill(sname[i], skilllvl);
		}
	}
/* skill map*/
	if ( mapp(map_status = master->query_skill_map()) )
	{
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++)
		{
			obj->map_skill(mname[i], map_status[mname[i]]);
		}
	}
/* skill prepare*/
	if ( mapp(prepare_status = master->query_skill_prepare()) )
	{
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++)
		{
			obj->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
/* Move to dest place */
	dir = get_dir("/d/");
	for (i = 0; i < sizeof(dir); i++)
	{
		if (strsrch(master->query("startroom"), dir[i]) >= 0)
			k = i;
	}
	file = get_dir("/d/"+dir[k]+"/");
	j = random(sizeof(file));

	if (strsrch(file[j], ".c") == -1 ||
		dir[k]=="death" ||
		dir[k]=="wizard" ||
		dir[k]=="working" ||
		dir[k]=="binghuo" ||
		dir[k]=="xiakedao" ||
		dir[k]=="npc")
	{
		message_vision("$N对着$n说：等等吧，等下山弟子回山后你再来看看。\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[k]+"/"+file[j]) ))
		room = load_object("/d/"+dir[k]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000)
	{
		message_vision("$N对着$n说：等等吧，等下山弟子回山再看看。\n", master, me);
		return 1;
	}
	obj->move(room);
	command("sys "+obj->query("name")+"在"+room->query("short")+"(/d/"+dir[k]+"/"+file[j]+")。\n");

	message_vision("$N对着$n说：本门弟子回报，我派周围有陌生人出现。你去查看一下是不是别派的奸细？\n", master, me);
	me->set("quest/thief/name", name["name"]);
	me->set("quest/thief/family", obj->query("family/family_name"));
	me->set("quest/thief/time", time() + 300 );
	me->set( "quest/thief/obj", obj );
	me->delete( "quest/thief/finished" );
	return 1;
}

int accept_quest_thief(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, e_bonus, p_bonus, s_bonus;

	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}
	if ( islocked( me, "thief" ) )
		return 1;

	if ( !me->query( "quest/thief" ) || me->query( "quest/thief/finished" ) )
		return 0;

/*        if (time() - (int)me->query("quest/thief/time") > 300 )
	{
		message_vision(WHT"$N对着$n说：你平时练功勤奋点，捉拿个奸细就不必去这么久了！下次努力点！\n"WHT, master, me);
		destruct(obj);

//		lock_quest( me, "thief", 3 + random(3) );
		me->add("qi",-(int)(me->query("qi")/10));

		return 1;
	}*/
	if (obj->query("userp") == 1)
	{
		message_vision(HIR"$N对着$n说：我叫你杀奸细，你却去杀玩家！去死吧你！\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "thief" );
		master->kill_ob(me);
		return 1;
	}

	master->add_temp("betrayers", -1);
	destruct(obj);

	exp = (int) me->query("combat_exp");
	e_bonus = (int)exp/10000 + random(exp / 10000);
	if (e_bonus > 1500)
		e_bonus = 1250+random(250);
	exp += e_bonus;

	pot = (int) me->query("potential");
	pot -=(int) me->query("learned_points");
	p_bonus = (int)random(e_bonus/10)+100;
	pot += p_bonus;
        pot += (int) me->query("learned_points");

/*
	if (me->query("potential") > me->query("learned_points")+300)
		me->set("potential", me->query("learned_points")+300);
*/
	score = (int) me->query("score");
	s_bonus = 50 + random(score / 200);
	score += s_bonus;

	me->set("combat_exp", exp);
	me->set("potential", pot);
	me->set("score", score);

	message_vision("$N对着$n说：奸细的人头？不错，你为本门立一大功！\n", master, me);
	tell_object(me,HIW + master->query("name")+"奖励了你："
		+ chinese_number(e_bonus) + "点实战经验，"
		+ chinese_number(p_bonus) + "点潜能，"
		+ chinese_number(s_bonus) + "点江湖阅历。\n"NOR);

	quest_finished( me, "thief" );

	return 1;
}

int cancle_quest_thief( object me )
{
	object master = this_object();

	if ( !me->query( "quest/thief" ) || me->query( "quest/thief/finished" ) )
		return 0;
	if ( me->query( "quest/thief/lock" ) )
	{
		tell_object( me, "你已经取消任务了！\n" );
		return 1;
	}
	switch ( random(3) )
	{
		case 0 :
			if( me->query("yipin/joined") )
			{
				lock_quest( me, "thief", "helian" );
				message_vision( "$N对着$n说：看来你还无法担当此等重任，去赫连铁树那里磨练一下也好。\n", master, me );
				break;
			}
		case 1 :
			lock_quest( me, "thief", "shan" );
			message_vision( "$N对着$n说：看来你还无法担当此等重任，去单正老爷子那里磨练一下也好。\n", master, me );
			break;
		case 2 :
			lock_quest( me, "thief", "betrayer" );
			message_vision( "$N对着$n说：还是先把本门叛徒铲除干净再管别的事吧。\n", master, me );
			break;
	}

	return 1;
}

int accept_betrayer(object ob)
{
	if (ob->query("shen") > 0) {
		if (ob->query("betrayer") > 0)
			return 1;
	} else {
		if (ob->query("betrayer") > 5)
			return 1;
	}
}

// 增加向掌门要求叛师的功能。
// Added by Constant Jan 12 2001
int betray(object ob, int depth)
{
	string *base_skill = ({
		"array",     	"axe",     	"blade",
		"claw",      	"club",    	"cuff", 
		"dagger",    	"dodge",   	"force",   
		"finger",    	"gambling" 	"hammer", 
		"hand",      	"leg",     	"literate",
		"magic",	"parry",     	"spear",   	
		"staff",	"stick",     	"strike",  	
		"sword", 	"throwing",  	"unarmed", 	
		"whip"
        });

	object master = this_object();
	mapping ob_skills = ob->query_skills();
	string skill_name;
	int skill_level, i;

	if (ob->query("family/family_name") !=
		master->query("family/family_name")) {
		message_vision("$N说道：“贵派之事自有贵派掌门处置，与我无关。”\n", master, ob);
		return 1;
	}

	if (ob->query("combat_exp") < 1000000) {
		message_vision("$N冷笑道：“就凭你这点微末道行，也想到江湖上去闯荡，还不叫人笑掉大牙？”\n", master, ob);
		return 1;
	}

	if (depth == 0) {
		message_vision(HIR"\n$N眉头一皱，紧紧盯着$n，目光如箭，$n不禁打了个寒战。\n"NOR, master, ob);
		ob->start_busy(10);
		call_out("betray", 5, ob, depth + 1);
	} else {
		message_vision(HIR"\n半晌，$N叹道：“既然你执意离去，我也不便强留。只是你的一身武功，哪里来就还哪里去吧。”\n"NOR, master, ob);
		message_vision(HIR"说罢，挥掌在$n额头轻轻一击，$n只觉全身劲力被绵绵不绝抽去，大骇之下，晕了过去。\n"NOR, master, ob);
		for (i = 0; i < sizeof(ob_skills); ) {
			skill_name = keys(ob_skills)[i];
			skill_level = ob_skills[skill_name];
			if (member_array(skill_name, base_skill) != -1) {
				skill_level = skill_level / 2;
				if (skill_level == 0)
					map_delete(ob_skills, skill_name);
				else {
					ob_skills[skill_name] = skill_level;
					i ++;
				}
			} else {
				map_delete(ob_skills, skill_name);
			}
		}
		ob->set("betrayer", ob->query("betrayer") + 1);
		ob->set("title", "普通百姓");
		ob->set("class", "0");
		ob->delete("family");
		ob->save();
		ob->unconcious();
	}
	
	return 1;
}
