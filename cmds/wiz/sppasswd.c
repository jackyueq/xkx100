// passwd.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}
int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
		return notify_fail("����Ҫ����˭�����룿��������֮ǰ����˼һ��Ҫ�õ��䱾��ͬ�⡣\n");
	ob=find_player(id);

	if(!ob)
	{
		ob = new(LOGIN_OB);
		ob->set("id",id);
		if( !ob->restore() ) return notify_fail("û�������ҡ�\n");
		else
		{
			ob->set("password",crypt(password,0));
			ob->save();
			destruct(ob);
			return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("password",crypt(password,0));
		link_ob->save();
		return 1;
	}
	else
		return notify_fail("�����޷������޸ġ�\n");
	return 1;
}


int help(object me)
{
	write(@HELP
ָ���ʽ : passwd

���ָ������޸�����������롣

HELP
    );
    return 1;
}
