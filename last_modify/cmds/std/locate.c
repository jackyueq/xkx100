// /cmds/std/locate.c

// Created by Constant Jan 4 2001

inherit F_CLEAN_UP;

int main(object me, string str)
{
	string output = "";
	
        if (!str) 
        	return notify_fail("ָ���ʽ: locate <��Ʒ>\n");
	me->add("jing",-10-random(10));
	output = TASK_D->locate_obj(me, str);
	if (output=="")
		return notify_fail("��Ǹ���޷�֪̽���﷽λ��\n");
	write(output);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: locate <��Ʒ>

������֪������Ʒ�Ĵ���λ�á�

HELP
	);
	return 1;
}
