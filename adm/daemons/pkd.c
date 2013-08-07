// pkd.c 
// ��ɽ�۽�ϵͳ������
// for XKX100 , by Sir 2004.1.13
#include <ansi.h>
#include <localtime.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

#define ENTRY_ROOM      "/d/huashan/sheshen"
#define READY_ROOM      "/d/huashan/pk/entry"
#define PK_ROOM         "/d/huashan/pk/turen"
#define PK_DIR		"/d/huashan/pk/"

// ϵͳ����״̬
static int state;

#define SLEEPING        0
#define GET_READY       1
#define STARTING        2

#define GET_READY_TIME  180

static int start = -2 ;
static int ready_time = 0;

static mapping *tlist = ({
([      "name" : ({"��ɽ�۽�֮�����Խ�","��ɽ�۽�֮�����Ƚ�","��ɽ�۽�֮��������","��ɽ�۽�֮��ʦ�۽�"}),
        "time" : ({ 2,4,6,8,10,12,14,16,18,20,22,24 }),
        "minexp" : ({ 100000, 1000000,3000000, 5000000}),
        "maxexp" : ({ 1500000,4000000,8000000,2000000000}),
        "last_lvl" : -1,
        "lvl_num" : 4,
        "time_num" : 12,
]),
});
static int selected=-2;

void change_state(int new_state);
int  start_competition();
void auto_check();
void give_bouns(object me);
void kickout_players();
void send_invite_message();

// ��ѯ����״̬
int is_pking()              { return state == STARTING; }
int is_ready()              { return state == GET_READY; }

void create()
{
        seteuid(ROOT_UID);       
        message("channel:sys", HIR"\n����ɽ�۽�����ɽ�۽��Ѿ�������\n"NOR, users());
        state = SLEEPING;
        set_heart_beat(10);
}

// ��ENTER_ROOM����READY_ROOM �ȴ�������ʼ
int join_competition(object ob)
{
        int exp;
        if (state == STARTING )
        {
        	tell_object(ob,"��ƽ�Ӷ���˵���������ڻ�ɽ֮�����ھ��л���㻹�ǵȵ���˵�ɡ���\n");
                return 1;
        }
        if (state == SLEEPING )
        {
        	tell_object(ob,"��ƽ�Ӷ���˵���������л�ɽ�۽������ӻ�û���أ��㻹�ǵȵ���˵�ɡ���\n");
                return 1;
        }
       
        if (ob->query_condition())
        {
        	tell_object(ob,"��ƽ�Ӷ���˵������������״̬���ѣ����Ǳ��ȥ�ˡ���\n");
                return 1;
        }               
        if (present("mian ju", ob) )
        {
        	tell_object(ob,"��ƽ�Ӷ���˵���������ܴ�������ڣ���\n");
                return 1;
        } 
    	if (present("helan huoqiang", ob) )
    	{
        	tell_object(ob,"��ƽ�Ӷ���˵���������ܴ���ǹ���ڣ���\n");
                return 1;
        }
        exp = ob->query("combat_exp");
        if (exp < tlist[0]["minexp"][selected])
        {
        	tell_object(ob,"��ƽ�Ӷ���˵���������»�������ߵ㾭�������μ��۽��ɡ���\n");
                return 1;
        }                

        if (exp > tlist[0]["maxexp"][selected])
        {
        	tell_object(ob,"��ƽ�Ӷ���˵������Ŷ�����书��˸�ǿ����λ��Ǳ��С�������ˡ���\n");
                return 1;
        }                   
       
        message("channel:snow", HIC"����ɽ�۽���"+"��ƽ�ӣ�" + ob->query("name") + "���������ֲμӻ�ɽ�۽���\n"NOR, users());

        tell_object(ob, HIY "����ǰ��Ȼһ������\n" NOR);
        ob->move(READY_ROOM);
        tell_object(ob, HIY "�㶨��һ������ŷ����Լ��Ѿ����������֣��㽫������ȴ�������ʼ��\n"NOR);
        
//        set_heart_beat(5);
        return 0;
}

// ��������
void heart_beat()
{
        mixed *lt;
        int i,j;
        int last_lvl;
        int flag;
        string err;
//        message("channel:sys", HIR"\n����ɽ�۽�����ɽ�۽�������顣\n"NOR, users());
//        seteuid(ROOT_UID);
        lt = localtime(time());
	
        switch (state)
        {
        case SLEEPING: 
        	flag = 0;       	
        	last_lvl = tlist[0]["last_lvl"];
        	for ( j = 0; j<tlist[0]["time_num"];j++)
        	{	        		        		        		              		
        		if ( (int)tlist[0]["time"][j] == (int)lt[LT_HOUR] && selected != last_lvl && start != (int)lt[LT_HOUR] )
        		{
        			tlist[0]["last_lvl"] = last_lvl + 1;
        			selected = last_lvl + 1;
        			start = (int)lt[LT_HOUR];
        			change_state(GET_READY);
        			ready_time = time();
        			flag = 1;
//        			if ( tlist[0]["last_lvl"] == 4 )
        			if ( tlist[0]["last_lvl"] == 3 )
        				tlist[0]["last_lvl"] = -1;
        			break;
        		}        		        				
        	}
        	if ( flag != 1 ) selected = -2;
        	flag = 0;
        	break;	        					        				        		        		        		        		               

        case GET_READY:        
            	if (time() < ready_time + GET_READY_TIME)
                        break;
                change_state(STARTING);
                break;

        case STARTING:
                break;
        }
        remove_call_out("auto_check");
        call_out("auto_check", 1);
//        auto_check();
}

// �ı����״̬
void change_state(int new_state)
{
//        mixed lt;
        int n;

//        lt = localtime(time());
        switch (new_state)
        {
        case GET_READY:              
                kickout_players();
                ready_time = time();
                message("channel:snow", HIM"��ҥ�ԡ�"+"��˵һ��һ�ȵ�" + tlist[0]["name"][selected] + "���Ͼ�Ҫ�����ˣ���֪������ĵ�һ��˭��\n"NOR, users());
//                set_heart_beat(5);
                send_invite_message();
                break;

        case STARTING:
                if (! (n = start_competition()))
                {
                       message("channel:snow", HIM"��ҥ�ԡ�"+"��˵�����" + tlist[0]["name"][selected] + "���ȡ���ˣ�����û����\n"NOR, users());
                       kickout_players();
                       new_state = SLEEPING;
                } else
                {
                       message("channel:snow", HIM"��ҥ�ԡ�"+"��˵�����" + tlist[0]["name"][selected] + "������" + chinese_number(n) +"�����֣���...��������ȥ��\n"NOR, users());      
//                        set_heart_beat(5);
                }
                break;

        default:
                break;
        }
        state = new_state;
//        if (state == SLEEPING)               	
//                set_heart_beat(30);        
        return;
}

// ������ʼǰ ������
void kickout_players()
{
        object *obs;
        object room;
        string *file;
        object *ob_list;
        int i,j;
	
	ob_list = children("/clone/quest/bwdhnpc");
        for(i=0; i<sizeof(ob_list); i++) 
	if(environment(ob_list[i]))
	{
		message_vision("$NЦ������ɽ�۽������ˣ���Ҳ��������\n",ob_list[i]);
		destruct(ob_list[i]);
        }
	file = get_dir(PK_DIR);        
        for ( i = 0 ; i <sizeof(file); i++)
        {
        	if(!( room = find_object(PK_DIR+file[i]) ))
			room = load_object(PK_DIR+file[i]);
		obs = all_inventory(room);		
		for ( j = 0 ; j <sizeof(obs); j++)
		{        
                	if (!living(obs[j]) || ! userp(obs[j]))
                	{                		
                        	destruct(obs[j]);
                        }
                	else 
              		{
                		tell_object(obs[j], HIC "\n��ƽ�����˹��������µ������峡�ˣ��峡�ˣ������߰ɣ���\n" NOR);
                		obs[j]->delete_temp("bwdh_join");
                		obs[j]->delete_temp("bwdh_pknum");
                		obs[j]->delete_temp("bwdh_nknum");
                		obs[j]->remove_all_enemy(1);
				            obs[j]->remove_all_killer();
                		obs[j]->move(ENTRY_ROOM);
                		message("vision", "ֻ��" + obs[j]->query("name") + "�㬵ı���̧�˳�����\n",obs[j]); 
                	}
                } 
         }                    
}

object create_thief( object me )
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;	
	object obj, thief_master, weapon;
	mapping skl;
	string *skillname;
	int skilllvl,topexp;
	int inc_exp,i,j,k;
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
	obj = new("/clone/quest/bwdhnpc");
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

	obj->set("max_jing",  hp_status["max_jing"]*3/2);
	obj->set("eff_jing",  hp_status["max_jing"]*3/2);
	obj->set("jing",      hp_status["jing"]*3/2);
	
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
	if ((hp_status["max_neili"])<1500)
	{
		obj->set("max_neili",1500);
		obj->set("jiali", 100);
	}
        else 
	{ 
		obj->set("max_neili", hp_status["max_neili"]);
		obj->set("jiali",     hp_status["max_neili"]/30);
	}
	if((hp_status["neili"])<1500)
	{
		obj->set("neili",1500);
	}
	else
	{
		obj->set("neili", hp_status["neili"]);	
	}
		
	topexp = (int) me->query("combat_exp") -  tlist[0]["minexp"][selected];
	topexp = tlist[0]["minexp"][selected] + random( topexp );
	obj->set("combat_exp", topexp );	
/* skill */
	skl = me->query_skills();
	skilllvl=30;	
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}		
		skilllvl = skilllvl - skilllvl * 1/5 ;		
	}

//	family = keys( masters );
//	i = random( sizeof(family) );
//	thief_master = new ( CLASS_D(family[i])+"/"+masters[family[i]] );
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
	obj->set("title", obj->query("family_name") + "����");
	obj->set("name", obj->query("fname"));
 	destruct( thief_master );
	return obj;
}

// ��ʼ�۽� ��������2�� ȡ������
int start_competition()
{
        object env,room;
        object *obs;
        object npc;
        string proom;
        int i,j,user_num = 0;
        string err;

	env = find_object(READY_ROOM);
        if (! objectp(env))
                return 0;
                
	obs = all_inventory(env);
	for (i=0;i<sizeof(obs);i++)
	{
		if ( userp (obs[i]) && !obs[i]->query_temp("noliving") 
			&& obs[i]->query_temp("bwdh_join") )
		user_num += 1;
	}		
	
  if ( user_num < 2)
  {
    for (i=0;i<sizeof(obs);i++)
    {
      obs[i]->move(ENTRY_ROOM);
      message("vision", HIG "���λ�ɽ�۽���Ϊ�μ�Ӣ��̫��ȡ���ˣ�\n", obs[i]);
    }
    return 0;
  }
   	
  message("vision", "��ƽ������һ���֣�˵��������ɽ�۽����ڿ�ʼ����\n", env);
      
  for (i = 0; i < sizeof(obs); i++)
  {
    if ( userp (obs[i])&& !obs[i]->query_temp("noliving") && obs[i]->query_temp("bwdh_join") )
		{
			for (j=0;j<2;j++)  // һ��player��Ӧ����npc
			{
			npc = create_thief( obs[i] );
			proom = sprintf(PK_ROOM "%d", random(12) + 1);
			if(!( room = find_object( proom )))
			room = load_object( proom );
			npc->move( room );
		  }
			tell_object(obs[i], HIY "����ǰ��Ȼһ������\n" NOR);			
//      obs[i]->move(sprintf(PK_ROOM "%d", random(12) + 1));
      proom = sprintf(PK_ROOM "%d", random(12) + 1);
			if(!( room = find_object( proom )))
			room = load_object( proom );
			obs[i]->move( room );
      tell_object(obs[i], HIY "�㶨��һ������ŷ����Լ��Ѿ����������֡�\n"NOR);
		}
  }

//        set_heart_beat(5);
        return user_num;
}

// �ռ������ڵ��������
void auto_check()
{
   object room;
   object ob;
   object *obs;
   string *file;
   int i,j,user_num=0;
   string *u_name=({});
   string msg="";
                
   if (state != STARTING)                  	           	
     return;        
	
	file = get_dir(PK_DIR);       
  for ( i = 0 ; i <sizeof(file); i++)
  {
    if(!( room = find_object(PK_DIR + file[i]) ))
			  room = load_object(PK_DIR + file[i]);
		obs = all_inventory(room);
		for ( j = 0 ; j <sizeof(obs); j++)
		{        
       if ( userp(obs[j]) )
       {
         ob=obs[j];
         u_name += ({ obs[j]->query("name")+"("+obs[j]->query("id")+")" });
         user_num += 1;
       }
    }
  }    	                    	

  if ( user_num < 1)        
	{
		message("channel:snow", HIC"��ҥ�ԡ�"+"��˵��ɽ���ϲμ�"+tlist[0]["name"][selected]+"�ĸ������������ӵ��ӣ�����һ���˶�û������\n"NOR, users());
		kickout_players();
		change_state(SLEEPING);
	}
  else if ( user_num == 1)
  {
    message("channel:snow", HIC"����ɽ�۽���"+"��ƽ�ӣ�����"+tlist[0]["name"][selected]+"Բ��������" + ob->query("name") + "��Ϊ��һ���֣�\n"NOR, users());                
    give_bouns(ob);
    change_state(SLEEPING);
    kickout_players();
  } 
  else  
  {
   for (i=0;i<user_num-1;i++)
  	msg += u_name[i] + "��";
   msg += u_name[user_num-1];
   message("channel:sys", HIC"����ɽ�۽�����ƽ�ӣ���ɽ�������ϻ���"+msg+"��"+chinese_number(user_num)+"����ʿ���μ�"+tlist[0]["name"][selected]+"��\n"NOR, users());
   return;      
  }
}

void give_bouns(object me)
{       
        int pot,exp,score;      
        string err="";
        tell_object(me, "���������ˬ���ˡ���\n"); 
        me->move(ENTRY_ROOM);
        message_vision("$N�˳������˳��������Ϲ�����ʤ����ϲ�ã�\n",me);     
        pot = 500 + (int)me->query_temp("bwdh_pknum")*500+(int)me->query_temp("bwdh_nknum")*100+random(1000);
        exp = 1000 + (int)me->query_temp("bwdh_pknum")*1000+(int)me->query_temp("bwdh_nknum")*200+random(2000);
        score = 300 + (int)me->query_temp("bwdh_pknum")*300+(int)me->query_temp("bwdh_nknum")*60+random(800);

//        if ( (int)me->query_temp("bwdh_nknum") <= 2 )
        if ( !me->query_temp("bwdh_nknum")  )
        {
        	pot = pot/10;
        	exp = exp/10;
        }
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
        me->delete_temp("bwdh_join");
        me->delete_temp("bwdh_pknum");
        me->delete_temp("bwdh_nknum");
	      me->remove_all_killer();
//        me->remove_all_enemy(1);
        me->remove_all_enemy();
        tell_object(me,HIW"���ñ��α��������ʤ�����õ����½�����\n");
        tell_object(me,chinese_number(exp) +"��ʵս����\n" +
        chinese_number(pot) + "��Ǳ�ܡ�\n"+
        chinese_number(score) + "�㽭��������\n"NOR);  
}

// ������ʼǰ���Է�����������ҷ�������
void send_invite_message()
{
        object *obs;
        int exp_ul, exp_dl,i;

	obs = users();
        exp_dl = tlist[0]["minexp"][selected];
        exp_ul = tlist[0]["maxexp"][selected];
        
        if (! sizeof(obs))
                return;
        
        for (i=0;i<sizeof(obs);i++)
        {
        	if ( obs[i]->query("combat_exp") >= exp_dl && obs[i]->query("combat_exp") <= exp_ul )
        	message("channel:snow", HIR "���յ��˹�ƽ�����µ�����������������μ����"+tlist[0]["name"][selected] + "��\n" NOR,obs[i]);
	}
}

//�ṩwiz�ֶ������۽�
int start_by_others(int n)
{
        if (state == STARTING)
                return notify_fail("���ڱ������ڽ����С�\n");

        if (state == GET_READY)
                return notify_fail("���ڱ������ڱ����С�\n");

        if (n < 0 || n >= tlist[0]["lvl_num"])
                return notify_fail("û������ȼ��ı���(0-" +
                                   (tlist[0]["lvl_num"] - 1) + ")��\n");
        selected = n;
        change_state(GET_READY);
        return 1;
}

// �ж��Ƿ�ܾ��μ��۽�
string reject_join(object me)
{
        int exp;

        if (state == STARTING)
                return "����" + tlist[0]["name"][selected] + "���ھ��У��㻹���´������ɡ�";

        if (state != GET_READY)
                return "����ûҪ���л�ɽ�۽�������������ʲô��";

        exp = me->query("combat_exp");
        if (exp < tlist[0]["minexp"][selected])
                return "���»�������ߵ㾭�������μ��۽��ɡ�";

        if (exp > tlist[0]["maxexp"][selected])
                return "Ŷ�����书��˸�ǿ����λ��Ǳ��С�������ˡ�";

        return 0;
}
