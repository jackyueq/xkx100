// /cmds/usr/unset.c

// Modified by Constant Jan 4 2001

inherit F_CLEAN_UP;

// ���������������飬���ڼ�黷���������õĺϷ��ԡ�
// Added by Constant Jan 4 2001
string *player_settings = ({
	"brief",
	"brief1",
	"brief2",
	"combatd",
	"combatd2",
	"no_accept",
	"no_teach",
	"no_mail",
	"no_map",
	"no_tell",
	"prompt",
	"public",
	"verbose",
	"wimpy",
	"auto_regenerate",
	"halt_age",
	"no_fight",
	"can_tell",
	"auto_reply",
});

string *wizard_settings = ({
	"immortal",
	"invisibility",
	"msg_home",
	"msg_min",
	"msg_mout",
	"msg_clone",
	"msg_desg",
	"combat",
	"trace_error"
	"no_task_msg"
});

int help();

int main(object me, string arg)
{
	if (!arg || arg=="") 
		return help();

	if (arg == "all") { 
		me->delete("env");
		write("��Ļ��������ѱ���ա�\n");
		return 1;
	}

	if (!me->query("env/" + arg))
		return notify_fail("�㲢û������������������\n");

	if (member_array(arg, player_settings) == -1) {
		if (!wizardp(me))
			return notify_fail("û�����ֻ�������������հ�����\n");
		else if (member_array(arg, wizard_settings) == -1)
			return notify_fail("û�����ֻ�������������հ�����\n");
	}

	me->delete("env/" + arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��unset <������> | all

    ���ָ������ɾ�������������趨������������Ϊall�� ��ɾ
�����л���������

See also��set
TEXT
	);
	return 1;
}

