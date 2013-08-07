// /cmds/usr/set.c

// Modified by Constant Jan 4 2001
 
#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;

// ���������������飬�����жϻ����������õĺϷ��ԡ�
// Added by Constant Jan 4 2001
string *player_settings = ({
	"brief",
	"brief1",
	"brief2",
	"combatd",
	"no_accept",
	"no_teach",
	"no_mail",
	"no_tell",
	"public",
	"wimpy"
});

string *wizard_settings = ({
	"immortal",
	"invisibility",
	"msg_home",
	"msg_min",
	"msg_mout",
	"msg_clone",
	"msg_desg",
	"combat verbose",
	"trace_error"
});
 

int help();
 
int main(object me, string arg)
{
    	int i;
    	string term, *terms;
	mixed data;
	mapping env;
 
	if ( me != this_player(1) ) 
		return 0;
 
	env = me->query("env");
 
	if ( !arg || arg=="" ) {
		write("��Ŀǰ�趨�Ļ��������У�\n");
		if ( !mapp(env) || !sizeof(env) )
			write("\tû���趨�κλ���������\n");
		else {
			terms = keys(env);
			for (i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	if ( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
 
	if ( term && term!="" ) {
		if ( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");

		if ( member_array(term, player_settings) == -1 ) {
			if (!wizardp(me))
				return notify_fail("û�����ֻ�������������հ�����\n");
			else if ( member_array(term, wizard_settings) == -1)
				return notify_fail("û�����ֻ�������������հ�����\n");
		}
        	if ((wiz_level(me) == 0) && (member_array(term, wizard_settings) != -1))
            		return notify_fail("ֻ����ʦ��������趨��\n");

		sscanf(data, "%d", data);
        	me->set("env/" + term, data);
		printf("�趨����������%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ����Ĭ��ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
 
��������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}

