// /cmds/arch/clearcoor.c

// Created by Constant Jan 8 2001

inherit F_CLEAN_UP;

int clearfile(object me,string file);

int main(object me, string arg, int recur_flag)
{
	int i, j;
	string dir;
	mixed *file;
	int recur = 0;

	seteuid(geteuid(me));

	if (arg == "-d") {
		recur = 1;
		arg = "";
	}

	if (arg && sscanf(arg, "-d %s", arg))
		recur = 1;

	if (arg && sscanf(arg, "-s %s", arg)) {
		arg = resolve_path(me->query("cwd"), arg);
		if (!sscanf(arg, "%*s.c"))
			arg += ".c";
		if (file_size(arg) > 0) {
			notify_fail("������ϡ�\n");
			return clearfile(me ,arg);
		} else
			return notify_fail("û������ļ���\n");
	}

	dir = resolve_path(me->query("cwd"), arg);

	if ( file_size(dir) == -2 && dir[strlen(dir)-1] != '/' )
		dir += "/";

	file = get_dir(dir, -1);

	if (!sizeof(file)) {
		if (file_size(dir) == -2)
			return notify_fail("Ŀ¼�ǿյġ�\n");
		else
			return notify_fail("û�����Ŀ¼��\n");
	}

	i = sizeof(file);
	while (i --) {
		if (file[i][1] == -2)
			file[i][0] += "/";
	}

	write("���ڴ���Ŀ¼��" + dir + "\n");

	if (sizeof(file)) {
		for(i = 0,j = sizeof(file); i < j; i ++) {
		       	if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.c")
       				&& file[i][0][strlen(file[i][0])-1] == 'c'
				&& file[i][0][strlen(file[i][0])-2] == '.')
				clearfile(me, dir + file[i][0]);
			else if (file[i][1] == -2 && recur)
				call_other(__FILE__, "main", me, dir+file[i][0], 1);
		}
	}

	return 1;
}

int clearfile(object me, string file)
{
	object obj;
	int i, x, y, z;
	string *in_text, *temp_text, out_text;

	reset_eval_cost();

	if (!(obj = find_object(file)))
		obj = load_object(file);

	if (!obj || !obj->query("coor"))
		return 0;
	else {
		x = obj->query("coor/x");
		y = obj->query("coor/y");
		z = obj->query("coor/z");
	}

	in_text = explode(read_file(file), "\n");

	reset_eval_cost();

	write("\t���������ļ�" + file);
	for (i = 0; i < sizeof(in_text); i ++) {
		if (strsrch(in_text[i], "set(\"coor/") == -1) {
			if (nullp(temp_text))
				temp_text = ({in_text[i]});
			else
				temp_text += ({in_text[i]});

		} else
			write(".");
	}

	out_text = implode(temp_text, "\n");
	out_text = replace_string(out_text, "setup()",
			sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", 
			x, y, z));

	write_file(file, out_text, 1);

	write("��ϡ�\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ: clearcoor [-d | -s] [<·����> | <�ļ���>]

���ָ��Ŀ¼�����е��ļ��Ķ������꣬�����ָ��
Ŀ¼, ��ʹ�õ�ǰĿ¼�����������-d������������
��Ŀ¼�����ָ������-s����ֻ������ļ���

HELP
);
return 1;
}
