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
    ��to chat����һ���ͳ������ı���to tell <ĳ��> ��һ�ΰѶ�
���ı����߸�ĳ�ˡ�

HELP
	);
	return 1;
}

