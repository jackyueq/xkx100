// Last Modified by winder on May. 29 2001
// ghost.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p")
	{
		me->set_ghost(1);
		write("��ɹ��ر����һֻ��\n");
	}
	else {
		me->set_ghost(0);
		write("����Ͷ̥�����ˣ�\n");
	}
	return 1;
}
		
int help(object me)
{
write(@HELP
ָ���ʽ : ghost [-p]
 
���ָ���������˹�֮���л���
HELP	);
	return 1;
}
