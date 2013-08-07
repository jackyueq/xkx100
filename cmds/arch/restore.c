// restore.c
// Last modified by winder 2003.10.31

#include <ansi.h>
#include <localtime.h>
#include <command.h>
#define BACKUP_D		"/adm/daemons/backupd"
#define DUMP_DIR		"/dump/"
#define TEMP_DIR		"/temp/"
inherit F_CLEAN_UP;

private string get_backup_data_dir(string user, int day);
private void clear_user_data(object ob);
int help(object me);

int main(object me, string arg)
{
	int day;
	string user;
	string dir;
	string flogin, fuser;
	string dump_apply;
	string msg;
	object ob, link_ob;
	int clear_flag;

	if (!wizardp(me)) return 0;
	if (BACKUP_D->is_backuping())
	{
		write("ע�⣺�Զ��������Ͼ�Ҫ��ʼ���������ڻָ����ݡ�\n");
		return 1;
	}
	if (! arg) return help(me);

// ���������Ժ������Ҫ������
	if (sscanf(arg, "-c %s", arg) || sscanf(arg, "%s -c", arg))
		clear_flag = 1;
	else clear_flag = 0;

	if (sscanf(arg, "%s from %d", user, day) != 2)
	{
		if (sscanf(arg, "%s from last", user) == 1) day = 1;
		else
			if (sscanf(arg, "%s from temp", user) == 1) day = 0;
			else
				if (sscanf(arg, "%s from dump/%s", user, dump_apply) == 2) day = -1;
				else
				{
					user = arg;
					day = 1;
				}
	}

	if (day < -1 || day > 7)
	{
		write("û�����������������\n");
		return 1;
	}

	seteuid(getuid());
	if (day == -1)
// restore from dump
	{
		dir = DUMP_DIR + dump_apply;
		if (dir[strlen(dir) - 1] != '/')
			dir += "/";
	}
	else
		if (day == 0)
// restore from temp
			dir = TEMP_DIR;
		else
// restore from backup
			dir = get_backup_data_dir(user, day);

	flogin = "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;
	fuser = "user/" + user[0..0] + "/" + user + __SAVE_EXTENSION__;

	msg = HIM "��ʼ�ָ����(" + user + ")�ı������ݡ�\n\n" NOR;
// check the backup data
	if (file_size(dir + flogin) < 0)
	{
		write(sprintf("%sȱ���ļ���%s���޷��ָ���\n", msg, dir+flogin));
		return 1;
	}

	if (file_size(dir + fuser) < 0)
	{
		write(sprintf("%sȱ���ļ���%s���޷��ָ���\n", msg, dir+fuser));
		return 1;
	}

// remove current user's data
	if (file_size(DATA_DIR + flogin) >= 0 ||
		file_size(DATA_DIR + fuser) >= 0)
	{
		if (dir == TEMP_DIR)
		{
			msg += "�ָ��������ݴ����е����ݡ�\n";
		}
		else
			if (file_size(TEMP_DIR + flogin) >= 0 ||
				file_size(TEMP_DIR + fuser) >= 0)
			{
				msg += "�����ݴ���(/temp/)�����Ѿ��������ҵ����ݣ���˱��β����ݴ档\n";
			}
			else
			{
// move current user's data to /temp/
				assure_file(TEMP_DIR + flogin);
				assure_file(TEMP_DIR + fuser);
				cp(DATA_DIR + flogin, TEMP_DIR + flogin);
				cp(DATA_DIR + fuser, TEMP_DIR + fuser);
				msg += "��ҵ�ǰ�����ݴ浽�ݴ���(/temp/)�¡�\n";
			}
		rm(DATA_DIR + flogin);
		rm(DATA_DIR + fuser);
		msg += "ɾ�����Ŀǰ�ĵ�����\n";
	}

// after remove, if the data existed ?
	if (file_size(DATA_DIR + flogin) >= 0 ||
	    file_size(DATA_DIR + fuser) >= 0)
	{
		write(sprintf( "%sû���ܹ��ɹ���ɾ��������ڵĵ���(%s)��(%s)��\n���Ȳ�֤Ȼ����ִ�б��ݲ�����\n", msg, DATA_DIR + flogin, DATA_DIR + fuser));
		return 1;
	}

// ok. copy the backup data to /data/
	assure_file(DATA_DIR + flogin);
	assure_file(DATA_DIR + fuser);
	cp(dir + flogin, DATA_DIR + flogin);
	cp(dir + fuser,  DATA_DIR + fuser);
	msg += sprintf("��(%s)�и�����ҵĵ������ݡ�\n", dir);

// success ?
	if (file_size(DATA_DIR + flogin) < 0 ||
	    file_size(DATA_DIR + fuser) < 0)
	{
		write(sprintf("%sû���ܹ��ɹ��Ĵ�(%s)�и�����ҵĵ�����\n", msg, dir));
		return 1;
	}
	msg += sprintf("�������Ƴɹ���\n");
	log_file("backup", sprintf("user %s has been restore by %s from %s.\n", user, geteuid(me), dir));

// the player online?
	if (! (ob = find_player(user)))
	{
		write(msg);
//		EXAMINE_CMD->main(me, "-u " + user);
		if (objectp(ob = find_player(user)))
		{
			if (clear_flag)
			{
				tell_object(me, HIG "��������" + ob->name(1) + "��ĳЩ������ݡ�\n" NOR);
				clear_user_data(ob);
			}
		}
		else tell_object(me, HIG "�޷��������ҡ�\n" NOR);
		return 1;
	}

// restore the object
	tell_object(ob, HIM "\n�Ӵ���������������ݣ����������á�\n" NOR);
	if (! ob->restore())
	{
		write(sprintf("%s���û��޷���ȡ���ݵ����ݡ�\n", msg));
		return 1;
	}
	if (objectp(link_ob = ob->query_temp("link_ob")))
		link_ob->restore();

	write(msg);

// re-setup the user
	ob->delete_temp("user_setup");
	ob->setup();
	if (! environment(ob))
	{
		tell_object(ob, HIC"\n�������Ļ��������������Ƶ�����\n"NOR);
		ob->move("/d/city/wumiao");
	}

// force look
	tell_object(ob, HIY  "> l\n" NOR);
	catch(ob->force_me("look"));

// force hp
	tell_object(ob, HIY  "> hp\n" NOR);
	catch(ob->force_me("hp"));

	// force show
	ob->write_prompt();
	tell_object(ob, HIY"check backup data now.\n" + HIC"������Ŀǰ��״���Ƿ���ȷ��\n" NOR);
	if (ob != me) tell_object(me, HIC "\n����Ѿ��������á�\n\n" NOR);
	if (clear_flag)
	{
		write(HIG"��������" + ob->name(1) + "��ĳЩ������ݡ�\n"NOR);
		clear_user_data(ob);
	}
	return 1;
}

// return the directory of the user
// dir/login/?/??? & dir/user/?/??? would be the user's data
private string get_backup_data_dir(string user, int day)
{
	mixed lt;
	int now;

	lt = localtime(time());
	lt[LT_MON]++;   // the month is from 0..31 so I will adjust it
	now = lt[LT_HOUR] * 100 + lt[LT_MIN];
	if (now > BACKUP_D->query_backup_time())
	{
		// because the o'clock has pass through the backuping
		// time, so the most recently backup data is of today
		day--;
	}

	lt[LT_MDAY] -= day;
	if (lt[LT_MDAY] > 0)
		return sprintf("%s%d-%d-%d/", BACKUP_DIR,
			       lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);

	lt[LT_MON]--;
	switch (lt[LT_MON])
	{
	case 2:
		if ((lt[LT_YEAR] % 4) == 0 && (lt[LT_YEAR] % 100) != 0)
			lt[LT_MDAY] += 29;
		else
			lt[LT_MDAY] += 28;
		break;

	case 1: case 3: case 5: case 7: case 8: case 10:
		lt[LT_MDAY] += 31;
		break;

	case 4: case 6: case 9: case 11:
		lt[LT_MDAY] += 30;
		break;

	case 0: // last year
		lt[LT_MDAY] += 31;
		lt[LT_MON] = 12;
		lt[LT_YEAR] --;
	}

	return sprintf("%s%d-%d-%d/", BACKUP_DIR,
		       lt[LT_YEAR], lt[LT_MON], lt[LT_MDAY]);
}

private void clear_user_data(object ob)
{
	ob->delete("private_room");
	ob->delete("can_summon");
	ob->delete("couple");
	ob->delete("brothers");
	ob->delete("league");
	ob->set("balance", 0);
}

int help(object me)
{
	write(@HELP

ָ���ʽ��restore [-c] <���ID> from <last | 1..7 | temp | dump>

    �ӱ������ָ�һ����ҵ����ݡ����� last ��Ч�ڣ�����ʾ����
��һ�εı����лָ���������ݻָ�ʱ����ǰ�����ݽ������浽һ��
�ݴ���������ݴ����գ����������һָ��ı��ݲ����⣬�����ٴ�
 temp �лָ�����ҵ����ݻָ�ʱ�������������ϣ���ִ�б�������
�����Ҵ�ʱ���ݲ�����������û�л�������û�� setup�������¸�
����ҡ������Ҳ������ϣ���������Զ�����ҵ�����Ϸ�����㴦
����ϱ�Ҫ�������Ժ���Խ�������߳�(kickout)��Ϸ��

    ִ����ָ������Ժ�Ӧ�ý���ҵ����ݴ��ݴ������������

    ϵͳ SHUTDOWN ���߱����Ժ����еĴ������ݰ���������ݽ�
�����浽 dump Ŀ¼�У�����Ϊ�˷�ֹϵͳ���������Ժ���ֹ��ϵ�
�������ܵ���ʧ�����Ҳ���Դ� dump �лָ����ݡ�

    ʹ�� -c ���������ڻָ���������Ժ���������������Ե���
�ݡ����������Щ��ɱ�Ժ�ָ�����Ҷ��Եģ�����������ɱ������
�е���������ݶ��ᱻ������ָ��Ժ�Ӧ����������������Щ���ݣ�
�������ݲ�һ�¡�

    ע�⣺�ڱ���ϵͳ��һ�������ʾ�Ժ�һֱ��������ϵĹ����У�
����ִ���йػָ�������ݵĲ�����

���ָ�cleartemp
HELP );
	return 1;
}
