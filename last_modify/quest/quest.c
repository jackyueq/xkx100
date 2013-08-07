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
        	quest_list += quest["quest_type"] + "��" + quest["quest"] + "����\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }	
        
	msg = quest_msg( "shan" );
	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += quest["quest_type"] + "��" + quest["quest"] + "����\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }	
        
	msg = quest_msg( "helian" );
	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += quest["quest_type"] + "��" + quest["quest"] + "����\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }	
                
       	msg = quest_msg( "book" );
       	quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += "�����ڡ�" + quest["dest"] + "��һ����" + quest["book"] + "��\n		";
        	nowtime = quest["time"] - time();
        	quest_list += time_period( nowtime );
        	quest_list += "\n\n"NOR;
        }
        
        msg = quest_msg( "betrayer" );
        quest_list += msg;
        if ( msg != "" && !quest["finished"] && !quest["lock"] )
       	{
       		quest_list += HIC;
        	quest_list += "�����ڡ�" + quest["dest"] + "��һ����ġ�" + quest["name"] + "����\n		";
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
       		write( "\n��Ŀǰ�Ĳ�������\n\n" );
       		write( HIC"��"HIY"������������������������������������������������������������"HIC"��\n\n"NOR );
 		write( quest_list );
 		write( HIC"��"HIY"������������������������������������������������������������"HIC"��\n\n"NOR ); 		
 	}
 	else
 		write( HIW"\n������û���κ�����\n\n"NOR );

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
 		return WHT"���Ѿ�û���㹻��ʱ����������ˡ�"NOR;
        if(d) time = chinese_number(d) + "��";
        else time = "";
 
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
//        tell_object(me,"�㻹��" + time + "ȥ�������\n");
        return "�㻹��" + time + "ȥ�������";
}

string quest_msg( string quest_id )
{
	string msg = "";
        
        if ( quest = this_player()->query( "quest/" + quest_id ) )
       	{
        	msg += HIY"��" + quest_name[quest_id] + "��	"NOR;
        	if ( quest["lock"] )
        		msg += "��������"HIY + quest_name[quest["lock"]] + NOR"������ܼ����������\n\n";
        	else
        		if ( quest["finished"] )
        			msg += "��ϲ�㣬���Ѿ��������������\n\n";
	}
	return msg;        	
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ : quest  ���ָ�������ʾ���㵱ǰ����������Ϣ��
HELP
        );
        return 1;
}
