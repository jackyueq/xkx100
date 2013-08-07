// /cmds/usr/quest.c

#include <ansi.h>
#include <quest.h>
 
//inherit F_CLEAN_UP;

mapping quest;
string time_period(int timep );
string quest_msg( object who, string quest_id );

int main(object me, string arg)
{
	int nowtime = time();
	string quest_list = "";
	string msg;
	object who = this_player();
	
	if ( stringp(arg) )
	{
		who = find_player( arg );
		if ( !objectp(who) || !me->visible(who))
			return notify_fail( "����鿴˭������\n" );
		if ( who->query("id") != me->query("id") && !wizardp(me) )
			return notify_fail( "ֻ����ʦ���ܲ鿴���˵�����\n" );
	}

	msg = quest_msg( who, "wei" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += quest["quest_type"]+"��"+quest["quest"]+"����\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}	
	
	msg = quest_msg( who, "shan" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += quest["quest_type"] + "��" + quest["quest"] + "����\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}	
	
	msg = quest_msg( who, "helian" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += quest["quest_type"] + "��" + quest["quest"] + "����\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}	
		
	msg = quest_msg( who, "book" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += "�����ڡ�" + quest["dest"] + "��һ����" + quest["book"] + "��\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}
	
	msg = quest_msg( who, "betrayer" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += "�����ڡ�" + quest["dest"] + "��һ����ġ�" + quest["name"] + "����\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}
	
	msg = quest_msg( who, "thief" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;		
	}

	msg = quest_msg( who, "kill" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += "ɱ���ڡ�" + quest["place"] + "��һ�����ֵġ�" + quest["name"] + "����\n		";
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
	s = t % 60;	     t /= 60;
	m = t % 60;	     t /= 60;
	h = t % 24;	     t /= 24;
	d = t;
 
 	if ( timep <= 0 )
 		return WHT"���Ѿ�û���㹻��ʱ����������ˡ�"NOR;
	if(d) time = chinese_number(d) + "��";
	else time = "";
 
	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	return "�㻹��" + time + "ȥ�������";
}

string quest_msg( object who, string quest_id )
{
	string msg = "";
	
	if ( quest = who->query( "quest/" + quest_id ) )
	{
		msg += HIY"��" + quest_name[quest_id] + "��	"NOR;
		if ( quest["lock"] )
			msg += "�����������ɸ�"HIY + quest_name[quest["lock"]] + NOR"������ܼ����������\n\n";
		else
			if ( quest["finished"] )
				msg += "��ϲ�㣬���Ѿ��������������\n\n";
	}
	return msg;		
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ : quest
	   quest <��������>		(��ʦר��)

    ���ָ�������ʾ���Լ���ָ������ǰ����������Ϣ��
HELP
	);
	return 1;
}
