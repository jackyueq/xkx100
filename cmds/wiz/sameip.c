// by snowcat
// sameip

#include <ansi.h>

inherit F_CLEAN_UP;

string fname(object ob);

static object run_user = 0;
int all;
string process_bar(int p)
{
	 return "�ٷ�֮"+p;
}

int main(object me, string arg)
{
        object who, ob;
        int    i, j, count;
        string *dir, *ppls;
        string name, address;
        string *result;
        all=0;

        if (! arg)
	        return notify_fail("ָ���ʽ��sameip <ʹ��������> | <IP ��ַ>\n");
        if (sscanf(arg,"-a %s",arg)==1)  all=1;
        
        if (find_call_out("search_dir") != -1)
        {
                if (run_user && run_user != me)
                        return notify_fail("��ǰ" + run_user->query("name") +
                                           "(" + run_user->query("id") + ")" +
                                           "����ʹ�ø�ָ����в��ң����Ժ���ʹ�á�\n");
                remove_call_out("search_dir");
        }

        seteuid(getuid());
        if (member_array('.', arg) != -1)
        {                
                address = arg;
        } else
        {
                name = arg;
                if (file_size(DATA_DIR + "login/" + name[0..0] + "/"  + name + __SAVE_EXTENSION__) < 0)
                        return notify_fail("û����λʹ���ߡ�\n");

                who = new(LOGIN_OB);
                who->set("id", name);
                if (! who->restore())
                        return notify_fail("û����λʹ���ߡ�\n");

                write(fname(who) + "�ϴδ� " + who->query("last_from")+" ���ߡ�\n");
                if (! who->query("last_from"))
                        return notify_fail("�޷���֪������ϴ����ߵص㡣\n");
                address = who->query("last_from");
                destruct(who);
        }

        write("Ѱ�Ҵ� " + address + " ���ߵ�ʹ���ߣ�\n");
        count = 0;
        dir = get_dir(DATA_DIR + "login/");
        i = 0;
        result = ({ });
        call_out("search_dir", 0, count, dir, i, address, me, result);
        write(HIG "����ϵͳ��ͳ�����ݣ��Ժ�㱨��\n"
              HIG "���ȣ�" + process_bar(0) + "\n");
 //       me->attach_system();
        run_user = me;
        return 1;
}

void search_dir(int count, string *dir, int i, string address, object me, string *result)
{
        object ob;
        int j;
        string *ppls, name, str, adr, s1, s2, s3, s4;
        string info;
        if (! objectp(me))
        {
                result = 0;
                return;
        }

/*        if (! me->is_attach_system())
        {
                run_user = 0;
                result = 0;
                return;
        }
*/
        if (i == sizeof(dir))
        {
                info = ESC + "[256D" + ESC + "[K"
                       HIC "\n����������ҵĽ�����£�\n" NOR WHT;
                for (i = 0; i < sizeof(result); i++)
                {
                        info += result[i];
                        if (i % 20)
                        {
                                message("system", info, me);
                                info = "";
                        }
                }
                info += HIG "���� " + to_chinese(count) + " λʹ���ߴ������ַ���ߡ�\n\n" NOR;
                message("vision", info, me);
                run_user = 0;
//                me->detach_system();
//                me->write_prompt();
                result = 0;
                return;
        } else
        {
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j = 0; j < sizeof(ppls); j++)
                {
                        reset_eval_cost();
                        if (sscanf(ppls[j], "%s.o", str)==1)
                        {
                                ob = new(LOGIN_OB);
                                ob->set("id", str);
                                if (! ob->restore() ||
                                    ! (adr = ob->query("last_from")) ||
                                    strsrch(adr, address) == -1 )
                           //         strsrch(address,adr) == -1)
                                {
                                        destruct(ob);
                                        continue;
                                }

                                info = sprintf("%-14s%-12s%-5s%-11s%-9s%s\n",
                                              ob->query("id"),
                                              fname(ob),
                                              ctime(ob->query("last_on"))[20..24],//2004
                                              ctime(ob->query("last_on"))[0..10], //Mon Nov  1 
                                              ctime(ob->query("last_on"))[11..19],//01:09:19 
                                              ob->query("last_from"));
                                result += ({ info });
                                destruct(ob);
                                count++;
                       }
                }
                i++;
        	message("vision", ESC + "[1A" + ESC + "[256D"
                                  HIG "���ȣ�" + process_bar(i * 100 / sizeof(dir)) +
                                  "\n" HIR "ִ����" NOR "> ", me);
         if (!all==1)
           call_out("search_dir", 0, count, dir, i, address, me, result);
         else
           search_dir(count,dir,i,address,me,result);
    }
}

string fname(object ob)
{
        string s2;

        s2 = ob->query("name");
        if (s2 == "") s2 = "����";
        return s2;
}

int  help(object  me)
{
write(@HELP
ָ���ʽ��sameip <ʹ��������> | <IP ��ַ>

����������ʹ������ͬһ��ַ���ߵ�ʹ���ߡ�
HELP
    );
        return  1;
}
