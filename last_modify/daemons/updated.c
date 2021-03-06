// /adm/daemons/updated.c
// Modified by Zeratul Jan 6 2001 修改了衰老速度，增加了存款上限判断

#include <ansi.h>;
void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int v1, i, level; 
	mapping my, skill_status, family;
	string *sname, m;
	float exper;
	string name,id,or,type,time;
	int value,make,lv,money_limit,xism_age;

	my = ob->query_entire_dbase();
/*
	if( ob->query("new_mail") == 1 )
	{
		tell_object(ob, HIG "绿林邮差跑步过来递给你一封信，转身就走了。\n" NOR );
//		write(GRN+"\n绿林邮差跑来对你说：这是人家留给您的信！\n\n"+NOR);
		ob->set("new_mail", 0);
	}
*/
// wuyun-jian
	if( ob->query_skill("wuyun-jianfa",1) > 0 )
	{
		ob->set_skill("wuyun-jian", ob->query_skill("wuyun-jianfa",1));
		ob->delete_skill("wuyun-jianfa");
	}
	if( ob->query("family/family_name") == "灵鹫宫")
	{
		ob->set("family/family_name","逍遥派");
	}
// 喇嘛属性
	if( ob->query("family/family_name") == "雪山寺" && 
		ob->query("class") == "bonze")
	{
		ob->set("class", "lama");
	}
// 镇南王府
	if( ob->query("family/family_name") == "大理段家" &&
		!ob->query("guard"))
	{
		ob->set("guard", "镇南王府家臣");
	}
// 不允许比开山祖师还老
	if( ob->query("family/generation")==0) ob->delete("family");
// 强制太监属性
	if( ob->query("gender")=="无性") ob->set("class", "eunach");
	if( ob->query("class")=="eunach") ob->set("gender", "无性");
// 临济庄
	if( ob->query("linji/jing") )
	{
		ob->apply_condition("linji_daxiao", 1);
	}
	if( ob->query("linji/per") )
	{
		ob->apply_condition("linji_tiandi", 1);
	}
	if( ob->query("linji/dex") )
	{
		ob->apply_condition("linji_fengyun", 1);
	}
	if( ob->query("linji/con") )
	{
		ob->apply_condition("linji_longhe", 1);
	}
	if( ob->query("linji/int") )
	{
		ob->apply_condition("linji_zhixin", 1);
	}
// 不允许自制兵器名为corpse, 九阴白骨抓需corpse才能练
	if( (ob->query("weapon/id")== "corpse") )
	{
		ob->set("weapon/id","shiti");
	}
// 官府
	if( ob->query("weiwang") > 100 && ob->query("officerlvl") >0)
	{
		ob->set("weiwang", 80 + 20*ob->query("officerlvl"));
	}
// 登录时记录经验和潜能, 以及登录时间, 为离线信息预留
	ob->set_temp("nowexp", ob->query("combat_exp"));
	ob->set_temp("nowpot",ob->query("potential"));
	ob->set_temp("nowtime", time());
// 潜能上限100000
	if ((ob->query("potential")-ob->query("learned_points"))>100000) 
		ob->set("potential", ob->query("learned_points")+100000);
// 隐性天赋
	if( undefinedp(my["per"]) ) my["per"] = 10 + random(21);
	if( undefinedp(my["kar"]) ) my["kar"] = 10 + random(21);
	if( undefinedp(my["cor"]) ) my["cor"] = 10 + random(21);
	if( undefinedp(my["cps"]) ) my["cps"] = 10 + random(21);
	if( undefinedp(my["sta"]) ) my["sta"] = 10 + random(21);

	if (ob->query("age")>730)
	{
		ob->add("age",-730);
		ob->add("mud_age",-63072000);
	}
	if( userp(ob) || undefinedp(my["max_jing"]) || my["max_jing"]<1 )
	{
		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["age"] - 14) * my["int"];
		else my["max_jing"] = my["int"] * 16 + 100;

		// Modified by zeratul Jan 6 2001
//		if( my["age"] > 60 ) my["max_jing"] -= (my["age"] - 60) * 5 ;
		if ( my["age"] > 60 )
		{
			i = my["age"] - 60;
			i = i * ( i + 1 ) / 2;
			my["max_jing"] -= i;
		}
		// 道家保精：
		if(my["age"] > 60 && (int)ob->query_skill("taoism", 1) >= 120)
		{
			// Modified by zeratul Jan 6 2001
//			my["max_jing"] += (my["age"] - 60) * 5;
			my["max_jing"] += i;
		}

		// 佛家养精：３０岁前补精，３０岁后长精
		if((xism_age=(int)ob->query_skill("buddhism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("hunyuan-yiqi", 1)/10);
		}
		// 紫氲吟长精：
		if((xism_age=(int)ob->query_skill("ziyunyin", 1)) > 39) 
		{
			xism_age = xism_age/2;
			xism_age -= 14;
			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("zixia-shengong", 1) / 20);
		}

		if(my["max_jingli"] > 0) my["max_jing"] += my["max_jingli"] / 4;
		
		// Modified by zeratul Jan 6 2001
		if ( my["max_jing"] < 1 )
			my["max_jing"] = 1; 
	}
	if( userp(ob) || undefinedp(my["max_qi"]) || my["max_qi"] < 1 )
	{
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else my["max_qi"] = my["con"] * 16 + 100;

		// Modified by zeratul Jan 6 2001
//		if( my["age"] > 60 ) my["max_qi"] -= (my["age"] - 60) * 5;
		if ( my["age"] > 60 )
		{
			i = my["age"] - 60;
			i = i * ( i + 1 ) * 2;
			my["max_qi"] -= i;
		}

		// 佛家保气：
		if(my["age"] > 60 && (int)ob->query_skill("buddhism", 1) >= 120)
		{
			// Modified by zeratul Jan 6 2001
//			my["max_qi"] += (my["age"] - 60) * 5;
			my["max_qi"] += i;
		}

		// 道家正一派练气：３０岁前补气，３０岁后长气
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("taiji-shengong", 1) / 10);
		}

		// 道家全真派练气：３０岁前补气，３０岁后长气
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("xiantian-qigong", 1) / 10);
		}

		// 正气诀长气：
		if((xism_age=(int)ob->query_skill("zhengqijue", 1)) > 39) 
		{
			xism_age = xism_age/2;
			xism_age -= 14;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("zixia-shengong", 1) / 20);
		}

		// 毒技练气：３０岁前补气，３０岁后长气
		if((xism_age=(int)ob->query_skill("poison", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("huagong-dafa", 1) / 10);
		}
		// 内力可长气血
		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;
		
		// Modified by zeratul Jan 6 2001
		if ( my["max_qi"] < 1 )
			my["max_qi"] = 1;
			
		// 体力与年龄相关
		if( my["age"] <= 14 ) my["max_tili"] = 100;
		else if( my["age"] <= 30 )
			my["max_tili"] = 100 + (my["age"]-14)*my["sta"];
		else my["max_tili"] = my["sta"] * 16 + 100;
		if( my["age"] > 60 ) my["max_tili"] -= (my["age"] - 60) * 5;
	}

	if (wizardp(ob)) return;

	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) ) my["eff_qi"] = my["max_qi"];
	if( my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
	if( my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
	if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
	if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
	if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];

	exper = to_float(ob->query("combat_exp"));

	if ( !(skill_status = ob->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
//		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "mahayana"
		&& sname[i] != "lamaism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" 
		&& sname[i] != "qimen-wuxing" 
		&& sname[i] != "poison" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			ob->set_skill(sname[i], level);
		}
	}

	// 限制存款数量。
	// Modified by zeratul Jan 6 2001
	ob->set( "max_balance", 200000 + ob->query( "combat_exp" ) );
	if ( ob->query( "balance" ) > ob->query( "max_balance" ) )
		ob->set( "balance", ob->query( "max_balance" ) );
	
}
