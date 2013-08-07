// /inherit/char/manager.c

//last modified by sega 4/13/2000
//�޸���ͽ������Ϊʦ���Ĺ���,quest �ĵȼ�,�Ǻ�
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
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}

	if (me->query("combat_exp") <= 10000)
	{
		message_vision(WHT"$N����$n˵����ѧ��δ����������ɽ��\n"NOR, master, me);
		return 1;
	}

	if ( islocked( me, "betrayer" ) )
		return 1;

/*	if (master->query_temp("betrayers") > 3)
	{
		message_vision("$N����$n˵���ȵȰɣ���ɽ���������Ż���û��ɽ��\n", master, me);
		return 1;
	}
*/
	if ( me->query("quest/betrayer") && !me->query( "quest/betrayer/finished" ) )
	{
		if (time() < (int)me->query("quest/betrayer/time") && !wizardp(me) )
		{
			message_vision("$N����$n˵���Ҳ��ǽ���ȥɱ"+
				me->query("quest/betrayer/name")+"����ô���ֻ����ˣ���\n", master, me);
			return 1;
		}
		else
		{
			message_vision( WHT"$N����$n˵�����ܵ������й�ȥ�ˣ�\n"NOR, master, me );
			quest_failed( me, "betrayer" );
/*			switch ( random(2) )
			{
				case 0 :
					lock_quest( me, "betrayer", "wei" );
					message_vision( "$N����$n˵��Τ��ү��Ϣ��ͨ����ȥ�������æ��˳�����һ����ͽ����Ϣ��\n", master, me );
					break;
				case 1 :
					lock_quest( me, "betrayer", "book" );
					message_vision( "$N����$n˵���㻹���Ȱ������ؼ��ɡ�\n", master, me );
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
		obj->set("gender", "Ů��");
	}
	else
	{
		name = NAME_D->man_name();
		obj->set("gender", "����");
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
		"��"+chinese_number((int)master->query("family/generation")+1)+
		"����ͽ");

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
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ��������������\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000)
	{
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ�ٿ�����\n", master, me);
		return 1;
	}
	obj->move(room);
	command("sys "+obj->query("name")+"��"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")��\n");

	message_vision("$N����$n˵�����Ź�ɽ���ӻر���������ͽ"+obj->query("name")+"��"+to_chinese(dir[i])+"һ����û�����ȥ������ͽ����ͷ����ȡ����ô��\n", master, me);
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
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}

	if ( islocked( me, "betrayer" ) )
		return 1;

	if ( !me->query( "quest/betrayer" ) || me->query( "quest/betrayer/finished" ) )
		return 0;

/*        if (time() - (int)me->query("quest/betrayer/time") > 100 )
	{
		message_vision(WHT"$N����$n˵����ƽʱ�����ڷܵ㣬�������Ż��Ͳ���ȥ��ô���ˣ��´�Ŭ���㣡\n"NOR, master, me);
		destruct(obj);

		me->add("qi",-(int)(me->query("qi")/10));

		return 1;
	}*/
	if (obj->query("userp") == 1)
	{
		message_vision(HIR"$N����$n˵���ҽ���ɱ��ͽ����ȴȥɱ��ң�ȥ�����㣡\n"NOR, master, me);
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

	message_vision("$N����$n˵����ͽ����ͷ����������Ϊ�����������Ż���\n", master, me);
	tell_object(me,HIW + master->query("name") + "�������㣺"
		+ chinese_number(e_bonus) + "��ʵս���飬"
		+ chinese_number(p_bonus) + "��Ǳ�ܣ�"
		+ chinese_number(s_bonus) + "�㽭��������\n"NOR);

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
		tell_object( me, "���Ѿ�ȡ�������ˣ�\n" );
		return 1;
	}
	switch ( random(2) )
	{
		case 0 :
			lock_quest( me, "betrayer", "wei" );
			message_vision( "$N��$n˵�������С��Ҳ�첻�ɣ�������ɽΪΤ��ү�����Ȱɡ�\n", master, me );
			break;
		case 1 :
			lock_quest( me, "betrayer", "book" );
			message_vision( "$N��$n˵��������Ͱ��������ؼ��ɡ�\n", master, me );
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
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}

	// Modified by zeratul 2000-12-24
	if (me->query("combat_exp") <= 1000)
	{
		message_vision(WHT"$N����$n˵����ѧ��δ����������ɽ��\n"NOR, master, me);
		return 1;
	}

	if ( me->query("quest/book") && !me->query( "quest/book/finished" ) )
	{
		if (time() < (int)me->query("quest/book/time") && !wizardp(me) )
		{
			message_vision("$N����$n˵���Ҳ��ǽ���ȥȡ"+
				me->query("quest/book/book")+"����ô���ֻ����ˣ���\n", master, me);
			return 1;
		}
		else
		{
			message_vision( CYN"$N����$n˵�����ܵ������й�ȥ�ˣ���ο�ҪС������Щ��\n"CYN, master, me );
			quest_failed( me, "book" );
		}
	}

	book = new("/clone/quest/questbook");
	book ->set("name", me->query("family/family_name")+"�ܼ�");
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
		message_vision("$N����$n˵�������ܼ������Ǻúõ�ô��\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000)
	{
		message_vision("$N����$n˵���ȵȰɣ����һ�ͷ���һ�¿�����\n", master, me);
		return 1;
	}
	book->move(room);
	command("sys "+book->query("name")+"��"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")��\n");

	message_vision("$N����$n˵�������ؼ����佭������˵�����"+to_chinese(dir[i])+"һ�����֡���ȥ����ȡ�����ɣ�\n", master, me);
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
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}

	if (obj->query("owner") != me->query("id"))
	{
		message_vision("$N����$n˵���ⲻ����Ҫ���ҵ��顣\n",master,me);
		return 1;
	}

	if ( !me->query("quest/book") || me->query( "quest/book/finished" ) )
	{
		message_vision("$N����$n˵����ûҪ���飬��ȥ���������ģ�\n", master, me);
		destruct(obj);
		return 1;
	}

        if (time() - (int)me->query("quest/book/time") > 1500 )
	{
		message_vision("$N����$n˵����ƽʱ�����ڷܵ㣬�Ͳ���ȥ��ô���ˣ��´�Ŭ���㣡\n", master, me);
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

	message_vision("$N����$n˵�������ؼ�����������Ϊ��������һ�󹦣�\n", master, me);
	tell_object(me,HIW + master->query("name") + "�������㣺"
		+ chinese_number(e_bonus) + "��ʵս���飬"
		+ chinese_number(p_bonus) + "��Ǳ�ܣ�"
		+ chinese_number(s_bonus) + "�㽭��������\n"NOR);

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
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}

	if (me->query("combat_exp") <= 100000)
	{
		message_vision(WHT"$N����$n˵����ѧ��δ�������ܳ��顣\n"NOR, master, me);
		return 1;
	}

	if ( islocked( me, "thief" ) )
		return 1;

/*	if (master->query_temp("thiefs") > 3)
	{
		message_vision("$N����$n˵����������������ʲô��ϸ���������£�\n", master, me);
		return 1;
	}
*/
	if ( me->query("quest/thief") && !me->query( "quest/thief/finished" ) )
	{
		if (time() < (int)me->query("quest/thief/time") && !wizardp(me) )
		{
			message_vision("$N����$n˵����ô������ϸ"+ me->query("quest/thief/name")+"����ͷ�أ���\n", master, me);
			return 1;
		}
		else
		{
			message_vision( WHT"$N����$n˵�����ü�ϸ�����˻������������ң�\n"NOR, master, me );
			switch ( random(3) )
			{
				case 0 :
					if( me->query("yipin/joined") )
					{
						lock_quest( me, "thief", "helian" );
						message_vision( "$N����$n˵�������㻹�޷������˵����Σ�ȥ������������ĥ��һ��Ҳ�á�\n", master, me );
						break;
					}
				case 1 :
					lock_quest( me, "thief", "shan" );
					message_vision( "$N����$n˵�������㻹�޷������˵����Σ�ȥ������ү������ĥ��һ��Ҳ�á�\n", master, me );
					break;
				case 2 :
					lock_quest( me, "thief", "betrayer" );
					message_vision( "$N����$n˵�������Ȱѱ�����ͽ�����ɾ��ٹܱ���°ɡ�\n", master, me );
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
		obj->set("gender", "Ů��");
	}
	else
	{
		name = NAME_D->man_name();
		obj->set("gender", "����");
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
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ��������������\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[k]+"/"+file[j]) ))
		room = load_object("/d/"+dir[k]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000)
	{
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ�ٿ�����\n", master, me);
		return 1;
	}
	obj->move(room);
	command("sys "+obj->query("name")+"��"+room->query("short")+"(/d/"+dir[k]+"/"+file[j]+")��\n");

	message_vision("$N����$n˵�����ŵ��ӻر���������Χ��İ���˳��֡���ȥ�鿴һ���ǲ��Ǳ��ɵļ�ϸ��\n", master, me);
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
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}
	if ( islocked( me, "thief" ) )
		return 1;

	if ( !me->query( "quest/thief" ) || me->query( "quest/thief/finished" ) )
		return 0;

/*        if (time() - (int)me->query("quest/thief/time") > 300 )
	{
		message_vision(WHT"$N����$n˵����ƽʱ�����ڷܵ㣬׽�ø���ϸ�Ͳ���ȥ��ô���ˣ��´�Ŭ���㣡\n"WHT, master, me);
		destruct(obj);

//		lock_quest( me, "thief", 3 + random(3) );
		me->add("qi",-(int)(me->query("qi")/10));

		return 1;
	}*/
	if (obj->query("userp") == 1)
	{
		message_vision(HIR"$N����$n˵���ҽ���ɱ��ϸ����ȴȥɱ��ң�ȥ�����㣡\n"NOR, master, me);
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

	message_vision("$N����$n˵����ϸ����ͷ����������Ϊ������һ�󹦣�\n", master, me);
	tell_object(me,HIW + master->query("name")+"�������㣺"
		+ chinese_number(e_bonus) + "��ʵս���飬"
		+ chinese_number(p_bonus) + "��Ǳ�ܣ�"
		+ chinese_number(s_bonus) + "�㽭��������\n"NOR);

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
		tell_object( me, "���Ѿ�ȡ�������ˣ�\n" );
		return 1;
	}
	switch ( random(3) )
	{
		case 0 :
			if( me->query("yipin/joined") )
			{
				lock_quest( me, "thief", "helian" );
				message_vision( "$N����$n˵�������㻹�޷������˵����Σ�ȥ������������ĥ��һ��Ҳ�á�\n", master, me );
				break;
			}
		case 1 :
			lock_quest( me, "thief", "shan" );
			message_vision( "$N����$n˵�������㻹�޷������˵����Σ�ȥ������ү������ĥ��һ��Ҳ�á�\n", master, me );
			break;
		case 2 :
			lock_quest( me, "thief", "betrayer" );
			message_vision( "$N����$n˵�������Ȱѱ�����ͽ�����ɾ��ٹܱ���°ɡ�\n", master, me );
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

// ����������Ҫ����ʦ�Ĺ��ܡ�
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
		message_vision("$N˵����������֮�����й������Ŵ��ã������޹ء���\n", master, ob);
		return 1;
	}

	if (ob->query("combat_exp") < 1000000) {
		message_vision("$N��Ц��������ƾ�����΢ĩ���У�Ҳ�뵽������ȥ��������������Ц����������\n", master, ob);
		return 1;
	}

	if (depth == 0) {
		message_vision(HIR"\n$Nüͷһ�壬��������$n��Ŀ�������$n�������˸���ս��\n"NOR, master, ob);
		ob->start_busy(10);
		call_out("betray", 5, ob, depth + 1);
	} else {
		message_vision(HIR"\n���Σ�$N̾��������Ȼ��ִ����ȥ����Ҳ����ǿ����ֻ�����һ���书���������ͻ�����ȥ�ɡ���\n"NOR, master, ob);
		message_vision(HIR"˵�գ�������$n��ͷ����һ����$nֻ��ȫ�����������಻����ȥ����֮�£����˹�ȥ��\n"NOR, master, ob);
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
		ob->set("title", "��ͨ����");
		ob->set("class", "0");
		ob->delete("family");
		ob->save();
		ob->unconcious();
	}
	
	return 1;
}