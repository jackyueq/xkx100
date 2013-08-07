// biaotou.c
inherit NPC;
#include <ansi.h>

#define lay_exp 20
#define lay_pot 5
#define price_exp 300
#define price_pot 80
#define total_appear 10
#define killer_appear 3
#define delay_appear 2
#define total_cmd 10
#define bt_cmd 3
#define A_TIME 60
#define B_TIME 1

string * random_act = ({
	"fear",
	"dazuo 40",
	"dazuo 60",
	"dazuo 100",
	"dazuo 120",
	"sigh",
	"sigh1",
	"say ��Ҫ���ڳ��˵�����ȥ��",
	"remove all",
	"remove all",
	"remove all",
	"drop all",
});

string * inroad_msg = ({
	"$NͻȻ��Ȼ�������Ŷ����ط�����ǰ�������ô����ߡ���˵�գ�ת����ߡ�\n",
	"$NͻȻ���ֵص�������ѽ���ٷ����ˣ��Ҵ�����·�����ˡ���\n",
	"$N��ֵص���$n���������㲻��ʶ·�ɣ�ȥ��������ߣ���˵���Թ����ˡ�\n",
	"$N��$n�ڰ��֣����Ǳ�����·��ƽ������������ࡣ��Ƨ���İɣ���һ��˵һ��Ťͷ���ߡ�\n",
	"$N���Ķ�$n˵�������������Ե�����С������ȥ�ã�çײ�粽���С���������$n�����ˡ�\n",
	"$N��$n˵���������̵�һʱ֮�����������֮�֡����ϴ�����Թ�����������Ǳ����ɡ���\n",
	"$N˵���������������Ե��������ɲ�ʶ�֣����ɲ�ʶ�ˡ�������Ҳ����$n���β����ߡ�\n",
	"$N˵���������������Ե��������첻���ߣ��ȵ�����ͷ����������˿����ͣ��һ·С�ܶ�ȥ��\n",
	"$N˵���������������Ե�����������ٵ��գ����ı��ƹ���ʱ����$n��������һ������\n",
	"$N˵���������������Ե�����·���մ��뵱�ܣ����ǲ���Ī��ʫ������˫��һ�Σ�����񱼡�\n",
	"$N˵���������������Ե�������Ҫ������һ����վ��Զ�������塣�������Ǳ�ȥ����������ߡ���\n",
	"$N˵���������������Ե��������˲�¶�࣬¶�಻���ˡ�������̽̽�Ǳ�·���ҵ���߶�����ߡ���\n",
	"$N��$n˵����������ȥ������ص��������ҵĶ�ľ�š����ؼ��ؼ�����\n",
	"$N������Ц����$n˵�����������������ǰ�������ֲ���Ц���ˡ������µ��Ǳ߷��㷽�㡣��\n",
});

string *xing=({"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��","��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��","³","Τ","��","��","��","��","��","��","��","��","Ԭ","��","ۺ","��","ʷ","��","��","��","�","Ѧ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","��","ƽ","��","��","��","��","��","Ҧ","��"}); 

string status_color(int current, int max);

void create()
{
	object ob;
	string name = xing[random(sizeof(xing))]+"��ͷ";
	set_name(name, ({"biao tou", "bt" }));
	set("title", HIR"��"HIC"��"YEL"�ھ�"HIY"��ͷ"NOR);
	set("gender", "����" );
	set("age", 20+random(10));
        set("max_qi",300+random(200));
        set("combat_exp", 100000);
	set("attitude", "friendly");
	set("vendetta_mark", "authority");
	set("env/wimpy",50);
	set("per",2);
	set("chat_chance", 15);
	set("chat_msg",({
		name+"�ȵ����������˵������ˡ���\n",
		name+"�ȵ��������߿��ߣ���͵������\n",
		name+"˵���������������Ե��������鲻���֣����ֲ����顣����\n",
		name+"˵���������������Ե�����ֻҪ���ֶ࣬��¥̧���ӡ�����λ����ͬ�����ڣ�����˭������\n",
		name+"˵���������������Ե������м�һ���֣���֪��û�С�����\n",
		name+"˵���������������Ե��������������飬��ƨ�����졣�����ǿɵö����񣬱������Ƴ�����������\n",
		name+"˵���������������Ե��������ȿ�Ҳ�ȣ������ò��������ص��ھ֣�������ʹʹ���Ĵ���һ������\n",
		name+"˵���������������Ե�������Եǧ������ᣬ��Ե���治��ꡣ���˴�ͬ�����ڣ������һ��ģ��һᣡ��\n",
	}) );
	set("chat_chance_combat",80);
	set("chat_msg_combat", ({
		name+"�󺰵����������ˣ����˽����ˡ���\n",
	}) );
	
	set_skill("sword",50);
	set_skill("force",40);
	set_skill("parry",50);
	set_skill("dodge",50);
	set_skill("bixie-sword",50);
	map_skill("sword","bixie-sword");
	map_skill("parry","bixie-sword");
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/cloth/cloth");
}

void init()
{
	add_action("do_baobiao","baobiao");
	add_action("do_baobiao","jiebiao");
	add_action("do_order","order");
	add_action("do_give","give");
	add_action("do_hp","hp");
	remove_call_out("do_check");
	call_out("do_check",A_TIME);
	remove_call_out("do_check1");
	call_out("do_check1",B_TIME);
}

int do_baobiao(string arg)
{
	object me = this_player();

	if (!me->query_temp("fuwei_ready"))
		return notify_fail(this_object()->query("name") +"˵����ȥȥȥ��ȥ�ʷ���Ǯȥ����\n"); 
	if ( query("leader_name") != me->query("id") )
		return notify_fail(this_object()->query("name") +"˵������û�и��𱣻����ڵ����񣡡�\n"); 
	set("gurader_name",me->query("id") );
	me->set_leader(this_object());
	tell_object(me, "�����ڿ�ʼ�ӹ��ڶ��ˣ�����(order)�������̣�������ȫ�͵�"+me->query_temp("fuwei_dest")+"�־־ͳɣ�\n");
	return 1;
}

int do_hp(string arg)
{
	object ob = this_object();
	object me = this_player();
	string msg;
	mapping my;

	if (!arg || (arg != ob->query("id") && arg != "bt") )
		return 0;
	my = ob->query_entire_dbase();

	if (me->query("id") == query("leader_name") )
	{
		tell_object(me,sprintf("%s�Ľ���������£�\n",my["name"]));
		msg = sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)\n" NOR ,
status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
		tell_object(me,msg);
		msg = sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)\n" NOR ,
status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"]);
		tell_object(me,msg);
		return 1;
	}
	else return 0;
}

int do_order(string arg)
{
	object me = this_player();
	string ss_name,act,sth,dest,dest_add, *dirs;
	int give_exp,give_pot,i,flag;
	object room,gaoshou,jiefei,fbiaotou,cart,ob = this_object();
	mapping exits;

	if ( query("leader_name") != me->query("id") )
		return notify_fail("�ⲻ����Ҫ�ӵ��ڣ��ڶӲ�������ָ�ӣ�\n");
	if ( query("gurader_name") != me->query("id") )
		return notify_fail("������û�н���(jiebiao)���ڶӲ�������ָ�ӣ�\n");
	if (!arg || sscanf(arg, "%s %s",act,sth) != 2)
		return notify_fail("ָ���ʽ��order <������> <���嶯������>\n");

	if ( act!="go" && act!="give" && act!="wear" && act!="remove" && act!="zou" && act!="wield" && act!="unwield" && act!="enter" && act!="eat" )
		return notify_fail("Ŀǰ��ʱ��֧�ָ����ָ�\n");

	if (act == "go")
	{
		if (! objectp(cart = present("cart", environment(me))))
		{
			command(arg);
			if (! objectp(cart = present("cart", environment(me))))
			return notify_fail(HIR"�ڳ�û���ţ����Ұɡ�\n"NOR);
		}
		if (ob->is_busy() )
			return notify_fail(HIG"�ڳ����������ˣ��Ȼ�ɡ�\n"NOR);
		dest = sprintf( "exits/%s",sth);
		if (! dest_add = environment()->query(dest))
			return notify_fail("�������û�г�·��\n");
		add("total_steps",1);

		if (random(5) == 0)
		{
			message_vision("�ڳ�¡¡ʻ�˿�ȥ��\n",ob);
			if (mapp(exits=environment(me)->query("exits")))
				dirs = keys(exits);
			message_vision(HIY+inroad_msg[random(sizeof(inroad_msg))]+NOR,ob,me);
			command("go " + dirs[random(sizeof(dirs))]);
			cart->move(environment());
			message_vision("�ڳ�¡¡ʻ�˹�����\n",ob);
		}
		else
		if (random(total_appear) < killer_appear)
		{
			message_vision("�ڳ�¡¡ʻ�˿�ȥ��\n",ob);
			if ( !room=find_object(dest_add) )
				room=load_object(dest_add);
			if (random(2)>0)
			{
				ss_name=__DIR__"gaoshou";
				gaoshou = new(ss_name);
				gaoshou->move(room);
			}
			else
			{
				ss_name=__DIR__"fake-biaotou";
				fbiaotou = new(ss_name);
				fbiaotou->move(room);
				fbiaotou->set("name", ob->query("name"));
//				fbiaotou->set("id", ob->query("id"));
				fbiaotou->set_leader(ob);
				message_vision("\n$N���˹�����\n",fbiaotou);
				message_vision("\n\n$N��Ȼ�����е㲻�Ծ�����������������\n",me);
			}
			command(arg);
			ob->start_busy(1);
			cart->move(environment());
			message_vision("�ڳ�¡¡ʻ�˹�����\n",ob);
		}
		else
		if (random(total_appear) < delay_appear)
		{
			command(arg);
			ob->start_busy(1);
			message_vision(HIR"�ڳ�û���ţ����Ұɡ�\n"NOR, ob);
		}
		else
		{
			message_vision("�ڳ�¡¡ʻ�˿�ȥ��\n",ob);
			command(arg);
			ob->start_busy(random(2));
			cart->move(environment());
			message_vision("�ڳ�¡¡ʻ�˹�����\n",ob);
		}
	}
	else command(arg);
	return 1;
}
void die()
{
	object me, cart;
	object ob;

	ob = this_object();
	if ( objectp( cart = present("cart", environment(ob))) )
		destruct(cart);
	if ( ob->query("leader_name") && objectp(me = find_player(ob->query("leader_name")) ))
		tell_object(me,HIB"��ʦ���ˣ��ڳ����ˣ��㽻���˲��ˣ�\n"NOR);
	return ::die();
}
int do_give(string arg)
{
	object me = this_player();
	object ob ;
	string o_name,p_name;

	if ( me->query("id") != query("leader_name") ) return 0;
	if ( sscanf(arg,"%s %s",p_name,o_name) == 2 ||
		sscanf(arg,"%s to %s",o_name,p_name) ==2 ) ;
	else return 0;
	if ( p_name != "bt") return 0;
	if (! ob = present(o_name,me))
		return notify_fail("������û������������\n");
	if (ob->query("no_drop"))
		return notify_fail("�����������������ˡ�\n");

	ob -> move(this_object());
	message("vision",sprintf("%s��%sһ%s%s��\n",me->name(),
		this_object()->name(),ob->query("unit"),ob->name()),me);
	return 1; 
}

void do_check()
{
	object me,gaoshou,jiefei;
	string ss_name;
	int i;
	mapping exits;
	string * dirs;
	object ob = this_object();
	object where = environment(ob);

	add ("total_tired",1);

	if (ob->is_fighting())
	{
		remove_call_out("do_check");
		call_out("do_check",A_TIME);
	}
	else
		if (! living(ob))
		{
			ob->receive_damage("qi",1000);
		}
		else
		{
			if (! me = find_player(query("leader_name") ))
			{
				remove_call_out("do_check");
				call_out("do_check",A_TIME);
			}
			else
			{
				if (random(total_appear) < killer_appear)
				{
					if (random(2)>0) ss_name=__DIR__"gaoshou";
					else ss_name=__DIR__"fake-biaotou";
					gaoshou = new(ss_name);
					gaoshou->move(where);
					ob -> start_busy(1);
				}
				else
				{
					if (random(total_cmd) < bt_cmd )
					{
						if (! ob->is_busy() )
						{
							if (random(2) >0 )
								command(random_act[random(sizeof(random_act))]);
							else
							{
								if ( mapp(exits = where->query("exits") ) )
								{
									message_vision(HIC+inroad_msg[random(sizeof(inroad_msg))]+NOR,ob);
									dirs = keys(exits);
									command("go "+dirs[random(sizeof(dirs))]);
								}
							}
						}
					}
				}
				remove_call_out("do_check");
				call_out("do_check",A_TIME);
			}
		}
}

void do_check1()
{
        object cart;
        object ob = this_object();

	if (living(ob) && ob->query("qi") > 0 )
	{
		remove_call_out("do_check1");
		call_out("do_check1",B_TIME);
	}
	else
	{
		message_vision(HIR"$N�ڻ�����ͻȻ���ٵ�������һ����Ȼ�����û�������ˡ�\n"NOR,ob);
	     if (objectp(cart = present("cart", environment(ob)))) destruct(cart);
  	      
             ob -> receive_damage("qi",1000);
        }
}


string status_color(int current, int max)
{
	int percent;

	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int accept_hit(object me)
{
	object ob = this_object();
	object gurad_ob;

	if (!query("gurader_name")) return 1;
	if (!gurad_ob = present(query("gurader_name"),environment(ob) ) )
  {
  	if (userp(me))
  		return notify_fail(HIW"��Ҳ��ܽ��ڣ�\n"NOR);
		return 1;
	}
	if (me == gurad_ob)
		return notify_fail(HIR"�㲻���������˵�\n"NOR);
	else
	{
		tell_object(me,HIR"��ֵ��ʦ���ܵ�"+gurad_ob->query("name")+"�ı��������ܵ����ˣ�\n"NOR);
		tell_object(gurad_ob,HIR"��ֵ��ʦ�ܵ�"+me->query("name")+"������Σ�գ�����Ҫ������ͦ����ϣ�\n"NOR);
		me -> kill_ob(gurad_ob);
		gurad_ob -> fight_ob(me);
		return notify_fail("");
	}
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}
