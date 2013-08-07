// bug.c
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;

        string sp, add;
        int bug, bugp , flag;

        seteuid(getuid(me));

        if (! arg || !wizardp(me))
                ob = me;
        else
        if (wizardp(me) )
        {
                // ��� bug ����
                if (sscanf(arg, "%s %d", arg, bug) == 2)
                {
                        if (bug == 0)
 	                        return notify_fail("�㵽��������ӻ���"
                                                   "���٣�\n");
                        if (! objectp(ob = find_player(arg)))
                                ob = LOGIN_D->find_body(arg);
                        if (! objectp(ob))
                        {
                            ob = new(USER_OB);
                            seteuid(arg);
                            export_uid(ob);
                            flag = 1;
                            if (!ob->restore())
                            {
                            	destruct(ob);
                            	return notify_fail("û�������ҡ�\n");
                            }
                        }
                        ob->add("bug", bug);
                        ob->add("bug_count",bug);
                        ob->save();
                        sp = sprintf("�û� " WHT "%s" NOR " �ı������"
                                     "������ " WHT "%d" NOR " �㣬��Ϊ"
                                     WHT " %d " NOR "�㡣\n", arg, bug,
                                     ob->query("bug", 1));

                        if (bug > 0)
                        tell_object(ob, HIG + me->name() + "��������� " +
                                        bug + " �㱨�������\n" NOR);
                        else 
                        tell_object(ob, HIG + me->name() + "��������� " +
                                        -bug + " �㱨�������\n" NOR);
                        

                        log_file("static/bug", sprintf("[%s] wizard %s a"
                                 "dd   %d bug point to user %s.\n",
                                 ctime(time()), getuid(me), bug, getuid(ob)));

                        //UPDATE_D->global_destruct_player(ob);

                        tell_object(me, sp);
                        if (flag == 1) destruct(ob);
                        return 1;
                }
                
                ob = present(arg, environment(me));
                if (! ob || ! ob->is_character()) ob = find_player(arg);
                if (! ob || ! ob->is_character()) ob = LOGIN_D->find_body(arg);
                if (! objectp(ob))
                {
                   ob = new(USER_OB);
                   seteuid(arg);
                   export_uid(ob);
                   flag = 1;
                   if (!ob->restore())
                   {
                    	destruct(ob);
                     	return notify_fail("û�������ҡ�\n");
                    }
                 }
                if (base_name(ob)!=USER_OB)
                {
                	if (flag == 1) destruct(ob);
                    return notify_fail("ֻ����Ҳž��д˲�����\n");
                }
                        
        }
 
        bug = ob->query("bug", 1);

        if (! bug)
                sp = ((ob == me ? "��" : ob->name()) + "��" +
                         MUD_NAME + NOR "�����ޱ�����κδ���\n");
        else
                sp = ((ob == me ? "��" : ob->name()) + "��" +
                         MUD_NAME + NOR "�еĴ��󱨸���۵���Ϊ"
                         HIC + bug +"/"+ob->query("bug_count")+ NOR "�㡣\n");

        tell_object(me, sp);
        if (flag == 1) destruct(ob);
        return 1;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ�� bugs
           bugs       <��������>               (��ʦר��)
           bugs       [<��������> <����>]      (��ʦר��)

���ָ�������ʾ������Ϸ�еĴ��󱨸���۵�������ҿ�ͨ��
�˵������һЩ�������������ʦ���ߣ���ֱ���ڹ���Ƶ���㱨
������ʱ��ʦ���� BUG��С��������ӱ������������Ϸ����
��ʦ���ߣ�������ʽID���Ե���ʦ����һ�BUG�����ң����ǻ�
�ڵ�һʱ�����޸� BUG������ID���ӱ����������ע�⣬ֻ�л�
�� BUG��ID���ܻ�õ��������һ�� BUG���������ͬʱ���֣�
����������ӵ����Ȼ㱨�� BUG��ID�ϡ���

��ʦ����ʹ����ӻ��߼�����ҵı��������

ϸС����1��           (������֡���䲻ͨ��������©��)
һ�����3��           (����Ӱ�쵽��Ϸ�������еĴ���)
���ش���5��           (��������ۡ�����ĳЩϵͳ����)
��������10��1000��    (�����������������������Ĵ���)

HELP);
        return 1;
}

