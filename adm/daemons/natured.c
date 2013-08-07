// natured.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
// #define TIME_TICK ((time()-1270000000)*60)
//#define TIME_TICK ((time()-1111000000)*365)//��ʵһ��mud365��
					   //��ʵһ��mud365��(һ��)
#define TIME_TICK ((time()%(60*24*3600))*365)//mud��60��һ��=��ʵ��60��
static int current_day_phase;
mapping *day_phase;

//������������ʿ����ı�ʶ
int thief_yinshi = 3;

string *weather_msg = ({
	"�������������",
	"���䵭�����Ʋ�ױ�������ʵ����",
	"�����������Ʈ��Ʈȥ",
	"�����Ʋ�ѻ������",
	"����������ܲ�",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];
	// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	// MUD ����ʱ����ˣ�ʱ�����ƫ������ǵ�������ÿСʱִ��һ��
	message("channel:sys", HIR"��ϵͳ�����ʱ�����ϵͳʱ�䣬һСʱһ�Ρ�\n"NOR, users());
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase", (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"]-t);
}

void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	message("outdoor:vision", HIG"�����⡿"NOR + day_phase[current_day_phase]["time_msg"] + NOR"��\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_midnight()
{
	string get_month, get_day;
	get_day = CHINESE_D->chinese_monthday(TIME_TICK);
	get_month = CHINESE_D->chinese_month(TIME_TICK);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/spring_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/spring_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/spring_wind"); break;
			}
			break;
		//summer weather
		case "��":
		case "��":
		case "��":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/summer_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/summer_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/summer_wind"); break;
			}
			break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/autumn_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/autumn_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/autumn_wind"); break;
			}
			break;
		//winter weather
		case "ʮ��":
		case "һ":
		case "��":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/winter_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/winter_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/winter_wind"); break;
			}
			break;
		default:
			day_phase = read_table("/adm/etc/nature/day_phase");
	}
}

object create_thief( )
{
	mapping skill_status,name;
	string *sname;	
	object obj;
	int skilllvl,topexp;
	int i;
	
	seteuid(getuid());
	if (thief_yinshi==0)	obj = new("/clone/quest/questfeizei");
	if (thief_yinshi==1)	obj = new("/clone/quest/questyinshi");
	if (random(2) == 0)
	{
	        if (thief_yinshi==1) name = NAME_D->woman_name();
		obj->set("gender", "Ů��");
	}
	else
	{
		if (thief_yinshi==1) name = NAME_D->man_name();
		obj->set("gender", "����");
	}
        if (thief_yinshi==1) obj->set("fname", name["name"]);
/* skilllvl && exp for ���� */    
     if (thief_yinshi==0)
        {
       	   i=random(5);
           if( i==0 )   
	       { topexp = 500000+random(500000);
                 skilllvl=100+random(50);
                 obj->set("str_lvl",1);
                } 
           else if( i==1 )   
	       { topexp = 1000000+random(1000000);
                 skilllvl=150+random(75);
                 obj->set("str_lvl",2);
                }          
           else if( i==2 )   
	       { topexp = 3000000+random(3000000);
                 skilllvl=200+random(100);
                 obj->set("str_lvl",3);
                }    
            else if( i==3 )   
	       { topexp = 5000000+random(5000000);
                 skilllvl=250+random(125);
                 obj->set("str_lvl",4);
                }  
             else if( i==4 )   
	       { topexp = 8000000+random(8000000);
                 skilllvl=300+random(150);
                 obj->set("str_lvl",5);
                }                        
         }
/* skilllvl && exp for ��ʿ*/
      if (thief_yinshi==1)
          { 
            skilllvl=250;
            topexp=3000000;            		
	   }          
            
      	obj->set("combat_exp", topexp); 
	NPC_D->copy_skill(obj);
 	if (mapp(skill_status = obj->query_skills()))
 	{
 		sname = keys(skill_status);
 		for(i=0;i<sizeof(skill_status);i++)
 		{
 			obj->set_skill(sname[i],skilllvl);
 		}
 	}
	return obj;
}
void event_morning()
{
	string *dir, *file, place;
	object yinshi;
	object room;
	int i,j,flag=0;

        thief_yinshi=1;
        yinshi=create_thief();
//ѡ��ص�
	dir = get_dir("/d/");
	i = random(sizeof(dir));
	file = get_dir("/d/"+dir[i]+"/");
	j = random(sizeof(file));
	if(  	file[j][<2..<1]!=".c" ||
		dir[i]=="death" ||
		dir[i]=="wizard" ||
		dir[i]=="working" ||
		dir[i]=="binghuo" ||
		dir[i]=="xiakedao" ||
		dir[i]=="npc" )
	     {
		    dir[i]="wuyi";
	    	    file[j]="sangufeng";
		    room = load_object("/d/wuyi/sangufeng");
	      }
   if(!objectp(room) && !( room = find_object("/d/"+dir[i]+"/"+file[j]) ))
		room = load_object("/d/"+dir[i]+"/"+file[j]);
	 if (room->query_max_encumbrance() < 10000000)
	 {
	 	dir[i]="wuyi";
	 	file[j]="sangufeng";
	  room = load_object("/d/wuyi/sangufeng");
	}
	yinshi->move(room);
	CHANNEL_D->do_channel(yinshi, "sys",yinshi->query("name")+"��"+room->query("short")+"(/d/"+dir[i]+"/"+file[j]+")��\n");	        				
        message("channel:snow", HIY"���������š�"HIC + "��˵��"+ to_chinese(dir[i]) + "һ��������һλ����ǰ����������ʿ�׷�ǰ��Ѱ�ã�\n"NOR,users() );
//��ԭ��ʶ
	thief_yinshi=3;              
}

void event_afternoon()
{       
	object *ob_list;
	int i;
	ob_list = children("/clone/quest/questyinshi");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$NЦ������Ҫ���ˣ���Ҳ��������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
	
void event_night()
{
	object badguy;
	object room;
	int num;
	num=random(15);
	thief_yinshi=0;
        if ( num == 0)
        {
		if(objectp(room=load_object("/d/city/shilijie4")))
		 badguy= create_thief();
		 badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        else if ( num == 1)
        {
		if(objectp(room=load_object("/d/beijing/tian_anm")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        else if ( num == 2)
        {
		if(objectp(room=load_object("/d/changan/center")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 3)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 4)
        {
		if(objectp(room=load_object("/d/quanzhou/guangchang")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "Ȫ�ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 5)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 6)
        {
		if(objectp(room=load_object("/d/hangzhou/jujingyuan")) )
		badguy= create_thief();
		badguy->move(room);		
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 7)
        {
		if(objectp(room=load_object("/d/wuxi/guangchang")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        else if ( num == 8)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 9)
        {
		if(objectp(room=load_object("/d/yueyang/zhongxin")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 10)
        {
		if(objectp(room=load_object("/d/chengdu/guangchang")))
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "�ɶ����н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
         else if ( num == 11)
        {
		if(objectp(room=load_object("/d/dali/center")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
        }
        else if ( num == 12)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
       else if ( num == 13)
        {
		if(objectp(room=load_object("/d/foshan/street3")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "��ɽ���н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
        }
       else 
        {
		if(objectp(room=load_object("/d/jiangling/xijie2")) )
		badguy= create_thief();
		badguy->move(room);
		message("channel:snow", HIM"���ٸ�ͨ�桿"HIR + "������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
         }
//��ԭ��ʶ
       thief_yinshi=3;
}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/clone/quest/questfeizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$NЦ���������ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
	object *ob;
	int i, skill,con,con1,con2,con3;
	string get_month,ill,msg;
	get_month = CHINESE_D->chinese_month(TIME_TICK);
	switch(get_month)
	{
		case "��":
		case "��":
		case "��":
			ill = "ill_kesou";
			msg = HIG"��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n"NOR;
			break;
		case "��":
		case "��":
		case "��":
			ill = "ill_zhongshu";
			msg = HIG"ͻȻ������֮��һ���ڣ��������ˡ�\n"NOR;
			break;
		case "��":
		case "ʮ":
		case "ʮһ":
			ill = "ill_shanghan";
			msg = HIG"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"NOR;
			break;
		case "ʮ��":
		case "һ":
		case "��":
			ill = "ill_dongshang";
			msg = HIG"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"NOR;
			break;
	}
	if(random(2))
	{
		ill = "ill_fashao";
		msg = HIG"��ż�з纮����������������\n"NOR;
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("qi");
		con2 = ob[i]->query("max_qi");
		(int)con = con1/con2*50;//�γɵ�һ�������ж�����
		con3 = ob[i]->query("neili");
		con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;//�γɵڶ��������ж�����
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10+random(40));
			tell_object(ob[i], msg);
		}
	}
}

string outdoor_room_description()
{
	return "    "+day_phase[current_day_phase]["desc_msg"]+NOR"��\n";
}
string outdoor_room_event()
{
	return day_phase[current_day_phase]["event_fun"];
}
string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }

