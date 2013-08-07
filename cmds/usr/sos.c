// cmds/usr/sos.c
// Last Modified by winder on Feb. 17 2001

#define SOS_DIR       "/data/sos/"
#define SOS_FILENAME  "sos"

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SAVE;

mapping *notes;

string query_save_file()
{
	return SOS_DIR + SOS_FILENAME ;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
	int i; //line 20
	note["msg"] = text;
	i = sizeof(notes);
	for( ; i > 0; i-- ) 
		if( notes[i-1]["author"] == me->query("id") ) break;
	if( !pointerp(notes) || i > 0 )
	if(!sizeof(notes)) notes = ({ note });
	else
	{
		notes[i-1]["title"] = note["title"];
		notes[i-1]["author"] = note["author"];
		notes[i-1]["msg"] = note["msg"];
		notes[i-1]["time"] = note["time"];
		notes[i-1]["solve"] = "";
	}
	else notes += ({ note });
	tell_object(me, HIM"�����ϡ������Ϣ�Ѿ����ӵ���ʦ֪ͨ�����\n");
	tell_object(me, HIM"��ʦ���ڴ���������ң���ȴ���\n");
	tell_object(me, HIM"�������æ���Լ������飬��һ��ʱ��������sos read�鿴�Ƿ񱻽����\n" NOR);
	save();
	return;
}

void list_bug(object me)
{
	int i;
	string str,s;
	if (sizeof(notes)<1)
	{
		write("û�˷��� sos ����źš�\n");
		return;
	} 
	s = sprintf("����Ѿ������� sos �б�����:\n"
"----------------------------------------------------------------------\n");
	for( i = 0; i<sizeof(notes); i++)
	{
		str = sprintf("%d) %-50s %10s %s \n", i+1, notes[i]["title"], notes[i]["solve"]==""?"No solved":"Solved By "+notes[i]["solve"], ctime(notes[i]["time"])[0..9] );
		s = s + str;
	}
	me->start_more(s);		
}

void do_read(object me, int i) 
{
	string s;
	if( i > sizeof(notes) || i < 1)
	{
		write("�޴˱��!!\n");
		return;
	}
	s = sprintf("%d) %-50s %10s %s\n"
"----------------------------------------------------------------------\n"
		"%s", i, notes[i-1]["title"], notes[i-1]["solve"]==""?"No solved":"Solved By "+notes[i-1]["solve"],
		ctime(notes[i-1]["time"])[0..9], notes[i-1]["msg"] );
		me->start_more(s);
}

int search_id(string id)
{
	int i;
	if( !(i = sizeof(notes)) ) return 0;
	for( ; i > 0; i-- ) 
		if( notes[i-1]["author"] == id ) break;
	return i;
}

int do_solve(object me, int i)
{
	if( i > sizeof(notes) || i < 1)
	{
		write("�޴˱��!!\n");
		return 0;
	} 
	if ( notes[i-1]["solve"]!="" )
	{
		write(notes[i-1]["solve"]+"�Ѿ���־��!\n");
		return 1;
	}
	notes[i-1]["solve"] = me->query("id");
	save();
	write("�� sos ��Ϣ�ѱ�־Ϊ�����\n");
	return 1;
}

int main(object me, string arg)
{
	mapping note;
	object where;
	string s, str,arg1; //line 40
	int i,arg2;
/*
	if (file_size(SOS_DIR + SOS_FILENAME) == -1)
	{
		notes = ({ });
		save();
	}
*/
	restore();
	if (!arg)
	{
		if(!wiz_level(me))
		{
			tell_object(me, HIM"������" HIY MUD_NAME HIM "�������������ͣ�ͻȻ����һֻ����ĳ�������������\n" NOR);
			tell_object(me, HIM"��Ͻ�����ʦ�Ƿ�����������źţ��ӣϣӣ�����\n" NOR);
			where = environment(me);
			if (!where) 
				s=sprintf("%s(%s)���", (string)me->name(), (string)me->query("id"));
			else
				s=sprintf("%s(%s)��%s(%s)���", (string)me->name(), (string)me->query("id"), (string)where->query("short"), (string)file_name(where));
			note = allocate_mapping(5);
			note["title"] = s;
			note["author"] = me->query("id"); 
			note["time"] = time();
			note["solve"] = "";
			me->edit( (: done_post, me, note :) );
		}
		else
		{
			list_bug(me);
		}
		return 1;
	} 

	if( sscanf(arg, "%s %s", s, arg1) == 2 )
	{
		if( !wiz_level(me)) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		if ( s != "solve" ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		if ( arg1 =="all" )
		{
			if( !(i = sizeof(notes)) ) return notify_fail("û�˷���sos����źš�\n");
			for( ; i > 0; i-- ) 
				notes[i-1]["solve"] = me->query("id");
			write("���е� sos ��Ϣ�Ѿ���־Ϊ����ˡ�\n");
			return 1;
		}
		i = search_id(arg1);
		if( i > 0 )
		{ 
			do_solve( me, i );
			return 1;
		}
	}
	if( sscanf(arg, "%s %d", s, arg2) == 2 )
	{
		if( !wiz_level(me)) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		if ( s != "solve" ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		do_solve( me, arg2 ); 
		return 1;
	}
	if ( sscanf(arg, "%s", s) == 1 ) 
	switch(arg)
	{
		case "read":
			if( !(i = sizeof(notes)) )
				return notify_fail("��û�������� sos ���У�\n");
			else
			{
				i = search_id( me->query("id") );
				do_read(me,i);
			}
			break;
		case "list":
			if( !wiz_level(me) )
				return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
			list_bug(me);
			break;
		case "pack":
			if( !wiz_level(me) )
				return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
			if( !(i = sizeof(notes)) )
				return notify_fail("û�˷��� sos ����źš�\n");
			for( ; i > 0; i-- ) 
				if( "" != notes[i-1]["solve"] )
				{
					printf("%s�� sos ����ѱ�ɾ����\n", notes[i-1]["author"]);
					if( sizeof(notes) == 1 ) notes = ({});
					else if(i==1) notes = notes[1..sizeof(notes)-1];
					else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
					else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
				}
			save();
			break;
		case "solve":
			if( !wiz_level(me) )
				return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
				return notify_fail("��ʽ: sos solve <��Ż����id>\n");
			break;
		default:
			if( !wiz_level(me) )
				return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
			if( sscanf(arg, "%d", i) == 1 ) do_read( me, i );
			else if( sscanf( arg, "%s", str ) == 1 )
			{
				i = search_id(str);
				if( i == 0 )
					return notify_fail("�޴���ҷ����� sos ��Ϣ��\n");
				do_read( me, i );
			}
	}
	else return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
	return 1;
}

int help(object me)
{
	if (!wiz_level(me) )
	write(@HELP
ָ���ʽ : 
	   sos
	   sos read
    ���ָ�������ϵͳ����bugʱ������ʦ������

    ����������ϵͳ����ʾ������� bug �����������������Ӧ
�ý� bug ���ֵ������ϵͳ����ʾ������ϸ�ؽ���˵�����Ա���ʦ��
�ĸ� bug��
    ÿ�����ֻ����һ�� sos���µ� sos ��������ǰ�����롣
    ������ sos read �Ķ��Լ������� sos��
HELP
	);
	else 
write(@HELP
ָ���ʽ : 
           sos
           sos <��������id>
           sos list
           sos pack
           sos solve <��������id>
    ���ָ����Ը�����ʦ������������ bug �б�sos �� sos list 
�Ĺ���һ�������ǽ����е� bug ��Ϣ�����б��������� sos �����
�ݲ����Ĳ�ͬ������ʾ��Ӧ������Ӧ��ҵ� bug ����ϸ��Ϣ��sos solve
������־ĳ��bug�� ��������ˡ�sos pack ��ɾ�������Ѿ���־Ϊ�����
�� bug��
HELP
	);
	return 1;
}
