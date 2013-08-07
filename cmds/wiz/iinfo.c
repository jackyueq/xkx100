// info.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object obj;
	object *ob;
	string str;
	int i,dest;
	object env;
	string place;
	string name;

	if (!arg) return help(me);

	seteuid(geteuid(me));
	if (sscanf(arg,"-d %s",arg)==1) dest=1;
	if( arg=="me" ) obj = me;
	else if( arg=="my link" ) obj = me->query_temp("link_ob");
	else {
		obj = present(arg, me);
		if (!obj) obj = present(arg, environment(me));
		if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
		if (!obj && sizeof(children(arg))) obj = find_object( resolve_path(me->query("cwd"), file_name(children(arg)[0])));
		if (!obj) return notify_fail("û���������....��\n");
	}

	printf("��� [%O]\n-----------------------------------------------------\n", obj);
	write("������\t\t" + base_name(obj) + ".c\n");
	write("����\t\t" + domain_file(base_name(obj)) + "\n");
	write("���ߣ�\t\t" + author_file(base_name(obj)) + "\n");
	write("Ȩ�ޣ�\t\tuid = " + getuid(obj) + ", euid = " + geteuid(obj) + "\n");
	write("�ȼ���\t\t" + wizhood(obj) + "\n");
	write("ʹ�ü����壺\t" + memory_info(obj) + "\n");
	str = "";
	if( living(obj) ) 		str += "���� ";
	if( userp(obj) )		str += "ʹ���� ";
	if( interactive(obj) )	str += "���� ";
	if( wizardp(obj) ) 		str += "��ʦ ";
	if( clonep(obj) ) 		str += "���� ";
	if( virtualp(obj) ) 	str += "���� ";
	if( query_heart_beat(obj) ) str += "����:" + query_heart_beat(obj) + " ";
	write("���ԣ�\t\t" + str + "\n");
	write("�ο����᣺\t" + refs(obj) + "\n");
	write("���Ƹ�����\t" + sizeof(children(base_name(obj)+".c")) + "\n");
	write("�ֱ����£�\n");
	ob=children(base_name(obj));
	if (dest==1)
	if ( base_name(obj)=="/clone/misc/void" 
			||base_name(obj)=="/clone/user/user")
	{	
		write("������������������ɾ����\n");
		return 1;
	}
	for (i=0;i<sizeof(ob);i++)
	{
	if (dest==1)
	{
		write("���"+file_name(ob[i]));
		destruct(find_object(resolve_path(me->query("cwd"), file_name(ob[i])) ));
		write("�ɹ���\n");
	}else
		{
			write(sprintf("%-24s ",file_name(ob[i])));
			if (ob[i]->query("name") && ob[i]->query("id"))
			name=ob[i]->query("name")+"("+ob[i]->query("id")+")";
			else 
      name="";
			write(sprintf("%-20s",name));
			if (objectp(env=environment(ob[i])))
			{
				place=env->query("name");
				if (!place)
				place=env->query("short");
				if (!place)
				place=env->query_short();
				write(sprintf("%-10s %s",place,file_name(env)));
			}
			write("\n");
		}
	}		

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : iinfo [-d] <���֮���ƻ���>
					 iinfo link me
					 iinfo me
					 iinfo here
	���� -d ��ʾɾ�����и��Ƴ��ĸ������
	
���ô�һָ��ɵ�֪һЩ�йظ��������Ѷ��
HELP
    );
    return 1;
}
