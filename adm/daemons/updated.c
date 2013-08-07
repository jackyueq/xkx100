// /adm/daemons/updated.c
// Modified by Zeratul Jan 6 2001 �޸���˥���ٶȣ������˴�������ж�

#include <ansi.h>;
void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int v1, i, j, level, max; 
	mapping my, skill_status, family, smap, pmap;
	string *sname, m,hometown;
	float exper;
	string name,id,or,type,time;
	int value,make,lv,money_limit,xism_age;

	my = ob->query_entire_dbase();
	smap = ob->query_skill_map();
	pmap = ob->query_skill_prepare();
	if( ob->query("degree") )
	{
		if(ob->query("gongming/lvl"))
			ob->set("degree", ob->query("gongming/rank"));
		else ob->delete("degree");
	}
// bixie-jian
	if( ob->query_skill("pixie-jian",1) > 0 )
	{
		ob->set_skill("bixie-jian", ob->query_skill("pixie-jian",1));
		ob->delete_skill("pixie-jian");
	}
	if( ob->query_skill("shenlong-xinfa",1) > 0 )
	{
		ob->set_skill("dulong-dafa", ob->query_skill("shenlong-xinfa",1));
		ob->delete_skill("shenlong-xinfa");
		ob->map_skill("force", "dulong-dafa");
	}
	if( ob->query_skill("shedao-qigong",1) > 0 )
	{
		ob->set_skill("shenlong-staff", ob->query_skill("shedao-qigong",1));
		ob->delete_skill("shedao-qigong");
	}
	if( ob->query_skill("pixie-sword",1) > 0 )
	{
		ob->set_skill("bixie-sword", ob->query_skill("pixie-sword",1));
		ob->delete_skill("pixie-sword");
	}
	for (i = sizeof(smap)-1;i >= 0;i --)
		if ((string)smap[keys(smap)[i]] == "pixie-jian")
			ob->map_skill(keys(smap)[i]);
	for (i = sizeof(smap)-1;i >= 0;i --)
		if ((string)smap[keys(smap)[i]] == "pixie-sword")
			ob->map_skill(keys(smap)[i]);
	ob->reset_action();
// wuyun-jian
/*	if( !ob->query_skill("xuantian-wuji",1) &&
		ob->query_skill("kunlun-shenfa",1) > 0 )
	{
		ob->delete_skill("kunlun-shenfa");
	}*/
/*	
	if( ob->query_skill("wuyun-jianfa",1) > 0 )
	{
		ob->set_skill("wuyun-jian", ob->query_skill("wuyun-jianfa",1));
		ob->delete_skill("wuyun-jianfa");
	}*/
/*	if( ob->query("family/family_name") == "���չ�")
	{
		ob->set("family/family_name","��ң��");
	}*/
	
// ��������
	if( ob->query("family/family_name") == "ѩɽ��" && 
		ob->query("class") == "bonze")
	{
		ob->set("class", "lama");
	}
// ��������
	if( ob->query("family/family_name") == "����μ�" &&
		!ob->query("guard"))
	{
		ob->set("guard", "���������ҳ�");
	}
	if( ob->query("no_get")) ob->delete("no_get");
// ������ȿ�ɽ��ʦ����
	if( ob->query("family/generation")==0) ob->delete("family");
//	if( ob->query("family/generation")>=100)
//	      ob->set("family/genearation",99);
// ǿ��̫������
	if( ob->query("gender")=="����") ob->set("class", "eunach");
	if( ob->query("class")=="eunach") ob->set("gender", "����");
// �ټ�ׯ
	if( ob->query("linji/jing") )
	{
		ob->apply_condition("linji_daxiao", 1);
	}
// ���������Ʊ�����Ϊcorpse, �����׹�ץ��corpse������
	if( (ob->query("weapon/id")== "corpse") )
	{
		ob->set("weapon/id","shiti");
	}
// �ٸ�
	if( ob->query("weiwang") > 100 && ob->query("officerlvl") >0)
	{
		ob->set("weiwang", 80 + 20*ob->query("officerlvl"));
	}
// ��¼ʱ��¼�����Ǳ��, �Լ���¼ʱ��, Ϊ������ϢԤ��
// ת�Ƶ�logind.c
//	ob->set_temp("nowexp", ob->query("combat_exp"));
//	ob->set_temp("nowpot", ob->query("potential"));
//	ob->set_temp("nowtime", time());
// Ǳ������100000 �����ް��� ������������ 10��
// ����ת�Ƶ�chard.c ���߲�����ȥ����Ǳ��
/*
	if ((ob->query("potential")-ob->query("learned_points"))>100000) 
		ob->set("potential", ob->query("learned_points")+100000);
        if( ob->query("shen")>1000000) ob->set("shen",1000000);
        if( ob->query("shen")<-1000000) ob->set("shen",-1000000);
        if( ob->query("score")>100000) ob->set("score",100000);
*/        
// �����츳
	if( undefinedp(my["per"]) ) my["per"] = 10 + random(21);
	if( undefinedp(my["kar"]) ) my["kar"] = 10 + random(21);
	if( undefinedp(my["cor"]) ) my["cor"] = 10 + random(21);
	if( undefinedp(my["cps"]) ) my["cps"] = 10 + random(21);
	if( undefinedp(my["sta"]) ) my["sta"] = 10 + random(21);
	if( undefinedp(my["spi"]) ) my["spi"] = 10 + random(21);

	max = 40 + SCBORN_D->query_scborn_times(ob)*5;
	if( my["int"] > max ) my["int"] = max;
	if( my["con"] > max ) my["con"] = max;
	if( my["str"] > max ) my["str"] = max;
	if( my["dex"] > max ) my["dex"] = max;
	if( my["per"] > max ) my["per"] = max;
	if( my["kar"] > max ) my["kar"] = max;
	if( my["cor"] > max ) my["cor"] = max;
	if( my["cps"] > max ) my["cps"] = max;
	if( my["sta"] > max ) my["sta"] = max;
	if( my["spi"] > max ) my["spi"] = max;


	if (ob->query("age")>730)
	{
		ob->add("age",-730);
		ob->add("mud_age",-63072000);
	}
	if( userp(ob) || undefinedp(my["max_jing"]) || my["max_jing"]<1 )
	{
		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 30 )
			my["max_jing"] = 100 + (my["age"] - 14) * my["int"];
		else my["max_jing"] = my["int"] * 16 + 100;

		// Modified by zeratul Jan 6 2001
//		if( my["age"] > 60 ) my["max_jing"] -= (my["age"] - 60) * 5 ;
		if ( my["age"] > 60 )
		{
			i = my["age"] - 60;
			i = i * ( i + 1 ) / 2;
			my["max_jing"] -= i;
		}
		// ���ұ�����
		if(my["age"] > 60 && (int)ob->query_skill("taoism", 1) >= 120)
		{
			// Modified by zeratul Jan 6 2001
//			my["max_jing"] += (my["age"] - 60) * 5;
			my["max_jing"] += i;
		}

		// ���������������ǰ������������󳤾�
		if((xism_age=(int)ob->query_skill("buddhism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("hunyuan-yiqi", 1)/10);
			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("zhanzhuang-gong", 1)/10);
			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("baiyun-xinfa", 1)/10);
		}
		// �����������
		if((xism_age=(int)ob->query_skill("ziyunyin", 1)) > 39) 
		{
			xism_age = xism_age/2;
			xism_age -= 14;
			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("zixia-shengong", 1) / 20);
		}

		if(my["max_jingli"] > 0) my["max_jing"] += my["max_jingli"] / 4;
		if ( my["max_jing"] < 1 ) my["max_jing"] = 1; 
	}
	if( userp(ob) || undefinedp(my["max_qi"]) || my["max_qi"] < 1 )
	{
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 )
			my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else my["max_qi"] = my["con"] * 16 + 100;

		// Modified by zeratul Jan 6 2001
//		if( my["age"] > 60 ) my["max_qi"] -= (my["age"] - 60) * 5;
		if ( my["age"] > 60 )
		{
			i = my["age"] - 60;
			i = i * ( i + 1 ) * 2;
			if ( my["max_qi"] > i)
			my["max_qi"] -= i;
			else my["max_qi"] = 10;  
		}

		// ��ұ�����
		if(my["age"] > 60 && (int)ob->query_skill("buddhism", 1) >= 120)
		{
			// Modified by zeratul Jan 6 2001
//			my["max_qi"] += (my["age"] - 60) * 5;
			i = my["age"] - 60;
			my["max_qi"] += i;
		}

		// ������һ��������������ǰ���������������
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("taiji-shengong", 1) / 10);
		}

		// ����ȫ����������������ǰ���������������
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("xiantian-qigong", 1) / 10);
		}

		// ������������
		if((xism_age=(int)ob->query_skill("zhengqijue", 1)) > 39) 
		{
			xism_age = xism_age/2;
			xism_age -= 14;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("zixia-shengong", 1) / 20);
		}

		// ����������������ǰ���������������
		if((xism_age=(int)ob->query_skill("poison", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("huagong-dafa", 1) / 10);		        
		             
		}
		// �����ɳ���Ѫ
		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;
		if ( my["max_qi"] < 1 ) my["max_qi"] = 1;
			
		// �������������
		if( my["age"] <= 14 ) my["max_tili"] = 100;
		else if( my["age"] <= 30 )
			my["max_tili"] = 100 + (my["age"]-14)*my["sta"];
		else my["max_tili"] = my["sta"] * 16 + 100;
		if( my["age"] > 60 ) my["max_tili"] -= (my["age"] - 60) * 5;
	}

        // ���ƴ��������
        // Modified by zeratul Jan 6 2001
        ob->set( "max_balance", 500000000 + ob->query( "combat_exp" ) );
        if ( ob->query( "balance" ) > ob->query( "max_balance" ) )
                ob->set( "balance", ob->query( "max_balance" ) );
        // �������������������ޡ�
	if( ob->query("weapon/lv") > (ob->query_sta() + ob->query_con())/3)
		ob->set("weapon/lv", (ob->query_sta() + ob->query_con())/3);

	if (wizardp(ob)) return;

	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) ) my["eff_qi"] = my["max_qi"];
	if( my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
	if( my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
	if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
	if( my["qi"] > my["eff_qi"] ) my["qi"] = my["eff_qi"];
	if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];

	exper = to_float(ob->query("combat_exp"));
	if ( !(skill_status = ob->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper &&
			exper > 100.0 && SKILL_D(sname[i])->type()!="knowledge" &&
			sname[i] != "qiankun-danuoyi" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			ob->set_skill(sname[i], level);
		}
	}
}
