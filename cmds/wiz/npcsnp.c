// snpnpc.c
int main(object me, string arg)
{
        string cname,ccmds;
        object ob,snpee;
        string snoopee;
        seteuid(getuid());
        if( !arg ) return notify_fail("��Ҫ����˭?\n");
        if( arg == "none" )
        {
                snoopee = me->query_temp("snoopee");
                if( !snoopee ) return notify_fail("��û�м����κ���.\n");
                snpee = find_player(snoopee);
                if( !snpee )
                snpee = find_living(snoopee);
                if( !snpee ) return notify_fail("�Ҳ���������������.\n");
                snpee->set_temp("is_snooped",0);
                me->set_temp("snoopee",0);
                return notify_fail("������ֹͣ����"+snpee->name()+"���յ�����Ϣ\n");
        }
        if( me->query_temp("snoopee") )
                return notify_fail("���Ѿ��ڼ�������.\n");
        ob = find_player(arg);
        if( !ob )
                ob = find_living(arg);
        if( !ob )
                return notify_fail("�Ҳ�������ˡ�\n");
        ob->set_temp("is_snooped",1);
        ob->set_temp("snooper",me->query("id"));
        me->set_temp("snoopee",ob->query("id"));
        write("�����ڿ�ʼ����"+ob->name()+"���յ�����Ϣ.\n");
        return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: snp <someone> ��ʼ����.
        �� snp none ȡ������.
HELP
   );
   return 1;
}
