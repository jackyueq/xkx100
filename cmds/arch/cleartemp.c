// cleartemp.c
// Last modified by winder 2003.10.31

#include <ansi.h>
#include <localtime.h>
#define TEMP_DIR		"/temp/"

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string flogin;
	string fuser;

	if (! wizardp(me)) return 0;
	if (! arg) return help(me);

	seteuid(getuid());
	arg = arg[0..0] + "/" + arg + __SAVE_EXTENSION__;
	flogin = TEMP_DIR + "login/" + arg;
	fuser  = TEMP_DIR + "user/"  + arg;

	if (file_size(flogin) < 0 && file_size(fuser) < 0)
	{
		write("���������ݴ�����û����ʱ������\n");
		return 1;
	}

	rm(flogin);
	rm(fuser);
	if (file_size(flogin) >= 0 || file_size(fuser) >= 0)
	{
		write("����ݴ��������(" + arg + ")���ļ�ʧ���ˡ�");
		return 1;
	}

	write("�ɹ�������ݴ������(" + arg + ")�ĵ�����\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��cleartemp <���ID>

    ��������ݴ����е������ʱ�����������Щ��ʱ����һ����ʹ
�� restore����ӱ������ָ��������ʱ�����ġ�

���ָ�restore
HELP );
    return 1;
}
