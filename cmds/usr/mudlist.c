// mudlist.c

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

#define	SYNTAX	"ָ���ʽ��mudlist [<Mud ����>]\n"

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

	if( !find_object(DNS_MASTER) )
		return notify_fail("��·���鲢û�б����룬���Ƚ���·�������롣\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
	if(arg && arg != "") {
		arg = htonn(arg);

		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
			return 1;
		}
		printf("�й� %s ����Ѷ��\n%O\n", arg, mud_list[arg]);
		return 1;
	}

	output = "�ͣգ�����\t ��������\t  ��   ַ\t�˿�\t�����\n��������������������������������������������������������������\n";

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
		output += sprintf("%-14s%-18s%6s\t%s\t%s\n", muds[loop], 
			mud_list[muds[loop]]["MUDNAME"],
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			mud_list[muds[loop]]["USERS"] );
			this_player()->start_more( output );

	return 1;
}


int help(object me)
{
	write(@HELP
ָ���ʽ��mudlist [<�������>]

    ���ָ�������г�Ŀǰ����� Mud ȡ����ϵ�е����� Mud��
HELP
	);
	return 1;
}

