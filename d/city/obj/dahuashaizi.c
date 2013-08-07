// dahuashaizi.c

#include <ansi.h>

#define MAX_SE		6
#define MAX_TOSS	5

inherit ITEM;

int has_start;
int has_guess;
int se_num;				// ÿ�˵���������
int se_total;				// ÿ�˵���������2
int cur_point;				// ��ǰ�ĵ���
int cur_amount;				// ��ǰ������
int has_guess_one;			// �Ƿ�¹���
string cur_player;			// ��ǰ�����ID
string last_player;			// ��һ�����
string who_lost;			// �䷽
mapping player;				// ������� [id:({������...})]
mapping player_deal;			// ��ɵ����
mapping player_toss;			// ���toss����
mapping player_follow;			// ���˳��
mapping visitor;			// ��ս���� [id:({id,...})]
mapping counter = ([]);			// ������
mixed	history;			// ��ʷ string
int reset_game(int all);

mixed se_text = ({
	({"","","","",""}),
	({
		"����������",
		"��      ��",
		"��  ��  ��",
		"��      ��",
		"����������",
	}),
	({
		"����������",
	        "��  ��  ��",
	        "��      ��",
	        "��  ��  ��",
		"����������",
	}),
	({
		"����������",
		"���񡡡���",
		"�����񡡩�",
		"��������",
		"����������",
	}),
	({
		"����������",
		"���񡡡�",
		"����������",
		"���񡡡�",
		"����������",
	}),
	({
		"����������",
		"���񡡡�",
		"�����񡡩�",
		"���񡡡�",
		"����������",
	}),
	({
		"����������",
		"���񡡡�",
		"���񡡡�",
		"���񡡡�",
		"����������",
	})
});

void msg(object me,object who,string msg)
{
	if(me)
		message_vision(msg,me,who);
	else
		tell_room(environment(this_object()),msg,0);
}

object get_player(string id)
{
	object ob;
	ob= find_player(id);
	if( !ob || environment(ob) != environment(this_object()) )
		return 0;
	return ob;
}

object get_cur_player()
{
	return get_player(cur_player);
}

int is_playing(object ob)
{
	string id;
	id = ob->query("id");
	if(undefinedp(player[id]))
		return 0;
	return 1;
}

mixed get_se(int num)
{
	return se_text[num];
}

void create()
{
	set_name("����̨", ({ "dahua desk", "desk"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�Ŵ���̨����ҿ���������������ӡ�\n");
		set("value", 1);
		set("material", "wood");
	}

	se_total = 5;
	reset_game(1);
	setup();
}

string for_other_msg(object who)
{
	object ob;
	string m;

	m = "";
	if(has_guess&&last_player)
	{
		ob = get_player(last_player);
		if(ob)
		{
			m = sprintf("%s\n%s(%s)��������Ϊ��%d��%d\n",m,ob->query("name"),ob->query("id"),cur_amount,cur_point);
			if(ob!=who)
				m = m + "����㲻���ţ����Բ𴩴�("HIY"dahua "+ob->query("id")+NOR")\n";
		}
	}
	return m;
}

string for_guess_msg()
{
	string m;

	m = "";
	if( has_guess&&last_player )
		m=m+for_other_msg(0)+"����";
	m = m+"��Ĳ²���("HIY"guess ������Ŀ ���ӵ���"NOR")��\n";
	if(has_guess&&last_player)
		m = m+"ע�⣺" HIC "������Ŀ�������ӵ��������ǰһλ��Ҵ�\n"NOR;
	return m;
}

int is_visitor(object who,string which)
{
	if(!get_player(which))
		return 0;

	if(!visitor[which]||member_array(who->query("id"),visitor[which])==-1)
		return 0;
	return 1;
}

string build_se(object who)
{
	mixed *s;
	string r,t;
	int i,y,num;
	object ob;

	if(!who)
		return "";

	r = "";
	if(s = player[who->query("id")])
	{
		for(y=0;y<5;y++)
		{
			t = "";
			for(i=0;i<sizeof(s);i++)
			{
				num = s[i];
				t = t + se_text[num][y] + "��";
			}
			r = r + t + "\n";
		}
		if(has_guess&&last_player)
			r = r + for_other_msg(who);
	}
	return r;
}

void toss(object ob)
{
	int i;
	mixed* s;

	if(!ob)
		return;
	if(s = player[ob->query("id")])
	{
		for(i=0;i<sizeof(s);i++)
			s[i] = random(6)+1;
	}
	player[ob->query("id")] = sort_array(s,1);
}

int auto_order()
{
	int i;
	string* key;
	string who,start_one;

	key = keys(player);
	player_follow = ([]);
	who = "";
	for(i=0;i<sizeof(key);i++)
	{
		if(get_player(key[i]))
		{
			if(!start_one)
				start_one = key[i];
			if(who =="")
				who = key[i];
			else
			{
				player_follow[who] = key[i];
				who = key[i];
			}
		}
	}
	player_follow[who] = start_one;
	return 1;
}

int reset_game(int all)
{
	int i;
	string* idx;
	object ob;

	if(all)has_start = 0;
	has_guess = 0;
	se_num = se_total;
	cur_point = 0;
	cur_amount = 0;
	cur_player = 0;
	has_guess_one = 0;
	last_player = 0;
	if(all)who_lost = 0;
	if(all)player = ([]);
	player_deal = ([]);
	player_toss = ([]);
	player_follow = ([]);
	if(all)visitor = ([]);
	if(all)counter = ([]);
	history = 0;
	if(!all)
	{
		idx = keys(player);
		for(i=0;i<sizeof(idx);i++)
		{
			if(ob = get_player(idx[i]))
			{
				player[idx[i]] = allocate(se_num);
				toss(ob);
			}
			else
				map_delete(player,idx[i]);
		}
		auto_order();
	}
	return 1;
}

string extra_long()
{
	object who;
	string r;
	mixed *idx;
	int i;
	
	if(sizeof(player)>0)
	{
		idx = keys(player);
		r =	"******************************************\n";
		for(i=0;i<sizeof(idx);i++)
		{
			who = get_player(idx[i]);
			if(who) r = r + who->short() + "\n";
		}
		r += "******************************************\n";
	}
	return r;
}

int view_se(object who,object bsee)
{
	if(who)
	{
		if(bsee)
			tell_object(bsee,build_se(who));
		else
			tell_object(who,build_se(who));
	}
	return 1;
}

void start_game(int num)
{
	if(num>1&&num<=MAX_SE)
		se_total = num;
	reset_game(0);
	has_start = 1;
	msg(0,0,"��ʼ��Ϸ�ˡ�\n");
}

void init()
{

//	add_action("do_help","helpse");			// ����

	add_action("do_reset","reset");			// ������Ϸ
	add_action("do_start","start");			// ���¿�ʼ
	add_action("do_join","join");			// ������Ϸ

	add_action("do_toss","toss");			// ҡ����
	add_action("do_view","view");			// �鿴���
	add_action("do_finish","finish");		// ���
	add_action("do_finish","deal");			// ���

	add_action("do_dahua","dahua");			// ���ִ�
	add_action("do_guess","guess");			// �²�
	add_action("do_guess","g");				// �²�

	add_action("do_next","next");			// �ߴ�
	add_action("do_showc","showc");			// ��ʾ������
	add_action("do_visitor","visit");		// �����Թ���
	add_action("do_history","history");		// �鿴�²���ʷ
}

int do_toss(string arg)
{
	object me,v;
	string* idx;
	int i;

	me = this_player();

	if(!is_playing(me))
		return notify_fail("�㶼���氡��\n");
	if(!has_start)
		return notify_fail("��Ϸ��û�п�ʼ�ˡ�\n");
	if(has_guess)
		return notify_fail("�Ѿ���ʼ�������ˡ�\n");
	if(player_toss[me->query("id")]>=MAX_TOSS)
		return notify_fail(sprintf("���Ѿ�ҡ��%d���ˡ�\n",MAX_TOSS));

	toss(me);
	player_toss[me->query("id")]++;
	msg(me,0,"$N��������������ҡ����ҡ��\n");
	view_se(me,0);

	if(idx = visitor[me->query("id")])
	{
		for(i=0;i<sizeof(idx);i++)
		{
			v = get_player(idx[i]);
			if(v)
				view_se(me,v);
		}
	}	
	return 1;
}

int do_reset(string arg)
{
	int i;
	mixed* idx;

	if(!this_object()->id(arg))
		return 0;

	if(!is_playing(this_player()))
	{
		idx = keys(player);
		for(i=0;i<sizeof(idx);i++)
		{
			if(get_player(idx[i]))
				return notify_fail("�㶼���氡��\n");
		}
	}
		
	reset_game(1);
	msg(this_player(),0,"$N��������Ϸ��\n");
	return 1;
}

int do_start(string arg)
{
	int i;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");

	if(sizeof(player)<2)
		return notify_fail("����Ҫ�����˲����档\n");

	if(!arg||sscanf(arg,"%d",i)!=1)
		i = 0;
	else
	{
		if(i<1||i>MAX_SE)
			return notify_fail(sprintf("start [������Ŀ]  *ע��* ������Ŀ����>1����<=%d\n",MAX_SE));
	}
	start_game(i);
	return 1;
}

int do_view(string arg)
{
	object me;
	object ob;

	me = this_player();
	
	if(!is_playing(me))
	{
		if(arg&&(ob = get_player(arg)))
			if(!is_visitor(me,arg))
				ob = 0;

		if(!ob)
			return notify_fail("�㶼���氡��\n");
	}
	else
		ob = me;
	
	view_se(ob,me);
	return 1;
}

int do_join(string arg)
{
	object me;

	me = this_player();
	if(has_start)
		return notify_fail("��Ϸ�Ѿ���ʼ�����ܼ����ˣ���ʹ��(reset)�������á�\n");
	if(is_playing(me))
		return notify_fail("���Ѿ��μ��ˡ�\n");

	player[me->query("id")]=allocate(se_num);
	toss(me);
	msg(me,0,"$N������Ϸ�ˡ�\n");
	return 1;
}

int do_next(string arg)
{
	object ob;
	object me;
	
	me = this_player();
	if(!is_playing(me))
		return notify_fail("�㶼���氡��\n");

	if(!has_guess)
		return notify_fail("��û�п�ʼ�������ˡ�\n");
	if(!cur_player)
		return notify_fail("������˭�°���\n");

	ob = get_cur_player();
	
	if(ob==0)
	{
		msg(0,0,"�����ȱ���ˣ������¿�ʼ��Ϸ(start)��\n");
		return 1;
	}

	if(me!=ob)
		msg(me,ob,"$N��$n˵���������ˡ�\n");
	else
		msg(me,0,"���Լ�˵������������\n");
	tell_object(ob,for_guess_msg());
	return 1;
}

int do_guess(string arg)
{
	int n,p,ok;
	object ob;
	object me;
	string nextone;
	
	me = this_player();
	if(!is_playing(me))
		return notify_fail("�㶼���氡��\n");

	if(!has_guess)
		return notify_fail("��û�п�ʼ�������ˡ�\n");
	ob = get_cur_player();
	if(ob!=me)
		return notify_fail("��û�е�����ˡ�\n");

	if(!arg||sscanf(arg,"%d %d",n,p)!=2)
		return notify_fail("guess ������Ŀ ���ӵ���\n");

	if(n<sizeof(player)||p>6||p<=0)
		return notify_fail(sprintf("������Ŀ����>=%d�����ӵ�������>0����<=6\n",sizeof(player)));

	ok = 1;
	if(last_player)
	{
		if(n>cur_amount)
			ok = 1;
		else
		{
			if(n==cur_amount)
			{
				if(p>cur_point)
					ok = 1;
				else
					ok = 0;
			}
			else
				ok = 0;
		}
	}
	if(!ok)
		return notify_fail("������Ŀ�������ӵ��������ǰһλ��Ҵ�\n");

	last_player = me->query("id");
	cur_amount = n;
	cur_point = p;
	if(p==1)has_guess_one = 1;

	cur_player = player_follow[last_player];

	msg(me,0,sprintf("$N(%s)˵����%d��%d\n",me->query("id"),n,p));
	if(history)
		history = history + ({ sprintf("%-20s��%d��%d",me->query("name")+"("+me->query("id")+")",n,p) });
	else
		history = ({ sprintf("%-20s��%d��%d",me->query("name")+"("+me->query("id")+")",n,p) });

	do_next("");
	return 1;
}

void add_counter(string who,int number)
{
	counter[who] = counter[who]+number;
}

int show_all_se(object who)
{
	string* idx;
	mixed* s;
	int i,j,p,sc,pt;
	object ob;

	int c;
	string m,o;

	if(!last_player)return 0;
	ob = get_player(last_player);
	if(!ob||!who)return 0;

	has_guess = 0;
	
	idx = keys(player);
	c = 0;
	m = "";
	for(i=0;i<sizeof(idx);i++)
	{
		if(get_player(idx[i]))
		{
			s = player[idx[i]];
			m = sprintf("%s%12s��",m,idx[i]);
			o = "";
			sc = 0;
			for(j=0;j<se_num;j++)
			{
				m = sprintf("%s%d",m,s[j]);
				p = s[j];
				if(p==1&&!has_guess_one)p = cur_point;
				if(p==cur_point)
				{
					c ++;
					sc ++;
					o = sprintf("%s%d",o,s[j]);
				}
			}
			if(sc==se_num)
			{
				o = o + " Χ��+1";
				c++;
			}
			m = m + "||"+o+"\n";
		}
	}
	m = sprintf("%s%s����"HIC"%d"NOR"��%d��",m,ob->query("name"),cur_amount,cur_point);
	m = sprintf("%s������"HIC"%d"NOR"��%d\n\n",m,c,cur_point);
	msg(0,0,m);

	if(who->query("id")==cur_player)
		pt = 1;
	else
		pt = 2;

	if(c<cur_amount)
	{
		add_counter(who->query("id"), pt);
		add_counter(ob->query("id"), -pt);
		msg(ob,who,BLINK HIY "$N��$n���˴󻰣�����\n\n" NOR);
		who_lost = last_player;
	}
	else
	{
		add_counter(who->query("id"), -pt);
		add_counter(ob->query("id"), pt);
		msg(who,0,BLINK HIY "$N�жϴ����ˣ�����\n\n" NOR);
		who_lost = who->query("id");
	}
	start_game(0);
}

int do_dahua(string arg)
{
	object ob;
	object me;
	
	me = this_player();

	if(!arg)
	{
		msg(me,0,"$Nһ�������������󻰾����󻰾�...��\n");
		return 1;
	}

	if(!is_playing(me))
		return notify_fail("�㶼���氡��\n");

	if(!has_guess||!last_player)
		return notify_fail("��û�п�ʼ�������ˡ�\n");
	
	ob = get_player(last_player);
	if(ob==me)
		return notify_fail("�Լ��������Լ���\n");

	if(last_player!=arg)
		return notify_fail("���������������ˡ�\n");

	msg(me,ob,HIC "\n$N��$n˵�����Ҳ����ţ�����\n" NOR);
	show_all_se(me);
	return 1;
}

int do_finish(string arg)
{
	object me,ob;

	me = this_player();
	if(!is_playing(me))
		return notify_fail("�㶼���氡��\n");
	if(!has_start)
		return notify_fail("��Ϸ��û�п�ʼ�ˡ�\n");
	if(has_guess)
		return notify_fail("�Ѿ���ʼ�������ˡ�\n");

	player_deal[me->query("id")] = 1;
	msg(me,0,"$N׼�����ˡ�\n");
	if(sizeof(player_deal)==sizeof(player))
	{
		// all is finish
		has_guess = 1;
		msg(0,0,"\n�����ӿ�ʼ\n");
		if(who_lost)cur_player = who_lost;
		who_lost = 0;
		if(!cur_player)cur_player = me->query("id");
		if(ob = get_cur_player())
		{
			msg(ob,0,"$N˵���������Ȳ£�����\n");
			tell_object(ob,for_guess_msg());
		}
		else
			msg(0,0,"ȱ����"+cur_player+"�����ܽ�����Ϸ�������¿�ʼ(start)\n");
	}
	
	return 1;
}

int do_history(string arg)
{
	if(!history)
		tell_object(this_player(),"û����ʷ���ϡ�\n");
	else
		tell_object(this_player(),implode(history,"\n")+"\n");
	return 1;
}

int do_showc(string arg)
{
	string r;
	string* idx;
	int i;

	if(!counter) return 0; 

	idx = keys(player);
	
	r = "������(Scoreboard)\n����������������������������������\nID��������������������\n����������������������������������\n";
	for(i=0;i<sizeof(idx);i++)
	{
		if(get_player(idx[i]))
			r = sprintf("%s%-14s%10d\n", r,idx[i],counter[idx[i]]);
	}
	r += "����������������������������������\n";

	msg(0,0,r);
	return 1;
}

int do_visitor(string arg)
{
	string key;
	object me,ob;
	int del;

	if(!arg)
		return notify_fail("visit [-d] ���ID\n");

	if(sscanf(arg, "-d %s", key)==1 )
		del = 1;
	else
	{
		del = 0;
		key = arg;
	}
		
	me = this_player();
	if(is_playing(me))
	{
		ob = present(key,environment(this_object()));
		if(!ob)
			return notify_fail("����û�������Ұ���\n");

		if(del)
		{
			if(!is_visitor(ob,me->query("id")))
				return notify_fail("������Ĺ�ս�ߡ�\n");

			msg(me,ob,"$N��������$n�ۿ�$N��ս����\n");
			visitor[me->query("id")] = visitor[me->query("id")] - ({ob->query("id")});
		}
		else
		{
			if(is_visitor(ob,me->query("id")))
				return notify_fail("�Ѿ�����Ĺ�ս���ˡ�\n");

			msg(me,ob,"$N��$n�ۿ�$N��ս����\n");
			if(!visitor[me->query("id")])
				visitor[me->query("id")] = ({ ob->query("id") });
			else
				visitor[me->query("id")] += ob->query("id");
		}
	}
	else
	{
		if(del)
			return notify_fail("��������\n");

		ob = get_player(key);
		if(!ob)
			return notify_fail("û�����������氡��\n");
		msg(me,ob,"$Nϣ����Ϊ$n�Ĺ�ս�ߡ�\n");
		tell_object(ob,"����ʹ��[visit "+me->query("id")+"]��\n");
	}
	return 1;
}

int do_help(string arg)
{
	this_player()->start_more( @HELP
����ʹ�÷���:
����[��ʼ��Ϸ]������������������������������
�������helpse
�������join����������������Ϸ
��ʼ���start ����������ʼ��Ϸ
�������reset se		������Ϸ

����[��Ϸǰ����]������������������������������
��ҡ���ӣ�toss
�鿴���ӣ�view [���ID]
׼��������finish ���� deal

����[��Ϸ����]������������������������������
�𴩴󻰣�dahua ���ID
�²����ӣ�guess �������� ���ӵ���
�������������� g �������� ���ӵ���
�ߴ���ң�next

����[��������]������������������������������
����������showc
�²���־��history

����[�Թ�����]������������������������������
��ս���visit [-d] ���ID
		����������ҹۿ������Ϸ��
		�Ӳ��� -d ��ʾɾ������ҵĹۿ��ʸ�

����[��Ϸ����]������������������������������
������...

��������������������������������������������
			make by è��è(Catyboy) v1.0
HELP
	);
	return 1;
}

