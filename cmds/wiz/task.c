#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	string output;
	
	output = HIC"��" + HIG"������������������������" + HIG" ��ѩ��������� " + HIG"������������������������" + HIC"��\n"NOR;
    	output += TASK_D->dyn_quest_list();
	output += HIC"��" + HIG"������������������������������������������������������������" + HIC"��\n"NOR;
	output += "ǰ����̵ı�ʾ����������ɡ�";
	me->start_more(output);
	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: task

���ָ����������֪Ŀǰ������ʹ��.

HELP
	);
	return 1;
}
