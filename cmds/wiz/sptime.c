// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("������" + time() + "��\n");
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: time

���ָ������(��)֪�����ڵ�ʱ����

HELP
    );
    return 1;
}
