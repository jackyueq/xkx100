// /adm/daemons/logind.c

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
// 10 
string *banned_name = ({
	"��", "��", "��", "��", "��", "��", "��", "��", "��",
	"����ү", "������", "����", "ʱ��", "��",
	"ľ��", "��������", "����", "ΤС��",
	"����", "���", "����", "�������", "����ѩ", "����"
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
private void sel_str(string item, object ob, mapping my);
private void sel_int(string item, object ob, mapping my);
private void sel_con(string item, object ob, mapping my);
private init_new_player(object user);
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

	for(i=0; i<sizeof(usr); i++) {
                if( query_ip_name(usr[i])==query_ip_name(ob)) 
			iplimit ++;
                if ( member_array(query_ip_name(ob), wiz_ip) == -1 && !environment(usr[i]))
                        in_login ++;
		if( !environment(usr[i]) ) 
			login_cnt++;
	        else if( wizardp(usr[i]) && usr[i]->query("env/invisibility") ) 
			inv_wiz_cnt++;
	        else if( wizardp(usr[i]) && !usr[i]->query("env/invisibility") ) 
			wiz_cnt++;
		else	ppl_cnt++;
	}

        if (in_login > 10 && !member_array(query_ip_name(ob), wiz_ip))
        {
       		write("�Բ���������������æ���أ����Ժ����ԡ�\n");
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
        write("����������һ����һ�žž�������إ���������ĵ�"+HIY+chinese_number(user_num+1)+NOR"λ�����ߡ�\n");
        set_visitor(user_num+1);
        if (iplimit>1)
        write("�����ڵĵ�ַ����"HIY+chinese_number(iplimit-1)+NOR"λ��������ϡ�\n");
// ���� End
	log_file( "PLAYERNUM", sprintf("At %s: %d %s\n", ctime(time()), ppl_cnt , query_ip_name(ob)) );
	printf("Ŀǰ���� %s λ������ˡ�%s λ������Ů�����ϣ��Լ� %s λʹ���߳��������С�\n",
		chinese_number(wiz_cnt), 
                chinese_number(ppl_cnt), 
                chinese_number(login_cnt+inv_wiz_cnt) );

	write("����Ӣ������(����ҿ���ѡ��һϲ��������)��");
	input_to( "get_id", ob );
}

void set_visitor(int num)
{
	if (num>0)
		write_file(VISITORS, sprintf("VISITORS %d", num), 1);
	else
		write("��ʦ��ע���������Ŀ����!\n");
	return;
}
void set_card(int num)
{
	if (num>0)
		write_file(GIFTCARD, sprintf("GIFTCARD %d", num), 1);
	else
		write("��ʦ��ע���������Ŀ����!\n");
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
	if(format!="VISITORS")
		write(format+"\n��ʦ��ע���������Ŀ����!\n");
	return num;
}

int howmany_card()
{
	int num=0;
	string content, format;
	content=read_file(GIFTCARD);
	sscanf(content, "%s %d", format, num);
	if(format!="GIFTCARD")
		write(format+"\n��ʦ��ע���������Ŀ����!\n");
	return num;
}

private void get_id(string arg, object ob)
{
	object ppl; 
	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write("����Ӣ������(����ҿ���ѡ��һϲ��������)��");
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
//	&& sizeof(users()) >= MAX_USERS ) {
	&& sizeof(users()) > 150 ) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write("�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
		}
	}
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
			+ " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}
	
	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
/*
	if( arg=="guest" ) {
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else*/ if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write("���������룺");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ������\n");
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

	write("\n");
	my_pass = ob->query("password");
	if( crypt(pass, my_pass) != my_pass )
	{
		write("�������\n");
		destruct(ob);
		return;
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
			log_file( "USAGE", sprintf("%s (%s) loggined from %s (%s)\n", user->query("name"),user->query("id"),query_ip_name(ob),ctime(time())));
			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write("�������´���������\n");
	confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
			+ " )����ȡ���������Ƶ����\n");
		log_file( "USAGE", sprintf("%s (%s) replaced by %s (%s)\n", user->query("name"), user->query("id"), query_ip_name(ob), ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);	
}
        
private void confirm_id(string yn, object ob)
{
	if( yn=="" ) {
		write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�ðɣ���ô��������������Ӣ�����֣�");
		input_to("get_id", ob);
		return;
	}
        
        ob->set_temp("new_char", 1);
	write( @TEXT

���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ�����������벻Ҫѡ���ӹС˵��
��������������

TEXT
	);
	write("������������(ʹ��Big5����ҿ�������ʦ�޸�)��");
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
	if( !check_legal_name(arg) ) {
		write("������������(ʹ��Big5����ҿ�������ʦ�޸�)��");
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
	if( strlen(pass)<5 ) {
		write("����ĳ�������Ҫ�����Ԫ���������������룺");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("��������һ���������룬��ȷ����û�Ǵ���");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("��������������벢��һ�����������趨һ�����룺");
		input_to("new_password", 1, ob);
		return;
	}

	write(@TEXT

һ��������츳��������������ϰ������ϢϢ��ء��������е����������
���������츳��

	������Ӱ�칥���������������Ĵ�С��
	���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ�����ʦ����������
	���ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������
	������Ӱ���������ܵ�������

TEXT);
// ��Ե����ò������������
	my = ([]);
	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(21);
	my["sta"] = 10 + random(21);
	my["cps"] = 80 - my["sta"] - my["kar"] - my["per"];
	printf("����츳�ܵ���Ϊ80����������������������(10-30)��");
        input_to("sel_str", ob, my);
}

private void sel_str(string qty1, object ob, mapping my)
{
	int qty;
	qty = atoi(qty1);
	if (qty < 10)
	{
		write(HIR"��ѡ���������ֵ����С��ʮ��\n"NOR);
		printf("����츳�ܵ���Ϊ80����������������������(10 �� 30)��");
		input_to("sel_str", ob, my);
	}
	else
	if (qty > 30)
	{
		write(HIR"��ѡ���������ֵ���ܴ�����ʮ��\n"NOR);
		printf("����츳�ܵ���Ϊ80����������������������(10 �� 30)��");
		input_to("sel_str", ob, my);
	}
        else
	{
		my["str"] = qty;
		printf("����츳��������%d�㣬���������������Ե���(10 �� 30)��", 80-my["str"]);
		input_to("sel_int", ob, my);
		return;
	}
}

private void sel_int(string qty1, object ob, mapping my)
{
	int qty;
	qty = atoi(qty1);
	if (qty < 10)
	{
		write(HIR"��ѡ���������ֵ����С��ʮ��\n"NOR);
		printf("����츳��������%d�㣬���������������Ե���(10 �� 30)��", 80-my["str"]);
		input_to("sel_int", ob, my);
	}
	else
	if (qty > 30)
	{
		write(HIR"��ѡ���������ֵ���ܴ�����ʮ��\n"NOR);
		printf("����츳��������%d�㣬���������������Ե���(10 �� 30)��", 80-my["str"]);
		input_to("sel_int", ob, my);
	}
        else
	{
		my["int"] = qty;
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		input_to("sel_con", ob, my);
		return;
	}
}

private void sel_con(string qty1, object ob, mapping my)
{
	int qty;
	qty = atoi(qty1);
	if(qty<10)
	{
		write(HIR"��ѡ��ĸ�����ֵ����С��ʮ��\n"NOR);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		input_to("sel_con", ob, my);
	}
	else
	if(qty>30)
	{
		write(HIR"��ѡ��ĸ�����ֵ���ܴ�����ʮ��\n"NOR);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
		input_to("sel_con", ob, my);
	}
	else
	if (80-my["str"]-my["int"]>40)
	{
		if(qty<80-my["str"]-my["int"]-30)
		{
			write(HIR"��ѡ��ĸ�����ֵ����������Χ�ڡ�\n"NOR);
			printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
			input_to("sel_con", ob, my);
		}
		else
		{
			my["con"] = qty;
			my["dex"] = 80-my["str"]-my["int"]-my["con"];
			printf("\n����[%d]�� ����[%d]�� ����[%d]�� ����[%d]\n", my["str"], my["int"], my["con"], my["dex"]);
			write("��ͬ����һ���츳��");
			input_to("get_gift", ob, my);
			return;
		}
	}
	else 
	{
		if(qty>80-my["str"]-my["int"]-10)
		{
			write(HIR"��ѡ��ĸ�����ֵ����������Χ�ڡ�\n"NOR);
		printf("����츳��������%d�㣬�����������ĸ��ǵ���(%d �� %d)��", 80-my["str"]-my["int"], (80-my["str"]-my["int"]<40)?10:80-my["str"]-my["int"]-30, (80-my["str"]-my["int"]>40)?30:80-my["str"]-my["int"]-10);
			input_to("sel_con", ob, my);
		}
		else
		{
			my["con"] = qty;
			my["dex"] = 80-my["str"]-my["int"]-my["con"];
			printf("\n����[%d]�� ����[%d]�� ����[%d]�� ����[%d]\n", my["str"], my["int"], my["con"], my["dex"]);
			write("��ͬ����һ���츳��");
			input_to("get_gift", ob, my);
			return;
		}
	}
}

private void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		printf("����츳�ܵ���Ϊ80����������������������(10 �� 30)��");
		input_to("sel_str", ob, my);
	}
	if (yn[0] == 'y' || yn[0] == 'Y') {
          	write("\n���ĵ����ʼ���ַ��");
        	input_to("get_email", ob, my);
	}
}

private void get_email(string email, object ob, mapping my)
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

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	ob->set("registered", 1);
	user->set("registered", 1);

	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	write("\n");
	if( gender=="" ) {
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

	log_file( "USAGE", sprintf("%s (%s) was created from %s (%s) with (%d %d %d %d)\n", user->query("name"),user->query("id"),query_ip_name(ob),ctime(time()),user->query("str"),user->query("int"),user->query("con"),user->query("dex")));
	init_new_player(user);
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
        user->set("food", (user->query("str")+10)*10);
        user->set("water", (user->query("str")+10)*10);

	user->set("channels", ({ "chat", "rumor", "party", "xkx", "sing" }) );
//	user->set("balance", 1000);
}

		
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, shoe, room, mailbox, gift, login_ob;
	string startroom;
	mixed *ltime;
        int i, cardnum, is_holiday = 0;

	// ����ӳ�����飬�밴�ո�ʽ�����½��ա�
	// Added by Constant Jan 2 2001.
	mapping *holidays = ({
		([
        		24   	    :   12,
        		25  	    :   12,
        		26  	    :   12,
        		"cardfile"  :  "/clone/misc/cards/card_cs",
        	]),
        	([
        		31  	    :   12,
        		 1  	    :    1,
        		 2  	    :    1,
        		"cardfile"  :  "/clone/misc/cards/card_ny",
        	]),
	});

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
        ob->set_temp("new_char", user);
	user->set("registered", ob->query("registered"));
	exec(user, ob);

	write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");
	user->setup();
	if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
	        user->set("food", user->max_food_capacity());
        	user->set("water", user->max_water_capacity());
	}

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	// Use condition to auto save user file
	user->apply_condition("autosave", 1);
	
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(user);

	// ����ʱ���ж��Ƿ�Ϊ���գ������������Ʒ��
	// Added by Constant Jan 2 2001
	ltime = localtime(time());
	
	for (i = 0; i < sizeof(holidays); i ++) {
		if (holidays[i][ltime[LT_MDAY]] == ltime[LT_MON]+1) {
			if (!user->query("holiday_cards") && user->query("mud_age") > 3600) {
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
				cloth = new("/clone/cloth/ni-cloth.c");
				shoe = new("/clone/cloth/ni-xie.c");
			}
			else
			{
				cloth = new("/clone/cloth/seng-cloth.c");
				shoe = new("/clone/cloth/seng-xie.c");
			}
		}
		else
		{
			if (user->query("class")=="taoist")
			{
				if ( user->query("gender")=="Ů��")
				{
					cloth = new("/clone/cloth/daogu-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
				else
				{
					cloth = new("/clone/cloth/dao-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
			}
			else
			{
				if ( user->query("gender")=="Ů��")
				{
					shoe = new("/clone/cloth/female-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/clone/cloth/female1-cloth.c");
						break;
						case 2:
					cloth = new("/clone/cloth/female2-cloth.c");
						break;
						case 3:
					cloth = new("/clone/cloth/female3-cloth.c");
						break;
						case 4:
					cloth = new("/clone/cloth/female4-cloth.c");
						break;
						case 5:
					cloth = new("/clone/cloth/female5-cloth.c");
						break;
						case 6:
					cloth = new("/clone/cloth/female6-cloth.c");
						break;
						case 7:
					cloth = new("/clone/cloth/female7-cloth.c");
						break;
						default:
					cloth = new("/clone/cloth/female8-cloth.c");
					}
				}
				else
				{
					shoe = new("/clone/cloth/male-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/clone/cloth/male1-cloth.c");
						break;
						case 2:
					cloth = new("/clone/cloth/male2-cloth.c");
						break;
						case 3:
					cloth = new("/clone/cloth/male3-cloth.c");
						break;
						case 4:
					cloth = new("/clone/cloth/male4-cloth.c");
						break;
						case 5:
					cloth = new("/clone/cloth/male5-cloth.c");
						break;
						case 6:
					cloth = new("/clone/cloth/male6-cloth.c");
						break;
						case 7:
					cloth = new("/clone/cloth/male7-cloth.c");
						break;
						default:
					cloth = new("/clone/cloth/male8-cloth.c");
					}
				}
			}
		}
		cloth->move(user);
		cloth->wear();
		shoe->move(user);
		shoe->wear();
	}

	if( !silent ) {
		if (ob->query("registered") == 0) 
			cat(UNREG_MOTD);
		else 
			cat(MOTD);
		if( ob->query("new_mail") ) {
			write(GRN+"\n�����ʲ���������˵�������˼����������ţ�\n\n"+NOR);
			user->set("new_mail", 0);
		}
		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom")) )
			startroom = START_ROOM;

		if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") + "���߽���������硣\n",
			({user}));
	}
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
        write("\n���ϴι���������һ���� " + HIG +ctime(login_ob->query("last_on"))+ NOR + " �� " + HIR +login_ob->query("last_from") + NOR + " ���ӵġ�\n\n");
        if( login_ob->query("new_mail") )
        {
                write( HIY + "\n�������ţ��쿴��������ɣ�\n\n" + NOR);
                login_ob->set("new_mail", 0);
        }
        destruct(login_ob);

	CHANNEL_D->do_channel( this_object(), "sys",
//		sprintf("%s��%s���߽��롣", user->name(), query_ip_name(user)) );
		sprintf("%s(%s)��%s���߽��롣����� " + reclaim_objects() + " ��������\n", user->name(),user->query("id"), query_ip_name(user)) );
	UPDATE_D->check_user(user);
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("new_char", user);
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();
	if( !silent ) {
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
	
	if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
		write("�Բ������Ӣ�����ֱ����� 3 �� 12 ��Ӣ����ĸ��\n");
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
	if( wiz_level(this_player(1)) < wiz_level("(arch)") )
		return 0;
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
