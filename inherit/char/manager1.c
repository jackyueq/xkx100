//last modified by sega 4/13/2000
//修改叛徒的属性为师傅的功夫,quest 的等级,呵呵
#include <dbase.h>
#include <login.h>

int party_quest1(object me)
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
		message_vision("$N对着$n说：你学艺未精，不宜下山。\n", master, me);
		return 1;
	}

	if (master->query_temp("betrayers") > 3)
	{
		message_vision("$N对着$n说：等等吧，下山弟子清理门户还没回山。\n", master, me);
		return 1;
	}

	if (time() - (int)me->query("family_quest1/time") < 300 && !wizardp(me))
	{
		message_vision("$N对着$n说：我不是叫你去杀"+
			me->query("family_quest1/name")+"，怎么空手回来了！？\n", master, me);
		return 1;
	}
	if (!master->query_temp("betrayers")) master->set_temp("betrayers", 1);
	else master->add_temp("betrayers", 1);

	obj = new("/clone/quest/questman");
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
	obj->set("shen",      -1*hp_status["shen"]);
	obj->set("max_neili", hp_status["max_neili"]);
	obj->set("neili",     hp_status["max_neili"]);
	obj->set("jiali",     hp_status["max_neili"]/20);
	obj->set("combat_exp",hp_status["combat_exp"]);
/* skill */
                skl = me->query_skills();
                skilllvl =10;
		if (sizeof(skl)) {
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
	me->set("family_quest1/name", obj->query("name"));
	me->set("family_quest1/family", obj->query("family/family_name"));
	me->set("family_quest1/time", time());
	return 1;
}

int accept_quest1(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, bonus;
	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}
        if (time() - (int)me->query("family_quest1/time") > 600 )
	{
		message_vision("$N对着$n说：你平时练功勤奋点，清理个门户就不必去这么久了！下次努力点！\n", master, me);
		destruct(obj);
		return 1;
	}
	if (obj->query("userp") == 1)
	{
		message_vision("$N对着$n说：我叫你杀叛徒，你却去杀玩家！去死吧你！\n", master, me);
		destruct(obj);
		master->kill_ob(me);
		return 1;
	}
	message_vision("$N对着$n说：叛徒的人头？不错，你为本门清理了门户！\n", master, me);
	master->add_temp("betrayers", -1);
	destruct(obj);
	bonus = (int) me->query("combat_exp");
	exp = (int)bonus/10000 + random(bonus / 10000);
	if (exp > 1000)
		exp = 850+random(150);
	bonus += exp;
	me->set("combat_exp", bonus);

	bonus = (int) me->query("potential");
	bonus = bonus - (int) me->query("learned_points");
	pot = (int)random(exp/10)+10;
	bonus = bonus + pot;
        bonus += (int) me->query("learned_points");
	me->set("potential", bonus );
/*
	if (me->query("potential") > me->query("learned_points")+300)
		me->set("potential", me->query("learned_points")+300);
*/
	bonus = (int) me->query("score");
	score = 50 + random(bonus / 200);
	bonus += score;
	me->set("score", bonus);

	tell_object(me,master->query("name")+"奖励了你：" + chinese_number(exp)
		+ "点实战经验，"+ chinese_number(pot) + "点潜能，"
		+ chinese_number(score)+"点江湖阅历。\n");
	me->delete("family_quest1");
	
	return 1;
}

int party_quest2(object me)
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

	if (me->query("combat_exp") <= 10000)
	{
		message_vision("$N对着$n说：你学艺未精，不宜下山。\n", master, me);
		return 1;
	}

	if (time() - (int)me->query("family_quest2/time") < 300 && !wizardp(me))
	{
		message_vision("$N对着$n说：我不是叫你去取"+
			me->query("family_quest2/book")+"，怎么空手回来了！？\n", master, me);
		return 1;
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
	me->set("family_quest2/book", book->query("name"));
	me->set("family_quest2/family", me->query("family/family_name"));
	me->set("family_quest2/time", time());
	return 1;
}
int accept_quest2(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, bonus;
	me = this_player();
	if (obj->query("owner") != me->query("id"))
	{
		message_vision("$N对着$n说：这不是我要你找的书。\n",master,me);
		return 1;
	}
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}
        if (time() - (int)me->query("family_quest2/time") > 2000 )
	{
		message_vision("$N对着$n说：你平时练功勤奋点，就不必去这么久了！下次努力点！\n", master, me);
		destruct(obj);
		return 1;
	}
	if (!me->query("family_quest2"))
	{
		message_vision("$N对着$n说：我没要这书，你去哪里拿来的！\n", master, me);
		destruct(obj);
		return 1;
	}
	message_vision("$N对着$n说：本门秘籍？不错，你为本门立了一大功！\n", master, me);
	destruct(obj);
	bonus = (int) me->query("combat_exp");
	exp = (int)bonus/2000 + random(bonus / 2000);
	if (exp > 500)
		exp = 350+random(150);
	bonus += exp;
	me->set("combat_exp", bonus);

	bonus = (int) me->query("potential");
	bonus = bonus - (int) me->query("learned_points");
	bonus = bonus + pot;
	pot = (int)random(exp/10)+10;
        bonus += (int) me->query("learned_points");
	me->set("potential", bonus );
/*
	if (me->query("potential") > me->query("learned_points")+300)
		me->set("potential", me->query("learned_points")+300);
*/
	bonus = (int) me->query("score");
	score = 50 + random(bonus / 200);
	bonus += score;
	me->set("score", bonus);

	tell_object(me,master->query("name")+"奖励了你：" + chinese_number(exp)
		+ "点实战经验，"+ chinese_number(pot) + "点潜能，"
		+ chinese_number(score)+"点江湖阅历。\n");
	me->delete("family_quest2");
	
	return 1;
}

int party_quest3(object me)
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

	if (me->query("combat_exp") <= 10000)
	{
		message_vision("$N对着$n说：你学艺未精，无能锄奸。\n", master, me);
		return 1;
	}

	if (master->query_temp("thiefs") > 3)
	{
		message_vision("$N对着$n说：本门清宁，哪来什么奸细？你且退下！\n", master, me);
		return 1;
	}

	if (time() - (int)me->query("family_quest3/time") < 300 && !wizardp(me))
	{
		message_vision("$N对着$n说：怎么样，奸细"+ me->query("family_quest3/name")+"的人头呢！？\n", master, me);
		return 1;
	}
	if (!master->query_temp("thiefs")) master->set_temp("thiefs", 1);
	else master->add_temp("thiefs", 1);

	obj = new("/clone/quest/questjianxi");
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
	obj->set("shen",      -1*hp_status["shen"]);
	obj->set("max_neili", hp_status["max_neili"]);
	obj->set("neili",     hp_status["max_neili"]);
	obj->set("jiali",     hp_status["max_neili"]/20);
	obj->set("combat_exp",2*hp_status["combat_exp"]);
/* skill */
                skl = me->query_skills();
                skilllvl=10;
		if (sizeof(skl)) {
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
	me->set("family_quest3/name", name["name"]);
	me->set("family_quest3/family", obj->query("family/family_name"));
	me->set("family_quest3/time", time());
	return 1;
}

int accept_quest3(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, bonus;
	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N对着$n说：我不是你的掌门人，你回你们"+me->query("family/family_name")+"去吧。\n", master, me);
		return 1;
	}
        if (time() - (int)me->query("family_quest3/time") > 600 )
	{
		message_vision("$N对着$n说：你平时练功勤奋点，捉拿个奸细就不必去这么久了！下次努力点！\n", master, me);
		destruct(obj);
		return 1;
	}
	if (obj->query("userp") == 1)
	{
		message_vision("$N对着$n说：我叫你杀奸细，你却去杀玩家！去死吧你！\n", master, me);
		destruct(obj);
		master->kill_ob(me);
		return 1;
	}
	message_vision("$N对着$n说：奸细的人头？不错，你为本门立一大功！\n", master, me);
	master->add_temp("betrayers", -1);
	destruct(obj);
	bonus = (int) me->query("combat_exp");
	exp = (int)bonus/10000 + random(bonus / 10000);
	if (exp > 1500)
		exp = 1500+random(500);
	bonus += exp;
	me->set("combat_exp", bonus);

	bonus = (int) me->query("potential");
	bonus = bonus - (int) me->query("learned_points");
	 pot = (int)random(exp/10)+10;
	bonus = bonus + pot;
        bonus += (int) me->query("learned_points");
	me->set("potential", bonus );
/*
	if (me->query("potential") > me->query("learned_points")+300)
		me->set("potential", me->query("learned_points")+300);
*/
	bonus = (int) me->query("score");
	score = 50 + random(bonus / 200);
	bonus += score;
	me->set("score", bonus);

	tell_object(me,master->query("name")+"奖励了你：" + chinese_number(exp)
		+ "点实战经验，"+ chinese_number(pot) + "点潜能，"
		+ chinese_number(score)+"点江湖阅历。\n");
	me->delete("family_quest3");
	
	return 1;
}

int accept_betrayer(object ob)
{
	if (ob->query("shen") > 0)
	{
		if (ob->query("betrayer") > 0) return 1;
	}
	else
	{
		if (ob->query("betrayer") > 5) return 1;
	}
}
