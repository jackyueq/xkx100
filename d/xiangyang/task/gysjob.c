// Last Modified by Sir 2003.11.13
#include <ansi.h>
#include <dbase.h>
#include <login.h>


mixed names = ({
	({
//	"������","�彣��","��ɽͯ��",
//	"ʯ����","����ͤ","������","�𴦻�","��մ�ʦ",
//	"�ɽ�","����","����","����","����ʦ","����",
//"����ʦ",
"��������",
"������",
"�������",
"�����ʦ",
	"��ܽ","����ͨ","³�н�","����ʦ̫","����ʦ̫","��Զ��","Ī����",
	"������","��ҩʦ","��׺�","��Ұ��","��־ƽ","С��Ů","����ͨ","������",
	"���˷�","ŷ����","�������","����","������",	"������","����Ⱥ",
	"�����","�����ʦ","���Ʊ���",	"ׯ����","˫��","������",
	"ľ����","��Զɽ","������","������","����","�ڰ���","������",
	"��ص���","����","����",	"ΤһЦ","лѷ","�μ�","����",
	"�Ŵ�ɽ",	"���Ǻ�","�½���",	"������",
	"�ⲻƽ","���ҵ���","���ɵ���","��ص���","���ŵ���","������",
	"��˼��","����̩","���Ƴ�","������","���׷�","����ʦ̫","����ʦ̫",
	"����ʦ̫","����ʦ̫","����ʦ̫","����ϼ","������","����ʦ̫","����ʦ̫",
	"Ī��","������","����־",	"�¼���","������","������","��־��",
	"��־��","�´�ͨ","��־��",	"����","��־��","Ƥ����",
	"��־��","�ﲻ��","̷����","��־ƽ","����һ","��־��","�ι�","�κ�",
	"�μ�","�μ�","�ξ�","����","����","����","����Ϫ","����","ŷ����",
	"��۴�ʦ","Ԫ��","�󲡴�ʦ",	"�󼲴�ʦ","��ƣ��ʦ",
	"����ʦ",	"������ʦ",	"����","����",
	"����","����","����","����","��ͨ","����","����","����","����","����",
	"Ԫ��","Ԫ��","Ԫ��","Ԫ��","Ԫ��","Ԫ��","Ԫ�","Ԫ��","Ԫ��","Ԫ��",
	"Ԫ��","Ԫŭ","Ԫ��","Ԫ��","Ԫˡ","Ԫʹ","Ԫ��","ԪϢ","Ԫ�","Ԫ��",
	"ԪԹ","ʤ��",
	}),
});
int ask_job()
{ 
	object ob, me,gift,*team;
	int exp,position;
	string target,myfam,obfam,job_type;
	ob=this_player();
	me=this_object();
	exp=ob->query("combat_exp");

//guoys_mis_flat == 1  ������� 
//guoys_mis_target     Ŀǰ��Ŀ��
//condition(guoys_mis) ������������
	
	if (interactive(ob) && ob->query_temp("guoys_mis_target") && 
		(int)ob->query_condition("guoys_mis") )
	{
		tell_object(ob,"�����������һ������������һ�ε�����û��ɣ���\n"); 
		return 1;
	}
	if (interactive(ob) && !ob->query_temp("guoys_mis_target") &&
		(int)ob->query_condition("guoys_mis"))
	{
		tell_object(ob,"�����������һ������������²������ȵȻ�ɣ���\n"); 
		return 1;
	}
	if(exp<=100000)
	{
		tell_object(ob,"��������Ц����������书̫���ˣ�����ǿ�������ɡ���\n");	
		return 1;
	}
   	ob->set_temp("guoys_mis_flag",1);
	
	target = names[0][random(sizeof(names[0]))];
	ob->apply_condition("guoys_mis",30);    
	ob->set_temp("guoys_mis_target", target);
	call_out("begin_kill",10,ob,target);
	tell_object(ob,CYN "�������˵�ͷ������˵�����ɹ���������һ�����ְ��࣬����Ҫ��ɱ"+target+"����ȥ������һ�¡�\n"NOR);
	message_vision("��������������һ·��Σ�����أ���ض��С�ġ���\n",me);
	message("channel:qst", HIR"��������ʿ��"+ob->query("name")+"���뱣��"+ob->query_temp("guoys_mis_target")+"����\n"NOR, users());
	return 1;
}
/*int accept_object(object who, object ob,object me)
{
	if ( ob->query("id") != "corpse")
	{
		tell_object(who,"���������������������Ҫ�Ķ�������\n");
		return 0;
	}
	if ( !who->query_temp("guoys_mis_target") )
	{
		tell_object(who,"�����ʵ������������������ô����\n");
		return 0;
	}
	if ( who->query_temp("guoys_mis_flag")!= 3 )
	{
		tell_object(who,"�����ʵ������������û��ɰɣ���\n");
		return 0;
	}
	if (ob->query_temp("must_killby")!= who->query("id") ||
			ob->query("victim_user")||who->query_temp("guoys_mis_given") )
		{
			tell_object(who,"����̾�˿�����˵���������º���ɱ�����˰ɣ���\n");
			return 0;
		} 
	who->set_temp("guoys_mis_given",1);
  destruct(ob);
  ok(who);
//	call_out("destroying", 0, ob);
//	call_out("ok", 0, who);
	return 1;
}
void ok(object who)
{
	int exp,pot;
	if (!who) return;
	tell_object(who,"����������ϲ���޵������ɵĺã����°��¸ɾ����䣬�����سɴ�������\n");
	//ȥ��ԭ���������ӵ�zzz_job_count����
	if( who->query("zzz_job_count")) who->delete("zzz_job_count",1);
	
	exp=400+random(200);
	pot=exp/3+random(60);
	who->add("potential",pot);
	who->add("combat_exp",exp);
	who->delete_temp("guoys_mis_target");
	who->delete_temp("guoys_mis_given");
	who->delete_temp("guoys_mis_flag");
	who->clear_condition("guoys_mis");	
	tell_object(who,HIW"�㱻�����ˣ�" + 
		chinese_number(exp) + "��ʵս���飬" +
		chinese_number(pot) + "��Ǳ�ܡ�\n"+ NOR);
	return;
}


void destroying(object obj)
{
	destruct(obj);
	return;
}
*/
object create_killer( object me )
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;	
	object obj, thief_master, weapon;
	mapping skl;
	string *skillname;
	int skilllvl,topexp;
	int inc_exp,inc_lvl,i,j,k;
	object *inv;
	string *family, weapon_type;
  string *masters = ({
	"baituo/ouyangfeng",	//lingshe-zhangfa	shexing-diaoshou hamagong
	"dali/duanzc",	//duanyun-fu		sun-finger
	"dali/daobaifeng",	//feifeng-whip		jinyu-quan 	wuluo-zhang
	"dali/yideng",	//duanjia-sword		six-finger
	"emei/miejue",	//huifeng-jian		jinding-zhang 	tiangang-zhi
	"emei/feng",         //yanxing-dao		jinding-zhang 	tiangang-zhi
	"gaibang/hong",		//dagou-bang		xianglong-zhang	suohou-hand
	"gaibang/jian",		//fengmo-staff		jianlong-zaitian
	"gumu/longnv",	//yunv-jian		meinv-quan
	"gumu/limochou",	//qiufeng-chenfa	meinv-quan
	"gumu/yangguo",	//xuantie-sword		anran-zhang
	"heimuya/dongfang",	//bixie-jian		xuantian-zhi
	"heimuya/ren",		//wuyun-jian		xuantian-zhi
	"heimuya/weng",		//shigu-bifa		xuantian-zhi
	"hengshan/xian",		//hengshan-jian		tianchang-zhang	chuanyun-shou
	"henshan/moda",		//hengshan-sword	biluo-zhang	luoyan-hand
	"honghua/chen-jialuo",	//luohua-jian		benlei-shou	baihua-cuoquan
	"honghua/wu-chen",	//zhuihun-jian		benlei-shou
	"huashan/yue-buqun",	//huashan-sword		huashan-ken
	"huashan/feng-buping",	//kuangfeng-jian	poyu-quan	hunyuan-zhang
	"huashan/feng",		//lonely-sword		poyu-quan	hunyuan-zhang
	"kunlun/hezudao",	//liangyi-sword		kunlun-strike
	"kunlun/hetaichong",	//xunlei-sword		zhentian-cuff	chuanyun-leg
	"lingjiu/tonglao",	//tianyu-qijian		liuyang-zhang	zhemei-shou
	"lingxiao/bai",		//xueshan-sword		snow-strike
	"lingxiao/shipopo",	//jinwu-blade		snow-strike
	"mingjiao/zhangwuji",	//shenghuo-ling		qishang-quan
	"mingjiao/yintianzheng",	//lieyan-dao		sougu
	"mingjiao/weiyixiao",	//liehuo-jian		hanbing-mianzhang
	"murong/murong-fu",	//murong-sword		canhe-finger	xingyi-strike
	"nanshaolin/tianhong",	//weituo-chu		jingang-cuff
	"nanshaolin/tianjing",	//riyue-whip		wuxiang-finger
	"qingcheng/yu",		//songfeng-jian		wuying-leg	cuixin-strike
	"quanzhen/wang",		//quanzhen-jian		chunyang-quan	haotian-zhang
	"quanzhen/ma",		//duanyun-bian		chunyang-quan	haotian-zhang
	"shaolin/da-mo",	//			nianhua-zhi	sanhua-zhang
	"shaolin/xuan-nan",	//wuchang-zhang		yizhi-chan  banruo-zhang
	"shaolin/du-nan",	//riyue-bian		jingang-quan
	"shenlong/hong",		//ruyi-hook		yingxiong-sanzhao	shenlong-bashi
	"shenlong/su",		//meiren-sanzhao	jueming-leg	huagu-mianzhang
	"shenlong/pang",		//shenlong-staff	huagu-mianzhang	jueming-leg
	"songshan/zuo",		//songshan-sword	songyang-strike	poyun-hand
	"taishan/tianmen",	//taishan-sword		kuaihuo-strike
	"taohua/huang",	//yuxiao-jian		tanzhi-shentong	lanhua-shou
	"taohua/lu",		//luoying-shenjian	xuanfeng-leg	luoying-zhang
	"tiezhang/qqren",	//			tiezhang-zhangfa
	"tiezhang/qqzhang",	//tiexue-qiang		zhusha-zhang
	"wudang/zhang",	//taiji-jian		taiji-quan
	"wudang/yu",		//liangyi-jian		taiji-quan
	"wudujiao/hetieshou",	//wudu-goufa		wudu-zhang	qianzhu-wandushou
	"xiaoyao/xiaoyaozi",	//ruyi-dao		zhemei-shou	liuyang-zhang
	"xingxiu/ding",		//			chousui-zhang	sanyin-wugongzhao
	"xingxiu/chuchen",	//tianshan-zhang	chousui-zhang	sanyin-wugongzhao
	"xueshan/jiumozhi",	//			huoyan-dao
	"xueshan/fawang",	//riyue-lun		dashou-yin	yujiamu-quan
	"xueshan/xuedao",	//xue-dao		dashou-yin
	"yunlong/chen",		//yunlong-jian		yunlong-zhua	yunlong-shou
	});
	seteuid(getuid());
	obj = new("/d/xiangyang/task/killer");
	obj ->set("owner", me->query("id"));
	hp_status = me->query_entire_dbase();
//	obj->set("str", hp_status["str"]+ 15);
	obj->set("str", hp_status["dex"]+10);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
//	obj->set("dex", hp_status["dex"]+ 15);
	obj->set("dex", hp_status["str"]-5);
	obj->set("age", hp_status["age"]+ 2);

	obj->set("max_jing",  hp_status["max_jing"]*3/2);
	obj->set("eff_jing",  hp_status["max_jing"]*3/2);
	obj->set("jing",      hp_status["max_jing"]*3/2);
	if ((hp_status["max_qi"]*2)<2000)
	{ 
		obj->set("max_qi", 2000);
		obj->set("eff_qi", 2000);
		obj->set("qi",     2000);
	}  
	else		
	{
		obj->set("max_qi", hp_status["max_qi"]*3/2);
		obj->set("eff_qi", hp_status["max_qi"]*3/2);
		obj->set("qi",     hp_status["max_qi"]*3/2);
	}
	if ((hp_status["max_neili"])<2000)
	{
		obj->set("max_neili",2000);
		obj->set("neili",2000);
		obj->set("jiali", 100);
	}
  else 
	{ 
		obj->set("max_neili", hp_status["max_neili"]);
		obj->set("neili",     hp_status["max_neili"]);
		obj->set("jiali",     hp_status["max_neili"]/20);
	}
	topexp = (int) me->query("combat_exp");
	obj->set("combat_exp", topexp + 100);
/* 1000��������ң��ڴ˳����������� */
	if(me->query("combat_exp") > 10000000)
		obj->set("shen", -1*hp_status["shen"]);
	
/* skill */
	skl = me->query_skills();
	skilllvl=100;	
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}
	}
//	skilllvl-=10;
	inc_exp = me->query("combat_exp")/1000000;
	inc_lvl = skilllvl*(inc_exp+1)/(inc_exp+2);
	skilllvl -= 30;
	if (skilllvl > inc_lvl) skilllvl = inc_lvl;
	
	i = random( sizeof(masters) );
	thief_master = new ( CLASS_D(masters[i]) );
	if ( mapp(skill_status = thief_master->query_skills()) )
	{
		skill_status = thief_master->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			obj->set_skill(sname[i], skilllvl);
		}
	}
/* skill map*/
	if ( mapp(map_status = thief_master->query_skill_map()) )
	{
		mname = keys(map_status);

		for(i=0; i<sizeof(map_status); i++)
		{
			obj->map_skill(mname[i], map_status[mname[i]]);
		}
	}
/* skill prepare*/
	if ( mapp(prepare_status = thief_master->query_skill_prepare()) )
	{
		pname = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++)
		{
			obj->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	inv = all_inventory(thief_master);
	for ( i = 0; i < sizeof(inv); i++ )
		if( inv[i]->query("equipped") && stringp(weapon_type = inv[i]->query("skill_type")) )
		{
			weapon = new( "/clone/weapon/" + weapon_type );			
			weapon->set("value", 0);
			weapon->move( obj );			
			weapon->wield();
		}
	obj->set( "family_name", thief_master->query("family/family_name") );
	obj->set( "chat_chance_combat", 80);
 	destruct( thief_master );
	return obj;
}

void begin_kill(object me,string target)
{
	object obj,*obs;
	int i;
	me->remove_call_out("begin_kill");
	obs = all_inventory(environment(me));
	if ( me->query_temp("guoys_mis_flag") == 1 && (int)me->query_condition("guoys_mis") )
	{
		call_out("begin_kill",10,me,target);
		return;
	}
	else if ( me->query_temp("guoys_mis_flag") == 2 && (int)me->query_condition("guoys_mis") )
	{
		for(i=0; i<sizeof(obs); i++)
		{
			if( !living(obs[i])||userp(obs[i])||obs[i]==me ) continue;
			if(obs[i]->query("name")==me->query_temp("guoys_mis_target"))		
				me->set_temp("guoys_mis_flag",3);
		}
		if ( me->query_temp("guoys_mis_flag") ==2 )
		{
			call_out("begin_kill",5,me,target);
			return;
		}
		else
		{
			obj=create_killer( me );
			obj->move(environment(me));
			if(environment(me)->query("no_fight")) obj->set_leader(me);
			obj->set_temp("must_killby",me->query("id"));
			obj->set("owner",me->query("id"));
			obj->set("title",HIR"���ְ���"NOR);
			if (random(30)==1)
			{
//				obj->set("title",HIR""NOR);
				obj->add_temp("apply/attack",200);
				obj->add_temp("apply/dodge",200);
				obj->add_temp("apply/damage",200);
				obj->add_temp("apply/defense",200);
				obj->add_temp("apply/armor",200);
				obj->add("combat_exp",obj->query("combat_exp"));
			}
	message_vision( GRN"\n$N����"+target+"����һ����Ц������"+target+"ȫ�����µĺ�ë�������𣬲���������\n"NOR,obj); 
	message_vision(HIY"$N��$n�ȵ����󵨿�ͽ������������Ұ����\n"NOR,me,obj);
	message_vision(HIY"$N����һЦ��Ҫ�������£�ȥ���ɣ���\n"NOR,obj);
			obj->kill_ob(me);
			me->kill_ob(obj);
			if (!me->is_busy())
			 me->start_busy(1);
		}
	}
}