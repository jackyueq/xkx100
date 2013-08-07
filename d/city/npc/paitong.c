// paitong.c ��ͯ

# include <ansi.h>
inherit NPC;
int pieqian(object me);
int pieshuang(object me);
int do_deal();
int do_turn();
int yesorno();
string cstr(int i);

//ȫ�̱���
int sumi,summ;
int thecash;
int m1,m2,m3,i1,i2,i3,j1,j2,j3,k1,k2,k3;

void create()
{
	set_name("��ͯ", ({ "pai tong", "paitong", "kid" }));
	set("gender", "����");
	set("long",
		"����һ���Ƴ�С�ˡ�\n"
	);
	set("age", 32);
	set("no_get", 1);
	set("immortal",1);

	set("inquiry", ([
		"��"   : "Ҫ�ľͶģ��������£�û��û�ա�\n",
		"Ѻ��" : "��Ѻ��Ѻ���ȸ�Ǯ��Ѻ����ĥ�䡣\n",
	]) );
	set("book_count",1);
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_deal","deal");
	add_action("do_turn","turn");
}

int accept_object(object who, object ob)
{
	object obj;
	object me=this_player();

	if (me->is_busy())
		return notify_fail("�㻹��æ���أ���һ��ɡ�");
	me->start_busy(5);
	if (query("book_count"))
	{
		if (ob->query("money_id"))
		{
			if (ob->query_temp("tmark/Ѻ"))
			{
				message_vision( HIG"��ͯ����ض�$N˵�����Ѿ��¹�ע��ѽ��\n"NOR,who);
				return 0;
			}
			if (ob->value()<100)
			{
				message_vision( HIR"��ͯ��мһ�˵ؿ���$N��˵����Ҫ��ע����һ�����ӣ�\n"NOR,who);
				return 0;
			}
			if (ob->value()>20000)
			{
				message_vision( HIR"��ͯҡ��ҡͷ����$N˵�������ﲻ��ӭ��עһ��������¶����ƽ�\n"NOR,who);
				return 0;
			}
			add("book_count",-1);
			thecash = ob->value();
			who->set_temp("tmark/Ѻ",1);
			sumi=summ=0;
			i1=i2=i3=m1=m2=m3=j1=j2=j3=k1=k1=k3=0;
			message_vision( HIY"��ͯߺ�ȵ���$N��ע��ɣ������ˡ�\n"NOR,who);
			i1 = 1+random(13);
			i2 = 1+random(13);
			message_vision( WHT"ׯ�ҵ�����:    ��   ��   "HIG+cstr(i1)+"\n"NOR,who);
			if (i1>10) j1=10; else j1=i1;
			if (i2>10) j2=10; else j2=i2;
			sumi = j1 + j2;

			m1 = 1+random(13);
			m2 = 1+random(13);
			message_vision( WHT"\n�������:    "HIR+cstr(m1)+WHT"   ��   "HIR+cstr(m2)+"\n"NOR,who);
			if (m1>10) k1=10; else k1=m1;
			if (m2>10) k2=10; else k2=m2;
			summ = k1+k2;
			if ((summ == 21) || ((summ==11) && (m1==1 || m2==1)) )
			{
				message_vision(HIG"����BLACKJACK��������������������˫�������ޣ�\n"NOR,who);
				remove_call_out("destroying");
				call_out("destroying", 0, me, ob);
				pieshuang(who);
				set("book_count",1);
			}
			else
			{
				message("vision", HIW"�����Ҫ�ƣ������ deal,��������� turn��\n"NOR,who);
			}

			remove_call_out("destroying");
			call_out("destroying", 0, me, ob);
			return 1;
		}
	}
	else
	{
		message_vision("�Ѿ���������ͯ�Զ��ˣ�����$N�õ���һ���ˡ�\n",who);
		return 0;
	}
}

int do_deal()
{
	object me=this_player();
	int m3;

	if (!me->query_temp("tmark/Ѻ"))
	{
		message_vision( MAG"��ͯ���ͷ�������$Nһ�ѣ�ȥȥȥ��ע��û���أ�Ѻʲô�ư���\n"NOR,me);
		return 1;
	}
	m3 = 1+random(13);
	message("vision", HIM"�㻹Ҫһ�Ű����ðɣ�����������:   "HIR+cstr(m3)+"\n"NOR,me);
	if (m3>10) k3=10; else k3=m3;
	summ = summ+k3;
	if(m1==1 || m2==1 || m3==1)
		if(summ<12) summ=summ+10;

	if (summ>21)
	{
		message_vision( WHT"��ͯЦ������˵��������˼��������Ǳ��ˣ�����Ӯ�ˡ�\n"NOR,me);
	}
	else
	{
		if (summ==21)
		{
			message_vision( HIW"��ͯ������ɫ�����ǣ����㣿�����̵ģ���������˫����\n"NOR,me);
			pieshuang(me);
		}
		else
		{
			sumi = yesorno();
			if(i1==1 || i2==1 || i3==1)
			{
				if(sumi<12) sumi=sumi+10;
				if(sumi>21) sumi=sumi-10;
			}

			if (sumi>21 || sumi<summ)
			{
				if (sumi>21)
					message_vision( HIY"��ͯɥ����˵���ҵ�"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"�Ǳ��ˣ������˻������㣡\n"NOR,me);
				else
					message_vision( HIY"��ͯ����һ�Ѱ����������ϣ���"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"�����󣬸���Ǯ�������㣡\n"NOR,me);
				pieqian(me);
			}
			else
			{
				if (sumi == summ)
				{
					message("vision", HIG"��ͯ������ĵ���������˼������"HIR+cstr(i1)+cstr(i2)+cstr(i3)+HIG"��ͬ��ׯ�ҳ��ˡ�\n"NOR,me);
				}
				else
				{
					message_vision( HIG"��ͯЦ������˵���ҵ�����"HIR+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
					message_vision( HIG"��ͯ�����ź��ı��飺�����ô��������ˣ���ô����Ӯ���Ǯ�أ��ֲ�����˼��\n"NOR,me);
				}
			}
		}
	}

	me->set_temp("tmark/Ѻ",0);
	set("book_count",1);
	return 1;
}

int do_turn()
{
	object me = this_player();
	if (!me->query_temp("tmark/Ѻ"))
	{
		message_vision( HIY"��ͯ���ͷ�������$Nһ�ѣ�ȥȥȥ��ע��û���أ�Ѻʲô�ư���\n"NOR,me);
		return 1;
	}

	summ = summ+k3;
	if(m1==1 || m2==1 || m3==1)
		if(summ<12) summ=summ+10;

	sumi = yesorno();
	if(i1==1 || i2==1 || i3==1)
	{
		if(sumi<12) sumi=sumi+10;
		if(sumi>21) sumi=sumi-10;
	}

	if (sumi>21 || sumi<summ)
	{
		if (sumi>21)
			message_vision( HIY"��ͯɥ����˵���ҵ���"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"�Ǳ��ˣ��������˼��ң����㣡\n"NOR,me);
		else
			message_vision( HIY"��ͯ����һ�Ѱ����������ϣ�����"HIG+cstr(i1)+cstr(i2)+cstr(i3)+HIY"���������ˣ�\n"NOR,me);
		pieqian(me);
	}
	else
	{
		if (sumi == summ)
		{
			message_vision( HIG"��ͯ������ĵ���������˼������"HIR+cstr(i1)+cstr(i2)+cstr(i3)+HIG"��ͬ��ׯ�ҳ��ˡ��ٺٺ�...\n"NOR,me);
		}
		else
		{
			message_vision( HIG"��ͯЦ������˵���ҵ�����"HIR+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
			message_vision( HIG"��ͯ�����ź��ı��飺�����ô��������ˣ�Ӯ���Ǯ�𲻿����ˣ�\n"NOR,me);
		}
	}

	me->set_temp("tmark/Ѻ",0);
	set("book_count",1);
	return 1;
}

int pieqian(object me)
{
	object ob,ob1;

	if(thecash<10000)
	{
		ob = new("/clone/money/silver");
		ob->set_amount(thecash/100*2);
		ob->move(me);
	}
	else
	{
		ob = new("/clone/money/gold");
		ob->set_amount(thecash/10000*2);
		ob->move(me);
		if((thecash % 10000)!=0)
		{
			ob1 = new("/clone/money/silver");
			ob1->set_amount((thecash-((thecash/10000*10000)))/100*2);
			ob1->move(me);
		}
	}
	me->set_temp("tmark/Ѻ",0);
	return 1;
}

int pieshuang(object me)
{
	object ob,ob1;

	if(thecash<10000)
	{
		ob = new("/clone/money/silver");
		ob->set_amount(thecash/100*3);
		ob->move(me);
	}
	else
	{
		ob = new("/clone/money/gold");
		ob->set_amount(thecash/10000*3);
		ob->move(me);
		if((thecash % 10000)!=0)
		{
			ob1 = new("/clone/money/silver");
			ob1->set_amount((thecash-((thecash/10000)*10000))/100*3);
			ob1->move(me);
		}
	}
	me->set_temp("tmark/Ѻ",0);
	return 1;
}

int yesorno()
{
	object me=this_player();

	if (i1==1 || i2==1)
		if(sumi<12) sumi=sumi+10;

	if (sumi>17) return sumi;
	else
	{
/* �ƺ�������ʲ�̫�� by xmmy

�ǹ���Ѻ�Ʒ�(���Ƕ�21��)��һ����bug��
�ڶ�21���ʱ��ϵͳ����������ͯ���õ�������С��15���ʱ��ͼ���Ҫ�ƣ�
���ڵ���15��Ļ���
                �����������Ƶĵ���������ͯ�ĵ��������Ǽ���Ҫ�ƣ�
                �����ҵĵ�������ͯ�ĵ���С����ͯ��ֱ��̯�ơ�
����㷨��ʵ���������Ų��ԡ�
ͨ��������Է��֣��������̫���ӣ���ΪҪ����A�ȿ�����1�㣬Ҳ������11��
������������Ȳ�����A������11����������������⣬��ͨ��ʵ������֤�ģ���
�ڴ��ڵ���16���ʱ���̯������ѵ�ѡ�񡣺Ǻǣ�����ļ�������ҾͲ��������ˣ�

�����Ҫ�Ļ������ٴ���㣨��Ϊ������ֽ����ģ���
������ʵ����һЩ���ݣ�
   �ҵĻ����������ó�����ҵ���С��16��ͼ���Ҫ�ƣ����ڵ���16���̯�ɡ�
   ��������������Ѻ�Ʒ�һ��ң�������12�㵽����7�㣬һ�����׬���򵽰���gold��
   �ҹһ���¼�����ݣ�win=39655,lost=37310,
   win����Ӯ�Ĵ���(����պ�21��Ӯ˫�ݵĻ�������Ӯ���ε�)�� lost������Ĵ�����
�����Ѻ�Ƶĳ���ĳ���ͯ�ڴ��ڵ���16���ʱ���̯�ƣ������ӾͲ�������bug�ˡ�
btw:�Ǻǣ��ҵ�bugû���ñ���֪���ģ����Բ��õ��Ļ���־�վ��ʱ��cash����ɵ���
����
    �ҵ�Ǯ�����ж���ʮ��ɣ���Ϊ��ֻ�ù����Σ�׬̫����Ҳû��˼�����һ�ע���
���ҵ�Ǯ�ģ�
     ��������mudϵͳ�Ľ�Ǯ���ҡ�
     xixi,��Ϊʲô��Ҫ��bug�������أ�����Ϊ�ϴ���bug��ʱ��������ҿ����ˣ�
Ϊ�˱�����־�վ�Ļ��ң��Ҿ���ʹ�������ˡ���Ȼ���������Ǿ仰�����ǲ�Ҫ�����ġ�
        ��Ϊxkx100��һ������ң���Ϊxkx100���㹱������Ϊ����ο������û������
��̶һ��!
		if (sumi<14)

*/
		if (sumi<15)
		{
			i3 = 1+random(13);
			if (i3>10) j3=10; else j3=i3;
			return sumi+j3;
		}
		else
		{
			if(random(21)>10)
			{
				i3 = 1+random(13);
				if (i3>10) j3=10; else j3=i3;
				return sumi+j3;
			}
			else return sumi;
		}
	}
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

string cstr(int i)
{
	switch(i) {
		case 1:
			return "��";
		case 2:
			return "��";
		case 3:
			return "��";
		case 4:
			return "��";
		case 5:
			return "��";
		case 6:
			return "��";
		case 7:
			return "��";
		case 8:
			return "��";
		case 9:
			return "��";
		case 10:
			return "��";
		case 11:
			return "��";
		case 12:
			return "��";
		case 13:
			return "��";
		default:
			return "";
	}
}
