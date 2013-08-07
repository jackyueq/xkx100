// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ��follow <ĳ��>|none��\n");

	if( arg=="none")
		if( me->query_leader() )
		{
			me->set_leader(0);
			write("��������ٸ����κ����ˡ�\n");
			return 1;
		} else {
			write("�����ڲ�û�и����κ��ˡ�\n");
			return 1;
		}
	if( me->is_ghost())
	{
                write("���ǹ�꣬���ܸ������ߡ�\n");
		return 1;
	}
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("����û�� " + arg + "��\n");
	if( !ob->is_character() )
		return notify_fail("ʲô������...." + ob->name() + "��\n");
	if( ob->query_leader() == me )
	{
		write("�˼��Ѿ��ڸ�������Ү��\n");
		return 1;
	}
/* ����������follow������崻�*/
	if( ob==me )
	{
		write("�����Լ���������ó�����\n");
		return 1;
	}
	if( ob->query_leader() && !(wizardp(me) && me->query("env/invisibility")))
	{
		write("�˼��Ѿ��ڸ���������أ�����¸�����Ү��\n");
		return 1;
	}

	me->set_leader(ob);
  if (!me->query("env/invisibility"))
	message_vision("$N������ʼ����$nһ���ж���\n", me, ob);

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ : follow [<����>|none]
 
    ���ָ�������ܸ���ĳ�˻�������ܸ����Ѿ��ڸ�����˵����
    ������� follow none ��ֹͣ���档
    ������ܻ��ʣ������ҵģ��Ҳ�ǣ���壬����ô�����ܸ�����
����������ϸ�����������������ġ���)

 
HELP );
	return 1;
}
