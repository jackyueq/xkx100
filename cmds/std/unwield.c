// unwield.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, *inv;
	string str;
	int i;

	if( !arg ) return notify_fail("��Ҫ�ѵ�ʲô��\n");

	if(me->query_temp("no_unwield",1))
		return notify_fail("�����ڲ�������������! \n");

	if( arg == "all" )
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if( (string)inv[i]->query("equipped")!="wielded" )
				continue;
			if( inv[i]->unequip() ) 
			{
				if(!stringp(str = inv[i]->query("unwield_msg")))
					str = "$N�������е�$n��\n";
				message_vision(str, me, inv[i]);
			}

		}
		write("���ˡ�\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("�㲢û��װ������������Ϊ������\n");

	if( ob->unequip() )
	{
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N�������е�$n��\n";
		message_vision(str, me, ob);
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : unwield <��Ʒ��>
 
    ���ָ������������е�������
 
HELP
	);
	return 1;
}
 
