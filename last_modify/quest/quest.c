// /cmds/usr/quest.c
// Modified by Zeratul Jan 5 2001

#include <ansi.h>
#include </quest/quest.h>
 
inherit F_CLEAN_UP;

mapping quest;
string time_period(int timep );
string quest_msg( string quest_id );

int main(object me, string arg)
{
        int nowtime = time();
        string	quest_list = "";
        string	msg;
        
	msg = quest_msg( "wei" );
	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += quest["quest_type"] + "『" + quest["quest"] + "』。\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }	
        
	msg = quest_msg( "shan" );
	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += quest["quest_type"] + "『" + quest["quest"] + "』。\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }	
        
	msg = quest_msg( "helian" );
	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += quest["quest_type"] + "『" + quest["quest"] + "』。\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }	
                
       	msg = quest_msg( "book" );
       	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += "查找在『" + quest["dest"] + "』一带的" + quest["book"] + "。\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }
        
        msg = quest_msg( "betrayer" );
        quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += "铲除在『" + quest["dest"] + "』一带活动的『" + quest["name"] + "』。\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
      	}
        
        msg = quest_msg( "thief" );
        quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;        	
      	}
      	
        if ( quest_list != "" )
       	{
       		write( "\n你目前的部分任务：\n\n" );
       		write( HIC"≡"HIY"──────────────────────────────"HIC"≡\n\n"NOR );
 		write( quest_list );
 		write( HIC"≡"HIY"──────────────────────────────"HIC"≡\n\n"NOR ); 		
 	}
 	else
 		write( HIW"\n你现在没有任何任务！\n\n"NOR );

        return 1;
}

string time_period( int timep )
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
 
 	if ( timep <= 0 )
 		return WHT"你已经没有足够的时间来完成它了。"NOR;
        if(d) time = chinese_number(d) + "天";
        else time = "";
 
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
//        tell_object(me,"你还有" + time + "去完成它。\n");
        return "你还有" + time + "去完成它。";
}

string quest_msg( string quest_id )
{
	string msg = "";
        
        if ( quest = this_player()->query( "quest/" + quest_id ) )
       	{
        	msg += HIY"〖" + quest_name[quest_id] + "〗	"NOR;
        	if ( quest["lock"] )
        		msg += "你得先完成"HIY + quest_name[quest["lock"]] + NOR"任务才能继续这个任务。\n\n";
        	else
        		if ( quest["finished"] )
        			msg += "恭喜你，你已经完成了这项任务！\n\n";
	}
	return msg;        	
}
 
int help(object me)
{
        write(@HELP
指令格式 : quest  这个指令可以显示出你当前任务的相关信息。
HELP
        );
        return 1;
}
