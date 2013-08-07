// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int rm_dir(string dir);
int help(object me);

int main(object me, string arg)
{
	string file;
	string dir;
	int rm_dir;
	int count;
 
	if (me != this_player(1)) return 0;
	seteuid(geteuid(me));
 
	if (! arg)
	{
		help(me);
		return 1;
	}

	if (sscanf(arg, "-R %s", dir) == 1)
	{
		rm_dir = 1;
	} else
	{
		dir = arg;
		rm_dir = 0;
	}

	file = resolve_path(me->query("cwd"), dir);
 
	switch (file_size(file))
	{
	case -1:
		write("û������ļ���\n");
		return 1;
	case -2:
		if (rm_dir)
		{
			write(HIR "ɾ��Ŀ¼�У����Ժ�..." NOR),

			count = rm_dir(file);
			if (count)
				write(HIY "�ܹ���" + count + "���ļ����ɹ�ɾ����\n" NOR);
			return 1;
		}

		if (rmdir(file))
			write("�ɹ���ɾ����Ŀ¼(" + file + ").\n");
		else
			write("��û��ɾ����Ŀ¼��Ȩ�޻�����ͼɾ��һ��"
			      "�ǿյ�Ŀ¼��\n");
		return 1;
		
	default:
		if (rm(file))
			write("�ɹ���ɾ�����ļ�(" + file + ").\n");
		else
			write("��û��ɾ������Ȩ�ޡ�\n");
		return 1;
	}
}
 
int rm_dir(string dir)
{
	mixed *file;
	int count;
	int i;
/*
	if (! is_root(previous_object()))
		return 0;
*/
	count = 0;
	if (dir[strlen(dir) - 1] != '/') dir += "/";
	file = get_dir(dir, -1);

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] != -2)
			if (rm(dir + file[i][0]))
				count++;
	}

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] == -2)
			count += rm_dir(dir + file[i][0]);
	}

	write (HIC "ɾ��Ŀ¼(" + dir + ")��\n" NOR);
	rmdir(dir);
	return count;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : rm [-R] ������
 
��ָ�������ɾ��ĳ��������Ŀ¼�����ʹ����-R����������ɾ���ǿյ�Ŀ
¼��ʹ�øò������ҪС�ģ�����ɾ����·����
HELP
    );
    return 1;
}

