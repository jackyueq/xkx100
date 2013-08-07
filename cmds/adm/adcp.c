// Last Modified by winder on Apr. 25 2001
#include <ansi.h>

inherit F_CLEAN_UP;

int copy_dir(string src, string dst, int dir_existed);
int help(object me);

// value of call parameter
#define DIR_EXISTED	     1
#define DIR_MAY_NOT_EXISTED     0

int main(object me, string arg)
{
	string *fn;
	string src, dst;
	int copy_dir;
	int count;

	if (me != this_player(1)) return 0;
	seteuid(geteuid(me));

	if (! arg)
	{
		help(me);
		return 1;
	}

	if (sscanf(arg, "-R %s %s", src, dst) == 2)
	{
		copy_dir = 1;
	} else
	if (sscanf(arg, "%s %s", src, dst) == 2)
	{
		copy_dir = 0;
	} else
	{
		write("��ʽ����\n");
		help(me);
		return 1;
	}

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	switch (file_size(src))
	{
	case -1:
		write("û�����(" + src + ")�ļ���Ŀ¼���޷����ơ�\n");
		return 1;

	case -2:
		if (copy_dir) break;
		write("û��ָ�� -R ���������ܸ���Ŀ¼(" + src + ")��\n");
		return 1;
	default:
		// copy file, not directory.
		copy_dir = 0;
		break;
	}

	if (! copy_dir)
	{
		if (file_size(dst) == -2)
		{
			// destination is a directory
			fn = explode(src, "/");
			dst += "/" + fn[sizeof(fn) - 1];
			fn = 0;
		}

		if (cp(src, dst))
			write("Ok.\n");
		else
			write("��û���㹻�Ķ�дȨ����\n");
		return 1;
	}

	if (dst[0..strlen(src) - 1] == src)
	{
		write("�㲻�ܽ�һ��·�����Ƶ������������·���С�\n");
		return 1;
	}

	switch (file_size(dst))
	{
	case -2:
		// destination is a directory
		fn = explode(src, "/");
		dst += "/";
		fn = 0;
		break;
	case -1:
		// no destination
		break;

	default:
		// destition is a file, error
		write("Ŀ¼���ܸ��Ƶ��ļ��ڣ����������Ŀ��·����\n");
		return 1;
	}

		write( "����Ŀ¼�У����Ժ�...\n" );
	count = copy_dir(src, dst, DIR_MAY_NOT_EXISTED);
	if (count)
		write(HIY "�ܹ���" + count + "���ļ����ɹ����ơ�\n" NOR);
	return 1;
}

int copy_dir(string src, string dst, int dir_existed)
{
	mixed *file;
	int count;
	int i;
/*
	if (! is_root(previous_object()))
		return 0;
*/
	count = 0;
	if (src[strlen(src) - 1] != '/') src += "/";
	if (dst[strlen(dst) - 1] != '/') dst += "/";

	// assure dst existed
	if (! dir_existed) assure_file(dst);

	file = get_dir(src, -1);
	if (! sizeof(file))
		return count;

	write (HIC "����Ŀ¼(" + src + ") -- > (" + dst + ")��\n" NOR);
	i = sizeof(file);
	while (i--) {
		reset_eval_cost();
		if (file[i][1] != -2) {
		       if ( file_size(dst) == -1 ) {
			       mkdir(dst);
			       write("����Ŀ¼" + dst + "�ɹ���\n");
			       }
		       if (cp(src + file[i][0], dst + file[i][0])) {
				write(src + file[i][0] + "  -->  ");
				write(dst + file[i][0] + "\n");
				count++; 
				}
		       }
	       }

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] == -2)
		{
			mkdir(dst + file[i][0]);
			count += copy_dir(src + file[i][0],
				dst + file[i][0], DIR_EXISTED);
		}
	}
	return count;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : cp [-R] <�ļ�|·����> <Ŀ���ļ�|Ŀ��·����>
 
���ָ����Ը���Դ�ļ���Ŀ���ļ����Ƶ�Ŀ��·�������ʹ���˲���-R��
���Ը���һ��Ŀ¼��û������������ܸ���·����
HELP
    );
    return 1;
}


