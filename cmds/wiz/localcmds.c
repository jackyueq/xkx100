// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;

	cmds = me->query_commands();
	write("�����ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��localcmds

�г������ϼ����ܵ���Ʒ�����ڵĻ����ṩ������ָ�
TEXT
	);
	return 1;
}

