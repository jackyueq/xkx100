// ban.c	

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string *str, site;
	int num = 0;

	if (!arg) {
		BAN_D->print();
		return 1;
	}

	str = explode(arg, " ");
	switch (sizeof(str)) {
		case 2 : site = str[1]; break;
		case 3 : site = str[1]; num = atoi(str[2]); break;
		default : write("ָ���ʽ��ban [+|- ��ַ [num]]\n"); return 1;
	}

	if (str[0] == "+")
		BAN_D->add(site, num);
	else if (str[0] == "-")
		BAN_D->delete(site, num);
	else	write("ָ���ʽ��ban [+|- ��ַ [num]]\n");

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��ban [+|- ��ַ [num]]

�����������������������ַsite��
��numΪ0�򲻽�num����ʾ���һ��ȷ���ĵ�ַ������������κε�¼��
��numΪ-1����ʾ�����õ�ַ��ƥ��Ķ����ַ������������κε�¼��
��numΪ��������ʾ���Ƹõ�ַ����¼����Ϊnum��
����ַΪclear���������Ӧ���б�
HELP
);
	return 1;
}

