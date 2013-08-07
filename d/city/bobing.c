
#include <ansi.h>
//inherit ROOM;

int Maxperson=100; // �����������
int minperson=2;   // ���ٿ�ʼ����
//int allow_leave=1; // ��֪������ ȡ��
int allow_start=0;  // ���������Կ�ʼthrow
int Max1=32;//һ��ĸ���
int Max2=16;//���ٵĸ���
int Max3=8; //�Ľ��ĸ���
int Max4=4; //����ĸ���
int Max5=2; //���õĸ���
int Max6=1; //״Ԫ�ĸ���
int Realmode=0; //�Ƿ���ʦ����
object* member,leader,dutang1,dutang2,winner;
//string roomname;

int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
void do_yao(string arg);
string getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
int pass_token(int,int);
int startreal();
int stopreal();
int givegift();
int qianbing(object,int);
int quitgame(object me);
int fyao(string arg);
string display_item(int,int,int,int,int,int);
int is_chat_room() {return 1;}

void init()
{
	add_action("fsit","sit");
	add_action("fleave","leave");
	add_action("fleader","leader");
	add_action("fview","view");
	add_action("fyao","throw");
	add_action("startreal","start");
	add_action("stopreal","stop");
	add_action("quitgame","quit");
	add_action("quitgame","exit");
}

int fleader(string id)
{
	int i;
	object ob = this_player();

	if (wizardp(ob))
	{
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				if (member[i]->query("id")==id)
				{
					leader=member[i];
					tell_room(environment(leader), "�����ֵ�"+ leader->query("name")+"���ˡ�\n");
					return 1;
				}
			}
			notify_fail("����˲������ﲫ����\n");
		}
		else notify_fail("û�����ⲫ����\n");
	}
	return 0;
}

int startreal()
{
	int i;
	object* pl;
	object ob = this_player();
	object null;
	string roomname;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");
	if (wizardp(ob))
	{
		Realmode=1;
		winner=null;
		pl=users();
		message("vision", HIY + ob->query("name") + "������" + roomname + "��ʽ���ţ���Ʒ�������֣�\n"NOR, pl);
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				member[i]->set_temp("bobing/g1",0);       //����bing1����
				member[i]->set_temp("bobing/g2",0);       //����bing2����
				member[i]->set_temp("bobing/g3",0);       //����bing3����
				member[i]->set_temp("bobing/g4",0);       //����bing4����
				member[i]->set_temp("bobing/g5",0);       //����bing5����
				member[i]->set_temp("bobing/g6",0);       //����bing6����
				member[i]->set_temp("bobing/dest","");    //��󲩵��ĳƺ�
				member[i]->set_temp("bobing/maxaward",0); //��󲩵���bing*����
				member[i]->set_temp("bobing/maxscore",0); //��󲩵��ķ���
			}
		}
		Max1=32; //һ��ĸ���
		Max2=16; //���ٵĸ���
		Max3=8;  //�Ľ��ĸ���
		Max4=4;  //����ĸ���
		Max5=2;  //���õĸ���
		Max6=1;  //״Ԫ�ĸ���
		return 1;
	}
	return 0;
}

int stopreal()
{
	int i;
	object* pl;
	object ob = this_player();
	string roomname;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");

	if (wizardp(ob))
	{
		pl=users();
		if (Realmode==1)
		{
			message("vision", HIY + ob->query("name") + "������" + roomname + "�ҽ��ѽ������´�Ŭ���ˣ�\n"NOR, pl);
			givegift();  //�ֱ�
			Realmode=0;
			if (arrayp(member))
			{
				for (i=0;i<sizeof(member);i++)
				{
					member[i]->set_temp("bobing/g1",0);
					member[i]->set_temp("bobing/g2",0);
					member[i]->set_temp("bobing/g3",0);
					member[i]->set_temp("bobing/g4",0);
					member[i]->set_temp("bobing/g5",0);
					member[i]->set_temp("bobing/g6",0);
					member[i]->set_temp("bobing/dest","");
					member[i]->set_temp("bobing/maxaward",0);
					member[i]->set_temp("bobing/maxscore",0);
				}
			}
		}
		return 1;
	}
	return 0;
}

int givegift()
{
	object ob;
	int i, j, num;

	if (!arrayp(member)||sizeof(member)==0)
		notify_fail("û�����ⲫ�����ͱ������\n");
	else
	{
		for (i=0;i<sizeof(member);i++)
		{
			num=member[i]->query_temp("bobing/g1");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing1");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g2");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing2");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g3");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing3");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g4");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing4");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g5");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing5");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g6");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing6");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
//			member[i]->set("marks/bobing",1);
		}
		return 1;
	}
}

int pass_token(int index,int passmode)
{
	int i,passok;
	passok=0;
	if (passmode==0)
	{
		for (i=0;i<sizeof(member)-1;i++)
		{
			if (index>=sizeof(member)) index=index-sizeof(member);
			if (member[index]->query_temp("bobing_skip"))
			{
				member[index]->delete_temp("bobing_skip");
			}
			else if (interactive(member[index]) && environment(member[index])==this_object())
			{
				  passok=1;
				  leader=member[index];
				  break;
			}
			else
				delete_member(member[index]);
		}
//		if ((!passok)||(sizeof(member)<minperson))
		if ( sizeof(member)<minperson )
		{
			allow_start=0;
			tell_room(environment(leader), "��������˻��������������˰ɡ�\n");
		}
		else if (!passok)
			fyao(" "); //�����������������������
		else tell_room(environment(leader), "�����ֵ�" + leader->query("name") + "���ˡ�\n");
		remove_call_out("check_throw");
		if (sizeof(member)>=2)
		call_out("check_throw",30,leader);
	}
}
void check_throw(object who)
{
	if (!objectp(who)) message_vision(HIC"������ʱ�뿪�ˣ�����һ����ʼ�ɡ�\n"NOR);
	else if (!interactive(who) || environment(who)!=this_object())
		message_vision(HIC"$N��ʱ�뿪�ˣ��ջ����Ľ�Ʒ������һ����ʼ��������\n"NOR,who);
	else if (Max1 == 0 && Max2 == 0 && Max3 == 0 && Max4 == 0 && Max5 == 0 && Max6 == 0)
		return;
	else
	{
		message_vision(HIC"����$N�ٳٲ��������ӣ����һ��Ҫ���ջؽ�Ʒ����$N�뿪���ء�\n"NOR,who);
	  delete_member(who);
	}
	pass_token(query_member(who),0);
}
int fyao(string arg)
{
	int i,j,k;
	object ob = this_player();

	i=query_member(ob);
	if (allow_start )
	{
		if (i>0)
		{
			if(ob==leader)
			{
				do_yao(arg);
				pass_token(i,0);
				return 1;
			}
			else notify_fail(HIC"��û�ֵ����أ�Ϲ���¸�ɶ���أ�\n"NOR);
		}
		else notify_fail(HIC"��Ҫ�����������ܺʹ��һ�𲫱���\n"NOR);
	}
	else notify_fail(HIY"�����˻����������ŵ�ɡ�\n"NOR);
}

int fview()
{
	int i;
	object ob = this_player();

	if (!arrayp(member) || sizeof(member)==0)
		notify_fail("û�����ⲫ����\n");
	else
	{
		printf(HIY"  ���          ��߽�         "HIC"һ��  "HIB"����  "HIG"�Ľ�  "HIR"����  "HIY"����  "HIM"״Ԫ\n"NOR);
	        printf("��������������������������������������������������������������������\n");
		for (i=0;i<sizeof(member);i++)
		{
			printf("��%-14s%-12s%6d%6d%6d%6d%6d%6d  ��\n",
				member[i]->query("name"),
				member[i]->query_temp("bobing/dest"),
				member[i]->query_temp("bobing/g1"),
				member[i]->query_temp("bobing/g2"),
				member[i]->query_temp("bobing/g3"),
				member[i]->query_temp("bobing/g4"),
				member[i]->query_temp("bobing/g5"),
				member[i]->query_temp("bobing/g6"),);
		}
		printf("��������������������������������������������������������������������\n");
		printf("Ŀǰ����һ���%i�顢���ٱ�%i�顢�Ľ���%i�顢�����%i�顢���ñ�%i�顣\n", Max1, Max2, Max3, Max4, Max5);
		if (objectp(winner))
			printf("���ڵ�״Ԫ��%s���֡�\n",winner->query("name"));
		if (objectp(leader))
			printf("���ڸ��ֵ�%s���ˡ�\n",leader->query("name"));
		return 1;
	}
}

int fleave(string id)
{
	int i, num;
	object nil, ob = this_player();

	if (wizardp(ob))
	{
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				if (member[i]->query("id")==id) ob=member[i];
			}
			if (i==sizeof(member))
				notify_fail("����˲������ﲫ����\n");
		}
		else notify_fail("û�����ⲫ����\n");
	}
	num=query_member(ob);
	if (num)
	{
		if (leader==ob)
		{
			if (num==sizeof(member)) num=1;
			else num++;
			leader=member[num-1];
		}
	}
	else return 1;
	if (sizeof(member)>minperson)
		message_vision(HIG"$N�뿪�˴������һ������ˣ�\n"NOR,ob);
	else message_vision(HIG"$N�뿪�˴���治���ˣ�\n"NOR,ob);
	Maxperson++;
	delete_member(ob);
	return 1;
}

int fsit()
{
	object ob = this_player();

	if ((int)ob->query("combat_exp") < 100)
	{
		tell_object(ob,HIY"��Ǹ�������㾭�飬�ò�����dummy�ɣ�\n"NOR);
		return 1;
	}

	if (!(query_member(ob)))
	{
		if (Maxperson>0)
		{
			message_vision(HIC"$N�������ʹ��һ�𲫱���\n"NOR,ob);
			Maxperson--;
			add_member(ob);
			ob->set_temp("bobing/dest","");
			ob->set_temp("bobing/g1",0);
			ob->set_temp("bobing/g2",0);
			ob->set_temp("bobing/g3",0);
			ob->set_temp("bobing/g4",0);
			ob->set_temp("bobing/g5",0);
			ob->set_temp("bobing/g6",0);
			ob->set_temp("bobing/maxscore",0);
			ob->set_temp("bobing/maxaward",0);
		}
		else tell_object(ob,HIY"��һ�����ˣ���ȥ�𴦿����ɡ�\n"NOR);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if (query_member(me))
		return notify_fail(HIB"��Ҫ���뿪�����������뿪���\n"NOR);
	return 1;
}

int quitgame(object me)
{
	if (query_member(me))
		return notify_fail(HIB"��Ҫ���뿪�����������˳���Ϸ��\n"NOR);
	return 1;
}

int delete_member(object ob)
{
	int i;
  object nil;
	int num;
	if (objectp(winner) && ob==winner)
	{
		winner->set_temp("bobing/g6",0);
		winner=nil;
	}
	num=query_member(ob);
	if (num)
	{
		if (leader==ob)
		{
			if (num==sizeof(member)) num=1;
			else num++;
			leader=member[num-1];
		}
	}
	else return 1;
	if (!arrayp(member)) return 0;
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			member-=({ob});
			Max1+=ob->query_temp("bobing/g1");
			Max2+=ob->query_temp("bobing/g2");
			Max3+=ob->query_temp("bobing/g3");
			Max4+=ob->query_temp("bobing/g4");
			Max5+=ob->query_temp("bobing/g5");
			Max6+=ob->query_temp("bobing/g6");
			ob->delete_temp("bobing");
			break;
		}
	}
	member -= ({0});
}

int add_member(object ob)
{
	if (!arrayp(member))
	{
		member=({ob});
		leader=ob;
	}
	else
	{
  	member -= ({0});
		member+=({ob});
		if (sizeof(member)>=minperson)
		{
			allow_start=1;
			if (!leader) leader = ob;
			tell_room(environment(leader), "̫���ˣ��˴չ��ˣ����Կ�ʼ���ˡ�\n");
			tell_room(environment(leader), leader->query("name")+"�����ɡ�\n");
			remove_call_out("check_throw");
			call_out("check_throw",30,leader);
		}
	}
	return 1;
}

int query_member(object ob)
{
	int i;

	if (!arrayp(member)) return 0;
	member -= ({0});
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			return i+1;
		}
	}
	return 0;
}

void do_yao(string arg)
{
	string *sha_msg = ({
"ץ���������ӷ���������ƴ��ҡ��Ȼ���������������д��˿��������л�����߶߶�������дʣ������飬�����顭�������������ˡ���\n",
"����һ�Ժ��ۣ����һ����״Ԫ�����е���������������һˤ��\n",
"�����ϴ��˿�����������������һ�ף�����\n",
"�����򾲵ؽ���������������һ�ף�����һ�����Ӵ�ָ����һ��С�ĵ������⡣���ˣ����ˣ�������һ�ѣ�\n",
"΢΢һЦ����������������һ��������\n",
"�������˸�Ҿ���������ӣ���������սս����������һͶ������\n",
"�����������ӣ����㾫��Ȣ�����������ڴ�һ�٣�\n",
"����һ�������е������ҵģ�\n",
"ҧ���гݣ����������������Ϻݺݵ�һ�ң�����\n",
"��ͷ�󺹣�������������Ҳ�Ҫ��ģ��и����þ͹��ˣ���\n",
"���������˸��ķ�Ҿ����Ѹ�����״Ԫ�ˣ������ˣ�����\n",
});

	int t1,s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore,msgno;
	string result,dest;
	object ob = this_player();

	getscore=0;
	dest="";

//��ʦ����
	if (wizardp(ob) && arg &&
		sscanf(arg, "%d %d %d %d %d %d", s1,s2,s3,s4,s5,s6) == 6 &&
		s1 > 0 && s1 < 7 &&
		s2 > 0 && s2 < 7 &&
		s3 > 0 && s3 < 7 &&
		s4 > 0 && s4 < 7 &&
		s5 > 0 && s5 < 7 &&
		s6 > 0 && s6 < 7)
	{
		CHANNEL_D->do_channel(ob, "sys", "������˼��������һ�Ѱɡ�\n");
	}
	else
	{
/*		t1=random(50)+1;
// �Ӵ���ø���
		if (t1==25)
		{
			s1=5; s2=2; s3=6; s4=4; s5=3; s6=1;
		}
		else
		{
*/
// ��������
			s1=random(6)+1;
			s2=random(6)+1;
			s3=random(6)+1;
			s4=random(6)+1;
			s5=random(6)+1;
			s6=random(6)+1;
//		}
	}
//������ͳ��
	c1=countit(s1,s2,s3,s4,s5,s6,1); //һ�ĸ���
	c2=countit(s1,s2,s3,s4,s5,s6,2); //���ĸ���
	c3=countit(s1,s2,s3,s4,s5,s6,3); //���ĸ���
	c4=countit(s1,s2,s3,s4,s5,s6,4); //�ĵĸ���
	c5=countit(s1,s2,s3,s4,s5,s6,5); //��ĸ���
	c6=countit(s1,s2,s3,s4,s5,s6,6); //���ĸ���

	if (c1==6||c2==6||c3==6||c4==6||c5==6||c6==6)
	{
		getaward=6;
		if (c1==6)
		{
//			dest="��  ��(һ)";
//			getscore=1201;
			dest="��  ��(һ)";
			getscore=1301;
		}
		else if (c2==6)
		{
			dest="��  ��(��)";
			getscore=1202;
		}
		else if (c3==6)
		{
			dest="��  ��(��)";
			getscore=1203;
		}
		else if (c5==6)
		{
			dest="��  ��(��)";
			getscore=1205;//1204
		}
		else if (c6==6)
		{
			dest="��  ��(��)";
			getscore=1206;//1205
		}
		else if (c4==6)
		{
			dest="��  ��(ͨ��)";
			getscore=1304;//1207
		}
	}
	else if (c4==5)
	{
		getaward=6;
		if (c1==1)
		{
			dest="����һ";
			getscore=1101;//1102
		}
		else if (c2==1)
		{
			dest="������";
			getscore=1102;//1103;
		}
		else if (c3==1)
		{
			dest="������";
			getscore=1103;//1104;
		}
		else if (c5==1)
		{
			dest="������";
			getscore=1105;
		}
		else if (c6==1)
		{
			dest="������";
			getscore=1106;
		}
	}
	else if (c6==5)
	{
		getaward=6;
		if (c1==1)
		{
			dest="����(��)��һ";
			getscore=1001;//1046;
		}
		else if (c2==1)
		{
			dest="����(��)����";
			getscore=1002;//1056;
		}
		else if (c3==1)
		{
			dest="����(��)����";
			getscore=1003;//1066;
		}
		else if (c4==1)
		{
			dest="����(��)����";
			getscore=1004;//1076;
		}
		else if (c5==1)
		{
			dest="����(��)����";
			getscore=1005;//1086;
		}
	}
	else if (c5==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="����(��)��һ";
			getscore=1001;//1045;
		}
		else if(c2==1)
		{
			dest="����(��)����";
			getscore=1002;//1055;
		}
		else if(c3==1)
		{
			dest="����(��)����";
			getscore=1003;//1065;
		}
		else if(c4==1)
		{
			dest="����(��)����";
			getscore=1004;//1075;
		}
		else if(c6==1)
		{
			dest="����(��)����";
			getscore=1006;//1096;
		}
	}
	else if(c3==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="����(��)��һ";
			getscore=1001;//1043;
		}
		else if(c2==1)
		{
			dest="����(��)����";
			getscore=1002;//1053;
		}
		else if(c4==1)
		{
			dest="����(��)����";
			getscore=1004;//1073;
		}
		else if(c5==1)
		{
			dest="����(�� )����";
			getscore=1005;//1083;
		}
		else if(c6==1)
		{
			dest="����(��)����";
			getscore=1006;//1093;
		}
	}
	else if(c2==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="����(��)��һ";
			getscore=1001;//1042;
		}
		else if(c3==1)
		{
			dest="����(��)����";
			getscore=1003;//1062;
		}
		else if(c4==1)
		{
			dest="����(��)����";
			getscore=1004;//1072;
		}
		else if(c5==1)
		{
			dest="����(��)����";
			getscore=1005;//1082;
		}
		else if(c6==1)
		{
			dest="����(��)����";
			getscore=1006;//1092;
		}
	}
	else if(c1==5)
	{
		getaward=6;
		if(c2==1)
		{
			dest="����(һ)����";
			getscore=1002;//1051;
		}
		else if(c3==1)
		{
			dest="����(һ)����";
			getscore=1003;//1061;
		}
		else if(c4==1)
		{
			dest="����(һ)����";
			getscore=1004;//1071;
		}
		else if(c5==1)
		{
			dest="����(һ)����";
			getscore=1005;//1081;
		}
		else if(c6==1)
		{
			dest="����(һ)����";
			getscore=1006;//1091;
		}
	}
	else if (c4==4)
	{
		getaward=6;
		if((s1+s2+s3+s4+s5+s6-16)==2)
		{
			dest="״Ԫ���";
	//		getscore=1206;
	// ������ 1304 ������ 120 - 1205 Ӧ�ñ���Щ����
	    getscore = 1402;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==12)
		{
			dest="״Ԫ��ʮ��";
			getscore=512;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==11)
		{
			dest="״Ԫ��ʮһ";
			getscore=511;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==10)
		{
			dest="״Ԫ��ʮ";
			getscore=510;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==9)
		{
			dest="״Ԫ����";
			getscore=509;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==8)
		{
			dest="״Ԫ����";
			getscore=508;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==7)
		{
			dest="״Ԫ����";
			getscore=507;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==6)
		{
			dest="״Ԫ����";
			getscore=506;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==5)
		{
			dest="״Ԫ����";
			getscore=505;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==4)
		{
			dest="״Ԫ����";
			getscore=504;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==3)
		{
			dest="״Ԫ����";
			getscore=503;
		}
	}
	else if (c1==4||c2==4||c3==4||c5==4||c6==4)
	{
		getaward=3;
		if (c4==2)
		{
			getscore=302;
			dest="�Ľ�������";
		}
		else if(c4==1)
		{
			getscore=301;
			dest="�Ľ���һ��";
		}
		else if(c4==0)
		{
			getscore=300;
			dest="�Ľ�";
		}
	}
	else if(c4==3)
	{
		getaward=4;
		getscore=400;
		dest="����";
	}
	else if(c4==2)
	{
		getaward=2;
		getscore=200;
		if (c1==2)
		{
			dest="���ٲ��";
		}
		dest="����";
	}
	else if (c4==1)
	{
		if (c1==1&&c2==1&&c3==1&&c5==1&&c6==1)
		{
			getaward=5;
			getscore=500;
			dest="����";
		}
		else if (c1==2)
		{
			getaward=1;
			getscore=100;
			dest="һ����";
		}
		else
		{
			getaward=1;
			getscore=100;
			dest="һ��";
		}
	}
	else
	{
		getaward=0;
		getscore=0;
		dest=NOR"��������������Ȼʲô������Ү�����ǺǺǺǣ���ͬ����Ŷ";
	}
	result=display_item(s1,s2,s3,s4,s5,s6);
	msgno = random(sizeof(sha_msg));
	if (msgno != 3) result=result+"\n��Ȼ�Ǹ�"HIR+dest+NOR"�����Ͱ���\n";
	else 
	 {
	 	result=result+"\n�����ˣ��ñ�������\n";
	 	ob->set_temp("bobing_skip",1);//��һ���ֿ�
	 }
	message_vision(HIC"$N"+sha_msg[msgno]+NOR+result,ob);
	if (msgno != 3) getit(ob,getaward,getscore,dest);
}

string checkcolor(int i)
{
	if (i==1||i==4) return RED;
	else return GRN;
}

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
{
	int i;

	i=0;
	if (s1==sd) i++;
	if (s2==sd) i++;
	if (s3==sd) i++;
	if (s4==sd) i++;
	if (s5==sd) i++;
	if (s6==sd) i++;
	return i;
}

string getit(object ob,int getaward,int getscore,string dest)
{
	object* play;
	string roomname;
	int i;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");
/*	if (getaward > (ob->query_temp("bobing/maxaward")))
	{
		ob->set_temp("bobing/maxaward",getaward );
		ob->set_temp("bobing/dest",dest);
	}
	if (getscore>(ob->query_temp("bobing/maxscore")))
		ob->set_temp("bobing/maxscore",getscore);*/
	if (getscore > (ob->query_temp("bobing/maxscore")))
	{
		ob->set_temp("bobing/maxaward",getaward );
		ob->set_temp("bobing/dest",dest);
  	ob->set_temp("bobing/maxscore",getscore);
	}	
	if (getaward==1)
	{
		if (Max1<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N����һ��һ�������ǿ�ϧ��û�н�Ʒ����\n"NOR, ob);
		}
		else
		{
			ob->add_temp("bobing/g1",1);
//			Max1=(Max1==0)?0:Max1-1;
       Max1 --;
			if (Realmode)
				message_vision(HIY"$N����һ��һ������һ���һ�飡\n"NOR, ob);
			else
				message_vision(CYN"$N����һ��һ�������ǿ�ϧ��ʦ���ڣ�û�н�Ʒ����\n"NOR, ob);
		}
	}
	if (getaward==2)
	{
		if (Max2<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N��������һ�������ǿ�ϧ��û�н�Ʒ����\n"NOR,ob);
		}
		else
		{
//			ob->set_temp("bobing/g2",ob->query_temp("bobing/g2")+1);
//			Max2=(Max2==0)?0:Max2-1;
      ob->add_temp("bobing/g2",1);
      Max2 -- ;
			if (Realmode)
				message_vision(HIY"$N��������һ���������ٱ�һ�飡\n"NOR,ob);
			else
				message_vision(CYN"$N��������һ�������ǿ�ϧ��ʦ���ڣ�û�н�Ʒ����\n"NOR,ob);
		}
	}
	if (getaward==3)
	{
		if (Max3<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N�����Ľ�һ�������ǿ�ϧ��û�н�Ʒ����\n"NOR,ob);
		}
		else
		{
//			ob->set_temp("bobing/g3",ob->query_temp("bobing/g3")+1);
//			Max3=(Max3==0)?0:Max3-1;
      ob->add_temp("bobing/g3",1);
      Max3 -- ;
			if (Realmode)
				message_vision(HIY"$N�����Ľ�һ�������Ľ���һ�飡\n"NOR,ob);
			else
				message_vision(CYN"$N�����Ľ�һ�������ǿ�ϧ��ʦ���ڣ�û�н�Ʒ����\n"NOR,ob);
		}
    //
    if (getscore == 302) //�Ľ�������
    getit(ob,2,0,0);	
    if (getscore == 301) //�Ľ���һ��
    getit(ob,1,0,0);
	}
	if (getaward==4)
	{
		if (Max4<=0 )
		{
			qianbing(ob,getaward);
		}
		else
		{
//			ob->set_temp("bobing/g4",ob->query_temp("bobing/g4")+1);
//			Max4=(Max4==0)?0:Max4-1;
      ob->add_temp("bobing/g4",1);
      Max4 -- ;
			if (Realmode)
				message_vision(HIY"$N��������һ�����������һ�飡\n"NOR,ob);
			else
				message_vision(CYN"$N��������һ�������ǿ�ϧ��ʦ���ڣ�û�н�Ʒ����\n"NOR,ob);
		}
	}
	if (getaward==5)
	{
		if (Max5<=0 )
		{
			qianbing(ob,getaward);
		}
		else
		{
//			ob->set_temp("bobing/g5",ob->query_temp("bobing/g5")+1);
//			Max5=(Max5==0)?0:Max5-1;
      ob->add_temp("bobing/g5",1);
      Max5 -- ;
			if (Realmode)
				message_vision(HIY"$N��������һ���������ñ�һ�飡\n"NOR,ob);
			else
				message_vision(CYN"$N��������һ�������ǿ�ϧ��ʦ���ڣ�û�н�Ʒ����\n"NOR,ob);
		}
	}
	if(getaward>=6)
	{
		if(Realmode) 
//		  Max6=(Max6==0)?0:Max6-1;
		  Max6=0;
		else
			message_vision(CYN"$N����״Ԫһ�������ǿ�ϧ��ʦ���ڣ�û�н�Ʒ����\n"NOR,ob);
		if(!objectp(winner))
		{
			winner=ob;
			ob->set_temp("bobing/g6",1);
			play=users();
			message("vision", HIY"\n\n[����������Ϣ]\n����������������������������������������������\n��ϲ�� ��ϲ��" + ob->query("name") + "������" + dest + "����Ϊ " + roomname+"��״Ԫ������\n"NOR, play);
		}
		else
		{
			if (ob!=winner &&
				getscore>winner->query_temp("bobing/maxscore"))
			{
				winner->set_temp("bobing/g6",0);
				winner=ob;
				winner->set_temp("bobing/g6",1);
				play=users();
				message("vision", HIY"\n\n[����������Ϣ]\n����������������������������������������������\n��ϲ�� ��ϲ��" + ob->query("name") + "������" + dest + "����Ϊ " + roomname+"��״Ԫ������\n"NOR, play);
			}
			else
				message_vision(CYN"$N����״Ԫһ�������ǿ�ϧ���״Ԫû�н�Ʒ����\n"NOR,ob);
		}
		if (getscore == 1004)//�������� ����һ��һ��
		getit(ob,1,0,0);
		if (getscore == 1304) //����ͨ��
		{
			if (arrayp(member))
			{
				for (i=0;i<sizeof(member);i++)
				{
					member[i]->set_temp("bobing/g1",0);
					member[i]->set_temp("bobing/g2",0);
					member[i]->set_temp("bobing/g3",0);
					member[i]->set_temp("bobing/g4",0);
					member[i]->set_temp("bobing/g5",0);
					member[i]->set_temp("bobing/g6",0);
				}
			}
			ob->set_temp("bobing/g1",32);
			ob->set_temp("bobing/g2",16);
			ob->set_temp("bobing/g3",8);
			ob->set_temp("bobing/g4",4);
			ob->set_temp("bobing/g5",2);
			ob->set_temp("bobing/g6",1);
	Max1=0;//һ��ĸ���
	Max2=0;//���ٵĸ���
	Max3=0; //�Ľ��ĸ���
	Max4=0; //����ĸ���
	Max5=0; //���õĸ���
	Max6=0; //״Ԫ�ĸ���			
		}
		if (getscore == 1402)//״Ԫ��� ����������
		{
			getit(ob,5,0,0);
			getit(ob,5,0,0);
		}
	}
}

int qianbing(object ob,int getaward)
{
	int i, flag;

	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]->query("name")==ob->query("name"))
		{
			flag=i;
			for (i=flag-1;i!=flag;i--)
			{
				if (i<0) i=sizeof(member)-1;
				switch (getaward)
				{
					case 1:
						if (member[i]->query_temp("bobing/g1"))
						{
							member[i]->add_temp("bobing/g1",-1);
							ob->add_temp("bobing/g1",1);
							message_vision(HIY "$N����һ��һ��������$nһ���һ�飡\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 2:
						if (member[i]->query_temp("bobing/g2"))
						{
							member[i]->add_temp("bobing/g2",-1);
							ob->add_temp("bobing/g2",1);
							message_vision(HIY "$N��������һ��������$n���ٱ�һ�飡\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 3:
						if (member[i]->query_temp("bobing/g3"))
						{
							member[i]->add_temp("bobing/g3",-1);
							ob->add_temp("bobing/g3",1);
							message_vision(HIY "$N�����Ľ�һ��������$n�Ľ���һ�飡\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 4:
						if (member[i]->query_temp("bobing/g4"))
						{
							member[i]->add_temp("bobing/g4",-1);
							ob->add_temp("bobing/g4",1);
							message_vision(HIY "$N��������һ��������$n�����һ�飡\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 5:
						if (member[i]->query_temp("bobing/g5"))
						{
							member[i]->add_temp("bobing/g5",-1);
							ob->add_temp("bobing/g5",1);
							message_vision(HIY "$N��������һ��������$n���ñ�һ�飡\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					default:
						message_vision(HIY "$N����һ��û���õı���\n"NOR,ob);
						break;
				}
			}
			message_vision(HIY"$N������һ�����õı���\n"NOR,ob);
			return 0;
		}
	}
	message_vision(HIY"$N��Ȼ�Ҳ����Լ���λ��\n"NOR,ob);
	return 0;
}

string display_item(int i1, int i2, int i3, int i4, int i5, int i6)
{
	string str;
	str = "���������� ���������� ���������� ���������� ���������� ����������\n";
	switch (i1)
	{
		case 1:
		case 2:
			str = str+"����������";
			break;
		case 3:
			str = str+"��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+"��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+"��"GRN"�񡡡�"NOR"��";
			break;
	}
	switch (i2)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
	}
	switch (i3)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
	}
	switch (i4)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
	}
	switch (i5)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
	}
	switch (i6)
	{
		case 1:
		case 2:
			str = str+" ����������\n";
			break;
		case 3:
			str = str+" ��"GRN"�񡡡�"NOR"��\n";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��\n";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��\n";
			break;
	}
/* ��һ��. ����! */
	switch (i1)
	{
		case 1:
			str = str+"��"HIR"����"NOR"��";
			break;
		case 3:
		case 5:
			str = str+"��"GRN"����"NOR"��";
			break;
		case 2:
		case 6:
			str = str+"��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+"����������";
			break;
	}
	switch (i2)
	{
		case 1:
			str = str+" ��"HIR"����"NOR"��";
			break;
		case 3:
		case 5:
			str = str+" ��"GRN"����"NOR"��";
			break;
		case 2:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ����������";
			break;
	}
	switch (i3)
	{
		case 1:
			str = str+" ��"HIR"����"NOR"��";
			break;
		case 3:
		case 5:
			str = str+" ��"GRN"����"NOR"��";
			break;
		case 2:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ����������";
			break;
	}
	switch (i4)
	{
		case 1:
			str = str+" ��"HIR"����"NOR"��";
			break;
		case 3:
		case 5:
			str = str+" ��"GRN"����"NOR"��";
			break;
		case 2:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ����������";
			break;
	}
	switch (i5)
	{
		case 1:
			str = str+" ��"HIR"����"NOR"��";
			break;
		case 3:
		case 5:
			str = str+" ��"GRN"����"NOR"��";
			break;
		case 2:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��";
			break;
		case 4:
			str = str+" ����������";
			break;
	}
	switch (i6)
	{
		case 1:
			str = str+" ��"HIR"����"NOR"��\n";
			break;
		case 3:
		case 5:
			str = str+" ��"GRN"����"NOR"��\n";
			break;
		case 2:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��\n";
			break;
		case 4:
			str = str+" ����������\n";
			break;
	}
/* �ڶ���. ��������! */
	switch (i1)
	{
		case 1:
		case 2:
			str = str+"����������";
			break;
		case 3:
			str = str+"��"GRN"������"NOR"��";
			break;
		case 4:
			str = str+"��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+"��"GRN"�񡡡�"NOR"��"NOR;
			break;
	}
	switch (i2)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"������"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��"NOR;
			break;
	}
	switch (i3)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"������"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��"NOR;
			break;
	}
	switch (i4)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"������"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��"NOR;
			break;
	}
	switch (i5)
	{
		case 1:
		case 2:
			str = str+" ����������";
			break;
		case 3:
			str = str+" ��"GRN"������"NOR"��";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��"NOR;
			break;
	}
	switch (i6)
	{
		case 1:
		case 2:
			str = str+" ����������\n";
			break;
		case 3:
			str = str+" ��"GRN"������"NOR"��\n";
			break;
		case 4:
			str = str+" ��"HIR"�񡡡�"NOR"��\n";
			break;
		case 5:
		case 6:
			str = str+" ��"GRN"�񡡡�"NOR"��\n"NOR;
			break;
	}
/* ������. ���������! */
	str = str+"���������� ���������� ���������� ���������� ���������� ����������\n";
	return str;
}
/*
���ﲩ���������

��

ÿ������ѽڣ����ź�̨��������Լ���������̨��ʿ�ľ�ס�أ���ʢ��һ�֡�������״Ԫ����ϰ�ס���ϰ��Դ����ĩ�������ʱ֣�ɹ��Ĳ�������Ϊ�˻���ʿ���ǵ�˼��֮�飬����ʿ����������һ�����ã���������������ȫ�彫ʿ������ҹ���۲��������죬���Ź������ϻ��е��격���ĵ��ܡ�

һ���������У����д�С��ͬ��63���������С˳��ֱ�Ϊ��״Ԫ��1�飻���ۣ����ã���2�飻̽�������죩��4�飻��ʿ���Ľ�����8�飻���ˣ����٣���16�飬��ţ�һ�㣩��32�飻�����Ŵ��ļ����ԡ�֮������63���������Ϊ���ڹŴ������ֵ�ʹ�����еȼ�֮�ֵġ�81�ǵ�������֮����72��ǧ�����������֮����֣�ɹ������ƽ����������63��

�������淨�ǣ�һȺ��Χ��һ�������ߣ������������Ͷ�����ӣ�һ��ͬʱͶ��6�����ӣ��������ӵ�������ϣ�������Ͷ����Ӧ�ֵ�ʲô���ı���һֱ�浽���еı��������Ϊֹ��

����һ����57�����棬���±�

����
 �������
 �ñ�˵��
 
״Ԫ���
 �������ĵ㣬������һ��
 �ɵ�״Ԫ���������ã�����׷��
 
�� �� ��
 �������ĵ�
 ��׷��ȫ���ı���������Ҫ���ҳԱ���ֻ������٣�Ҫ�ɵ�������
 
�۵�����
 ������һ��
 ��״Ԫ���ɱ�׷�ɣ�Ҫ���
 
�� �� ��
 �������㣨���㡢���㡢��㣩
 ����ɴ��ƽ��
 
�� ��
 �������ĵ�
 ��״Ԫ���ɱ�׷��
 
�� ��
 ����һ�㣨���㡢���㡢��㡢���㣩
 ��״Ԫ���ɱ�׷��
 
״ Ԫ
 �������ĵ�
 ��״Ԫ���ɱ�׷��
 
�� ��
 ͬʱ����һ�����������ġ��塢����
 �ö���һ�����ɱ�׷��
 
�� ��
 �������ĵ�
 ������һ�����ɱ�׷��
 
�� ��
 ����һ�㣨���㡢���㡢��㡢���㣩
 ���Ľ�һ��������׷��
 
�� ��
 �������ĵ�
 �ö���һ��������׷��
 
һ ��
 һ�����ĵ�
 ��һ��һ��������׷��
 
��

��

��ע
 ���û�г���������������е��κ�һ�����Σ���Ͷ����ʲôҲ�ò��������Ͷ��������������������룬��Ͷ���߲���ʲôҲ�ò�������һ�ֻ�Ҫ�ֿգ�

�����ӵ�������1�������Ǻ��ĵ�ʱ���������Ե�һ��һ����

���Ľ���������2�����Ӿ�Ϊ���ĵ�ʱ���������Եö���һ����

���Ľ���������2��������ֻ��һ�����ĵ�ʱ���������Ե�һ��һ����

���һ��������Ͽ��Է��϶�������ʱ��������ߣ��������ڱ������ϲ��ߣ��㡣���������ĵ㣬�ö���һ���������ܵ�һ��������

�ڻ��ȫ���������ǰ���Ե������������𣬺�����������������԰�˳��׷��ǰ����������������һ����ͬ�����Ե��������õ����𣬺����Ķ��õ�����Ҳ���԰�˳��׷��ǰ����õ����Ķ��ñ�һ����

״Ԫ���ķ��䣬�򰴴�С���㣬���ڱ����ϲ��Ϊ�����ͬʱ�������������ӣ���ʣ�µ��Ǹ����ӵĵ�����С���㣬��������ʤ�����ͬʱ���ֶ������������ĵ㣬��ʣ�µ�2�����ӵĵ���֮�͵Ĵ�С���㣬����ʤ�����������ͬ������������ʤ��
 

������ᾭ�õķ�չ������е��±���ͱ�������Ʒ��ȡ�������磺�����ġ����ࡢ����Ħ�г���������ʲô�ģ�ֻ�ǲ��滹����û�иı䡣

��
*/