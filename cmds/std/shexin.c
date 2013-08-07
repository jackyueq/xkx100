// shexin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd, verb;
	object ob;
	mapping fam;

	seteuid(getuid());

	if( environment(me)->query("no_ansuan") )
		return notify_fail("�����ֹս����\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if( me != this_player() ) return 0;
	me = this_player();
	if ((!(fam = me->query("family")) || fam["family_name"] != "ѩɽ��"))
		return notify_fail("ֻ��ѩɽ�µ��Ӳ�����ʹ��������\n");
	if (me->query_skill("necromancy",1) < 40)
		return notify_fail("��Ľ�������̫ǳ���ˣ�û����ʹ��������\n");

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("ָ���ʽ: shexin <ĳ��> to <ָ��>\n");

//	if (!ob = get_object( dest ) )
	if( !objectp(ob = present(dest, environment(me))))
		return notify_fail("�Ҳ���" + dest + "��\n");
	if( !living(ob) || ob->query_temp("noliving") )
		return notify_fail("���������ܱ����ġ�\n");
	if( ob->query("id") == "ren zhi" )
		return notify_fail("���"+ob->name() + "��ʹ�������ɲ��ɡ�\n");
	if (userp(me) && ob->query("owner") && me->query("id") != ob->query("owner"))
			return notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");						
	notify_fail("������ͷ��С����������Ϊ�\n");
	if (!userp(ob) && !ob->accept_hit(me)) return 0;		

	if( ob->query("no_get") || ob->query("no_get_from") )
		return notify_fail("���"+ob->name() + "��ʹ�������ɲ��ɡ�\n");
	if( wizardp(ob) ) return notify_fail("��ʦ���ܱ������ġ�\n");
	if( wiz_level(me) < wiz_level(ob) )
		return notify_fail("��û����" + ob->name() + "��ʹ��������\n");
message_vision("
$N��һ���۾������ţ�ֻ������ϸ�죬��ϸ����ӨȻ�й⣬�����������ʡ�
$n΢�����ף�Ҫ��תͷ�ܿ�$N���۹⣬����һ˫�۾����Ʊ�$N��Ŀ����ס�ˣ�
��������������������\n", me, ob);
	if( random(me->query_skill("necromancy",1)) < random(ob->query_skill("force",1)))
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		if( ob->query("age")>17) ob->kill_ob(me);
		return 1;
	}
	if (strsrch(cmd, "give ") >= 0)
	{
		message_vision("���ǣ�$n���Ժ���Ҳ��֪���ǵ���Щʲô��$N��\n", me, ob);
	}
	else
	{
		if (strsrch(cmd, "go ") >= 0)
		{
			if( !userp(ob) )
				return notify_fail("��ֻ�ܶ������ʹ��������\n");
			message_vision("�����$n���Ժ���Ҳ��֪����ô���¾���ǰ�����߿��ˡ�\n", me, ob);
		}
		else
		{
			if (strsrch(cmd, "follow ") >= 0)
			{
				if( !userp(ob) )
					return notify_fail("��ֻ�ܶ������ʹ��������\n");
				message_vision("��Ȼ��$n���Ժ����ؾ͸���$N��ƨ�ɺ������ˡ�\n", me, ob);
			}
			else
				return notify_fail("��ֻ�������˼�����give��go��follow��\n");
		}
	}
	me->start_busy(5);

	if( userp(ob) )
		log_file("shexin_player", sprintf("[%s] %s shexin %s to %s\n", ctime(time()), geteuid(me), geteuid(ob), cmd));
	return ob->force_me(cmd);
}

int help(object me)
{
	write(@HELP
ָ���ʽ: shexin <ĳ��> to <ָ��>

    shexin sb to give sth to sb
    shexin sb to follow sb
    shexin sb to go <dir>

    �����������ջ�ĳ���������ϵĶ�������, ���������뿪������
�����㡣��Ȼ�������ѩɽ�ɵ��ӣ������൱�Ľ�������Ϊ��
    �Է�����ڹ���񣬶���ѧ�ղ�������ȻҲ������������������
�ģ�
HELP
	);
	return 1;
}

