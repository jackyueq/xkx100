// semote.c
// ���Ӳ������ܣ�ʹsemote������Բ��ҿ�ͷ������ĸƥ���emote
// Modified by Spacenet@FXLT

#include "/doc/help.h"

inherit F_CLEAN_UP;

int head_index(string str, string index);

int main(object me, string arg)
{
	string *e, str;
	int i;

	e = sort_array(EMOTE_D->query_all_emote(), 1);
	e = filter_array(e, (: head_index :), arg);

	if (sizeof(e)) {
		str = "                        ������һ�ٱ��鶯���ܻ� \n\n";
		str += "��������������������������������������������������������������������������\n";
		for(i=0; i<sizeof(e); i++)
//			printf("%-15s%s", e[i], (i%5==4)?"\n": "");
			str += sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
		me->start_more(str);
		write("\n");
		return 1;
	} else return notify_fail("û�з���ָ��Ҫ��ı��鶯����\n");
}

int head_index(string str, string substr)
{
	int i;
	
	for (i = 0; i < sizeof(substr); i ++)
		if (str[i] != substr[i])
			return 0;
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : semote [����]

    ���ָ������г�Ŀǰ����ʹ�õģ�����塣������ϲ��������г���
�ò���Ϊ���׵����У�����壬���磺��������| ����������г����
��ͷ�ģ�����塣���������Ļ����г�ȫ���ģ�����塣

HELP
	);
	return 1;
}
