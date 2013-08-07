// wizlist.c
// Modified by winder May.26 2000

#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int level(mixed, mixed);
string wiz_rank(string hood);

int main(object me, string arg)
{
	string *list, hood = "", str;
	int j = 0;

	list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
	str = HIC+CHINESE_MUD_NAME+NOR +"��ʦ���»��Ա��\n";
	str += "��������������������������������������\n";
	for(int i=0; i<sizeof(list); i++, j++)
	{
		if (hood!= wiz_rank(wizhood(list[i])))
		{
			hood = wiz_rank(wizhood(list[i]));
			if (j%7) str += "\n";
			str += hood;
			str = replace_string(str,"(",HIG);
			str = replace_string(str,")",": "NOR);
			j = 0;
		}
		str += sprintf(" %s%s", list[i],
			( j%7==6 ) ? "\n" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : "" );
	}
	str += "\n��������������������������������������\n";
	str += sprintf("Ŀǰһ����: %s����ʦ\n",chinese_number(sizeof(list)) );
	me->start_more(str);
	return 1;
}

string wiz_rank(string hood)
{
	switch(hood)
	{
		case "(admin)":
			return HIM "�� ��  �� / ��  �� ��" NOR;
		case "(arch)":
			return HIY "�� ��  �� / ��  �� ��" NOR;
		case "(wizard)":
			return HIG "�� ��  �� / ��  Ů ��" NOR;
		case "(apprentice)":
			return HIC "�� ��  �� / ��  Ů ��" NOR;
		case "(immortal)":
			return HIC "�� ��  ͯ / Ů��ͯ ��" NOR;
	}
}

int level(mixed ob1, mixed ob2)
{
	if (wiz_level(ob1) != wiz_level(ob2))
		return wiz_level(ob2) - wiz_level(ob1);
	return ob1 > ob2?-1:1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : wizlist
 
    ���ָ�����ʾ�����ϷĿǰ����ʦ������
 
HELP
	);
	return 1;
}

