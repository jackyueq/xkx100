// /cmds/usr/to.c

// Modified by Constant Jan 4 2001

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

// ��������������飬����ĳЩָ�����to�����á�
// Added by Constant Jan 4 2001
string *cannot_to = ({
	"nick",
	"set",
	"unset"
});

int main(object me, string arg)
{
	if (!wizardp(me) && member_array(arg, cannot_to) != -1) 
		return 0;
	me->edit( (: this_object(), ({ "do_to", me, arg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say , tell , describe , chat , reple ........�ȡ�
���� : 
 to say
 �����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
����������������������������������������������������������
 ������̽��� : ����ϯ���ض�
 ����������߷��������� : Elon
 ����С���������㲿���� : ������
 ������ߴ�첿���� : ���Ѫ��
 .

�����өĻ�ϵĽ������ :

��˵����������̽��� : ����ϯ���ض�
����������߷��������� : Elon
����С���������㲿���� : ������
������ߴ�첿���� : ���Ѫ��
HELP
    );
    return 1;
}

