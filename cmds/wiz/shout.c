// han.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) || !arg) return 0;
	shout(HIW"��������" + me->name() + HIW + "[" + me->query("id") + "]" + HIW + "������Х��" + arg + "\n"NOR);
	write(HIW"��������Х��" + arg + "\n"NOR);
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : shout | han <ѶϢ>
 
    ���ָ�����㽫 <ѶϢ> ���ͳ�ȥ������������Ϸ�е��˶�
��������Ļ���
 
see also : tune
HELP
	);
	return 1;
}
 
