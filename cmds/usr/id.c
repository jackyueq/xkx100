// id.c
// Modified by Spacenet@FXLT

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object obj, *inv, *inv1;
	string *id;
	string str;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("������û���κζ�����\n");
		for (i = 0;i < sizeof(inv);i ++)
			if (!arrayp(inv1)) 
				inv1 = ({inv[i]});
			else {
				for (j = 0;j < sizeof(inv1);j ++)
					if (inv[i]->short(1) == inv1[j]->short(1))
						break;
				if (j == sizeof(inv1))
					inv1 += ({inv[i]});
			}
			
		write( "��(��)����Я����Ʒ�ı������(�ҷ�) :\n");
		for(i = 0; i < sizeof(inv1); i ++) {
			if( !me->visible(inv1[i]) ) continue;
			printf("%-20s = %s\n", inv1[i]->name(),
				implode(inv1[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("����û���κζ�����\n");
		write( "�����������, ���Ｐ��Ʒ��(Ӣ��)�������� :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			str = implode(inv[i]->parse_command_id_list(), ", ");
			if (inv[i]->query_temp("pretend") && 
				arrayp(inv[i]->query_temp("apply/pid")))
			str = implode(inv[i]->query_temp("apply/pid"), ", ");
			printf("%-20s = %s\n", inv[i]->name(),str );
		}
		return 1;
	}
}
int help(object me)
{
write(@HELP
ָ���ʽ : id [here]
 
    ���ָ���������֪����Ʒ��Ӣ�����Ƽ����֡�ֻ�� id ����ʾ
��������Я����Ʒ�����ơ�'id here' ����ʾ���и�����ͬһ������
���������ơ�
 
HELP
	);
	return 1;
}
 

