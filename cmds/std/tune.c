// tune.c
// Modified by zeratul,2000.1.14

inherit F_CLEAN_UP;

mapping channel_name = ([
	"sys"  :        1,
	"snp"  :        1,
	"debug":        1,
	"wiz"  :        1,
	"gwiz" : 	1,
	"qst"  :  1,
	"rumor":        0,
	"chat" :        0,
	"xkx"  :        0,
	"sing" :        0,
	"party":        0,
	"snow" :        0,
	"es"   :	0,	
]);

int main(object me, string arg)
{
	string *tuned_ch, chinese_name;
	int i;

	tuned_ch = me->query("channels");
	if( !arg )
	{
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("�����ڲ�û�������κ�Ƶ����\n");
		else
			write("������������Ƶ����" + implode(tuned_ch, ", ") + "��\n");
		return 1;
	}

	switch (arg)
	{
		  case "sys" 	: chinese_name = "ϵͳ"; break;
		  case "snp" 	: chinese_name = "����"; break;
		  case "debug"	: chinese_name = "����"; break;
		  case "wiz"	: chinese_name = "��ʦ"; break;
		  case "gwiz"	: chinese_name = "������ʦ"; break;
		  case "qst"  : chinese_name = "����"; break;
		  case "rumor"	: chinese_name = "ҥ��"; break;
		  case "chat"	: chinese_name = "����"; break;
		  case "xkx"	: chinese_name = "������"; break;
		  case "sing"	: chinese_name = "�質"; break;
		  case "party"	: chinese_name = "����"; break;
		  case "es"	: chinese_name = "��������"; break;
		  case "snow": chinese_name = "����"; break;
	}	
	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 )
	{
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		write("�ر�" + chinese_name + "Ƶ����\n");
		return 1;
	}
	else
		if ( !undefinedp(channel_name[arg]))
		{
			if (!wizardp(me) && channel_name[arg])
				return notify_fail("��û��ʹ�����Ƶ����Ȩ����\n");
			tuned_ch += ({ arg });
			me->set("channels",tuned_ch);
			write("��" + chinese_name + "Ƶ����\n");
			return 1;
		}

	if ( arg == "on" )
	{
		tuned_ch = ({ });
		for ( i = 0; i < sizeof(channel_name); i++ )
			if ( (!wizardp(me) && !values(channel_name)[i]) ||
				wizardp(me) )
				tuned_ch += ({ keys(channel_name)[i] });
		me->set("channels", tuned_ch);
		write("�Ѵ�����Ƶ����\n");
		return 1;
	}
	if ( arg == "off" )
	{
		tuned_ch = ({ });
		me->set("channels", tuned_ch);
		write("�ѹر�����Ƶ����\n");
		return 1;
	}

	return notify_fail("�����Ƶ����\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tune [<Ƶ������> | on | off]

    ���ָ������ѡ���Ƿ�Ҫ����ĳһƵ����ѶϢ�����û��ָ��Ƶ
�����ƣ��ͻ��г���Ŀǰ�����е�Ƶ�������ָ����Ƶ����ԭ������
�еľͻ�ص�����֮�򿪡�
    �� tune on|off ���Դ򿪻�ر�����Ƶ����

������һ��û�������е�Ƶ�����������Զ������򿪡�
Ҫ��һ��Ƶ��������ֻҪ�ã�

<Ƶ������> <ѶϢ> ....

���ӣ�
     chat hello everyone!

������� help channels ��ѯĿǰ����ЩƵ������������

see also : shout
HELP
	);
	return 1;
}

