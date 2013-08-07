// /d/npc/renzhi.c ����
//modified by sega 1/10/99
//�޸��˽���������
#include <ansi.h>
#define lay_exp 20
#define lay_pot 5
#define lay_score 10
#define price_exp 300
#define price_pot 80
#define price_score 100
#define total_appear 10
#define killer_appear 2
#define total_cmd 10
#define rz_cmd 3
#define A_TIME 60
#define B_TIME 5

inherit NPC;
string * des_str=({
	"����һλ��ɴ������ˣ��������ж��������\n",
	"�������˶�������һ������ĺ����ĬĬվ������һ�Բ�����\n",
	"һλ΢΢���ֵ��ˣ���������Ц��\n",
	"����üͷ������һ���ƺ���ʲô�ºܵ��ĵ����ӡ�\n",
	"�������������վ�����������ʲô���ֲ���˵�Ƶġ�\n",
	"һλ�������������ص��ˣ����������˾����е��������ӡ�\n",
	"�����վ���������ͣ���ڷ�����Ҳ���Ǻ���ʲô��\n",
	"�����������ƣ����������������ܴ󣬲�����ϸһ�����ֺ���û��ʵ����ô��\n",
	"������һ�������ʵغܺõ��·������������·���մ���˳�����Ѫ����\n",
});

string * random_act = ({
	"fear",
	"dazuo 40",
	"dazuo 60",
	"dazuo 100",
	"dazuo 120",
	"sigh",
	"sigh1",
	"say ��Ҫ���Ҵ�������ȥ����",
	"remove all",
	"remove all",
	"remove all",
	"drop all",
});

string * escape_msg = ({
	"$NͻȻ���ֵص�������ѽ��ɱ�����ˣ��Ҵ�����·�����ˡ���\n",
	"$NͻȻ���ֵ�ָ���㣬Ъ˹����ش���������ɱ�֣������ɱ�֣����������ɱ�ҵ�ɱ�֣���û��˭��Ӧ������$Nת�����������\n",
	"$N���ӵ��Ĵ����˿���ͻȻ��������������ط����ƫƧ����ô�ܶ���أ������߰ɡ���\n",
	"$Nһ��ͷ���ƺ�����Զ����ʲô�����ӹ�������ת����ܡ�\n",
	"��Ȼ����$Nһ���ҽУ����󱻲�ס��β�͵�����һ��ת�����˿�ȥ��\n",
	"$NͻȻ��Ȼ�������Ŷ����ط�����ǰ�������ô�����·�ߡ�˵�գ�ת����ߡ���\n"
,
	"$N������Ⱦ��ܣ���ô����Ҳ����ͷ��һ���̵���ʧ�ˡ�\n",
});

string status_color(int current, int max);

void create()
{
	mapping name;
	if (random(2) == 0)
	{
		name = NAME_D->woman_name();
		set("gender", "Ů��");
	}
	else
	{
		name = NAME_D->man_name();
		set("gender", "����");
	}
	set_name(name["name"],({"ren zhi", "rz"}));

	set("age", 17 + random(60) );
	set("long", des_str[random(sizeof(des_str))]);

	set("combat_exp", 500 + random(5000));
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "�ҵ������ǲ��ܶ����ҽ��ġ�\n",
	]));

	set("env/wimpy",50);
	set("no_get",1);
	set("no_beg",1);
	set("no_steal",1);
	set("no_kill",1);
	set("max_neili",150 + random(150) );
	set("neili",query("max_neili") );

	set_skill("unarmed",20);
	set_skill("sword",20);
	set_skill("blade",20);
	set_skill("dodge",20);
	set_skill("force",20);
	set_skill("huntian-qigong",20);
	map_skill("force","huntian-qigong");
	
	set( "max_qi", 350 + random(200) );
	set( "max_jing", 200 + random(300) );

	set("leader_name","");
	set("dest_add","");
	set("combat_num",0);
	set("total_steps",0);
	set("total_tired",0);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_baohu","baohu");
	add_action("do_order","order");
	add_action("do_steal","steal");
	add_action("do_hit","hit");
	add_action("do_kill","kill");
	add_action("do_give","give");
	add_action("do_hp","hp");
	add_action("do_touxi","touxi");
	remove_call_out("do_check");
	call_out("do_check",A_TIME);
	remove_call_out("do_check1");
	call_out("do_check1",B_TIME);
}


int do_baohu(string arg)
{
	object me = this_player();

	if ( query("leader_name") != me->query("id") )
		return notify_fail("��û�и��𱣻������ʵ�����\n"); 
	set("gurader_name",me->query("id") );
	tell_object(me,HIR"ע�⣺�����ڿ�ʼ�����ʽ��б������κ�������ʵĹ��������Զ�ת�Ƶ������ϣ�\n"NOR);
	return 1;
}

int do_hp(string arg)
{
	object ob = this_object();
	object me = this_player();
	string msg;
	mapping my;

	if (!arg || (arg != ob->query("id") && arg != "rz") )
		return 0;
	my = ob->query_entire_dbase();

	if (me->query("id") == query("leader_name") ) {
		tell_object(me,sprintf("%s�Ľ���������£�\n",my["name"]));
		msg = sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)\n" NOR ,
			status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
			status_color(my["eff_jing"], my["max_jing"]), my["eff_jing"] * 100 / my["max_jing"]);
		tell_object(me,msg);
		msg = sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)\n" NOR ,
status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"]);
		tell_object(me,msg);
		return 1;
	}
	else
		return 0;
}

int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if (!arg || (arg != ob->query("id") && arg != "rz") )
		return 0;
	if (!query("gurader_name") || !gurad_ob = present(query("gurader_name"),environment(ob)) )
	{
		if (userp(me) )
		{
			tell_object(me,HIW"��Ҳ��ܹ����ޱ��������ʣ�\n"NOR);
			return 1;
		}
		else
			return 0;
	}
	if (me == gurad_ob)
	{
		tell_object(me,HIR"�ף��㲻�����ı�������?\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,HIR"�������ܵ�"+gurad_ob->query("name")+"�ı������˼Ҽ���ս�����㷢�𹥻���\n"NOR);
		tell_object(gurad_ob,HIR"�����ܵ�"+me->query("name")+"��������ͦ�����ս����\n"NOR);
		me -> fight_ob(gurad_ob);		
		gurad_ob -> fight_ob(me);
		return 1;
	}
}

int do_kill(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if (!arg || (arg != ob->query("id") && arg != "rz") ) return 0;
	if (!query("gurader_name") || !gurad_ob = present(query("gurader_name"),
environment()) )
	{
		if (userp(me) )
		{
			tell_object(me,HIW"��Ҳ��ܹ����ޱ��������ʣ�\n"NOR);
			return 1;
		}
		else return 0;
	}

	if (!gurad_ob = present(query("gurader_name"),environment(ob) ) )
		return 0;
	if (me == gurad_ob)
	{
		tell_object(me,HIR"�㲻����������������\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,HIR"�������ܵ�"+gurad_ob->query("name")+"�ı������˼Ҽ���ս��������Ĺ�����\n"NOR);
		tell_object(gurad_ob,HIR+me->query("name")+"׼��ɱ�����ʣ���ͦ�����ս����\n"NOR);
		me -> kill_ob(gurad_ob);		
		gurad_ob -> fight_ob(me);
		return 1;
	}
}

int do_touxi(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if (!arg || (arg != ob->query("id") && arg != "rz") )
		return 0;
	if (!query("gurader_name") || !gurad_ob = present(query("gurader_name"),environment(ob)) )
	{
		if (userp(me) )
		{
			tell_object(me,HIW"��Ҳ��ܹ����ޱ��������ʣ�\n"NOR);
			return 1;
		}
		else return 0;
	}

	if (!gurad_ob = present(query("gurader_name"),environment() ) )
		return 0;
	if (me == gurad_ob)
	{
		command("papa "+me->query("id"));
		tell_object(me,HIR"�㲻��͵Ϯ���ʡ�\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,HIR"�������ܵ�"+gurad_ob->query("name")+"�ı������˼Ҽ���ս��������Ĺ�����\n"NOR);
		tell_object(gurad_ob,HIR+me->query("name")+"׼�������ʽ���͵Ϯ����ͦ�����ս����\n"NOR);
		me -> kill_ob(gurad_ob);
		gurad_ob -> fight_ob(me);
		return 1;
	}
}

int do_steal(string arg)
{
	object ob = this_object();
	object me = this_player();
	string who;

	sscanf(arg,"%*s %*s %s",who);

	if (who == ob->query("id") || who == "rz" )
	{
		message("vision",HIW"��Ҳ���͵�������ϵĶ�����\n"NOR,me);
		return 1;
	}
	return 0;
}

int do_order(string arg)
{
	object me = this_player();
	object ml;
	string act,sth,dest,dest_add;
	int give_exp,give_pot,give_score;
	int i;
	object room,shashou,anshazhe;
	string ss_name;

	if ( query("leader_name") != me->query("id") )
		return notify_fail("�����㲻�Ǹ�����Ľ����ߣ����ʲ��������ָ�ӣ�\n");
	if (!arg || sscanf(arg, "%s %s",act,sth) != 2)
		return notify_fail("ָ���ʽ��order <������> <���嶯������>\n");

	if (query("qi") < 50)
		return notify_fail("Ŀǰ����û������ִ�и������\n");

	if ( act!="go" && act!="ask chuanfu about ����" && act!="get" && act!="give" && act!="drink" && act!="wear" && act!="remove" && act!="zou" && act!="wield" && act!="unwield" && act!="enter" && act!="eat" )
		return notify_fail("Ŀǰ��ʱ��֧�ָ����ָ�\n");

        if ( me->is_busy() || me->is_fighting())
		    return notify_fail("����æ���ء�\n");

	if (act == "go")
	{
		if (this_object()->is_busy() )
			return notify_fail(HIY"����Ҫ��Ϣһ�������·��\n"NOR);
		dest = sprintf( "exits/%s",sth);
		if (! dest_add = environment()->query(dest))
			return notify_fail("�������û�г�·��\n");
		if (! environment(this_object())->query("no_fight"))
			add("total_steps",1);
		if (dest_add == query("dest_add") )
		{
		//Ŀ�ĵص���
			message_vision(YEL"$N������һ���������������ڵ��ˡ���֪��������ð����һ������$N�����˳���Ȼ���ﳾ��ȥ��\n"NOR,this_object(),me);
			tell_object(me,HIW"��ϲ��ɹ��������͵�Ŀ�ĵأ��������������\n"NOR);
			i = 0;
			give_exp = lay_exp * query("total_steps");
			give_pot = lay_pot * query("total_steps");
			give_score = lay_score * query("total_steps");
			while ( i < query("combat_num") )
			{
				give_exp += (price_exp/2 + random(price_exp/2));
				give_pot += (price_pot/2 + random(price_pot/2));
				give_score += (price_score/2 + random(price_score/2));
				i++;
			}
			if(give_exp > 8000) give_exp = 6000 + random(2000);
			if(give_pot > 2000 ) give_pot = 1200 + random(400);
			if(give_score > 4000 ) give_score = 3000 + random(500);
			tell_object(me,HIW + sprintf("�㱻�����ˣ��õ�%s�㾭���%s��Ǳ�ܣ�%s�㽭��������\n", chinese_number(give_exp), chinese_number(give_pot), chinese_number(give_score) ) + NOR);
			me->add("combat_exp",give_exp);
			me->add("potential",give_pot);
			if ( ml = present("mi ling",me) ) destruct(ml);
			destruct(this_object());
			return 1;
		}
		else
		{
			if (random(total_appear) < killer_appear)
			{
				if (random(2)>0) ss_name=__DIR__"shashou";
				else ss_name=__DIR__"anshazhe";
				if ( !room=find_object(dest_add) )
					room=load_object(dest_add);
				shashou = new(ss_name);
				shashou->move(room);
				shashou->set_leader(this_object());
				command(arg);
				this_object()->start_busy(1);
			}
			else
			{
				command(arg);
				this_object()->start_busy(random(2));
			}
		}
	}
	else command(arg);
	return 1;

}

int do_give(string arg)
{
	object me = this_player();
	object ob ;
	string o_name,p_name;

	if ( me->query("id") != query("leader_name") ) return 0;
	if (!arg) return 0;
	if ( sscanf(arg,"%s %s",p_name,o_name) != 2) return 0;
	if ( sscanf(arg,"%s to %s",o_name,p_name) !=2 ) return 0;
	if ( p_name != "rz") return 0;
	if (! ob = present(o_name,me))
		return notify_fail("������û������������\n");
	if (ob->query("no_drop"))
		return notify_fail("�����������������ˡ�\n");

	ob -> move(this_object());
	message("vision",sprintf("%s��%sһ%s%s��\n",me->name(),
		this_object()->name(),ob->query("unit"),ob->name()),me);
	return 1;

}

int active_died()
{
	object me;
	object ml;

	if (! me = find_player(query("leader_name")) ) return 1;
	else {
		tell_object(me,HIB"�������ˣ��������ʧ���ˣ�\n"NOR);
		if (ml = present("mi ling",me) )
			destruct(ml);
		return 1;
	}
}

void do_check()
{
	object me,shashou;
	string ss_name;
	int i;
	mapping exits;
	string * dirs;
	object ob = this_object();
	object where = environment(ob);

	add ("total_tired",1);

	if (! living(ob) || ob->is_fighting())
	{
		remove_call_out("do_check");
		call_out("do_check",A_TIME);
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
				if (random(2)>0) ss_name=__DIR__"shashou";
				else ss_name=__DIR__"anshazhe";
				shashou = new(ss_name);
				shashou->move(where);
				ob -> start_busy(1);
				shashou->set_leader(ob);
			}
			else
			{
				if (random(total_cmd) < rz_cmd )
				{
					if (! ob->is_busy() )
					{
						if (random(2) >0 ) command(random_act[random(sizeof(random_act))]);
						else
						{
							if ( mapp(exits = where->query("exits") ) )
							{
								message_vision(HIY+escape_msg[random(sizeof(escape_msg))]+NOR,ob);
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
	object ob = this_object();

	if (ob -> query("qi") < 10)
	{
		message_vision(HIR"$Nһ���ҽУ����һ�����ڵ��ϡ�\n"NOR,ob);
		ob -> receive_damage("qi",100);
		ob -> receive_wound("qi",100);
		ob -> die();
	}
	else
	{
		if (living(ob) )
		{
			remove_call_out("do_check1");
			call_out("do_check1",B_TIME);
		}
		else
		{
			message_vision(HIR"$N�ڻ�����ͻȻ���ٵ�������һ����Ȼ�����û�������ˡ�\n"NOR,ob);
			ob -> die();
		}
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

