// /inherit/char/manager.c

// last modified by sega 4/13/2000
// �޸���ͽ������Ϊʦ���Ĺ���,quest �ĵȼ�,�Ǻ�
// Modified by Constant Jan 11 2001
// Modified by sir 4/12/2001
// �޸ı��ɼ�ϸ,13��һ��,��ɺ󸽼�pot,score����
// Modified by Zeratul May 3 2001
//�޸���ͽ����10��һ�֣���ɺ������ʦ���д�������skill 1��,����score����
//Modified by sir 5.1.2002

#include <dbase.h>
#include <login.h>
#include <ansi.h>
#include <quest.h>
#define ONE_DAY                 (86400 / 365)
int is_manager() {return 1;}
///////��ʼ�ؼ�����
int party_quest_book(object me)
{
	object book, room, master = this_object();
	string *dir, *file, place;
	int i,j;

	me = this_player();
  if (!me->query("family/family_name"))
   {
		message_vision("$N����$n˵����λ"+RANK_D->query_respect(me)+"�β�������"+master->query("family/family_name")+"��\n", master, me);
		return 1;   	
   	}
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������" + me->query("family/family_name") + "ȥ�ɡ�\n", master, me);
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
		if (time() < (int)me->query("quest/book/time") )
		{
			message_vision("$N����$n˵���Ҳ��ǽ���ȥȡ" + me->query("quest/book/book") + "����ô���ֻ����ˣ���\n", master, me);
			return 1;
		}
		else
		{
			message_vision( CYN"$N����$n˵�����ܵ������й�ȥ�ˣ���ο�ҪС������Щ��\n"CYN, master, me );
			quest_failed( me, "book" );
		}
	}

	dir = get_dir("/d/");
	i = random(sizeof(dir));
	file = get_dir("/d/"+dir[i]+"/");
	j = random(sizeof(file));
	if (
		sizeof(file[j]) < 2 ||
		file[j][sizeof(file[j])-2..sizeof(file[j])-1] != ".c" ||
		dir[i]=="gaibang" ||
		dir[i]=="gaochang" ||
    dir[i]=="gumu"	||
    dir[i]=="taohua" ||
    dir[i]=="heizhao" ||
    dir[i]=="shenlong" ||
    dir[i]=="wanjiegu" ||
    dir[i]=="yanziwu" ||
		dir[i]=="death" ||
		dir[i]=="wizard" ||
		dir[i]=="working" ||
		dir[i]=="binghuo" ||
		dir[i]=="xiakedao" ||
		dir[i]=="npc")
	{
		message_vision("$N����$n˵�������ؼ������Ǻúõ�ô��\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);
	if (room->query_max_encumbrance() < 10000000	
	|| !mapp(room->query("exits")) //add by qingyun
	|| room->query("no_quest")		//add by qingyun
)
	{
		message_vision("$N����$n˵���ȵȰɣ����һ�ͷ���һ�¿�����\n", master, me);
		return 1;
	}
	book = new("/clone/quest/questbook");
	book ->set("name", me->query("family/family_name")+"�ؼ�");
	book ->set("owner", me->query("id"));
	book->move(room);
	command("qst "+book->query("name")+"��"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")��\n");

	message_vision("$N����$n˵�������ؼ����佭������˵�����" + to_chinese(dir[i]) + "һ�����֡���ȥ����ȡ�����ɣ�\n", master, me);
	me->set("quest/book/book", book->query("name"));
	me->set("quest/book/family", me->query("family/family_name"));
	me->set("quest/book/time", time() + 500 );
	me->set("quest/book/dest", to_chinese(dir[i]) );
	me->delete( "quest/book/finished" );
	return 1;
}
int accept_quest_book(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, num, times, e_bonus, p_bonus, s_bonus;
	int cost;

	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������" + me->query("family/family_name") + "ȥ�ɡ�\n", master, me);
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

	num=(int)me->query("perform/number")+1;	
	if (num<4) times=num;
	else times=4;   
	
	e_bonus = 100 + random( 50 );
	cost = time() - ((int)me->query("quest/book/time")-500); //���˶���ʱ�����

	e_bonus += e_bonus * cost /250; // cost ���1500  Ҳ�����ı�
	p_bonus = 12 + random( e_bonus / 8 );
	s_bonus = random(10)+ 10 * times;

	me->add("combat_exp",e_bonus);
	me->add("potential",p_bonus);
	me->add("family/fealty",s_bonus);
	me->set_temp("prize_reason","�ؼ�");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",e_bonus);
	me->set_temp("prize_pot",p_bonus);
	me->add("family/gongxian",1);
    

	message_vision("$N����$n˵�������ؼ���������Ϊ��������һ�󹦣�\n", master, me);
	tell_object(me,HIW + "��������߽����������" + chinese_number(e_bonus) + "��ʵս���飬" + chinese_number(p_bonus) + "��Ǳ�ܣ�������" + chinese_number(s_bonus) + "��ʦ���ҳϡ�\n"NOR);

	quest_finished( me, "book" );
	return 1;
}
//////////�ؼ�����//////////
//////////��ʼ��ͽ���� ////////////
object create_betrayer(object me)
{	
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	object room, obj, weapon, armor, master = this_object();
	object *inv;
	string weapon_type;
	mapping skl;
	string *skillname;
	int skilllvl;
  int i,j;

  seteuid(getuid());
	obj = new("/clone/quest/questman");
	obj ->set("owner", me->query("id"));
	obj ->set("quest", "betrayer");
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

//	obj->set("name", name["name"],({name["id"]}));
	obj->set_name(name["name"],({me->query("id")+"'s betrayer",name["id"],"betrayer"}));
	hp_status = me->query_entire_dbase();
	obj->set("str", hp_status["str"]);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
	obj->set("dex", hp_status["dex"]+random(20));
	obj->set("age", hp_status["age"]+2);

	obj->set("max_jing",  hp_status["max_jing"]);
	obj->set("eff_jing",  hp_status["max_jing"]);
	obj->set("jing",      hp_status["max_jing"]);
	obj->set("max_qi",    hp_status["max_qi"]*3/2);
	obj->set("eff_qi",    hp_status["max_qi"]*3/2);
	obj->set("qi",	      hp_status["max_qi"]*3/2);
	obj->set("max_neili", hp_status["max_neili"]);
	obj->set("neili",     hp_status["max_neili"]);
	obj->set("jiali",     hp_status["max_neili"]/20);
	obj->set("combat_exp",hp_status["combat_exp"]*5/4+100);
/* 1000��������ң��ڴ˳����������� */
	if(me->query("combat_exp") > 100000000)
			obj->set("shen", -1 * master->query("shen_type") * obj->query("combat_exp") / 2000);
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
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			obj->set_skill(sname[i], skilllvl*11/10-20);
		}
	}
/* skill map*/
	if ( mapp(map_status = master->query_skill_map()) )
	{
		mname = keys(map_status);

		for(i=0; i<sizeof(map_status); i++)
	{
			obj->map_skill(mname[i], map_status[mname[i]]);
		}
	}
/* skill prepare*/
	if ( mapp(prepare_status = master->query_skill_prepare()) )
	{
		pname = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++)
		{
			obj->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
/* weapon */
	inv = all_inventory(master);
	for ( i = 0; i < sizeof(inv); i++ )
		if( inv[i]->query("equipped") && stringp(weapon_type = inv[i]->query("skill_type")) )
		{
			weapon = new( "/clone/weapon/" + weapon_type );			
			weapon->set("value", 0);
			weapon->move( obj );			
			weapon->wield();
		}
/* family */
	obj->set("family/family_name",master->query("family/family_name"));
	obj->set("family/master_name",master->query("name"));
	obj->set("family/generation",(int)master->query("family/generation")+1);
	obj->set("family/title",master->query("family/title"));
	obj->set("family/master_id",master->query("id"));
	obj->set("family/enter_time",time());
	obj->set("title",master->query("family/family_name") + "��" + chinese_number((int)master->query("family/generation") + 1) + "����ͽ");
  return obj;
}
////////ѯ�ʻ����ͽ����//////////
int party_quest_betrayer(object me)
{
	string *dir, *file, place;
	int i, j ;
  object room;
  object obj;
  object master=this_object();
//	me = this_player();

  if (!me->query("family/family_name"))
   {
		message_vision("$N����$n˵����λ"+RANK_D->query_respect(me)+"�β�������"+master->query("family/family_name")+"��\n", master, me);
		return 1;   	
   	}
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
	if ( islocked( me, "betrayer" ) ) return 1;
	if ( me->query("quest/betrayer") &&
		!me->query( "quest/betrayer/finished" ) )
	{
		if (time() < (int)me->query("quest/betrayer/time") )
		{
			message_vision("$N����$n˵���Ҳ��ǽ���ȥɱ" + me->query("quest/betrayer/name") + "����ô���ֻ����ˣ���\n", master, me);
			return 1;
		}
		else
		{
			message_vision( WHT"$N����$n˵�����ܵ������й�ȥ�ˣ�\n"NOR, master, me );
			quest_failed( me, "betrayer" );
			me->add("qi",-(int)(me->query("qi")/10));
		}
	}


/* Move to dest place */
//��ѡ�ط� ����ϵͳ��֧
	dir = get_dir("/d/");
	i = random(sizeof(dir));
	file = get_dir("/d/"+dir[i]+"/");
	j = random(sizeof(file));

	if (//strsrch(file[j], ".c") == -1 ||
		file[j][sizeof(file[j])-2..sizeof(file[j])-1] != ".c" ||
		dir[i]=="gaibang" ||
		dir[i]=="gaochang" ||
    dir[i]=="gumu"	||
    dir[i]=="taohua" ||
    dir[i]=="heizhao" ||
    dir[i]=="shenlong" ||
    dir[i]=="wanjiegu" ||
    dir[i]=="yanziwu" ||
		dir[i]=="death" ||
		dir[i]=="wizard" ||
		dir[i]=="working" ||
		dir[i]=="binghuo" ||
		dir[i]=="xiakedao" ||
		dir[i]=="lingjiu"||
		dir[i]=="gaibang"||
		dir[i]=="npc")
	{
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ��������������\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);
	if (room->query_max_encumbrance() < 10000000
	|| !mapp(room->query("exits")) //add by qingyun
	|| room->query("no_quest")		//add by qingyun
		|| room->query("no_fight"))
	{
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ�ٿ�����\n", master, me);
		return 1;
	}

	if (!master->query_temp("betrayers")) master->set_temp("betrayers", 1);
	else master->add_temp("betrayers", 1);

  obj = create_betrayer(me);
  
	if (!objectp(obj) || !obj->move(room))
	{
		if (objectp(obj))	destruct(obj);
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ�ٿ�����\n", master, me);
  	 return 1;
	}
	command("qst "+obj->query("name")+"("+obj->query("id")+")"+"��"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")��\n");
	message_vision("$N����$n˵�����Ź�ɽ���ӻر���������ͽ" + obj->query("name") + "��" + to_chinese(dir[i]) + "һ����û�����ȥ������ͽ����ͷ����ȡ����ô��\n", master, me);
	me->set("quest/betrayer/name", obj->query("name"));
	me->set("quest/betrayer/family", obj->query("family/family_name"));
	me->set("quest/betrayer/time", time() + 500);
	me->set("quest/betrayer/dest", to_chinese(dir[i]));
	me->set("quest/betrayer/obj", obj );
	me->delete("quest/betrayer/finished");
	return 1;
}
///////�����ͽ���񡢽���///////
int accept_quest_betrayer(object me, object obj)
{
	object master = this_object();
	int exp, pot, score, num, times, e_bonus, p_bonus, s_bonus;
	int cost;

	me = this_player();

	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������" + me->query("family/family_name") + "ȥ�ɡ�\n", master, me);
		return 1;
	}
	if ( islocked( me, "betrayer" ) ) return 1;
	if ( !me->query( "quest/betrayer" ) ||
		me->query( "quest/betrayer/finished" ) )
		return 0;
	if (obj->query("userp") == 1)
	{
		message_vision(HIR "$N����$n˵���ҽ���ɱ��ͽ����ȴȥɱ��ң�ȥ�����㣡\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "betrayer" );
		me->delete_temp("mebetrayernum");
		master->kill_ob(me);
		return 1;
	}
	if (obj->query("quest") != "betrayer" )
	{
		message_vision( HIR"$N����$n˵���ҽ���ɱ��ͽ����ȴ��ɱ�޹����ɱ�ʦ����ȥ�����㣡\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "thief" );
		me->delete_temp("methiefnum");
		me->delete_temp("mebetrayernum");
		master->kill_ob(me);
		return 1;
	}
	master->add_temp("betrayers", -1);
	destruct(obj);

	num=(int)me->query("perform/number")+1;
	if (num<4) times=num;
	else times=4;

	cost = time() - ((int)me->query("quest/betrayer/time")-500); //���˶���ʱ�����

//  e_bonus = 200 + random( 200 );
		e_bonus = 200 + random( 100 );
    e_bonus += 50*me->query_temp("mebetrayernum");
    e_bonus += e_bonus * cost / 1200; // ��ͽ1200��ͻ��Զ�����
//	p_bonus = (int)random(e_bonus/4)+35;
    p_bonus = (int)random(e_bonus/2)+35;
  	s_bonus = random(10)+ 15* times;
    me->add("combat_exp",e_bonus);
    me->add("potential",p_bonus);
    me->add("family/fealty",s_bonus);
    me->add("family/gongxian",1);
	me->set_temp("prize_reason","��ͽ");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",e_bonus);
	me->set_temp("prize_pot",p_bonus);

	message_vision("$N����$n˵����ͽ����ͷ��������Ϊ�����������Ż���\n", master, me);
	tell_object(me,HIW + "�㾭�����ƴɱ�������" + chinese_number(e_bonus) + "��ʵս���飬" + chinese_number(p_bonus) + "��Ǳ�ܣ�������" + chinese_number(s_bonus) + "��ʦ���ҳϡ�\n"NOR);

	me->add_temp("mebetrayernum",1);
	
	if ((int)me->query_temp("mebetrayernum") == 10)
	{
		me->add("score", 3000);
		me->delete_temp("mebetrayernum");
		me->set_temp("family_can_qiecuo",1);
		
		message_vision(HIW "$N����$nЦ���������������ڼ䣬Ϊʦ�չز��򣬽��ճ��أ���ѧ��Ϊ������ͻ�ƣ�\n", master, me);
		tell_object(me,HIM +"�������л�����"+ master->query("name")+"�д� ( qiecuo )��ѧ��\n"NOR);
	}

	quest_finished( me, "betrayer" );

	return 1;
}


//ȡ������
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
	lock_quest( me, "betrayer", "book" );
	message_vision( "$N��$n˵��������Ͱ��������ؼ��ɡ�\n", master, me );
	return 1;
}
/////��ͽ����//////////////

/////////��ʼ��ϸ����////////
object create_thief( object me )
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
	"emei/feng",	 //yanxing-dao		jinding-zhang 	tiangang-zhi
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
	obj = new("/clone/quest/questjianxi");
	obj ->set("owner", me->query("id"));
	obj ->set("quest", "thief");
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
	if (obj->query("str")<me->query_str()-20)
		obj->set("str",me->query_str()-20);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
	obj->set("dex", hp_status["dex"]+ 10);
	if (obj->query("dex")<me->query_dex()-20)
		obj->set("dex",me->query_dex()-20);
	obj->set("age", hp_status["age"]+2);

	if ((hp_status["max_qi"]*2)<1500)
	{ 
		obj->set("max_qi", 1500);
		obj->set("eff_qi", 1500);
		obj->set("qi",     1500);
	}  
	else		
	{
		obj->set("max_qi", hp_status["max_qi"]*2);
		obj->set("eff_qi", hp_status["max_qi"]*2);
		obj->set("qi",     hp_status["max_qi"]*2);
	}
	if (hp_status["max_jing"]*3/2 < obj->query("max_qi")/4)
	{
		obj->set("max_jing",  obj->query("max_qi")/4*3/2);
		obj->set("eff_jing",  obj->query("max_qi")/4*3/2);
		obj->set("jing",      obj->query("max_qi")/4*3/2);
	}
	else {
		obj->set("max_jing",  hp_status["max_jing"]*3/2);
		obj->set("eff_jing",  hp_status["max_jing"]*3/2);
		obj->set("jing",      hp_status["max_jing"]*3/2);
	}

	
	if ((hp_status["max_neili"])<1500)
		obj->set("max_neili",1500);
	else 
		obj->set("max_neili", hp_status["max_neili"]);

	if((hp_status["neili"]) < hp_status["max_neili"])
		obj->set("neili", hp_status["max_neili"]);
	else  obj->set("neili", hp_status["neili"]);	
	if (obj->query("neili") < 1500) obj->set("neili",1500);
	obj->set("jiali",     hp_status["neili"]/20);

	topexp = (int) me->query("combat_exp");
	inc_exp = ( topexp*2 - topexp ) / 11;
	topexp = topexp + inc_exp * ((int) me->query_temp("methiefnum")-1);
	obj->set("combat_exp", topexp + 100);
	
/* skill */
	skl = me->query_skills();
	skilllvl=100;	
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
//				skilllvl = skl[skillname[j]]*4/5 + skl[skillname[j]]*((int) me->query_temp("methiefnum")-1)*2/55;
				skilllvl = skl[skillname[j]];
		}
		inc_lvl = ( skilllvl - skilllvl * 4/5 ) / 11;
		skilllvl = skilllvl - inc_lvl *((int) me->query_temp("methiefnum")-1);		
	}

	i = random( sizeof(masters) );
	thief_master = new ( "/kungfu/class/"+masters[i] );

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
/* 1000��������ң��ڴ˳����������� */
	if(me->query("combat_exp") > 100000000)
			obj->set("shen", -1 * thief_master->query("shen_type") * obj->query("combat_exp") / 2000);
 	destruct( thief_master );
	return obj;
}

int party_quest_thief(object me)
{
	string *dir, *file, place;
	int i, j, k;
	string err;
	object room, obj, master = this_object();

	me = this_player();
  if (!me->query("family/family_name"))
   {
		message_vision("$N����$n˵����λ"+RANK_D->query_respect(me)+"�β�������"+master->query("family/family_name")+"��\n", master, me);
		return 1;   	
   	}
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
	{
		return 1;
	}

	if ( me->query("quest/thief") && !me->query( "quest/thief/finished" ) )
	{
		if (time() < (int)me->query("quest/thief/time") )
		{
			message_vision("$N����$n˵����ô������ϸ"+ me->query("quest/thief/name")+"����ͷ�أ���\n", master, me);
			return 1;
		}
		else
		{
			message_vision( CYN"$N����$n˵�����ܵ������й�ȥ�ˣ���ο�ҪС������Щ��\n"NOR, master, me );
			quest_failed( me, "thief" );
			if ((int)me->query_temp("methiefnum")>1)
				me->add_temp("methiefnum",-1);
			else
				me->delete_temp("methiefnum");
			me->add("qi",-(int)(me->query("qi")/10));
		}
	}

/* Move to dest place */
	dir = get_dir("/d/");
//	for (i = 0; i < sizeof(dir); i++)
// Ϊ���չ�������(shaolin��nanshaolin�ַ������Ӽ�)�����ԴӺ����
	for (i = sizeof(dir)-1; i >= 0; i--)
	{
		if (strsrch(master->query("startroom"), dir[i]) >= 0)
			k = i;
	}
	file = get_dir("/d/"+dir[k]+"/");
	j = random(sizeof(file));

	if (sizeof(file[j]) < 2 ||
		file[j][sizeof(file[j])-2..sizeof(file[j])-1] != ".c" )
	{
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ��������������\n", master, me);
		return 1;
	}
	if(!( room = find_object("/d/"+dir[k]+"/"+file[j]) ))
		room = load_object("/d/"+dir[k]+"/"+file[j]);

	if (room->query_max_encumbrance() < 10000000
		|| !mapp(room->query("exits")) //add by qingyun
	|| room->query("no_quest")		//add by qingyun
)
	{
		message_vision("$N����$n˵���ȵȰɣ�����ɽ���ӻ�ɽ�ٿ�����\n", master, me);
		return 1;
	}
	err = catch(obj = create_thief( me ));
	if (stringp(err))
	{
		tell_object(find_player("qingyun"),"����\nerr="+err);
		return 1;
	}
  if (!obj || 
   obj->query("family_name") == me->query("family/family_name") ||
  !obj->move(room))
   {
   	if (objectp(obj)) destruct(obj);
   	message_vision("$N����$n˵���������е���Ҫæ���Ȼ�����ٿ����ɡ�\n", master, me);
    return 1;
   }
	if (!master->query_temp("thiefs")) master->set_temp("thiefs", 1);
	else master->add_temp("thiefs", 1);
	if (!me->query_temp("methiefnum"))
		me->set_temp("methiefnum",1);
	

	me->set("quest/thief/name", obj->query("fname"));
	me->set("quest/thief/family", obj->query("family/family_name"));
	me->set("quest/thief/time", time() + 300 );
	message_vision("$N����$n˵�����ŵ��ӻر���������Χ��İ���˳��֡���ȥ�鿴һ���ǲ��Ǳ��ɵļ�ϸ��\n", master, me);
	me->set( "quest/thief/obj", obj );
	me->delete( "quest/thief/finished" );	
	command("qst "+obj->query("name")+"��"+room->query("short")+"(/d/"+dir[k]+"/"+file[j]+")��\n");
//	obj->move(room);
	return 1;
}

int accept_quest_thief(object me, object obj)
{
	object master = this_object();
	int num, times, e_bonus, p_bonus, s_bonus, lastfealty;
	int cost;
	
	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}
	if ( islocked( me, "thief" ) )
		return 1;

	if ( !me->query( "quest/thief" ) || me->query( "quest/thief/finished" ))
		return 0;

	if (obj->query("userp") == 1)
	{
		message_vision( HIR"$N����$n˵���ҽ���ɱ��ϸ����ȴȥɱ��ң�ȥ�����㣡\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "thief" );
		me->delete_temp("methiefnum");
		master->kill_ob(me);
		return 1;
	}

	if (obj->query("quest") != "thief" )
	{
		message_vision( HIR"$N����$n˵���ҽ���ɱ��ϸ����ȴ��ɱ�޹����ɱ�ʦ����ȥ�����㣡\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "thief" );
		me->delete_temp("methiefnum");
		master->kill_ob(me);
		return 1;
	}

	master->add_temp("thiefs", -1);
	destruct(obj);

	num=(int)me->query("perform/number")+1;	
	if (num<4) times = num;
	else times = 4;
	
	cost = time() - ((int)me->query("quest/thief/time")-300); //���˶���ʱ�����

	e_bonus = (int)me->query_temp("methiefnum");
	e_bonus = e_bonus*100 + 200 + random(50);
	if (e_bonus > 1500)
		e_bonus = 1250+random(250);
  e_bonus += e_bonus* cost / 1200;
  e_bonus -= e_bonus/3;

	p_bonus = (int)random(e_bonus/10)+100;
	s_bonus = random(10) + 15 * times;
  
	me->add("combat_exp", e_bonus);
	me->add("potential", p_bonus);
	me->add("family/fealty", s_bonus);
	me->add("family/gongxian",1);
	me->set_temp("prize_reason","��ϸ");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",e_bonus);
	me->set_temp("prize_pot",p_bonus);

	message_vision("$N����$n˵����ϸ����ͷ��������Ϊ������һ�󹦣�\n", master, me);
	tell_object(me, HIW + "�����ⷬ������������" + chinese_number(e_bonus) + "��ʵս���飬" + chinese_number(p_bonus) + "��Ǳ�ܣ�����" + chinese_number(s_bonus) + "��ʦ���ҳϡ�\n"NOR);
	
	me->add_temp("methiefnum",1);
	
	if ((int)me->query_temp("methiefnum") == 13)
	{
		me->delete_temp("methiefnum");
		p_bonus = 1300+ random(100);

		me->add("potential",p_bonus);
		me->add("score", 4000);
		message_vision(HIW "$N����$nЦ���������������˿���֮��Ҳ��Ϊ���������湦ѽ��\n"NOR, master, me);
		tell_object(me,HIM + master->query("name")+"�ν����㣺"	+ chinese_number(p_bonus) + "��Ǳ�ܣ�\n"NOR);
	}

	quest_finished( me, "thief" );
	
	return 1;
}

int cancle_quest_thief( object me )
{
	object master = this_object();

	if( !me->query( "quest/thief" ) || me->query( "quest/thief/finished" ) )
		return 0;
	if( me->query( "quest/thief/lock" ) )
	{
		tell_object( me, "���Ѿ�ȡ�������ˣ�\n" );
		return 1;
	}
	lock_quest( me, "thief", "betrayer" );
	message_vision( "$N����$n˵�������Ȱѱ�����ͽ�����ɾ��ٹܱ���°ɡ�\n", master, me );
	me->delete_temp("methiefnum");
	
	return 1;
}
/////////��ϸ�������////////////
int party_quest_kill(object me)
{
	object killer, room, master = this_object();
	string place;
	int i,j;
	int level;
	int t;

	me = this_player();

	if (master->query("eff_qi") * 2 < master->query("max_qi") ||
		master->query("qi") * 2 < master->query("max_qi"))
	{
		message_vision(HIC "$N" HIC "�����ؿڣ�һ���ǳ�ʹ������ӣ������"
                               "����Ȼû������ȥ��\n" NOR, me);
		return 1;
	}

  if (!me->query("family/family_name"))
  {
		message_vision("$N����$n˵����λ"+RANK_D->query_respect(me)+"�β�������"+master->query("family/family_name")+"��\n", master, me);
		return 1;   	
 	}

	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������" + me->query("family/family_name") + "ȥ�ɡ�\n", master, me);
		return 1;
	}

	if (me->query("combat_exp") <= 1000)
	{
		message_vision(WHT"$N����$n˵����ѧ��δ����������ɽ��\n"NOR, master, me);
		return 1;
	}

	if ( me->query("quest/kill") && !me->query( "quest/kill/finished" ) )
	{
			message_vision("$N����$n˵���Ҳ��ǽ�����"HIY+CHINESE_D->chinese_monthday(((me->query("quest/kill/time")-1270000000)*365))+NOR"֮ǰɱ��" + me->query("quest/kill/name") + "��������"HIY+CHINESE_D->chinese_monthday(((time()-1270000000)*365))+NOR"����Ҫ����ͷ�أ���\n", master, me);
			return 1;
	}
	
	if (me->query("shen")>0 && master->query("shen")<0)
	{
		message_vision(CYN "$N" CYN "��ŭ�������д����ż��첻����"
                  "���ȻҲѧ����ʼ������ˣ�����ҹ���\n"
                   NOR, master, me);
    return 1;
	}
	
	if (me->query("shen")<0 && master->query("shen")>0)
	{
		message_vision(CYN "$N" CYN "��ŭ�������д������Ȼ�Ѿ���"
                  "����;�����������ң�\n" NOR, master, me);
    return 1;
	}
	
	level = me->query_temp("quest/next_level");
	if (level < 0 || level > 3)	level = 0;

	killer = new("/clone/quest/killer");
	killer ->set("owner", me->query("id"));
	killer ->set("level", level);
	NPC_D->copy_skill(killer); //�޲��������ȡ����
	NPC_D->init_npc_skill(killer,NPC_D->check_level(me));//�����鿽���ȼ�
	NPC_D->copy_status(killer,me,100); //����״̬�ٷ���

	if (killer->query("combat_exp")<1000000)
		killer->set("neili",killer->query("max_neili"));
	else if (killer->query("combat_exp")<3000000)
		killer->set("neili",killer->query("max_neili")*3/2);
	else 
		killer->set("neili",killer->query("max_neili")*2);

	killer->add_temp("apply/attack", killer->query_skill("force") * (level - 1) * 2 / 15);
	killer->add_temp("apply/dodge",  killer->query_skill("force") * (level - 1) * 2 / 15);
	killer->add_temp("apply/parry",  killer->query_skill("force") * (level - 1) * 2 / 15);
	killer->add_temp("apply/damage", 5 + level * 7);
	killer->add_temp("apply/unarmed_damage", 5 + level * 7);
	killer->add_temp("apply/armor", 10 + level * 15);
	
	if (me->query("combat_exp") > 1000000)
		NPC_D->set_perform(killer);
	if (me->query("combat_exp")<2000000)
		NPC_D->place_npc(killer,0);
	else 
		NPC_D->place_npc(killer,1);
	
	room = environment(killer);
	place = to_chinese(killer->query("place"));
	command("qst "+killer->query("name")+"("+killer->query("id") +")"+"��"+room->query("short")+"("+file_name(room)+")��\n");
	
		message("vision", WHT + master->name() + WHT "С���Ķ�" + me->name() +
				  WHT "�Ը���ʲô��" + me->name() +
				  WHT "һ������һ�߲�ס�ĵ�ͷ��\n" NOR,
	       			   environment(me), ({ me }));
		if (master->query("shen")>0)
		{
			killer->set("shen", -killer->query("combat_exp") / 2000);
			if (master->query("family/family_name") == "������")
				tell_object(me, CYN + master->name() + CYN "���������"
						 "Ȼ���ǳ������Դȱ�Ϊ�������Ƕ��ڴ�"
						 "�״��֮ͽҲ���ܷŹ���\n���" NOR +
						 HIR + killer->name() +"("+killer->query("id") +")"+NOR + CYN "��" +
						 place + "�����ˣ���ȥ�������ˣ���ͷ������\n" NOR);
			else
				tell_object(me, CYN + master->name() + CYN"�������" NOR
						 + HIR + killer->name() +"("+killer->query("id") +")"+ NOR + CYN "���"
						 "�����ҽ��ᣬ�޶�����\n��˵�����"
						 "��" + place +	"����ȥ����������ͷ�����ҡ�\n" NOR);
		} else
		if (master->query("shen")<0)
		{
			killer->set("shen", killer->query("combat_exp") / 2000);
			tell_object(me, CYN + master->name() + CYN "�������" NOR + HIR
					 + killer->name() +"("+killer->query("id") +")"+ NOR + CYN "�����ν�����Ŵ�"
					 "���������ԣ�\n��˵�������" + place + "����"
					 "ȥ����������ͷ������\n" NOR);
		} else
		{
			killer->set("shen_type", 0);
			killer->set("shen", 0);
			tell_object(me, CYN + master->name() + CYN "����˵��������Ϳ�"
					 NOR + HIR + killer->name() +"("+killer->query("id") +")"+ NOR + CYN "��˳��"
					 "��\n��˵�������" + place + "����ȥ����������������ͷ�����\n" NOR);
		}
                switch (level)
                {
                case 0:
                        message_vision(CYN "$N" CYN "���˶٣��ֶ�$n" CYN "�������"
                                       "�������װ�úܣ���Ҫ�ǻ��첻���ǿɲ��󻰡�"
                                       "\n" NOR, master, me);
                        break;
                case 1:
                        break;
                case 2:
                        message_vision(CYN "$N" CYN "���˿�$n" CYN "�ֵ����������"
                                       "������Щ�Ѱ죬��Ҫ�ǲ����Ҿ������˰ɡ�\n"
                                       NOR, master, me);
                        break;
                case 3:
                        message_vision(CYN "$N" CYN "̾�˿�����֣�صĶ�$n" CYN "��"
                                       "������������յý����㲻Ҫ��ǿ�Լ������о�"
                                       "���ˡ�\n" NOR, master, me);
                        break;
                }
	me->set("quest/kill/level", level);
	me->set("quest/kill/master_name", master->name());
	me->set("quest/kill/master_id", master->query("id"));
	me->set("quest/kill/id", killer->query("id"));
	me->set("quest/kill/name", killer->name());
	me->set("quest/kill/place", place);
	t = time() +4 * ONE_DAY - 1; // ������һ�� one day
	me->set("quest/kill/time", t );
	message("vision", WHT + master->name() + WHT "�����������˵���������Ҫ��"
	                  NOR + HIY + CHINESE_D->chinese_monthday(((t-1270000000)*365)) + NOR + WHT
	                          "֮ǰ��ɣ�\n" NOR, me);
	me->delete( "quest/kill/finished" );
	return 1;
}
int cancle_quest_kill(object who)
{
        mapping dbase;
        mapping q;
        object ob;
        string msg;
        int n;
        int g;

        object me = this_object();
        dbase = who->query_entire_dbase();
              
        if (! mapp(q = dbase["quest"]["kill"]) ||
            q["master_name"] != me->name())
                {
                	message_vision("$N˵������û����ʲô���񰡣�mapp(q)="+mapp(q)+"\n",me,who);
                	return 1;
                }

                if (q["notice"] == "die")
                {
                        message_vision(CYN "$N" CYN "���ͷ����$n" CYN "�������ˣ���˵����"
                                       "�Ѿ���ɱ�ˣ��㲻���������ˡ�\n" NOR, me, who);
                } else
                {
                        message_vision(CYN "$N" CYN "�ڰ��֣���$n" CYN "������ɲ��˾�����"
                                       "���ñ������ɣ�\n" NOR, me, who);
                        who->delete("quest_num/kill");
                }

	            who->delete_temp("quest/next_level");
                n = (40 + random(40) + NPC_D->check_level(who) * 5);
                g = (10 + random(10) + NPC_D->check_level(who));

                switch (q["level"])
                {
                case 0:
                        n *= 2;
                        break;
                case 1:
                        break;
                case 2:
                        n = 0;
                        break;
                case 3:
                        n = 0;
                        break;
                default:
                				n = 0;
                				break;
                }
//                if (! n) break;

                // adjust weiwang
                dbase["weiwang"] -= n;
                if (dbase["weiwang"] < 0)
                        dbase["weiwang"] = 0;
                msg = HIR "��Ľ��������ܵ�����ʧ";

                // adjust gongxian
                dbase["family/gongxian"] -= g;
                if (dbase["family/gongxian"] < 0)
                        dbase["family/gongxian"] = 0;
                msg += HIR "��ʦ�Ŷ�������ν�����";

                // notice place
                message("vision", msg + "��\n" NOR, who);

        who->start_busy(2);

        who->delete("quest/kill");
        ob = find_living(q["id"]);
        if (! ob || ob->query_temp("owner") != who->query("id"))
                return 1;

        if (environment(ob))
                message_vision(HIC "$N" HIC "���˿����ܣ�����ææ���ߵ��ˡ�\n" NOR, ob);

        destruct(ob);
        return 1;
}
int accept_quest_kill(object me, object obj)
{
	object master = this_object();
	int num, times, exp ,pot ,score, fealty , gongxian;
	object *helper;
	string msg;
	int t;
	mapping q;
	int timeover;
	int bonus;
	int quest_count;
	int special;
	int type;
	
	me = this_player();
	if (me->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}

	if ( !me->query( "quest/kill" ) || me->query( "quest/kill/finished" ))
		return 0;

	if (obj->query("userp") == 1)
	{
		message_vision( HIR"$N����$n˵���ҽ���ɱ�ˣ���ȴȥɱ��ң�ȥ�����㣡\n"NOR, master, me);
		destruct(obj);
//		quest_failed( me, "thief" );
		me->delete_temp("quest_num/kill");
		master->kill_ob(me);
		return 1;
	}

	if (obj->query("quest") != "kill" )
	{
		message_vision( HIR"$N����$n˵���ҽ���ɱ�ˣ���ȴ��ɱ�޹����ɱ�ʦ����ȥ�����㣡\n"NOR, master, me);
		destruct(obj);
		quest_failed( me, "kill" );
//		me->delete_temp("quest_num/kill");
		master->kill_ob(me);
		return 1;
	}

///	master->add_temp("kill", -1);
//	destruct(obj);
                q = me->query("quest/kill");
                if (! mapp(q) || ! obj->is_corpse() && ! obj->is_head())
                        return 0;
        
                if (! stringp(obj->query("owner")))
                {
                        message_vision(CYN "$N" CYN "���ű��ӿ��˿�" + obj->name()
                                       + NOR + CYN "������ʲô�����ģ������"
                                       "���ߡ�\n" NOR, master);
                        return 0;
                }
        
                if (obj->query("owner") != me->query("id"))
                        return 0;
                        
                msg = CYN "$N" CYN "�ӹ�" + obj->name() + NOR + CYN "���ǺǴ�Ц"
                      "����$n" CYN "����";

                if (me->query("shen")>0)
                        msg += CYN "�ֳ���һ�����ܺã�";
                else
                if (me->query("shen")<0)
                        msg += CYN "�ü��ˣ�ʲô����������һ����";
                else
                        msg += CYN "�ɵúã�Ư����";
                msg += "\n" NOR;
                t = time();
                if (me->query_temp("quest/escape_times"))
                {
                        msg += CYN "$N" CYN "����������û�뵽������ôǿ����ʵ"
                               "��δ���ϵ������࣬���࣡\n" NOR;
                        timeover = 0;
                } else
                if (t > q["time"])
                {
                        msg += CYN "$N" CYN "ҡҡͷ���ֵ�����ϧ����������" +
                               CHINESE_D->chinese_monthday(t*60) + "ǰ��������"
                               "�ˣ������������������°ɡ�\n" NOR;
                        timeover = 1;
                } else
                {
                        if (t - q["time"] < ONE_DAY)
                        {
                                msg += CYN "$N" CYN "���ͷ�����ɵò�����ô"
                                       "�������ˣ��úøɣ�\n" NOR ;
                        } else
                                msg += CYN "$N" CYN "���ͷ������β�������"
                                       "�ˡ�\n" NOR;

                        timeover = 0;
                }
                bonus = 1;
                helper = q["helper"];

              	if (!arrayp(helper) || member_array(me,helper) < 0)
               	{
               	 msg += CYN "$N" CYN "�ֶ�$n" CYN "������ϧ���"
               	 	"�Է�����������ɱ����Ŭ��һ�㣬�����Լ�����ˣ�\n" NOR;
				       	 type = 1;
				       	}
				       	else
                {
                	helper -= ({ me });
                	helper -= ({ 0 });
                	if (sizeof(helper)>0)
                	{
                        msg += CYN "$N" CYN "��ο�Ķ�$n" CYN "����������ܹ�"
                               "�õ�" + helper[0]->name() +
                               NOR + CYN "�İ�æ��Ҳ�����ף��Ժ�˴�Ҫ�����"
                               "Ӧ��\n" NOR;
                		bonus = 2;
                	}
                }
                destruct(obj);
                
					       exp = me->query_temp("quest_kill/combat_exp");
					       pot = me->query_temp("quest_kill/potential");
					       score = me->query_temp("quest_kill/score");
					       me->delete_temp("quest_kill");
					       
					       exp /= bonus;
					       pot /= bonus;
					       score /= bonus;
					       
					       quest_count = me->query("quest_num/kill");
					       if (type!=1 && (!exp || !pot || !score))
					       {
					       	 msg += CYN "$N" CYN "�ֶ�$n" CYN "����ֻ��ϧ�ؼ�ʱ�̣���"
					       	        "�Ĵ浨�ӣ�û�����жԷ������ǿ�ϧ��\n"NOR;
                   bonus = 2;
					       }
                if (quest_count == 100)
                {
                        msg += CYN "$N" CYN "������Ц��������������ģ�������"
                               "�ٴ�������ɵ�ƯƯ�������ܺã��ܺá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 200)
                {
                        msg += CYN "$N" CYN "��ϲ�������������ǲ�������"
                               "������ɵúܺá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 300)
                {
                        msg += CYN "$N" CYN "��ϲ�����������������ٸ�����"
                               "��˿�������������Ư����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 400)
                {
                        msg += CYN "$N" CYN "��ϲ�������ǲ�����Ȼ�����İٸ�"
                               "����˿����������ɵúá�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 500)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "�������ٴ�������һ��©�����ǲ���\n" NOR;
                        special = 1;
                } else
                if (quest_count == 600)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "��������ٴ�������һ��©��Ư��֮����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 700)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "���߰ٴ�������һ��©�����ף����ף�\n" NOR;
                        special = 1;
                } else
                if (quest_count == 800)
                {
                        msg += CYN "$N" CYN "̾�������ǳ���������ǰ�ˣ��벻��"
                               "������˰ٴ�������һ��©������֮����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 900)
                {
                        msg += CYN "$N" CYN "�����̾�����벻��������Űٴ���"
                               "����һ��©������֮��������֮����\n" NOR;
                        special = 1;
                } else
                if (quest_count == 1000)
                {
                        msg += CYN "$N" CYN "����̾�˿����������벻��������һ"
                               "ǧ��������һʧ�֣���������" +
                               me->query("family/family_name") +
                               "���Ǻ�����˰���\n" NOR;
                        special = 1;
                } else
                if (quest_count > 1000)
                {
                        me->set("quest_num/kill",1);
                } else
                if ((quest_count % 10) == 0)
                {
                        msg += CYN "$N" CYN "ϲ�������ǲ�������Ȼ����" +
                               chinese_number(quest_count) +
                               "�ζ�û��ʧ�֣��ɵĺã�\n" NOR;
                }                
                message_vision(msg, master, me);
                me->delete_temp("quest/escape_times");
                me->delete("quest/kill");
                fealty = 10;
                gongxian = 1;
        if (timeover)
        {
                exp /= 2;
                pot /= 3;
                score /= 4;
                fealty /= 2;
                gongxian /= 2;
        } else
        {
                // �ٷ�֮һ�ļ���ֱ��������Ʒ����
//                if ((quest_count >= 100 && random(200) == 1) || special)
                if ( special)
                {
                  "/quest/weixiaobao"->special_bonus(master, me,"gongxian");
                }
        }
        if (type==1 || (exp==0 &&pot==0 && score==0))
          return 1;
        message("vision", sprintf(HIC "ͨ����ζ���������%s�㾭�飬"
                                  "%s��Ǳ�ܡ�\nͬʱ����"
                                  "����%s�㽭����������%s����"
                                  "���ҳ϶ȡ�\n" NOR,
                                  chinese_number(exp),
                                  chinese_number(pot),
                                  chinese_number(score),
                                  chinese_number(fealty)), me);
        me->add("combat_exp", exp);
        me->add("potential", pot);
        me->add("score", score);
        me->add("family/gongxian", gongxian);
        me->add("family/fealty",fealty);
	return 1;
}
int accept_reply(object me,object ob,string arg)
{
	return "/quest/weixiaobao"->accept_reply(me,ob,arg);
}
/////�������֣� ��ʦ�����͵���qiecuo///////
////������θ���� ����  ��֪��//
int accept_betrayer(object ob)
{
	if (ob->query("shen") > 0)
	{
		if (ob->query("betrayer") > 0)
			return 1;
	} else {
		if (ob->query("betrayer") > 5)
			return 1;
	}
}
// ������Ҫ����ʦ
// Added by Constant Jan 12 2001
int betray(object ob, int depth)
{
	string *base_skill = ({
		"array",     	"axe",     	"blade",
		"claw",      	"club",    	"cuff", 
		"dagger",    	"dodge",   	"force",   
		"finger",    	"gambling" 	"hammer", 
		"hand",      	"hook",		  "leg",
	  "literate", 	"parry",     	"spear",   	
		"staff",	    "stick",     	"strike",  	
		"sword", 	    "throwing",  	"unarmed", 	
		"whip"
	});

	object master = this_object();
	mapping ob_skills = ob->query_skills();
	string skill_name;
	int skill_level, i;

	if (ob->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N˵����������֮�����й������Ŵ��ã������޹ء���\n", master, ob);
		return 1;
	}
	if (ob->query("combat_exp") < 1000000)
	{
		message_vision("$N��Ц��������ƾ�����΢ĩ���У�Ҳ�뵽������ȥ��������������Ц����������\n", master, ob);
		return 1;
	}

	if (depth == 0)
	{
		message_vision(HIR "\n$Nüͷһ�壬��������$n��Ŀ�������$n�������˸���ս��\n"NOR, master, ob);
		ob->start_busy(10);
		call_out("betray", 5, ob, depth + 1);
	}
	else
	{
		message_vision(HIR "\n���Σ�$N̾��������Ȼ��ִ����ȥ����Ҳ����ǿ����ֻ�����һ���书���������ͻ�����ȥ�ɡ���\n"NOR, master, ob);
		message_vision(HIR "˵�գ�������$n��ͷ����һ����$nֻ��ȫ���������಻����ȥ����֮�£����˹�ȥ��\n"NOR, master, ob);
		for (i = 0; i < sizeof(ob_skills); )
		{
			skill_name = keys(ob_skills)[i];
			skill_level = ob_skills[skill_name];
			if (member_array(skill_name, base_skill) != -1)
			{
				skill_level = skill_level / 2;
				if (skill_level == 0)
					map_delete(ob_skills, skill_name);
				else
				{
					ob_skills[skill_name] = skill_level;
					i ++;
				}
			}
			else
			{
				map_delete(ob_skills, skill_name);
			}
		}
//		ob->set("betrayer", ob->query("betrayer") + 1);
		ob->add("expell",1);
		ob->set("detach/"+ob->query("family/family_name"),1);
		ob->set("title", "��ͨ����");
		ob->set("class", "0");
		ob->delete("family");
		ob->save();
		ob->unconcious();
	}
	return 1;
}
// ���ŵ��ӿ�����������Ҫ�������͵�

int xkd(object me)
{
	object master = this_object();
	object ob = this_player();
	object ling;
	object first;
	string first_dir;
	string *dir;
	string c_player;
	int i;
	
  if (!me->query("family/family_name"))
   {
		message_vision("$N����$n˵����λ"+RANK_D->query_respect(me)+"�β�������"+master->query("family/family_name")+"��\n", master, me);
		return 1;   	
   	}
	if (ob->query("family/family_name") !=
		master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}
	
	if (!ob->query("xkd/ling"))
	{
		message_vision("$N����$n˵���㻹�������Ŵ���ӣ�������������Ρ�\n", master, me);
		return 1;
	}	
	dir = explode(base_name(master),"/");
	first_dir = dir[sizeof(dir)-2];
	if (objectp(first = NPC_D->create_first(first_dir)))
	{
		c_player=first->query("current_player");
		destruct(first);
		if (ob->query("id")!= c_player)
		{
			message_vision("$N����$n˵���㲻�����Ŵ���ӣ�������������Ρ�\n", master, me);
			return 1;
		}
	}
	if ( ob->query("xkd/ling") && !ob->query_temp("xkd/ask") )
	{
		ling = new( "/d/xiakedao/obj/tongpai1" );
		ling->set( "own", ob->query("id") );
		ling->move( ob );
		ling = new( "/d/xiakedao/obj/tongpai2" );
		ling->set( "own", ob->query("id") );
		ling->move( ob );
		message_vision( HIY"$N��$n˵�������͵������������Ʒ��������Ϊʦ�ϵ���\n���Ǳ������ŵ��ӣ��ʹ�Ϊʦ��һ�˰ɡ�\n"NOR, master, ob );
		message_vision( HIC"˵�꣬$N���������ƽ���$n���\n"NOR, master, ob );
		ob->set_temp("xkd/ask",1);
	}
	else 
	{
		message_vision("$N����$n˵���㲻���Ѿ������������𣬻���������̡�\n", master, me);
		return 1;
	}			
	return 1;
}

//�д���ѧ����ʦ������������perform
int do_qiecuo(string arg)
{  
	object master = this_object();
	object me = this_player();
	object weapon;
	string special;
	string *sskl,pfskill,pfmartial,pfarg,pfmsg;
	mapping skl, map_status;
	mixed perform_actions = ({});  
	int bl,sl,i,j,num,learn_b,fealty_b;
     
	fealty_b=(int)me->query("family/fealty");

	num=(int)me->query("perform/number")+1;	
	if (num<4) learn_b= num * num * 100;
	else learn_b=1600;
   
	if (!living(me)||!living(master)) return 0;
	if (me->query("family/family_name") !=master->query("family/family_name"))
	{
		message_vision("$N����$n˵���Ҳ�����������ˣ��������"+me->query("family/family_name")+"ȥ�ɡ�\n", master, me);
		return 1;
	}
	if (me->is_busy() || me->is_fighting())
	{
		message_vision("$N����$n˵����æ���������ɣ�\n", master, me);
		return 1;
	}
	if (master->is_fighting())
	{
		message_vision("$N����$n˵����������æ���أ�\n", master, me);
		return 1;
	}
      //family_can_qiecuo��Ϊʦ������������perform�д������
      	if( !me->query_temp("family_can_qiecuo"))
      	{
		if (!arg) 
		{
	     		message_vision("$N����$n˵����Ҫ�д�ʲô��\n", master, me);
	     		return 1;
		}
		if( sscanf(arg, "%s.%s", pfmartial, pfarg)!=2 )
		{
			message_vision("$N����$n˵����Ҫ�д�ʲô��\n", master, me);
	     		return 1;
		}
		if (fealty_b<learn_b)
		{
			message_vision("$N����$n˵���㻹�Ƕ�Ϊ�������㹱�������ɣ�\n",master,me);
			return 1;
		}
		
		if( stringp(pfskill = me->query_skill_mapped(pfmartial)))
		{
			if (!master->query_skill(pfskill,1))
			{
				message_vision("$N����$n˵������书��û��������ȥ�������˰ɡ�\n", master, me);
				return 1;
			}
			perform_actions = get_dir( SKILL_D(pfskill) + "/" );
			for ( j = 0; j < sizeof( perform_actions ); j++ )
			{
				sscanf( perform_actions[j], "%s.c", perform_actions[j] );
				if ( perform_actions[j] == pfarg )
				{
					bl=me->query_skill(pfmartial,1);
					sl=me->query_skill(pfskill,1);
					pfmsg="perform/"+pfarg;
					if(sl<10 || bl<10)
					{
						message_vision("$N����$n˵�����ȴ�û����������д�ɣ�\n", master, me);
						return 1;
					}
					else if(me->query(pfmsg,1)==1)
					{
						message_vision("$N����$n˵�����Ѿ���������У���Ҫ�д�ô��\n", master, me);
						return 1;
					}
					else
					{ 
						message_vision(HIW"$N����Ц�������ðɣ�Ϊʦ�ʹ�����Щ�ĵã�����\n"NOR, master, me);
						write(HIC"������ָ�����˼���룬��"+to_chinese(pfskill)+"�����������һ�㡣\n"NOR);
						me->set(pfmsg,1);
						me->add("perform/number",1);
						fealty_b=fealty_b - learn_b;
						me->set("family/fealty",fealty_b);
						me->start_busy(3); 
						return 1; 
					}
				}
			 }
			me->start_busy(1); 
			message_vision("$N����$n˵����Ҫ�д�ʲô��\n", master, me);
	     		return 1;
		}
		else
		{
			me->start_busy(1); 
			message_vision("$N����$n˵����Ҫ�д�ʲô��\n", master, me);
	     		return 1;
		}
	}
	else
	{	      
      		if (!arg) 
		{
			message_vision("$N����$n˵����Ҫ�д�ʲô��\n", master, me);
	     		return 1;
		} 
      		if (!(special=me->query_skill_mapped(arg)))
		{
			message_vision("$N����$n˵����ֻ�ܴӻ���������������⼼�ܡ�\n", master, me);
	     		return 1;
		}
	  	if(arg=="force")
		{
			message_vision("$N����$n˵���ڹ���Ϊ�����ǿ��д�����ߵġ�\n", master, me);
	     		return 1;
		}
	  	else if(special=="bixie-jian"
			  ||special=="jinshe-jian"
			  ||special=="jiuyin-baiguzhao"
			  ||special=="liangyi-jian"
			  ||special=="lonely-sword"
			  ||special=="shenzhao-jing"
			  ||special=="taixuan-gong"
			  ||special=="shenxing-baibian"
	||special=="xianglong-zhang"
	||(special=="hamagong" && arg=="strike")
			  )
		{
			message_vision("$N����$n˵��������޷�ͨ���д�����ߣ�\n", master, me);
	     		return 1;
		}
	  	else
		{      
		   	bl=me->query_skill(arg,1);
	   		sl=me->query_skill(special,1);
		   	if(sl>=bl*3/2)
		   	{
				message_vision("$N����$n˵�����ȴ�û����������д�ɣ�\n", master, me);
				return 1;
			}
		   	else
			{       //chinese_number(p_bonus)
//				tell_object(me,HIM + master->query("name")+"ȡ�����㣺"	+ chinese_number(learn_b) + "���ҳ϶ȡ�\n"NOR);		
				message_vision(HIW"$N����Ц�������ðɣ�Ϊʦ�ʹ�����Щ�ĵã�����\n"NOR, master, me);	  
		   		write(HIC"������ָ�����˼���룬��"+to_chinese(special)+"�����������һ�㡣\n"NOR);
		   		me->set_skill(special,sl+1); 
			   	me->delete_temp("family_can_qiecuo");
		   		me->start_busy(3);
			   	return 1;
			}
		}
	}
}
