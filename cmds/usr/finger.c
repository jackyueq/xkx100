// /cmds/usr/finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
	if( !arg ) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
		me->start_more( FINGER_D->finger_all() );
	} else {
		for (i = 0; i < sizeof(arg); i++)
        		if (arg[i]<'a' || arg[i]>'z')
                           return notify_fail("û������˴��ڡ�\n"); 
		if( (int)me->query("jing") < 15 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : finger [ʹ��������]
 
    ���ָ����û��ָ��ʹ��������������ʾ�����������������
���������ϡ���֮�������ʾ�й�ĳ����ҵ����ߣ�Ȩ�޵����ϡ�
 
see also : who
HELP
	);
	return 1;
}
 
