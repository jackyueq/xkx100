// mailbox.c
// Last Modified by sir on 5.5.2002
// ���������������Ϊ100�� wiz���ܴ�����

#include <ansi.h>
#define MAX_MAIL 20 //�����������

inherit ITEM;
inherit F_SAVE;
mapping *mails;

void get_mail_text(mapping mail, string str);
void confirm_copy(string yn, mapping mail);

void create()
{
	set_name("����", ({ "mailbox", "box" }) );
	set("long",
		"���Ǹ������䣬���ż����ݶ���ʦ�޷����ܣ�����̸��������˽��\n\n"
		"mailto  <ĳ��>            ���Ÿ����ˡ�\n"
		"forward <�ż����> <ĳ��> ��ĳ����ת�ĸ����ˡ�\n"
		"from                      �鿴�����е��ż���\n"
		"read    <�ż����>        �Ķ�ĳһ���ż���\n"
		"discard <�ż����>        ����һ���ż���\n"
	);
	set("unit", "��");
	set("no_drop", 1);
	set("no_steal", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_get", 1);
	set("no_insert", 1);

	seteuid(getuid());
}
int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}
void init()
{
	object ob;
	int i, j = 0;

	if( this_player() && environment()==this_player() )
	{
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("mbox_ob", this_object());
		set_name(this_player()->name(1)+"������", ({"mailbox", "box"}));
		add_action("do_mail", "mailto");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
	}
	if (!present(this_object(), this_player())) return 0;
	if( !pointerp(mails) || !sizeof(mails) ) return 0;
	for(i=0; i<sizeof(mails); i++)
		if(mails[i]["read"] == "N") j++;
	if( j >0 )
		tell_object(this_player(), HIG"�����ʲ��ܲ������ݸ���"+chinese_number(j)+"���ţ�Ȼ��ת������ȥ��\n"NOR);
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;
	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(string rcvr,mapping mail)
{
	object ppl, ob, obj;

	ob = FINGER_D->acquire_login_ob(rcvr);
	ppl = find_player(rcvr);
	if (!ppl) obj = ob;
	else obj = ppl;
	if(sizeof(mails) >=MAX_MAIL && !wizardp(this_player()) && !wizardp(ppl))
	{ 
		if (obj->query("id")==this_player()->query("id"))
			write("�������Ѿ����ˣ�\n");
		else
		{
			write(HIR"�Է������Ѿ����ˡ���û���ĳ����ţ�\n"NOR);
			tell_object(obj,HIR"��������Ѿ����ˣ������Ѿ��޷����Ÿ��㣬����������ɣ�\n"NOR);
		}
		mails = mails;
		save();
	}
	else
	{
		if( !pointerp(mails) ) mails = ({ mail });
		else mails += ({ mail });
		save();
		if (obj->query("id")==this_player()->query("id"))
			write("���Ѿ��ɹ������ˣ�\n");
		else 
		{
			tell_object(obj,HIG"�����ʲ��ܲ������ݸ���һ���ţ�Ȼ��ת������ȥ��\n"NOR);
			write(HIG"���ѷ��ͳɹ���\n"NOR);
		}
	}
}

void send_mail(string rcvr, mapping mail)
{
	object ppl, ob, mbx, obj;
	int i;

	for (i = 0; i < sizeof(rcvr); i++) 
	if (rcvr[i]<'a' || rcvr[i]>'z') 
	{
		 write("û������˴��ڡ�\n");
		 return;
	}
	// Acquire the login object of receiver and mark the arrival of newmail.
	ob = FINGER_D->acquire_login_ob(rcvr);
	if( !ob ) 
	{
		write("û������˴��ڡ�\n");
		return;
	}

	// Get the mailbox or make a new one if not found.
	ppl = find_player(rcvr);
	if (!ppl) obj = ob;
	else obj = ppl;
	if (obj->query("env/no_mail"))
	{
		tell_object(this_player(), HIR"�˼Ҳ��������������\n"NOR);
		return;
	}
	else
	{
		mbx = obj->query_temp("mbox_ob");
	}
	if( !mbx )
	{
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
	}

	// Receive the mail and destruct the objects if receiver is off-line.
	mbx->receive_mail(rcvr,mail);
	if(!ppl)
	{
		destruct(mbx);
		destruct(ob);
	}
}

int do_mail(string arg)
{
	mapping mail;
	object me = this_player();

	if( me!=environment() ) return 0;
	if( !arg || arg=="" ) return notify_fail("��Ҫ��˭���ţ�\n");
	mail = ([
		"from":	me->name(1)+"("+me->query("id")+")",
		"title": "����",
		"to": arg,
		"time": time(),
		"text": "",
		"read": "N"
	]);
	write("�ż����⣺");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("�ż����ݣ�\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	mail["text"] = str;
	if( sizeof(mails)>=MAX_MAIL && !wizardp(this_player()) )
	{
		write("�������Ѿ����ˣ��뼰ʱ����\n");
		confirm_copy("nonono", mail);
	}
	else
	{
		write("��Ҫ���Լ���һ�ݱ�����(y/n)��[n]");
		input_to("confirm_copy", mail);
	}
}

void confirm_copy(string yn, mapping mail)
{
	if( ( yn[0]=='y' || yn[0]=='Y' ) )
	receive_mail(this_player()->query("id"), mail);
	send_mail(mail["to"], mail);
}

int do_from()
{
	int i;

	if (!present(this_object(), this_player())) return 0;
	if( !pointerp(mails) || !sizeof(mails) )
	{
		write("����������Ŀǰû���κ��ż���\n");
		return 1;
	}
	write("�������������ڹ��� " + sizeof(mails) + " ���ż���\n\n");
	for(i=0; i<sizeof(mails); i++)
		printf("%4s %2d %-40s "HIY"����"NOR"��%-20s\n",
			mails[i]["read"] == "N" ? HIR"δ��"NOR : HIG"����"NOR,
			i+1, mails[i]["title"], mails[i]["from"]);
	write("\n");

	return 1;
}

int do_read(string arg)
{
	int num;

	if (!present(this_object(), this_player())) return 0;
	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ����һ���ţ�\n");
	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("û�������ŵ��ż���\n");
	num --;
	printf("�ż����⣺%s\n�� �� �ˣ�%s\n����ʱ�䣺%s\n\n%s\n", mails[num]["title"], mails[num]["from"], ctime(mails[num]["time"]), mails[num]["text"] );
	mails[num]["read"]="Y";
	save();

	return 1;
}

int do_discard(string arg)
{
	int num;

	if (!present(this_object(), this_player())) return 0;
	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ������һ���ţ�\n");
	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("û�������ŵ��ż���\n");
	num --;
	if(num == 0) mails = mails[num+1..sizeof(mails)-1];
	else mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("�����ɹ���\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if (!present(this_object(), this_player())) return 0;
	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("��Ҫ����һ����ת�ĸ����ˣ�\n");
	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("û�������ŵ��ż���\n");
	num --;
	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"]+"/ת����"+this_player()->query("name");
	m["to"] = dest;
	m["read"]="N";
	send_mail( dest, m );

	return 1;
}

void owner_is_killed() { destruct(this_object()); }
