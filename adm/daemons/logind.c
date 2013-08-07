// adm/daemons/logind.c
// Modified by Constant Apr 19 2000
// Modified by Constant Jan 2 2001
// Modified by Zeratul Jan 12 2001 �����������updated.c��

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <localtime.h>

#define VISITORS "/log/MUDVISITOR"
#define GIFTCARD "/log/GIFTCARD"

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
// tentop
int mad_lock = 0;
// �ƽٲ�������������
int dienpc = 0;
string *banned_name = ({
	"��", "��", "��", "��", "��", "��", "��", "��", "��",
	"����ү", "������", "����", "ʱ��", "��",
	"ľ��", "��������", "����", "ΤС��","����",
        "����", "���", "����", "�������", "����ѩ", "���ҡﰮ��",
        "��־��"
});

string *wiz_ip = ({
	"127.0.0.1",
	"210.34.9.71",
	"210.34.1.193",
	"localhost",
	"210.34.9.25",
	"210.34.4.159"
});

private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
private void sel_str(string item, object ob, mapping my,int all,int min,int max);
private void sel_int(string item, object ob, mapping my,int all,int min,int max);
private void sel_con(string item, object ob, mapping my,int all,int min,int max);
private init_new_player(object user);
private void get_hometown(string born,object ob );
private void config_gift(object me,mapping my);
private void delete_err_pass(string yn,object ob,object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object make_body(object ob);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int howmuch_money(object ob);
int howmany_visitor();
int howmany_card();
void set_visitor(int num);
void set_card(int num);
// tentop

void create() 
{
	seteuid(getuid());
	set("channel_id", "���߾���");
}

void logon(object ob)
{
	object *usr;
	int i, inv_wiz_cnt, wiz_cnt, ppl_cnt, login_cnt;
	int iplimit;
	int in_login;
	int user_num;

	if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
		write("�Բ������ĵ�ַ���ܻ�ӭ��\n");
		destruct(ob);
		return;
	}
	cat(WELCOME);
	"/cmds/usr/time"->main();

	usr = users();
	wiz_cnt = 0;
	inv_wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	iplimit = 0;
	in_login = 0;

	for(i=0; i<sizeof(usr); i++)
	{
		if( query_ip_name(usr[i])==query_ip_name(ob)) 
			iplimit ++;
		if ( member_array(query_ip_name(ob), wiz_ip) == -1 &&
			!environment(usr[i]))
			in_login ++;
		if( !environment(usr[i]) ) 
			login_cnt++;
		else if( wizardp(usr[i]) && (usr[i]->query("env/invisibility") || usr[i]->query("no_look_wiz")) ) 
			inv_wiz_cnt++;
		else if( wizardp(usr[i]) && !usr[i]->query("env/invisibility") )
			wiz_cnt++;
		else ppl_cnt++;
	}

	if (in_login > 10 && !member_array(query_ip_name(ob), wiz_ip))
	{
       		write("�Բ���������һ��������æ���أ����Ժ����ԡ�\n");
		destruct(ob);
		return;
	}

	if (BAN_D->is_multi(query_ip_name(ob), iplimit-1))
	{
		write("�Բ��������ڵĵ�ַ�޷���¼����Ľ�ɫ��\n");
		destruct(ob);
		return;
	}
// ���� Start
	user_num=howmany_visitor();
	write("����������һ���Զ�ǧ��һ��һ��ʮ���������ĵ�"+HIY+chinese_number(user_num+1)+NOR"λ�����ߡ�\n");
	set_visitor(user_num+1);
	if (iplimit>1)
	write("�����ڵĵ�ַ����"HIY+chinese_number(iplimit-1)+NOR"λ��������ϡ�\n");
/*	if (iplimit>8)
	{
		write("�Բ��������ڵĵ�ַ�޷���¼����Ľ�ɫ��\n");
		destruct(ob);
		return;
	}
*/
// ���� End
	log_file( "PLAYERNUM", sprintf("At %s: %d %s\n", ctime(time()), ppl_cnt , query_ip_name(ob)) );
	printf( "Ŀǰ���� %s λ������ˡ�%s λ������Ů�����ϣ��Լ� %s λʹ���߳��������С�\n",
		chinese_number(wiz_cnt), 
		chinese_number(ppl_cnt), 
		chinese_number(login_cnt+inv_wiz_cnt) );

	write("����Ӣ�����֣�");
	input_to( "get_id", ob );
}

void set_visitor(int num)
{
	if (num>0) write_file(VISITORS, sprintf("VISITORS %d", num), 1);
	else write("��ʦ��ע���������Ŀ���ԣ�\n");
	return;
}

void set_card(int num)
{
	if (num>0) write_file(GIFTCARD, sprintf("GIFTCARD %d", num), 1);
	else write("��ʦ��ע���������Ŀ���ԣ�\n");
	return;
}

int howmany_user()
{
	int i,j,ppl_cnt;
	string *dir , *ppls, name;
	mixed info;
	seteuid(getuid());
	ppl_cnt=0;
	dir=get_dir(DATA_DIR+"login/");
	for(i=0; i<sizeof(dir);i++)
	{
		reset_eval_cost();
		ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
		ppl_cnt+=sizeof(ppls);
	}
	return ppl_cnt;
}

int howmany_visitor()
{
	int num=0;
	string content, format;
	content=read_file(VISITORS);
	sscanf(content, "%s %d", format, num);
	if(format!="VISITORS") write(format+"\n��ʦ��ע���������Ŀ���ԣ�\n");
	return num;
}

int howmany_card()
{
	int num=0;
	string content, format;
	content=read_file(GIFTCARD);
	sscanf(content, "%s %d", format, num);
	if(format!="GIFTCARD") write(format+"\n��ʦ��ע���������Ŀ���ԣ�\n");
	return num;
}

private void get_id(string arg, object ob)
{
	object ppl, *ob_list;
	int i,j;

	arg = lower_case(arg);
	if( !check_legal_id(arg))
	{
		write("����Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)" &&
//		sizeof(users()) >= MAX_USERS )
		sizeof(users()) > 1000 )
	{
		ppl = find_body(arg);
// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) )
		{
			write("�Բ���"+MUD_NAME+ "��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
		}
	}
#endif

        if( wiz_level(arg) < wiz_lock_level )
	{
		write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL + " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg )
	{
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
/*
	if( arg=="guest" )
	{
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else
*/
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
	{
		if( ob->restore() )
		{
			write("���������룺");
			input_to("get_passwd", 1, ob);
			return;
		}
//		write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
		write("�������ﴢ�浲����һЩ���⣬�����������ʺ�֪ͨ��ʦ����\n");
		destruct(ob);
		return;
	}
	else
        	if(strlen(arg) > 8)
		{
			write("����Ӣ������̫���ˣ���ѡ���һ��ġ�\n");
			destruct(ob);
			return;
		}

	ob_list = users();
	j = 0;
	for(i=0;i<sizeof(ob_list);i++)
	{
		if((string)ob_list[i]->query("id")==arg) j++;
	}
	if(j>1)
	{
		write("�Բ�����������ʹ�øô���ע�ᣬ�뻻һ�����ŵ�¼��\n");
		destruct(ob);
		return;
	}

	write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
	input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
	string my_pass;
	object user;
	int i,j,s;
	mapping m;
	string *k;

	write("\n");
	my_pass = ob->query("password");
	if( crypt(pass, my_pass) != my_pass )
	{
		write("�������\n");
		ob->set("error_pass/"+ctime(time()),query_ip_name(ob));
		ob->save();
		destruct(ob);
		return;
	}

// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user)
	{
		if( user->query_temp("netdead") )
		{
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if (!ob->query("scborn/reset_gift"))
	if( objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			log_file( "USAGE", sprintf("%s (%s) loggined from %s (%s)\n", user->query("name"),user->query("id"),query_ip_name(ob),ctime(time())));
			if (mapp(m = ob->query("error_pass")))
			{
				if ((string)SECURITY_D->get_status(ob->query("id"))=="(player)")
				{
					tell_object(find_player("trya"),"status="+SECURITY_D->get_status(ob->query("id"))+"\n");
					delete_err_pass("y",ob,user);
					return;
				}
				k = keys(m);
				for (i=0;i<sizeof(m);i++)
					write(k[i]+"\t"+m[k[i]]+"\n");
				write("ɾ��������������¼��[y/n]");
				input_to("delete_err_pass",ob,user);
				return;
			}
			enter_world(ob, user);
			return;
		}
		destruct(user);
	}
	write("�������´���������\n");
	confirm_id("y", ob);
}
private void delete_err_pass(string yn,object ob,object user)
{
	if (yn=="")
	{
		write("ɾ��������������¼��[y/n]");
		input_to("delete_err_pass",ob,user);
		return;
	}
	if(yn[0]=='y' || yn[0]=='Y')
		ob->delete("error_pass");
	enter_world(ob,user);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" )
	{
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob) + " )����ȡ���������Ƶ����\n");
//		log_file( "USAGE", sprintf("%s (%s) replaced by %s (%s)\n", user->query("name"), user->query("id"), query_ip_name(ob), ctime(time()) ) );
		log_file( "LOGIN", sprintf("%-20s replaced by   %15s (%s)\n", user->query("name")+"("+user->query("id")+")",query_ip_name(ob),ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link )
	{
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);	
}
	
private void confirm_id(string yn, object ob)
{
	if( yn=="" )
	{
		write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to("confirm_id", ob);
		return;
	}	
	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("�ðɣ���ô��������������Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}
	ob->set_temp("new_char", 1);
	write( @TEXT

���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ���������벻Ҫѡ���ӹС˵��
��������������

TEXT
	);
	write("�����������֣�");
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
	if( !check_legal_name(arg) )
	{
		write("�����������֣�");
		input_to("get_name", ob);
		return;
	}
	ob->set("name", arg);
	write("���趨�������룺");
	input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 )
	{
		write("����ĳ�������Ҫ�����Ԫ���������������룺");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("��������һ���������룬��ȷ����û�Ǵ�");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("��������������벢��һ�����������趨һ�����룺");
		input_to("new_password", 1, ob);
		return;
	}
	write(@TEXT

��ѡ�������������أ�
 
    ����֮���������������ɽ֮ˮ��������Դ��
    ���磬�������λ����ơ�շת����ĵط����������������������ǣ�ҡ�
    
    �����ѡ����������г��У�
 
    1�� ���� �� �� ���� �� �� ���� �� �� ���� �� �� Į�� �� �� ���� ��
    2�� ���� �� �� ���� �� �� ���� �� �� ���� �� �� ���� �� �� ���� ��
    3�� ���� �� �� ���� �� �� ���� �� �� ���� �� �� ���� �� �� ���� �� 
    4�� ���� �� �� Ȫ�� �� �� ̨�� �� �� ��ƽ �� �� ʯ�� �� �� ��� ��
    5�� ���� �� �� ���� �� �� ���� �� �� ���� �� �� ��ɽ �� �� �ɶ� �� 

TEXT);
	input_to("get_hometown",ob);

}

private void get_hometown(string born,object ob )
{
	mapping my;
	string hometown;
	int j;
	object old;
	
	j = random(6);
  	my = ([]);
  	my["area"] = born;
	switch (born)
	{
		case "1" :
			switch (j)
			{
				case 0:hometown = "����";my["START_ROOM"]="/d/beijing/kedian";break;
				case 1:hometown = "����";my["START_ROOM"]="/d/kaifeng/daoxiang1";break;
				case 2:hometown = "����";my["START_ROOM"]="/d/nanyang/kedian1";break;
				case 3:hometown = "����";my["START_ROOM"]="d/lingzhou/chema";break;
				case 4:hometown = "Į��";my["START_ROOM"]="/d/mobei/menggubao1";break;
				default:hometown = "����";my["START_ROOM"]="d/lingzhou/chema";break;
			}
			break;
			
		case "2" :
			switch (j)
			{
				case 0:hometown = "����";my["START_ROOM"]="/d/changan/kedian";break;
				case 1:hometown = "����";my["START_ROOM"]="/d/lanzhou/kedian";break;
				case 2:hometown = "����";my["START_ROOM"]="/d/hanzhong/kedian1";break;
				case 3:hometown = "����";my["START_ROOM"]="/d/luoyang/luoshenmiao";break;
				case 4:hometown = "����";my["START_ROOM"]="/d/xiangyang/kedian";break;
				default:hometown = "����";my["START_ROOM"]="/d/yongdeng/kedian";break;
			}
			break;
		case "3" :
			switch (j)
			{
				case 0:hometown = "����";my["START_ROOM"]="/d/city/kedian";break;
				case 1:hometown = "����";my["START_ROOM"]="/d/hangzhou/kedian";break;
				case 2:hometown = "����";my["START_ROOM"]="/d/suzhou/kedian";break;
				case 3:hometown = "����";my["START_ROOM"]="/d/wuxi/kedian";break;
				case 4:hometown = "����";my["START_ROOM"]="/d/jiaxing/yanyu";break;
				default:hometown = "����";my["START_ROOM"]="/d/yixing/nanxun";break;
			}
			break;
		case "4" :
			switch (j)
			{
				case 0:hometown = "����";my["START_ROOM"]="/d/fuzhou/rongcheng";break;
				case 1:hometown = "Ȫ��";my["START_ROOM"]="/d/quanzhou/kedian";break;
				case 2:hometown = "̨��";my["START_ROOM"]="/d/taiwan/anping";break;
				case 3:hometown = "��ƽ";my["START_ROOM"]="/d/yanping/road3";break;
				case 4:hometown = "ʯ��";my["START_ROOM"]="/d/shiliang/gate";break;
				default:hometown = "���";my["START_ROOM"]="/d/taiwan/penghu";break;
			}
			break;
		default  :
			switch (j)
			{
				case 0:hometown = "����";my["START_ROOM"]="/d/henshan/chaguan";break;
				case 1:hometown = "����";my["START_ROOM"]="/d/jiangling/majiu";break;
				case 2:hometown = "����";my["START_ROOM"]="/d/yueyang/yueyanglou1";break;
				case 3:hometown = "��ɽ";my["START_ROOM"]="/d/foshan/yingxionglou";break;
				case 4:hometown = "����";my["START_ROOM"]="/d/dali/baiyiminju";break;
				default:hometown = "�ɶ�";my["START_ROOM"]="/d/chengdu/kedian";break;
			}
			break;
	}
  	write("\n���ĳ������ǣ�"+hometown+"\n");
  	my["hometown"]= hometown;
  		write(@TEXT
����������������������������������������������������������������������������
��      һ��������츳��������������ϰ������ϢϢ��ء��������е������    ��
��  ������������������츳��                                              ��
��                                                                        ��
��  ������Ӱ�칥���������������Ĵ�С��                                    ��
��  ���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ����ʦ����������                        ��
��  ���ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������                        ��
��  ����Ӱ���������ܵ�������                                          ��
��                                                                        ��
��      ÿ���������⻹�����������õ��������ԣ�                            ��
��                                                                        ��
��  ������Ӱ�쵽�򶷡������ߵģ��ڴ����ܸ���ػָ�Ԫ����                ��
��  ���ԣ�Ӱ�켼��ѧϰ�����Ըߵģ������׶�ѧЩ����                      ��
��  ��ʶ��Ӱ�칥���ɹ��ʡ���ʶ�ߵģ������ڽ�����                          ��
��  ������Ӱ������ɹ��ʡ������͵ģ����ױ������ҵ�����������              ��
��  ��Ե��Ӱ�쵽����Ϸ��Ļ�����������˵��Խ��Խ�á�����������ˡ�        ��
��  ��ò����ò�õ��ˣ�������������⡣�Զ����͵ĵ��֣����������á�        ��
��                                                                        ��
����������������������������������������������������������������������������
TEXT);
  if (ob->query("scborn/reset_gift"))
  {
  	old = NPC_D->create_player(ob->query("id"));
  	write("��ǰ�����츳Ϊ��\n\n");
  	write("������[ "+old->query("str")+" ]\t");
  	write("���ԣ�[ "+old->query("int")+" ]\n");
  	write("���ǣ�[ "+old->query("con")+" ]\t");
  	write("����[ "+old->query("dex")+" ]\n");
  	write("������[ "+old->query("sta")+" ]\t");
  	write("��ò��[ "+old->query("per")+" ]\n");
  	write("���ԣ�[ "+old->query("spi")+" ]\t");
  	write("��Ե��[ "+old->query("kar")+" ]\n");
  	write("��ʶ��[ "+old->query("cor")+" ]\t");
  	write("������[ "+old->query("cps")+" ]\n");
  	write("\n");
  	destruct(old);
  	write("��Ҫ�̳�ǰ����������(Y/N)");
  	input_to("confirm_gift",ob,my);
  	return;
  }
  config_gift(ob,my);
}

private void confirm_gift(string arg,object ob,mapping my)
{
	object old;
	string chartype;
	
	arg = lower_case(arg);
	if (arg == "y" || arg == "Y")
	{
		write("\n��̳�ǰ�����������ԡ�\n");
  	old = NPC_D->create_player(ob->query("id"));
  	my["str"]=old->query("str")+2;
  	my["int"]=old->query("int");
  	my["con"]=old->query("con")+2;
  	my["dex"]=old->query("dex")+2;
  	my["sta"]=old->query("sta")+2;
  	my["per"]=old->query("per")+2;
  	my["spi"]=old->query("spi")+2;
  	my["kar"]=old->query("kar")+2;
  	my["cor"]=old->query("cor")+2;
  	my["cps"]=old->query("cps")+2;
  	chartype = old->query("character");
  	destruct(old);
  	write("���ĵ����ʼ���ַ��");
		input_to("get_email", ob, my,chartype);
	}
	else if (arg == "n" || arg == "N")
	{
		write("�������Լ����������ԡ�\n");
		config_gift(ob,my);
	}
	else 
  	write("��Ҫ�̳�ǰ����������(Y/N)");
  	input_to("confirm_gift",ob,my);
}

private void config_gift(object ob,mapping my)
{
	int all,min,max;

	all = 80+10*ob->query("scborn/times");
	if (ob->query("scborn/times")) all += 10;
	max = 30+5*ob->query("scborn/times"); 
	min = (all-max-max)/2;
//	min = 10+5*ob->query("scborn/times");
	printf("����츳�ܵ���Ϊ"+all+"����������������������("+min+"��"+max+")��");
	input_to("sel_str", ob, my, all, min, max);
}

private void sel_str(string qty1, object ob, mapping my, int all, int min, int max)
{
	int qty;
	qty = atoi(qty1);
	if (qty < min)
	{
		write(HIR"��ѡ���������ֵ����С��"+min+"��\n"NOR);
		printf("����츳�ܵ���Ϊ"+all+"����������������������("+min+" �� "+max+")��");
		input_to("sel_str", ob, my, all, min, max);
	}
	else
	if (qty > max)
	{
		write(HIR"��ѡ���������ֵ���ܴ���"+max+"��\n"NOR);
		printf("����츳�ܵ���Ϊ"+all+"����������������������("+min+" �� "+max+")��");
		input_to("sel_str", ob, my, all, min, max);
	}
	else
	{
		my["str"] = qty;
		printf("����츳��������%d�㣬���������������Ե���("+min+" �� "+max+")��", all-my["str"]);
		input_to("sel_int", ob, my, all, min, max);
		return;
	}
}

private void sel_int(string qty1, object ob, mapping my, int all, int min, int max)
{
	int qty;
	qty = atoi(qty1);
	if (qty < min)
	{
		write(HIR"��ѡ���������ֵ����С��"+min+"��\n"NOR);
		printf("����츳��������%d�㣬���������������Ե���("+min+" �� "+max+")��", 80-my["str"]);
		input_to("sel_int", ob, my, all, min, max);
	}
	else
	if (qty > max)
	{
		write(HIR"��ѡ���������ֵ���ܴ���"+max+"��\n"NOR);
		printf("����츳��������%d�㣬���������������Ե���("+min+" �� "+max+")��", 80-my["str"]);
		input_to("sel_int", ob, my, all, min, max);
	}
	else
	{
		my["int"] = qty;
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��",
    all-my["str"]-my["int"],
		((all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max),
		(all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
//		  80-my["str"]-my["int"],
//		  (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, 
//		  (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		input_to("sel_con", ob, my, all, min, max);
		return;
	}
}

private void sel_con(string qty1, object ob, mapping my, int all, int min, int max)
{
	int qty;
	qty = atoi(qty1);
	if(qty<min)
	{
		write(HIR"��ѡ��ĸ�����ֵ����С��"+min+"��\n"NOR);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 
		all-my["str"]-my["int"],
		(all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
		(all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
//		80-my["str"]-my["int"], 
//(80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, 
//(80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		input_to("sel_con", ob, my,all,min,max);
	}
	else
	if(qty>max)
	{
		write(HIR"��ѡ��ĸ�����ֵ���ܴ���"+max+"��\n"NOR);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��",
		all-my["str"]-my["int"],
		(all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
		(all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
//		80-my["str"]-my["int"], 
//		(80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, 
//		(80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		input_to("sel_con", ob, my,all,min,max);
	}
	else
	if (all-my["str"]-my["int"]>(max+min))
	{
		if(qty<all-my["str"]-my["int"]-max)
		{
			write(HIR"��ѡ��ĸ�����ֵ��������Χ�ڡ�\n"NOR);
//			printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 
		all-my["str"]-my["int"],
		(all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
		(all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
			input_to("sel_con", ob, my,all,min,max);
		}
		else
		{
			my["con"] = qty;
			my["dex"] = all-my["str"]-my["int"]-my["con"];
			printf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]\n", my["str"], my["int"], my["con"], my["dex"]);
			write("��ͬ����һ���츳��");
			input_to("get_gift", ob, my);
			return;
		}
	}
	else 
	{
		if(qty>all-my["str"]-my["int"]-min)
		{
			write(HIR"��ѡ��ĸ�����ֵ��������Χ�ڡ�\n"NOR);
//		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 
		all-my["str"]-my["int"],
		(all-my["str"]-my["int"])<(max+min)?min:all-my["str"]-my["int"]-max,
		(all-my["str"]-my["int"])>(max+min)?max:all-my["str"]-my["int"]-min);
			input_to("sel_con", ob, my,all,min,max);
		}
		else
		{
			my["con"] = qty;
			my["dex"] = all-my["str"]-my["int"]-my["con"];
			printf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]\n", my["str"], my["int"], my["con"], my["dex"]);
			write("��ͬ����һ���츳��");
			input_to("get_gift", ob, my,all,min,max);
			return;
		}
	}
}

private void get_gift(string yn, object ob, mapping my,int all,int min,int max)
{
	if (yn[0] != 'y' && yn[0] != 'Y')
	{
		printf("����츳�ܵ���Ϊ"+all+"����������������������("+min+" �� "+max+")��");
		input_to("sel_str", ob, my,all,min,max);
	}
	if (yn[0] == 'y' || yn[0] == 'Y')
	{
	write(@TEXT

��ѡ����������Ը����ԣ�
 
    �����������и����Ը�ͱ������Ը����Ե�ѡ�񣬻�����Ӱ��������
�ķ�չ��δ������ÿ���Ը����Զ����Ǿ��Եģ�������ò���ע�⣬��ѡ��ͨ
�ɡ�
    �����ѡ�������Ը����ԣ�

    1��ð�գ���ʶ��Ը�Щ�����������ͱȽϵ��ˡ�
    2��������������Ը�Щ��������ʶ�ͱȽϵ��ˡ�
    3�����ˣ���ò�ȽϺ�Щ����Ĳ���̫�ã���Ҳ����̫�
    4����ǣ����Ը�Щ����ѧ���Ƚ϶�Ĺ��򡣱����Ȼһ�㣬ȴҲ������ȥ��
    5�����ͣ�������Щ��������ѡ�ĸ��ǲ���̫�͡�
    0����ͨ��ʲô�������ǣ�Ҳ���л���ѡ���������������ĺ��츳�ء�
TEXT);
		input_to("get_char", ob, my);
	}
}

private void get_char(string chartype, object ob, mapping my)
{
// ��Ե
	my["kar"] = 10 + random(21)+5*ob->query("scborn/times");
// ��ʶ����������ò�����ԡ�����
	switch (chartype)
	{
		case "1" :
			my["cor"] = 20 + random(11)+3*ob->query("scborn/times");
			my["cps"] = 10 + random(11)+3*ob->query("scborn/times");
			my["per"] = 15 + random(11)+3*ob->query("scborn/times");
			my["spi"] = 15 + random(11)+3*ob->query("scborn/times");
			my["sta"] = 15 + random(11)+3*ob->query("scborn/times");
			write("��ѡ����ð�յ��Ը�\n");
			break;
		case "2" :
			my["cor"] = 10 + random(11)+3*ob->query("scborn/times");
			my["cps"] = 20 + random(11)+3*ob->query("scborn/times");
			my["per"] = 15 + random(11)+3*ob->query("scborn/times");
			my["spi"] = 15 + random(11)+3*ob->query("scborn/times");
			my["sta"] = 15 + random(11)+3*ob->query("scborn/times");
			write("��ѡ���˽������Ը�\n");
			break;
		case "3" :
			my["cor"] = 13 + random(15)+3*ob->query("scborn/times");
			my["cps"] = 13 + random(15)+3*ob->query("scborn/times");
			my["per"] = 20 + random(11)+3*ob->query("scborn/times");
			my["spi"] = 13 + random(15)+3*ob->query("scborn/times");
			my["sta"] = 13 + random(15)+3*ob->query("scborn/times");
			write("��ѡ���˿��˵��Ը�\n");
			break;
		case "4" :
			my["cor"] = 13 + random(15)+3*ob->query("scborn/times");
			my["cps"] = 13 + random(15)+3*ob->query("scborn/times");
			my["per"] = 13 + random(15)+3*ob->query("scborn/times");
			my["spi"] = 20 + random(11)+3*ob->query("scborn/times");
			my["sta"] = 13 + random(15)+3*ob->query("scborn/times");
			write("��ѡ������ǵ��Ը�\n");
			break;
		case "5" :
			my["cor"] = 13 + random(15)+3*ob->query("scborn/times");
			my["cps"] = 13 + random(15)+3*ob->query("scborn/times");
			my["per"] = 13 + random(15)+3*ob->query("scborn/times");
			my["spi"] = 13 + random(15)+3*ob->query("scborn/times");
			my["sta"] = 20 + random(11)+3*ob->query("scborn/times");
			write("��ѡ���˼��͵��Ը�\n");
			break;
		default  :
			my["cor"] = 10 + random(21)+3*ob->query("scborn/times");
			my["cps"] = 10 + random(21)+3*ob->query("scborn/times");
			my["per"] = 10 + random(21)+3*ob->query("scborn/times");
			my["spi"] = 10 + random(21)+3*ob->query("scborn/times");
			my["sta"] = 10 + random(21)+3*ob->query("scborn/times");
			write("����ѡ���ض����Ը�\n");
			break;
	}
  write("\n���ĵ����ʼ���ַ��");
	input_to("get_email", ob, my,chartype);
}

private void get_email(string email, object ob, mapping my,string chartype)
{
	object user;

	write("\n");
	if (email == "" || strsrch(email, "@") == -1) {
		write("�����ʼ���ַ��Ҫ�� id@address �ĸ�ʽ��\n");
		write("���ĵ����ʼ���ַ��");
		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", 1);

	// If you want do race stuff,ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) ) return;
	if (ob->query("scborn/times")==6)
	{
		my["str"]=60;
		my["dex"]=60;
		my["con"]=60;
		my["int"]=60;
		my["kar"]=60;
		my["cor"]=60;
		my["cps"]=60;
		my["per"]=60;
		my["spi"]=60;
		my["sta"]=60;
	}
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	user->set("kar", my["kar"]);
	user->set("cor", my["cor"]);
	user->set("cps", my["cps"]);
	user->set("per", my["per"]);
	user->set("spi", my["spi"]);
	user->set("sta", my["sta"]);
	user->set("START_ROOM",my["START_ROOM"]);
//save in data
//save in user ob and login ob
	user->set("base",my);
	user->set("scborn/times",ob->query("scborn/times"));
    ob->set("base",my);
/////////
	user->set("character", chartype);
	user->set("born/hometown",my["hometown"]);
	user->set("born/area",my["area"]);
	ob->set("registered", 1);
	user->set("registered", 1);

	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	object res;
	string err;
	
	write("\n");
	if( gender=="" )
	{
		write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else {
		write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "Newuser", sprintf("%s (%s) was created from %s (%s) with (%d %d %d %d)\n", user->query("name"),user->query("id"),query_ip_name(ob),ctime(time()),user->query("str"),user->query("int"),user->query("con"),user->query("dex")));
	ob->set("created_on",ctime(time()));
 	ob->set("created_from",query_ip_name(ob));
	init_new_player(user);
	if (ob->query("scborn/reset_gift"))
	{
		err = catch(res = SCBORN_D->check_user(user,ob));	//��ȡ����Ķ�����
    if (stringp(err))
  	CHANNEL_D->do_channel( this_object(), "sys","SCBORN_D CATCH ERROR="+err );
    if (!err && objectp(res)) user = res;
		ob->delete("scborn/reset_gift");
		user->set("scborn/times",ob->query("scborn/times"));
	}
	enter_world(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

	user = new(ob->query("body"));
	if(!user) {
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private init_new_player(object user)
{
	user->set("title", "��ͨ����");
	user->set("birthday", time() );
	user->set("potential", 99);
  user->set("jing",100);
  user->set("qi",100);
  user->set("tili",100);
	user->set("food", (user->query("str")+10)*10);
	user->set("water", (user->query("str")+10)*10);

	user->set("channels", ({ "chat", "rumor", "party", "xkx", "sing" , "es" , "snow" }) );
}

		
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, shoe, room, mailbox, gift, login_ob;
	string startroom;
	string baseroom;
	mixed *ltime;
	int i, cardnum, is_holiday = 0;

	// ����ӳ�����飬�밴�ո�ʽ����½��ա�
	// Added by Constant Jan 2 2001.
	mapping *holidays = ({
		([
			24          : 12,
			25          : 12,
			"cardfile"  : "/clone/misc/cards/card_cs",
		]),
		([
			31          : 12,
			 1          : 1,
			"cardfile"  : "/clone/misc/cards/card_ny",
		]),
		([
			11          : 2,
			12          : 2,
			13          : 2,
			14          : 2,
			"cardfile"  : "/clone/misc/cards/card_ft",
		]), 
	});

	user->set_temp("link_ob", ob);
// ��¼ʱ��¼�����Ǳ��, �Լ���¼ʱ��, Ϊ������ϢԤ��
	user->set_temp("nowexp", user->query("combat_exp"));
	user->set_temp("nowpot", user->query("potential"));
	user->set_temp("nowtime", time());
	user->set_name(user->query("name"),({user->query("id")}));
	ob->set_temp("body_ob", user);
	ob->set_temp("new_char", user);
	user->set("registered", ob->query("registered"));
	exec(user, ob);

	write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");
	user->setup();
	if (!user->query("food") && !user->query("water") &&
		ob->query("age") == 14)
	{
		user->set("food", user->max_food_capacity());
		user->set("water", user->max_water_capacity());
	}

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	// Use condition to auto save user file
	user->apply_condition("autosave", 1);
	
	// ����ʱ���ж��Ƿ�Ϊ���գ������������Ʒ��
	// Added by Constant Jan 2 2001
	ltime = localtime(time());
	
	for (i = 0; i < sizeof(holidays); i++)
	{
		if (holidays[i][ltime[LT_MDAY]] == ltime[LT_MON]+1)
		{
			if (!user->query("holiday_cards") &&
				user->query("mud_age") > 86400)
			{
				cardnum = howmany_card();
				set_card(cardnum + 1);
				gift = new(holidays[i]["cardfile"]);
				gift->move(user);
				user->set("holiday_cards", cardnum);
			}
			is_holiday = 1;
			break;
		}
	}

	// �����ǽ��գ���ɾ������������ԣ�ʹ��һ�������յ���Ʒ��
	// Added by Constant Jan 2 2001
	if (!is_holiday && user->query("holiday_cards"))
		user->delete("holiday_cards");
	
	if (wizhood(user) == "(player)")
	{
		if (user->query("class")=="bonze")
		{
			if (user->query("gender")=="Ů��")
			{
				cloth = new("/clone/cloth/ni-cloth");
				shoe = new("/clone/cloth/ni-shoe");
			}
			else
			{
				cloth = new("/clone/cloth/seng-cloth");
				shoe = new("/clone/cloth/seng-shoe");
			}
		}
		else
		{
			if (user->query("class")=="taoist")
			{
				if ( user->query("gender")=="Ů��")
				{
					cloth = new("/clone/cloth/daogu-cloth");
					shoe = new("/clone/cloth/dao-shoe");
				}
				else
				{
					cloth = new("/clone/cloth/dao-cloth");
					shoe = new("/clone/cloth/dao-shoe");
				}
			}
			else
			{
				if ( user->query("gender")=="Ů��")
				{
					cloth =new("/clone/cloth/female-cloth");
					shoe = new("/clone/cloth/female-shoe");
				}
				else
				{
					cloth = new("/clone/cloth/male-cloth");
					shoe = new("/clone/cloth/male-shoe");
				}
			}
		}
	}
	else
	{
		if ( !user->query("no_look_wiz") )
		{
			cloth = new("/clone/cloth/wiz-cloth.c");
			shoe = new("/clone/cloth/wiz-shoe.c");
		}
		else
		{
			cloth = new("/clone/cloth/male-cloth");
			shoe = new("/clone/cloth/male-shoe");
		}
	}
	cloth->move(user);
	cloth->wear();
	shoe->move(user);
	shoe->wear();

	if( !silent )
	{
		baseroom = START_ROOM;
		if (stringp(user->query("START_ROOM")))
		baseroom=user->query("START_ROOM");
		if (ob->query("registered") == 0) cat(UNREG_MOTD);
		else cat(MOTD);
		if( user->is_ghost() ) startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom")) )
			startroom = baseroom;

		if( !catch(load_object(startroom)) ) user->move(startroom);
		else
		{
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		if (!user->query("env/invisibility"))
		tell_room(startroom, user->query("name") + "���߽���������硣\n", ({user}));
	}
	login_ob=new(LOGIN_OB);
	login_ob->set("id",user->query("id"));
	login_ob->restore();
	write("\n���ϴι���������һ���� " + HIG +ctime(login_ob->query("last_on"))+ NOR + " �� " + HIR +login_ob->query("last_from") + NOR + " ���ӵġ�\n\n");
	destruct(login_ob);

	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s���߽��롣����� " + reclaim_objects() + " ��������\n", user->name(),user->query("id"), query_ip_name(user)) );
	UPDATE_D->check_user(user);
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(user);
//  user->start_call_out( (: call_other,"/cmds/usr/news","check_me",user :),5);
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("new_char", user);
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();
	if( !silent ) {
		if (!wizardp(user) || !user->query("env/invisibility"))
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
		({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s��%s�������߽��롣", user->query("name"), query_ip_name(user)) );
	UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
		write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}

	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 4) || (strlen(name) > 10 ) ) {
		write("�Բ�������������ֱ����� 2 �� 5 �������֡�\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( (strsrch(name, "��") >= 0) ||
		    (strsrch(name, "��") >= 0)) {
			write("�Բ�������������ֲ������������ĵ��֡�\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&	getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
// add for ten top. 
int set_madlock(int setmark)
{
       // if( wiz_level(this_player(1)) < wiz_level("(arch)") )
      // 	return 0;
	if( setmark == 1 ) mad_lock = 1;
	else mad_lock = 0;
	return 1;
}

int get_madlock()
{
	return mad_lock;
}
int howmuch_money(object ob)
{
	int total;
	int total2;
	object gold, silver, coin;

	total = 0;
	total2 = 0;

	gold = present("gold_money",ob);
	silver = present("silver_money",ob);
	coin = present("coin_money",ob);

	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	total2 = (int)ob->query("balance");
	if (!total2 || total2 < 0) {
		ob->set("balance", 0);
	}
	total=total+total2;
	return total;
}

// ���Ӻƽ��ж����������Ķ�ȡ������
void add_dienpc()
{
	dienpc++;
}
void set_dienpc(int i)
{
	if (i == -1)
	{
	        mad_lock = 1;
		dienpc = 0;
		return;
	}
	dienpc = i;
}
int get_dienpc()
{
	return dienpc;
}

