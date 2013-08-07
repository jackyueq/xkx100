// bbsboard.c
// Last modified by jjgod@FYTX. 01/03/06.
/*��ǿ�������԰棺BBS_BOARD
 *���ӣ��ظ����ܡ������ܡ������ܡ���ֹ FLOOD ���� */

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
// ������� 100 ������
#define MAX_PLAN	100
// �������ӳ����� MAX_PLAN��ɾ��ǰ 10 ��
#define DEL_TO		10
// �Ƿ񱣴�����ԭ�������ӣ�������Ϊ0��������Ϊ 1
#define SAVE_ALL_OLD_PLAN 0
// �����Ҫ��ʾ����������ܳ��ܳ������룺
// #define DEBUG		1
// ���ı��ⳤ��
#define MAX_TITLE_LEN	30
// ����������Ҫ������
#define NEED_EXP	0
#define NEED_AGE	15
string content(mapping *notes,int num);//����note[num]�����ݺͻ�������
string replace_str(string w_name);
string makeup_space(string s,int max); 
void setup()
{
	string loc;
	seteuid(getuid());

	if( stringp(loc = query("location"))) move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_re", "re");
	add_action("do_read", "read");
	add_action("delete_post", "delete");
	add_action("delete_post", "discard");
	add_action("do_banzhu", "banzhu");
	add_action("do_wenxuan", "wenxuan");
	add_action("do_hold", "hold");
	add_action("do_mark", "mark");
	add_action("do_look", "look");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ û���κ����� ]";

	if( this_player() )
	{
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf(HIC"%s"NOR" [ "HIW"%d"NOR" �����ӣ�"HIR"%d"NOR" ƪδ�� ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ "HIW"%d"NOR" ������ ]", ::short(), sizeof(notes));
}

int do_look(string arg)
{
	mapping *notes;
	int i, t, max,size,num,last_time_read;
	string msg, myid;
	object ob = this_object();
	object me = this_player();
	if (!arg || arg != ob->query("id") )
		return 0;
	notes = ob->query("notes");
	size = ((int)sizeof(notes)-1)/20;
	if( !pointerp(notes) || !sizeof(notes) ) 
	{
		msg=ob->query("long");
		message("vision", msg, me);
		return 1;
	}
	
	msg=query("long")+(query("banzhu")?("�����ĵİ����� "HIG+query("banzhu")+NOR"��\n"):"")+
	HIW"���"NOR"����"HIY"����"NOR"��������������������������������"HIR"����"NOR"��"HIG"�ظ���"NOR"������"HIM"ʱ��"NOR"����������"NOR;
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	message("vision", msg, me);
	for(t=0; t<=size; t++)
    	{
    		num = t*20;
    		max = num + 20;
    		if( max > sizeof(notes)) max = (int)sizeof(notes);
    		i=num;
    	msg = sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s%s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], makeup_space(notes[i]["title"],29), notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    		for(i=num+1; i<max; i++)
    		{
        msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s%s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], makeup_space(notes[i]["title"],29), notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    		}
    		message("vision", msg, me);
        }
        msg = "\n������������������������������������������������������������������������������\n";
        msg += sprintf("�ð湲�� %d �����ӡ�\n", sizeof(notes));
    	message("vision", msg, me);
    	return 1;
}

void done_post(object me, mapping note, string text)
{
	mapping *notes;
	string msg="";
	int i, j;

	text = replace_str(text);
	if (me->query("signature"))
		note["msg"]= text+"\n---------------------------------\n"+me->query("signature");
	else
		note["msg"]=text;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({note });
	else
		notes += ({ note });

	set("notes", notes);
	save();
	tell_object(me, HIW"��������ɡ�\n"NOR);

	if (sizeof(query("notes"))>MAX_PLAN)
	{
// DEL_TO ��ǰ�����ӽ����浽 /data/board/�����board_id �ļ���
// ɾ��Ŀǰ board ��� DEL_TO ��ǰ������
// ���mark���±���
		i = 0;
		j = 0;
		while (i<sizeof(notes))
		{
			if (notes[i]["mark"] != "M")
			{
				msg = content(notes,i);
				write_file(LOG_DIR+"board/"+query("board_id")+".old",msg,SAVE_ALL_OLD_PLAN);
				notes=notes[0..i-1]+notes[i+1..<1];
				j++;
			}
			else i++;
			if (j == DEL_TO) break;
		}
		set("notes",notes);
		save();
		tell_object(me, HIR"����������ϣ�ɾ�� "HIW+(DEL_TO+1)+HIR" ����ǰ�����ӡ�\n"NOR);
	}
	return;
}

void done_re(object me, mapping report, int project, string text)
{
	mapping *notes, *reports;
// ֧��ǩ������ɫ
	text = replace_str(text);
	if (me->query("signature"))
		report["msg"]= text+"\n---------------------------------\n"+me->query("signature");
	else
		report["msg"]=text;

	notes = query("notes");
	reports = notes[project]["re"];
	if( !arrayp(reports) )	reports = ({ report });
	else reports += ({ report });

	notes[project]["re"] = reports;
	notes[project]["time"] = time();

	set("notes", notes);
	tell_object(me, HIW"�ظ���ϡ�\n"NOR);

	save();
	return;
}

int do_post(string arg)
{
	mapping note;
	object me=this_player();
	string holded;

	if(!arg) return notify_fail("��������ָ��һ�����⡣\n");
	if (!query("hold")) holded = "0"; else holded = query("hold");
	if (strsrch(holded,"*"+me->query("id")+"*") >= 0 && !wizardp(me))
		return notify_fail("���ڱ����Ȩ���Ѿ������ˡ�\n");
	arg = replace_str(arg);
	if (strlen(arg)>MAX_TITLE_LEN && !wizardp(me))
		return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");

	if (query("avoid_flood") && me->query("combat_exp")<NEED_EXP &&
		me->query("age")<NEED_AGE)
		return notify_fail("����ʱ��û��Ȩ�������﷢�����£���Ҫ "WHT +NEED_EXP+NOR" �㾭��ֵ���� "WHT+NEED_AGE+NOR" ������䡣\n");

	note = allocate_mapping(5);
	note["title"] = arg;
	note["owner"] = me->query("id");
	note["author"] = me->name(1);
	note["time"] = time();
	me->edit( (: done_post,me, note :) );
	return 1;
}

int do_re(string arg)
{
	int num;
	string title, holded;
	mapping note, *notes;
	object me=this_player();

	if(!arg || sscanf(arg, "%d.%s", num, title)<1)
		return notify_fail("ָ���ʽ��re <���ӱ��>.<�ظ�����>\n");
	if (!query("hold")) holded = "0"; else holded = query("hold");
	if (strsrch(holded,"*"+me->query("id")+"*") >= 0 && !wizardp(me))
		return notify_fail("���ڱ����Ȩ���Ѿ������ˡ�\n");

	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û��������ӡ�\n");

	if (strlen(title)>MAX_TITLE_LEN)
		return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");

	if (query("avoid_flood") && me->query("combat_exp")<NEED_EXP &&
		me->query("age")<NEED_AGE)
		return notify_fail("����ʱ��û��Ȩ�������﷢�����£���Ҫ "WHT
			+NEED_EXP+NOR" �㾭��ֵ���� "WHT+NEED_AGE+NOR" ������䡣\n");

	if (!title) title="Re: "+notes[num-1]["title"];

	note = allocate_mapping(5);
	note["title"] = title;
	note["owner"] = me->query("id");
	note["author"] = me->name(1);
	note["time"] = time();
	me->edit( (: done_re, me, note, num-1 :) );
	return 1;
}

int do_read(string arg)
{
	int num, rep, last_read_time,i,last;
	mapping *notes;
	string myid,msg,file;
	object me=this_player();

	last_read_time = me->query("board_last_read/" + query("board_id"));
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("������Ŀǰû���κ����ӡ�\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <���ӱ��>[.<�ظ����>]|new|next|old\n");

// ��ʾ��ǰ���ݵľ�����
	if (arg=="old")
	{
		file=LOG_DIR+"board/"+query("board_id")+".old";
		if (file_size(file)<=0) return notify_fail("�Բ���Ŀǰ����û�б���ľ�����\n");
		else
		{
			msg=read_file(file);
			me->start_more(msg);
			return 1;
		}
	}
// ��ʾδ��������
	if( arg=="new" || arg=="next" )
	{
		if( !intp(last_read_time) || undefinedp(last_read_time) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"]>last_read_time) break;
	} else if( sscanf(arg, "%d.%d", num, rep)==2 )
		{
			if( num < 1 || num > sizeof(notes) )
				return notify_fail("û��������ӡ�\n");
			else num--;
			if( rep < 1 || rep > sizeof(notes[num]["re"]) )
				return notify_fail("û������ظ���\n");
			else rep --;
			me->start_more( sprintf(
		"[ "HIW"��ţ�"NOR"%2d | "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"ԭ�⣺"NOR"%-27s%s ] \n"
		"[ "HIW"�ظ����⣺"NOR"%-50s%s ]\n����������������������������������������������������������������\n"
		"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
		HIW"���ߣ�"NOR" %19s]\n",
			num + 1, rep + 1,
			notes[num]["title"],
			makeup_space(notes[num]["title"],27),
			notes[num]["re"][rep]["title"],
			makeup_space(notes[num]["re"][rep]["title"],50),
			notes[num]["re"][rep]["msg"],
			ctime(notes[num]["re"][rep]["time"]),
			notes[num]["re"][rep]["author"]+"("+
			notes[num]["re"][rep]["owner"]+")"));

		if( notes[num]["time"] > last_read_time )
			me->set("board_last_read/" + query("board_id"),
				notes[num]["time"]);

		return 1;
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ���ڼ������ӵĻظ���\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("û��������ӡ�\n");
	num--;
	msg=sprintf(
	"[ "HIW"��ţ�"NOR"%2d ] [ "HIW"���ߣ�"NOR"%20s ] [ "HIW"ʱ�䣺"NOR"%-9s ]\n[ "
	HIW"���⣺"NOR"%-54s%s ]\n����������������������������������������������������������������\n%s\n"
	"����������������������������������������������������["HIW" �� ƪ �� "NOR"]\n",
		num + 1,
		notes[num]["author"]+"("+notes[num]["owner"]+")",
		ctime(notes[num]["time"])[0..9],
		notes[num]["title"],
		makeup_space(notes[num]["title"],54),
		notes[num]["msg"],);
// ��ʾ�ظ�����Ŀ
	if (sizeof(notes[num]["re"])&&me->query("env/show_reply")!="all") msg+=sprintf(HIW"�ظ���"NOR"%d �ݡ�\n",sizeof(notes[num]["re"]));
// ��ʾ����һ���ظ�
	if (me->query("env/show_reply")=="last")
	{
		last=sizeof(notes[num]["re"])-1;
		msg+=sprintf(
			"\n[ "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"�ظ����⣺"NOR"%-34s%s ] \n"
			"����������������������������������������������������������������\n"
			"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
			HIW"���ߣ�"NOR" %19s]\n",
			last+1,
			notes[num]["re"][last]["title"],
			makeup_space(notes[num]["re"][last]["title"],34),
			notes[num]["re"][last]["msg"],
			ctime(notes[num]["re"][last]["time"]),
			notes[num]["re"][last]["author"]+"("+
			notes[num]["re"][last]["owner"]+")");
	}
// ��ʾ���еĻظ�
	if (me->query("env/show_reply")=="all")
	{
		for (i=0;i<sizeof(notes[num]["re"]);i++)
		{
			msg+=sprintf(
		"\n[ "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"�ظ����⣺"NOR"%-34s%s ] \n"
		"����������������������������������������������������������������\n"
		"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
		HIW"���ߣ�"NOR" %19s]\n",
			i+1,
			notes[num]["re"][i]["title"],
			makeup_space(notes[num]["re"][i]["title"],34),
			notes[num]["re"][i]["msg"],
			ctime(notes[num]["re"][i]["time"]),
			notes[num]["re"][i]["author"]+"("+
			notes[num]["re"][i]["owner"]+")");
		}
	}
	me->start_more(msg);

	if( notes[num]["time"] > last_read_time )
		me->set("board_last_read/" + query("board_id"),
			notes[num]["time"]);

	return 1;
}

int do_banzhu(string arg)
{ 
	string oper;
	if (!arg) return notify_fail("ָ���ʽ�� banzhu +|- <����id>\n");
	if (sscanf(arg, "%s %s", oper, arg) != 2 || oper!="+" && oper!="-")
		return notify_fail("ָ���ʽ�� banzhu +|- <����id>\n");
//	if (SECURITY_D->get_status(this_player(1)) != "(admin)")
	if (!wizardp(this_player(1)) )
		return notify_fail("�㲻����ʦ������������������\n");
	if (!stringp(arg)||strlen(arg)<3) return notify_fail("û������ˡ�\n");
	if (oper == "+")
	{
		if (query("banzhu")==arg)
			return notify_fail("Ŀǰ�İ������� "+arg+"������Ҫ������\n");
		set("banzhu",arg);
		save();
		write("���� "HIY+arg+NOR" Ϊ"+name()+"�����ɹ���\n");
	}
	else
	{
		if (!query("banzhu"))
			return notify_fail("Ŀǰû�а���������Ҫ������\n");
		if (query("banzhu")!=arg)
			return notify_fail("Ŀǰ�İ������� "+arg+"�����ܳ�����\n");
		delete("banzhu");
		save();
		write("���� "HIY+arg+NOR" "+name()+"����ְλ�ɹ���\n");
	}
	return 1;
}

int do_hold(string arg)
{
	string oper, holded;
	if (!arg) return notify_fail("ָ���ʽ�� hold +|- <id>\n");
	if (sscanf(arg, "%s %s", oper, arg) != 2 || oper!="+" && oper!="-")
		return notify_fail("ָ���ʽ�� hold +|- <id>\n");
	if (!stringp(arg)||strlen(arg)<3) return notify_fail("û������ˡ�\n");
	if ((string)this_player(1)->query("id") &&
		query("banzhu")!=this_player(1)->query("id") &&
		(string)SECURITY_D->get_status(this_player(1)) != "(admin)")
		return notify_fail("�㲻�ǰ����������Է����Ȩ�ޡ�\n");
	if (!query("hold")) holded = "0"; else holded = query("hold");
	if (oper == "+")
	{
		if (strsrch(holded, "*"+arg+"*") >= 0)
			return notify_fail(arg+"�Ѿ����⣬����Ҫ�ٷѾ��ˡ�\n");
		set("hold", query("hold")+"*"+arg+"*");
		save();
		write("��ɱ "HIY+arg+NOR" Ȩ�޳ɹ���\n");
	}
	else
	{
		if (holded == "0")
			return notify_fail("Ŀǰû����ˣ�����Ҫ��⡣\n");
		if (!strsrch(holded, "*"+arg+"*") >= 0)
			return notify_fail(arg+"û����Ȩ�ޣ�����Ҫ��⡣\n");
                holded = replace_string(holded, "*"+arg+"*", "");
		set("hold", holded);
		save();
		write("��� "HIY+arg+NOR" Ȩ�޳ɹ���\n");
	}
	return 1;
}
int delete_post(string arg)
{
	mapping *notes;
	int num,re_num;

	if(!arg ||sscanf(arg, "%d.%d",num,re_num)<1)
		return notify_fail("ָ���ʽ��delete <���ӱ��>[.<�ظ����>]\n");
	notes = query("notes");
	if( !arrayp(notes)|| num <1 || num > sizeof(notes))
		return notify_fail("û���������ӡ�\n");
	if( notes[num-1]["mark"] == "M")
	{
		return notify_fail("��������Ϊ������������ȥ��������־��\n");
	}
	else if(re_num)
		{
			if (re_num<1 ||
				!arrayp(notes[num-1]["re"])||re_num>sizeof(notes[num-1]["re"]))
				return notify_fail("û�����Żظ���\n");
			else
			{
				num--;
				re_num--;
				if( notes[num]["re"][re_num]["owner"] != (string)this_player(1)->query("id") && query("banzhu")!=this_player(1)->query("id") &&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)")
					return notify_fail("����ظ�������д�ģ����ֲ��ǰ�����\n");
				else
				{
					notes[num]["re"]=notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
					set("notes", notes);
					save();
					write("ɾ���� " + (num+1) + " �����ӵĵ� "+ (re_num+1)+" �Żظ�....Ok��\n");
					return 1;
				}
			}
		}
		else
		{
			num--;
			if( notes[num]["owner"] != (string)this_player(1)->query("id") &&
				query("banzhu")!=this_player(1)->query("id") &&
				(string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
				return notify_fail("������Ӳ�����д�ģ����ֲ��ǰ�����\n");
			notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
			set("notes", notes);
			save();
			write("ɾ���� " + (num+1) + " ������....Ok��\n");
			return 1;
		}
}
int do_mark(string arg)
{
	mapping *notes;
	int num;

	if(!arg ||sscanf(arg, "%d",num)<1)
		return notify_fail("ָ���ʽ��mark <���ӱ��>\n");
	notes = query("notes");
	if( !arrayp(notes)|| num <1 || num > sizeof(notes))
		return notify_fail("û���������ӡ�\n");

	num--;
	if(query("banzhu")!=this_player(1)->query("id") &&
		(string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		return notify_fail("�㲻�ǰ������޷��������¡�\n");
	if( notes[num]["mark"] == "M")
	{
		notes[num]["mark"] = " ";
		write("ȥ���� " + (num+1) + " �����ӵı�����־�ɹ���\n");
	}
	else
	{
		notes[num]["mark"] = "M";
		write("������ " + (num+1) + " �����ӳɹ���\n");
	}
	save();
	return 1;
}

int do_wenxuan(string arg)
{
	object me=this_player();
	int num,i;
	mapping *notes= query("notes");
	string msg,file_name;

// ֮���� return 0 ���� return notify_fail... ����Ϊ�� wenxuan ���ָ��
	if (!arg) return 0;
	if (sscanf(arg,"add %d",num)!=1) return 0;

	if (num>sizeof(query("notes"))||!arrayp(notes)|| num <1) return 0;
	if (!wizardp(me)&&query("banzhu")!=getuid(me)) return 0;

	else
	{
		num--;
		msg=sprintf(
		"%s \n\t   ������ "HIW"%s(%s)"NOR" �� "HIW"%-10s"NOR" ������ "HIW"%s"NOR" \n"
		"����������������������������������������������������������������\n%s\n"
		"����������������������������������������������������["HIW" �� ƪ �� "NOR"]",
		notes[num]["title"],
		notes[num]["author"],notes[num]["owner"],
		ctime(notes[num]["time"])[0..9],
		name(),
		notes[num]["msg"],);

		if (sizeof(notes[num]["re"]))
		{
			for (i=0;i<sizeof(notes[num]["re"]);i++)
			{
				msg+=sprintf(
				"\n\n���Ļظ�["HIW"%2d"NOR"]��"NOR"%-34s%s\n\t   ������ "HIW"%s(%s)"NOR" ������ "HIW"%-10s"NOR"\n"
				"����������������������������������������������������������������\n"
				"%s\n����������������������������������������������������������������\n",
				i+1,
				notes[num]["re"][i]["title"],
				makeup_space(notes[num]["re"][i]["title"],34),
				notes[num]["re"][i]["author"],
				notes[num]["re"][i]["owner"],
				ctime(notes[num]["re"][i]["time"]),
				notes[num]["re"][i]["msg"],);
			}
		}

		file_name=DATA_DIR+"wenxuan/"+localtime(time())[5]+"/"+(sizeof(get_dir(DATA_DIR+"wenxuan/"+localtime(time())[5]+"/"))+1)+".w";

		write("����д��"+file_name+"����");
		write_file(file_name,msg,);
		write("�ɹ���\n");
		return 1;
	}
}
string content(mapping *notes,int num)
{
	string msg;
	int i;

	//ԭ������
	msg=sprintf(
	"[ "HIW"��ţ�"NOR"%2d ] [ "HIW"���ߣ�"NOR"%20s ] [ "HIW"ʱ�䣺"NOR"%-9s ]\n[ "
	HIW"���⣺"NOR"%-54s%s ]\n����������������������������������������������������������������\n%s\n"
	"����������������������������������������������������["HIW" �� ƪ �� "NOR"]\n",
		num + 1,
		notes[num]["author"]+"("+notes[num]["owner"]+")",
		ctime(notes[num]["time"])[0..9],
		notes[num]["title"],
		makeup_space(notes[num]["title"],34),
		notes[num]["msg"],);
// ��ʾ�ظ�����Ŀ
	if (sizeof(notes[num]["re"])) msg+=sprintf(HIW"�ظ���"NOR"%d �ݡ�\n",sizeof(notes[num]["re"]));

// �ظ�����
		for (i=0;i<sizeof(notes[num]["re"]);i++)
		{
			msg+=sprintf(
		"\n[ "HIW"�ظ���ţ�"NOR"%2d] [ "HIW"�ظ����⣺"NOR"%-34s%s ] \n"
		"����������������������������������������������������������������\n"
		"%s\n����������������������������������������������������������������\n[ "HIW"ʱ�䣺"NOR"%s ] [ "
		HIW"���ߣ�"NOR" %19s]\n",
			i+1,
			notes[num]["re"][i]["title"],
			makeup_space(notes[num]["re"][i]["title"],34),
			notes[num]["re"][i]["msg"],
			ctime(notes[num]["re"][i]["time"]),
			notes[num]["re"][i]["author"]+"("+
			notes[num]["re"][i]["owner"]+")");
		}
	return msg;
}
string replace_str(string w_name)
{
	w_name = replace_string(w_name, "$BLK$", BLK);
	w_name = replace_string(w_name, "$RED$", RED);
	w_name = replace_string(w_name, "$GRN$", GRN);
	w_name = replace_string(w_name, "$YEL$", YEL);
	w_name = replace_string(w_name, "$BLU$", BLU);
	w_name = replace_string(w_name, "$MAG$", MAG);
	w_name = replace_string(w_name, "$CYN$", CYN);
	w_name = replace_string(w_name, "$WHT$", WHT);
	w_name = replace_string(w_name, "$HIR$", HIR);
	w_name = replace_string(w_name, "$HIG$", HIG);
	w_name = replace_string(w_name, "$HIY$", HIY);
	w_name = replace_string(w_name, "$HIB$", HIB);
	w_name = replace_string(w_name, "$HIM$", HIM);
	w_name = replace_string(w_name, "$HIC$", HIC);
	w_name = replace_string(w_name, "$HIW$", HIW);
	w_name = replace_string(w_name, "$NOR$", NOR);
	w_name += NOR;
	return w_name;
}
string makeup_space(string s,int max)
{
	string *ansi_char = ({
		BLK,   RED,   GRN,   YEL,   BLU,   MAG,   CYN,   WHT,
		BBLK,  BRED,  BGRN,  BYEL,  BBLU,  BMAG,  BCYN,
		       HIR,   HIG,   HIY,   HIB,   HIM,   HIC,   HIW,
		       HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
		NOR
	});

	string space = s;
	int i, space_count;

	for (i = 0; i < sizeof(ansi_char); i ++)
		space = replace_string(space, ansi_char[i], "", 0);

	space_count = sizeof(s) - sizeof(space);
	if (sizeof(s) >= max)
		space_count = max - sizeof(space);

	space = "";

	for (i = 0; i < space_count; i ++) space += " ";
	return space;
}