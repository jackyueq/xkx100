// ce.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	object obj;
	int flag=1;
	if(!me->query("couple/have_couple")) return help(me);

	obj = find_player(me->query("couple/couple_id"));

		if(!obj || (!wizardp(me) && !me->visible(obj)))
			flag=0;

//	if (!wizardp(me) && obj->query_temp("pigging_seat"))
//		return notify_fail("��İ������ڹ������������Ļ�....\n");

	if( !arg )
	{
//		message_vision(MAG "\n$N��ô˼��"+me->query("couple/couple_gender")+me->query("couple/couple_name")+"�����������˺η���...\n"NOR, me);
		write(MAG "\n���ô˼��"+me->query("couple/couple_gender")+me->query("couple/couple_name")+"�����������˺η���...\n"NOR);
		if (flag)
		tell_object(obj,MAG"\n���"+obj->query("couple/couple_gender")+"��˼����... ...\n" NOR);
	}
	else
		switch (arg)
		{
			case "kiss":
				if( objectp(present(me->query("couple/couple_id"), environment(me))) )
//					message_vision(MAG "\n$Nӵ����$n�����һ��...\n"NOR, me, obj);
				{
					write(MAG "\n��ӵ����"+me->query("couple/couple_name")+"�����һ��...\n"NOR);
					tell_object(obj,MAG"\n"+obj->query("couple/couple_name")+"ӵ�����������һ��...\n" NOR);
				}
				else
				{
					write(MAG "\n�����ӵ�����" + me->query("couple/couple_gender") + "�����һ��...\n" NOR);
					if (flag)
					tell_object(obj, MAG "\n���"+obj->query("couple/couple_gender")+"����ӵ���㣬���������һ��... ...\n" NOR);
				}
				break;	
			case "bye":
				if( objectp(present(me->query("couple/couple_id"), environment(me))) )
//					message_vision(MAG "\n$N����������$n�����ʵ�: ��Ҫ�ټ��ˣ���ʱ���ܳ���۲�����ѽ...\n"NOR, me, obj);
				{
							write(MAG "\n�㺬��������"+me->query("couple/couple_name")+"�����ʵ�: ��Ҫ�ټ��ˣ���ʱ���ܳ���۲�����ѽ...\n"NOR);
							tell_object(obj,MAG "\n"+obj->query("couple/couple_name")+"�����������㣬���ʵ�: ��Ҫ�ټ��ˣ���ʱ���ܳ���۲�����ѽ...\n"NOR);
				}
				else
				{
					if (me->query("gender")=="Ů��")
					{
						write(MAG"\n������ٶ࿴���"+me->query("couple/couple_gender")+"һ�ۣ�����֪������������һֱ�������...\n"NOR);
					if (flag)
						tell_object(obj, sprintf(MAG "\n���%s�����ٶ࿴��һ�ۣ�ɽңˮ��������һֱ�ǹ���ģ���Ҫ�Լ����ذ�... ...\n" NOR, obj->query("couple/couple_gender")));
					}
					else
					{
						write(MAG"\n������ٶ࿴���"+me->query("couple/couple_gender")+"һ�ۣ�����֪������������һֱ�������...\n"NOR);
					if (flag)
						tell_object(obj, MAG "\n���"+obj->query("couple/couple_gender")+"�����ٶ࿴��һ�ۣ�ɽңˮ��������һֱ�ǹ���ģ���Ҫ�Լ����ذ�... ...\n" NOR);
					}
				}
				break;
			default:
			if (!flag)
				if (me->query("gender")=="Ů��")
					return notify_fail(MAG"��������" + me->query("couple/couple_gender")+"˵˵�������������ڲ������ϡ�\n"NOR);
				else
					return notify_fail(MAG"��������" + me->query("couple/couple_gender")+"˵˵�������������ڲ������ϡ�\n"NOR);
			write(MAG "�����ĸ������" + me->query("couple/couple_gender") + "��" + arg + "\n" NOR);
			tell_object(obj, sprintf( MAG "���%s���ĸ����㣺%s\n" NOR, obj->query("couple/couple_gender"), arg));
//				message("channel:snp", HIB"��������" + me->name() + "���ĸ���"+ obj->name() + "��" + arg + "\n"NOR, users());
// 				������˽�������ð�?
		}
		return 1;
}

int help(object me)
{
	write(@HELP

ָ���ʽ��ce [kiss | bye] [<ѶϢ>]

    ����������ָ�����İ���˵���Ļ���

HELP
	);
	return 1;
}
