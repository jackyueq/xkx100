// emote.c (Mon 09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
	if (!str)
	{
		write(CYN"�㿴��������ḻ��\n"NOR);
		tell_room(environment(me),CYN+(string)me->name()+"����������ḻ��\n" +NOR, me);
		return 1;
	}
	write(CYN"��"+str+"\n"NOR);
	tell_room(environment(me), CYN+(wizardp(me)? "":"->")+(string)me->name()+str+"\n"+NOR, me);
	message("channel:snp", HIB"��������"+me->query("name")+"���飺"+str+"\n"NOR, users());
	return 1;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ: emote <������>

    ���ָ�����������һ��ϵͳû��Ԥ��Ķ����ʣ�ϵͳ�Ὣ��
����������ּ��������������ʾ��������ͬһ���ط������￴��Ϊ
�˱���������ţ����������Ĵʾ�ǰ������ -> �Թ�������ʦ
���ڴ��ޣ���
    Ԥ���ָ�����ֱ�Ӽ��롣

    ������emote ����������

��ῴ����������������
�����˻ῴ����->��������������

    ���У����Ӿ����������.

���ָ��: semote
HELP
	);
	return 1;
}
