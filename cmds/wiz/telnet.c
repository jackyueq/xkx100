// telnet

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping minfo;
        object tob;

//        if (! SECURITY_D->valid_grant(me, "(wizard)"))
//                return 0;

        seteuid(getuid());

        if (! arg)
                return notify_fail("��Ҫ�������\n");

        if (mapp(minfo = DNS_MASTER->query_mud_info(arg)))
        {
                arg = minfo["HOSTADDRESS"] + " " + minfo["PORT"];
                write("����" + minfo["NAME"] + "(" + arg + ")\n");
        } else
        if (sscanf(arg, "%*s %*s") != 2)
                arg += " 23";

        tob = new("/shadow/telnet");
        if (tob->do_shadow(me, 1) != me)
        {
                write("ϵͳ����ӳ��ʧ�ܡ�\n");
                return 1;
        }

        tob->connect_to(arg);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: telnet <MUD> | <������ַ> [<Ŀ�Ķ˿�>]

���ָ�����������������һ����������

����ʱ���� CLOSE ���������ֹ���ӡ�

HELP );
        return 1;
}
