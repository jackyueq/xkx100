// seaf.c ��ս��

#include <ansi.h>

#define WIDTH	9
#define HEIGHT	9
#define SHIP_NUM	10

inherit ITEM;

int has_start;
int game_mode;		// ��ʼ������0-���� 1-���� 2-���� 3-����
int who_win;		// ʤ���� 0=û�н��� -1=����
mixed table;		// �������� table = cell[9][9]
			// cell = ({ HasShip , HasFire })
mapping player;		// ������� [id:tableNumber(1,2)]
mixed player_action;	// ��ҵĻ
mapping visitor;	// ������ҹ�ս���� [id:({id,...})]
mixed ship;		// ������ҵ�ս�� ({ mixed({hasDest,x,y,fireX,fireY,fireValue}) ,...})
mixed numbers = ({"��","��","��","��","��","��","��","��","��","��"});
mixed cell_status = ({
			// �Լ�������
			({"��","��","��"}),
			({"��","��","��"}),
			// �з�������
			({"��","��","��"}),
			({"��","��","��"})
	});		// ����״̬
mixed fire_x,fire_y;
int reset_game(int all);

void msg(object me,object who,string msg)
{
	if(me) message_vision(msg,me,who);
	else tell_room(environment(this_object()),msg,0);
}

int player_id(string key)
{
	return player[key];
}

object get_player(string id)
{
	object ob;
	ob= find_player(id);
	if( !ob || environment(ob) != environment(this_object()) )
		return 0;
	return ob;
}

string enemy_id(string key)
{
	mixed *idx;
	int i;
	idx = keys(player);
	for(i=0;i<sizeof(idx);i++)
		if(idx[i]!=key)
			return idx[i];
	return 0;
}

object get_player2(int wHIYh)
{
	mixed *idx;
	int i;

	idx = keys(player);
	for(i=0;i<sizeof(idx);i++)
		if(player[idx[i]]==wHIYh)
			return get_player(idx[i]);
	return 0;	
}

int is_visitor(object who,string which)
{
	if(!get_player(which))
		return 0;
	if(!visitor[which]||member_array(who->query("id"),visitor[which])==-1)
		return 0;
	return 1;
}

int is_playing(object ob)
{
	string id;
	id = ob->query("id");
	if(player[id])
		return 1;
	return 0;
}

mixed get_table(string id)
{
	int i;
	if(i=player[id])
		return table[i-1];
	return 0;
}

mixed get_ship(string id)
{
	int i;
	if(i=player[id])
		return ship[i-1];
	return 0;
}

int remain_ship(string who)
{
	int i,c;
	mixed *sh;
	sh = get_ship(who);
	c = 0;
	for(i=0;i<SHIP_NUM;i++)
		if(!sh[i][0])c++;
	return c;
}

int remain_place(string who)
{
	int i,c;
	mixed *sh;
	sh = get_ship(who);
	c = 0;
	for(i=0;i<SHIP_NUM;i++)
		if(!sh[i][1])c++;
	return c;
}

int remain_fire(string who)
{
	int i,c;
	mixed *sh;
	sh = get_ship(who);
	c = 0;
	for(i=0;i<SHIP_NUM;i++)
		if(!sh[i][0]&&!sh[i][3])c++;
	return c;
}

void create()
{
	set_name("��ս��", ({ "seawar board","board","sea"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ����ս�壬����ϡϡ�������һЩ������\n");
		set("value", 1);
		set("material", "wood");
	}
	reset_game(1);
	setup();
}

string player_status(string key)
{
	mixed* sh;
	int i;
	string r;

	sh = get_ship(key);

	if(!sh)
		return "???";

	r = "";
	for(i=0;i<SHIP_NUM;i++)
	{
		if(sh[i][0])
			r+= HIR"��"NOR" ";
		else
			r+= HIB"��"NOR" ";
	}
	return r;
}

string build_board(string key)
{
	mixed *mt,*et,*d;
	string r;
	int x,y,id,mid,eid;

	id = player_id(key);
	if(!id) return "";
	if(id==1)
	{
		mid = 0;
		eid = 1;
	}
	else
	{
		mid = 1;
		eid = 0;
	}
	mt = table[mid];
	et = table[eid];
	
	r = "\n";
	r += "���Ҿ���������������������о��������\n";
	r += "��������������������������������������������\n";
	for(y=0;y<HEIGHT;y++)
	{
		r = r+numbers[y+1];
		for(x=0;x<WIDTH;x++)
		{
			d = mt[x][y];
			if(game_mode==2 && x==fire_x[mid]-1 && y==fire_y[mid]-1)
				r += BLINK+HIY + cell_status[d[0]][d[1]] + NOR;
			else r += cell_status[d[0]][d[1]];
		}

		r = r+"����" + numbers[y+1];
		for(x=0;x<WIDTH;x++)
		{
			d = et[x][y];
			if(game_mode == 2 && x == fire_x[eid]-1 && y == fire_y[eid]-1)
				r += cell_status[d[0]+2][d[1]];
			else
				r += cell_status[d[0]+2][d[1]];
		}
		r+="\n";
	}
	r += "��ֻ״̬��" + player_status(key) + "\n";
	return r;
}

int reset_game(int all)
{
	int i,x,y;

	table = ({0,0});
	if(all)
	{
		player = ([]);
		visitor = ([]);
	}
	ship = ({0,0});
	player_action = ([]);

	for(i=0;i<2;i++)
	{
		table[i] = allocate(WIDTH);
		for(x=0;x<WIDTH;x++)
		{
			table[i][x] = allocate(HEIGHT);
			for(y=0;y<HEIGHT;y++)
				table[i][x][y] = ({0,0});
		}
		
		ship[i] = allocate(SHIP_NUM);
		for(x=0;x<SHIP_NUM;x++)
			ship[i][x] = ({0,0,0,0,0,0});
	}

	if(all)
		has_start = 0;
	return 1;
}

void display(int who)
{
	string b,id,m;
	int i,j;
	mixed* v;
	object ob,vtor;

	for(i=1;i<=2;i++)
	{
		if(!who||who==i)
		{
			ob = get_player2(i);
			if(ob)
			{
				id = ob->query("id");
				b = build_board(id);
				tell_object(ob,b);
				v = visitor[id];
				for(j=0;j<sizeof(v);j++)
				{
					vtor = find_player(v[j]);
					if(vtor)//&&environment(vtor) == environment(this_object()))
						tell_object(vtor,b);
				}
				
				switch(game_mode)
				{
				case 0:
					m = sprintf("���ô�ֻ��%dֻ\n",remain_place(ob->query("id")));
					m += "ʹ��["HIY"place X���� Y����"NOR"]���ô�ֻ\n";
					m += "ʹ��["HIY"unplace X���� Y����"NOR"]ȡ������\n";
					m += "ʹ��["HIY"rplace"NOR"]����ڷŴ�ֻ\n";
					break;
				case 1:
					m = sprintf("���û�����%d��\n",remain_fire(ob->query("id")));
					m += "ʹ��["HIY"fire X���� Y����"NOR"]���ù���λ��\n";
					m += "ʹ��["HIY"unfire X���� Y����"NOR"]ȡ������\n";
					break;
				case 3:
					m = "ս�������ˡ�\nս����";
					if(who_win==-1)
						m+="����";
					else if(who_win==i)
						m+=HIY"ʤ����"NOR;
					else
						m+=HBWHT BLK"ʧ����"NOR;
					break;
				}
				if(m)
					tell_object(ob,m);
			}
		}
	}
}

string extra_long()
{
	object who;
	string r,key;
	mixed *idx;
	int i;
	
	if(sizeof(player)>0)
	{
		idx = keys(player);
		r =	"******************************************\n";
		for(i=0;i<sizeof(idx);i++)
		{
			key = idx[i];
			who = get_player(key);
			if(who)
				r = r + key + "��"+player_status(key)+"\n";
		}
		r += "******************************************\n";
	}
	return r;
}

int view_board(object who,string which)
{
	string b;
	object ob;
	mixed *v;
	int i,see;

	ob = get_player(which);
	if(!ob)
		return 0;

	see = 0;
	if(ob==who)
		see = 1;

	if(!see)
		see = is_visitor(who,which);

	if(see)
	{
		b = build_board(which);
		tell_object(who,b);
		return 1;
	}
	return 0;
}

void start_game()
{
	has_start = 1;
	game_mode = 0;
	who_win = 0;

	msg(0,0,"��ʼ��Ϸ\n");
	display(0);
}

int before_fire()
{
	game_mode = 1;
	player_action = ([]);
	msg(0,0,"\n\n"HIC"����������ս��״̬������"NOR"\n\n");
	display(0);
}

int start_fire()
{
	player_action = ([]);
	msg(0,0,"\n\n"HIR"��������ʼս��״̬������"NOR"\n\n");
	game_mode = 2;
	fire_x = ({0,0});
	fire_y = ({0,0});
	remove_call_out("fire_it");
	call_out("fire_it",2);
}

void init()
{

//	add_action("do_help","helpboard");		// ����

	add_action("do_reset","reset");			// ������Ϸ
	add_action("do_start","start");			// ���¿�ʼ
	add_action("do_join","join");			// ������Ϸ

	add_action("do_view","view");			// �鿴���
	add_action("do_visitor","visit");		// �鿴���
	add_action("do_finish","finish");		// ���

	add_action("do_place","place");			// ���ô�ֻ
	add_action("do_rplace","rplace");		// ����ڷŴ�ֻ
	add_action("do_unplace","unplace");		// ȡ����ֻ

	add_action("do_fire","fire");			// ���û���
	add_action("do_unfire","unfire");		// ȡ������
}

int do_reset(string arg)
{
	mixed *idx;
	int i;

	if(!this_object()->id(arg))
		return 0;

	if(!is_playing(this_player()))
	{
		if(get_player2(1)||get_player2(2))
			return notify_fail("�㶼���氡��\n");
	}
		
	if(reset_game(1))
		msg(this_player(),0,"$N��������Ϸ��\n");
	return 1;
}

int do_start(string arg)
{
	mixed *idx;
	int i;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");

	reset_game(0);
	start_game();
	return 1;
}

int do_view(string arg)
{
	mixed *idx;
	int i;

	if(!is_playing(this_player()))
	{
		if(!arg) return notify_fail("�㶼���氡��\n");
		if(!is_visitor(this_player(),arg))
			return notify_fail("�㲻�ܹ���"+arg+"���壬����ʹ��[visit "+arg+"]�����Ϊ"+arg+"�Ĺ��ڡ�\n");
	}
	if(!arg) arg = this_player()->query("id");
	if(!view_board(this_player(),arg)) return notify_fail("������\n");
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

	player[me->query("id")]=sizeof(player)+1;
	msg(me,0,"$N������Ϸ�ˡ�\n");

	if(sizeof(player)==2)
		start_game();

	return 1;
}

int do_place(string arg)
{
	int i,x,y;
	mixed *sh,*tb;
	string id;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");
	
	if(!has_start||game_mode!=0)
		return notify_fail("���ڲ��ǲ��ô�ֻ��ʱ��\n");

	if( !arg || sscanf(arg, "%d %d", x, y)!=2 )
		return notify_fail("place X���� Y����\n");

	if(x<1||x>WIDTH)
		return notify_fail("X�������\n");
	if(y<1||y>HEIGHT)
		return notify_fail("Y�������\n");

	id = this_player()->query("id");
	sh = get_ship(id);
	tb = get_table(id);
	if(!sh||!tb)
		return notify_fail("access date fail\n");

	if(tb[x-1][y-1][0] == 1)
		return notify_fail("�ô��Ѿ������˴�ֻ\n");

	for(i=0;i<SHIP_NUM;i++)
	{
		if(!sh[i][1])
		{
			sh[i][1] = x;
			sh[i][2] = y;
			tb[x-1][y-1][0] = 1;
			break;
		}
	}

	if(i==SHIP_NUM)
		return notify_fail("���Ѿ�û�п���Ĵ�ֻ���Բ����ˡ�\n");
	else
	{
		display(player_id(id));
		if(!remain_place(id))
			tell_object(this_player(),"\nʹ��[Finish]�������ô�ֻ��\n");
	}
	return 1;
}

int do_unplace(string arg)
{
	int i,x,y;
	mixed *sh,*tb;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");
	
	if(game_mode!=0)
		return notify_fail("���ڲ��ǲ��ô�ֻ��ʱ��\n");

	if( !arg || sscanf(arg, "%d %d", x, y)!=2 )
		return notify_fail("unplace X���� Y����\n");

	if(x<1||x>WIDTH)
		return notify_fail("X�������\n");
	if(y<1||y>HEIGHT)
		return notify_fail("Y�������\n");

	sh = get_ship(this_player()->query("id"));
	tb = get_table(this_player()->query("id"));
	if(!sh||!tb)
		return notify_fail("access date fail\n");

	for(i=0;i<SHIP_NUM;i++)
	{
		if(sh[i][1]==x&&sh[i][2]==y)
		{
			sh[i][1] = 0;
			sh[i][2] = 0;
			tb[x-1][y-1][0] = 0;
			display(player_id(this_player()->query("id")));
			break;
		}
	}

	if(i==SHIP_NUM)
		return notify_fail("��λ��û�в��ô�ֻ��\n");
	return 1;
}

int do_finish(string arg)
{
	int i,x,y;
	mixed *sh;
	string id;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");
	
	if(!(game_mode==0||game_mode==1))
		return notify_fail("������\n");

	id = this_player()->query("id");
	sh = get_ship(id);
	if(!sh)
		return notify_fail("access date fail\n");

	if(game_mode==0)
	{
		if(remain_place(id))
			return notify_fail("���д�ֻû�в���\n");
	}
	else if(game_mode==1)
	{
		if(remain_fire(id))
			return notify_fail("���л���û�в���\n");
	}

	if(game_mode==0)
		msg(this_player(),0,"$N�Ĵ�ֻ�������\n");
	else if(game_mode==1)
		msg(this_player(),0,"$N�Ļ����������\n");

	player_action[this_player()->query("id")] = 1;
	if(sizeof(player_action)==2)
	{
		// all finish,go fire
		if(game_mode==0)
			before_fire();
		else if(game_mode==1)
			start_fire();
	}
	return 1;
}

int do_fire(string arg)
{
	int i,x,y;
	mixed *sh,*tb;
	string id;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");
	
	if(game_mode!=1)
		return notify_fail("���ڲ��ǲ��û�����ʱ��\n");

	if( !arg || sscanf(arg, "%d %d", x, y)!=2 )
		return notify_fail("place X���� Y����\n");

	if(x<1||x>WIDTH)
		return notify_fail("X�������\n");
	if(y<1||y>HEIGHT)
		return notify_fail("Y�������\n");

	id = this_player()->query("id");
	sh = get_ship(id);
	tb = get_table(enemy_id(id));
	if(!sh||!tb)
		return notify_fail("access date fail\n");

	if(tb[x-1][y-1][1] != 0)
		return notify_fail("�ô��Ѿ������˻���\n");

	for(i=0;i<SHIP_NUM;i++)
	{
		if(!sh[i][0]&&!sh[i][3])
		{
			sh[i][3] = x;
			sh[i][4] = y;
			sh[i][5] = tb[x-1][y-1][1];
			tb[x-1][y-1][1] = 2;
			break;
		}
	}

	if(i==SHIP_NUM)
		return notify_fail("���Ѿ�û�п���Ļ������Բ����ˡ�\n");
	else
	{
		display(player_id(id));
		if(i+1==SHIP_NUM)
			tell_object(this_player(),"\nʹ��[Finish]�������û�����\n");
	}
	return 1;
}

int do_unfire(string arg)
{
	int i,x,y;
	mixed *sh,*tb;
	string id;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");
	
	if(game_mode!=1)
		return notify_fail("���ڲ��ǲ��û�����ʱ��\n");

	if( !arg || sscanf(arg, "%d %d", x, y)!=2 )
		return notify_fail("unplace X���� Y����\n");

	if(x<1||x>WIDTH)
		return notify_fail("X�������\n");
	if(y<1||y>HEIGHT)
		return notify_fail("Y�������\n");

	id = this_player()->query("id");
	sh = get_ship(id);
	tb = get_table(enemy_id(id));
	if(!sh||!tb)
		return notify_fail("access date fail\n");

	for(i=0;i<SHIP_NUM;i++)
	{
		if(!sh[i][0]&&sh[i][3]==x&&sh[i][4]==y)
		{
			sh[i][3] = 0;
			sh[i][4] = 0;
			tb[x-1][y-1][1] = sh[i][5];
			display(player_id(id));
			break;
		}
	}

	if(i==SHIP_NUM)
		return notify_fail("��λ��û�в��û�����\n");
	return 1;
}

int which_ship(mixed* sh,int x,int y)
{
	int i;
	for(i=0;i<SHIP_NUM;i++)
	{
		if(sh[i][1]==x&&sh[i][2]==y)
			return i;
	}
	return -1;
}

int fire_it()
{
	int i,j1,j2,x,y,bFire;
	int r1,r2;
	string key1,key2;
	string m;
	mixed *sh1,*sh2;
	mixed *tb1,*tb2;
	
	key1 = keys(player)[0];
	key2 = keys(player)[1];
	sh1 = get_ship(key1);
	sh2 = get_ship(key2);
	tb1 = get_table(key1);
	tb2 = get_table(key2);

	game_mode = 2;

	m = 0;
	bFire = 0;

	fire_x = ({0,0});
	fire_y = ({0,0});

	if(sh1&&sh2)
	{
		for(i=0;i<SHIP_NUM;i++)
		{
			j1 = -1;
			j2 = -1;
			if(!sh1[i][0]&&sh1[i][3])
			{
				// fire it
				x = sh1[i][3];
				y = sh1[i][4];
				fire_x[0] = x;
				fire_y[0] = y;
				sh1[i][3] = 0;
				sh1[i][4] = 0;
				tb2[x-1][y-1][1] = 1;
				j2 = which_ship(sh2,x,y);
				bFire = 1;
			}

			if(!sh2[i][0]&&sh2[i][3])
			{
				// fire it
				x = sh2[i][3];
				y = sh2[i][4];
				fire_x[1] = x;
				fire_y[1] = y;
				sh2[i][3] = 0;
				sh2[i][4] = 0;
				tb1[x-1][y-1][1] = 1;
				j1 = which_ship(sh1,x,y);
				bFire = 1;
			}

			if(j1>=0)
			{
				m = BLINK HIY + key1 + "�Ĵ��������ˡ�\n" NOR;
				sh1[j1][0] = 1;	// be fired
				if(sh1[j1][3])
				{
					x = sh1[j1][3];
					y = sh1[j1][4];
					sh1[j1][3] = 0;
					sh1[j1][4] = 0;
					tb2[x-1][y-1][1] = sh1[j1][5];
				}
			}
			if(j2>=0)
			{
				if(!m)m="";
				m = m + BLINK HIY + key2 + "�Ĵ��������ˡ�\n" NOR;
				sh2[j2][0] = 1;	// be fired
				if(sh2[j2][3])
				{
					x = sh2[j2][3];
					y = sh2[j2][4];
					sh2[j2][3] = 0;
					sh2[j2][4] = 0;
					tb1[x-1][y-1][1] = sh2[j2][5];
				}
			}

			if(bFire)break;
		}
	}

	if(bFire)
	{
		msg(0,0,BLINK HIR"\n~~~~~ �������� ~~~~~\n"NOR);
		if(m)msg(0,0,m);
		display(0);
		remove_call_out("fire_it");
		call_out("fire_it",4);
	}
	else
	{
		// fire finish
		r1 = 0;
		r2 = 0;
		for(i=0;i<SHIP_NUM;i++)
		{
			if(!sh1[i][0])r1++;
			if(!sh2[i][0])r2++;
		}

		if(r1==0||r2==0)
		{
			game_mode = 3;
			if(r1==0)
			{
				if(r2==0)
					who_win = -1;
				else
					who_win = 1;
			}
			else
				who_win = 2;

			display(0);
			msg(0,0,HIR"\n\n ����ս�������ˣ�ʹ��(start)���¿�ʼ��\n"NOR);
		}
		else
		{
			msg(0,0,sprintf(HIC"\n�ûغϹ�������...\n%s(%d) VS %s(%d)\n"NOR,key1,remain_ship(key1),key2,remain_ship(key2)));
			before_fire();
		}
	}
}

int do_visitor(string arg)
{
	string key;
	object me,ob;
	int del;

	if(!arg)
		return notify_fail("visit [-]���ID\n");

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
				return notify_fail("������Ĺ�ս���ˡ�\n");

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

int do_rplace(string arg)
{
	int i,x,y;
	mixed *sh,*tb;

	if(!is_playing(this_player()))
		return notify_fail("�㶼���氡��\n");
	
	if(!has_start||game_mode!=0)
		return notify_fail("���ڲ��ǲ��ô�ֻ��ʱ��\n");
	
	sh = get_ship(this_player()->query("id"));
	tb = get_table(this_player()->query("id"));
	for(i=0;i<SHIP_NUM;i++)
	{
		if(!sh||!tb)
			return notify_fail("access date fail\n");

		if(!sh[i][1])
		{
			x = random(WIDTH)+1;
			y = random(HEIGHT)+1;

			if(tb[x-1][y-1][0] != 1)
			{
				sh[i][1] = x;
				sh[i][2] = y;
				tb[x-1][y-1][0] = 1;
			}
		}
	}

	display(player_id(this_player()->query("id")));
	return 1;
}

int do_help(string arg)
{
	this_player()->start_more( @HELP
��ս��ʹ�÷���:
����[��ʼ��Ϸ]������������������������������
�������helpboard
�������join����������������Ϸ
��ʼ���start ����������ʼ��Ϸ
�������reset board ��������Ϸ

����[��ֻ����]������������������������������
���ô�ֻ��place X���� Y����
ȡ�����ã�unplace X���� Y����
������ã�rplace
���ý�����finish

����[��������]������������������������������
���û�����fire X���� Y����
ȡ�����ã�unfire X���� Y����
���ý�����finish

����[��ս����]������������������������������
��ս���visit [-d] ���ID
		����������ҹۿ������Ϸ��
		�Ӳ��� -d ��ʾɾ������ҵĹۿ��ʸ�

����[��Ϸ����]������������������������������
����Ϸ��������Ϸ��
��Ϊ׼����ս���׶������׶Ρ�

��׼���׶Σ����˰��Լ��Ĵ��������Լ���
�����ϡ������˶�׼�����Ժ󣬽���ս����
�Ρ�

��ս���׶Σ����˾���������λ�á�ÿһ��
���� 1�ι������ᡣ����ɹ��������Ժ�
����ս��״̬��ϵͳ����˫���Ĺ������ý�
�й�����������λ�����ез���������԰�
�Է��ô����١������ٵĴ�ɥʧ����������

�����й��������Ժ����½��빥�����á�
���ѭ����ֱ��һ���Ĵ�ȫ�������١�

��Ϸ��ʼʱ��ÿ����10�Ҵ���
���˭�Ĵ����ȱ�ȫ���������˭Ϊ���ߡ�

��������������������������������������������
HELP
	);
	return 1;
}
