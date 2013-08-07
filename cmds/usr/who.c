// who.c
// From ES2
// Modified by Java on Sep.14 1998
// Commedted by Spacenet on Nov.4 1999
// Modified by Zeratul on Mar.26 2000

#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
string *faction_name = ({
	"������",
	"��������",
	"�䵱��",
	"������",
	"�����",
	"������",
	"��ɽ��",
	"̩ɽ��",
	"��ɽ��",
	"��ɽ��",
	"��ɽ��",
	"������",
	"ؤ��",
	"����",
	"������",
	"����μ�",
	"�һ���",
	"����ɽ��",
	"����Ľ��",
	"ȫ���",
	"��Ĺ��",
	"ѩɽ��",
	"��ң��",
	"���չ�",
	"������",
	"������",
	"�컨��",
	"��ľ��",
	"�嶾��",
	"���ư�",
});
int sort_user(object,object);
int visiblep(object);
int help();

void create() {  seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string name, str, *option;
        object *list, *ob, ob1;
	int i, j, ppl_cnt, fac_no, fac_amt = sizeof(faction_name);
        int opt_long, opt_wiz, opt_party ,opt_age, opt_exp;

        if( arg ) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-h": return help();
                                case "-l": opt_long = 1;        break;
                                case "-w": opt_wiz = 1;         break;
//                              case "-f":
                                case "-p": opt_party = 1;       break;
                                case "-a": opt_age = 1;         break;
  //                              case "-e": opt_exp = 1;         break;
                                //����������ϼ��ֲ�������Ϊwho + player_id���
                                default:
                                        
                                       if(option[i][0]=='@' ) {
                                       	      if (option[i][1..sizeof(option[i])-1]!=mud_nname())
                                       	      {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])-1],
                                                        //me, opt_long);
                                                        me, replace_string(arg,option[i],""));
                                                write("��·ѶϢ���ͳ������Ժ�\n");
                                                return 1;
                                              }
                                              else
                                              {
                                              	return main(this_player(),replace_string(arg,option[i],""),remote);
                                              	}
                                        }
                                        //���ڸ���������Ļ�������Ѱ������ҡ�
                                        ob1 = present(option[i], environment(me));
                                        //���û�ҵ���������������б�����Ѱ��
                                        if (!ob1) ob1 = find_player(option[i]);
                                        //�������û�ҵ����������������б�����Ѱ��
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if (!ob1)
                                        {
                                        	list = users();
                                         	for(j=0;j<sizeof(list);j++)
                                         	{
                                         	 if (list[j]->query("name") == option[i])
                                         	   {ob1 = list[j];break;}
                                         	}
                                        }
                                        if (!ob1) return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]\n");
                                       // if ( objectp(this_player()) && userp(this_player())&& !wizardp(this_player()) && !this_player()->visible(ob1))
                                        if ( objectp(me) && userp(me) && !wizardp(me) && !me->visible(ob1))
                                        	return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]\n");
                                        /* �����������У�ʹ�õ�who + ��ʦ��ʱ�����۸���ʦ���������Ҷ���
                                           �����������������б��������������ķ�����Modified by Spacenet */
                                        me = ob1; opt_party = 1;
                        }
        }

        if( objectp(me) && userp(me) && opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 5 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("jing", 5);
        }
	//���ݲ�ͬ�Ĳ������ñ�ͷ��
        str = HIG "��"+MUD_NAME+HIG "��"+HIW+"    Ŀǰ�����е� " NOR;
        if(opt_party)
                if(me->query("family/family_name"))
                        str += HIR+"("+me->query("family/family_name")+") "+NOR;
                else str += HIR + "(������) " + NOR;
        if ( opt_wiz )
                str += "�����У�";
        else
                if ( opt_long ) str += "����У�";
                else str += "�������У�";

        str += "\n";
        str +=
                HIC"��"+HIY"����������������������������������������������������������������������"HIC"��\n"NOR;
        ob = filter_array( objects(), (: visiblep :) );
        if (opt_party) {
               //������ob����Ѱ����partyָ����ͬ����ҡ�	
               ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
                        }
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;   //ppl_cnt ?= party player count��ͬ�����������
        
        //����who -l�������
        if( opt_long )
        {
               //�������ɷ����г���ҡ�	
               for (fac_no=0; fac_no<fac_amt; fac_no++)
               {           	
                       i = sizeof(list);
                       while ( i-- )
                       {
                                if( interactive(list[i]) )
                                	ppl_cnt++;
                                //��ͬ�ŵ��������һ��	
                                if( list[i]->query("family/family_name") == faction_name[fac_no])
                                        str = sprintf("%s%12s%s%s\n",
                                                str,
                                                RANK_D->query_rank(list[i]),
                                                //������ҵ�ǰ״̬�����������ߣ��ֱ���ϲ�ͬ��־��
                                                interactive(list[i])?(query_idle(list[i]) > 150? HIG "*" NOR:" "):HIR "#" NOR,
                                                list[i]->short(1));
			}
                }
                //������������ҡ�
                i = sizeof(list);
                while ( i-- )
                {
                        if( interactive(list[i]) )
                        ppl_cnt++;
                        if(!list[i]->query("family") )
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                }
        } else  if( opt_wiz )  //����who -w�������
                {
                        i = sizeof(list);
                        while( i-- )
                        {
                                if (interactive(list[i]))
                                ppl_cnt++;
                                if (!wizardp(list[i]) ) continue;
                                if (list[i]->query("no_look_wiz")) continue;
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                        }
        } else  if( opt_exp )  //����who -e�������
                {
                	      list = sort_array(list,(: $1->query("combat_exp") - $2->query("combat_exp") :));
                        i = sizeof(list);
                        while( i-- )
                        {
                            //    if (interactive(list[i]))
                            //    ppl_cnt++;
                                if (wizardp(list[i]) && !list[i]->query("no_look_wiz")) continue;
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                        }
                } else  //�������������
                {
                i = sizeof(list);
                while ( i-- )
                        {
                        if( interactive(list[i]) && wizardp(list[i]) && !list[i]->query("no_look_wiz") )
                                        name = sprintf( "%s"HIM"%-10s(%-11s"HIY"��",
                                                        " ",
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else if( interactive(list[i]) && query_idle(list[i]) > 150)
                                        name = sprintf( "%s%-10s(%-11s"HIY"��",
                                                        HIG"*"HIW,
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else if(list[i]->query_temp("netdead"))
                                        name = sprintf( "%s%-10s(%-11s"HIY"��",
                                                        HIR"#"HIW,
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else
                                        name = sprintf( HIW"%s%-10s(%-11s"HIY"��",
                                                        " ",
                                                       list[i]->name(1),
                                                       capitalize(list[i]->query("id"))+")");
                                        str = sprintf("%s%25s%s", str, name,
                                                ppl_cnt%3==2?"\n":"");
//                                        if (interactive(list[i]))
                                                ppl_cnt++;
                }
                if ( ppl_cnt%3 ) str += "\n";
        }

        str += HIC"��"+HIY"����������������������������������������������������������������������"HIC"��\n"NOR;
        str = sprintf("%s���� %s λʹ���������У�ϵͳ������%s\n "HIG"*"NOR" ��ʾ�����У�"HIR"#"NOR" ��ʾ�����С�", str, CHINESE_D->chinese_number(sizeof(list)),
                query_load_average());

        if( remote ) return str+"\n";
//      write(str + "\n");
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
}

int visiblep( object ob )
{
	if ( userp(ob) && environment(ob) ) {
    if( !objectp(this_player()) || !userp(this_player())) 
    {
      	if (!wizardp(ob)) return 1;
      	else if (!ob->query("env/invisibility")) return 1;
      	else return 0;
    }
		if(  wizardp(this_player()) ) return 1;
		if( !wizardp(this_player()) && this_player()->visible(ob) ) return 1;
	}
	return 0;
}
int help()
{
//write(@HELP
write("
ָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]

    ���ָ������г����������ϵ���Ҽ���ȼ���

-h �г�������Ļ��
-l ѡ���г��ϳ���ѶϢ��
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��
<ID> �г�<ID>��������������ɵ���ҡ�

    who @mudname ����ʾ����������������ҡ�

"HIG"*"NOR" ��ʾ"HIG"����"NOR"�У�"HIR"#"NOR" ��ʾ"HIR"����"NOR"�С�

���ָ� finger
"
    );
    return 1;
}



