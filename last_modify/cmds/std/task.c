// /cmds/std/task.c

// Created by Constant Jan 4 2001

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	string output;

	output = HIC"\n��" + 
		 HIY"������������������������" + 
		 HIC"��ѩ���������" + 
		 HIY"������������������������" + 
		 HIC"��"NOR + "\n";

	output += HIG"       ��������Ʒ��" + 
		  "                " + 
		  "          ����Ʒ���ˡ�\n"NOR;

	output += HIY"  ��������������������������������������������������������������"NOR + 
		  "\n";

	if (!str || str != "-u")
    		output += TASK_D->dyn_quest_list(0);
    	else
    		output += TASK_D->dyn_quest_list(1);
    	
	output += HIC"��" + 
		  HIY"��������������������������������������������������������������" + 
		  HIC"��"NOR + "\n";
		  
	output += HIW"      ǰ���"HIR"��"HIW"�ı�ʾ����������ɡ�"NOR;
	me->start_more(output);
	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: task [-u]

���ָ����������֪Ŀǰ������ʹ������-u��������ʾ����δ
���֮ʹ����

HELP
	);
	return 1;
}

