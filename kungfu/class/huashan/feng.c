// feng.c ������

#define FENG "/log/feng"

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
string ask_skill1();
string ask_skill2();
string ask_skill3();
string ask_skill4();
int check_betrayal(object ob);
int check_student(object ob);
int improve_sword(object ob);
int save_data();
int load_data();
int auto_perform();

void create() 
{
	seteuid(getuid());
	set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "��ɽ��ʮ�������ڳ���");
	set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��
����ݳ���ü���һֱ������һ�ɵ�����������ɫ����Ȼ�Ե���Ľ�������
֮��һֱ����������\n");
	set("gender", "����");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 4800);
	set("max_qi", 4800);
	set("jing", 3600);
	set("max_jing", 3600);
	set("neili", 4400);
	set("max_neili", 4400);
	set("jiali", 200);

	set("combat_exp", 3000000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 200);
	set_skill("poyu-quan", 300);
	set_skill("fanliangyi-dao", 300);
	set_skill("huashan-sword", 300);
	set_skill("hunyuan-zhang", 300);
	set_skill("lonely-sword", 300);
	set_skill("feiyan-huixiang",250);
	set_skill("literate", 120);
	set_skill("ziyunyin",100);
	set_skill("zhengqijue",100);

	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");
	create_family("��ɽ��", 12, "������");

	set("chat_chance_combat", 90);
	set("inquiry", ([
		"�ƽ�ʽ" 	:	(: ask_skill1 :),
		"����ʽ"  :	(: ask_skill2 :),
		"�ܾ�ʽ"  :	(: ask_skill3 :),
		"����"    : (: ask_skill4 :),
	]));
	set("chat_msg_combat", ({
		(: perform_action, "sword.po" :),
		(: perform_action, "sword.po" :),
		(: perform_action, "sword.poqi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	setup();
	carry_object(WEAPON_DIR"sword/changjian")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	load_data();
}

void init()
{
	object ob, me = this_object();

	::init();

	if( interactive(ob = this_player()) &&
		ob->query("family/master_id") == "feng qingyang" )
	{
		remove_call_out("check_student");
		call_out("check_student",0,ob);
	}
	else if( ob->query("family/master_id") != "feng qingyang" &&
			(int)ob->query_skill("lonely-sword", 1) > 1 )
	{
		remove_call_out("check_betrayal");
		call_out("check_betrayal",0,ob);
	}
	else if( !ob->is_fighting() &&	!ob->query("fengtaugh") &&
		file_name(environment(me)) ==	"/d/huashan/xiaofang" )
	{
		remove_call_out("improve_sword");
		call_out("improve_sword", 0, ob );
	}
	if (wizardp(this_player()))
	{
		add_action("do_stnow", "stnow");
		add_action("save_data","sdt");
		add_action("load_data","ldt");
	}
}

int do_stnow(string arg) // ���������������еķ����
{
	object *user;
	string *list=({});
	string str;
	mapping st;
	int i;
	
	load_data();
	user=users();
	for (i=0;i<sizeof(user);i++)
	{
		if (user[i]->query("family/master_id")=="feng qingyang")
			list += ({user[i]->query("id")});
	}
	if (arrayp(list))
	{
		write("�����еķ���ӹ���"+sizeof(list)+"�ˣ�"+implode(list,"��")+"\n");
	}
	else 
	{
		write("������û�з���ӡ�\n");
	}
	if (mapp(st = query("students")))
	{
		write("ϵͳ�������"+sizeof(query("students"))+"�ˣ�"+implode(keys(st),"��")+"��\n");
	}
	else
	{
		write("ϵͳ��û���յ��ӡ�\n");
	}
	if (stringp(str=query("pending")))
	{
		write("������Ŀǰ����"+str+"Ϊͽ��\n");
	}
	if (mapp(st = query("no_accept")))
	{
		write("��������Զ����"+implode(keys(st),"��")+"Ϊͽ��\n");
	}
	return 1;
}

int check_betrayal(object ob)
{
	object me=this_object();
	mapping std_status;
	string *stdname;
	int i;

//	load_data();
	if ( mapp(std_status = me->query("students")) )
	{
		stdname = keys(std_status);
		for(i=0; i<sizeof(std_status); i++)
		{
			if ( ob->query("id")==stdname[i] &&
				ob->query("normal_die") == me->query("students/"+ob->query("id")) ) // û������ʦ��
			{
				command( "chat ��ʦ����ļһ���㻹�����������ң�" );
				me->delete( "students/"+ob->query("id") );
				me->set( "no_accept/"+ob->query("id"), 1);
				save_data();
			}
		}
	}
	return 1;
}

int check_student(object ob)
{
	int death_time;
	string std_id;
	object me = this_object();
	int ap_death_time;

	death_time = ob->query("normal_die");
	std_id = ob->query("id");

	if ( ob->query("family/master_id")=="feng qingyang")
	{
		if (member_array(ob->query("id"),keys(this_object()->query("students")))==-1)
		{
			// �Ƿ������
			command( "say �ø���������������Ϊ��������" );
			command( "expell " + ob->query("id"));
			ob->delete_skill("lonely-sword");
			ob->delete("can_perform/lonely-sword");
			this_object()->set( "no_accept/"+ob->query("id"), 1);
			save_data();
			return 1;
		}
	}
	sscanf(me->query("students/"+std_id),"%d",ap_death_time);
	if ( death_time +1 > ap_death_time )
	{
		// ���������
		ob->delete("family");
		ob->set("title","��ͨ����");
		message_vision( "�����￴�˿�$N�������ֳ����ݵ���ɫ��\n", ob );
		command( "say ����ʦͽ֮���Ѿ����Ժ������Ϊ֮�ɡ�" );
		me->delete( "students/"+std_id );
		me->set( "pending", std_id );
	}
	else if ( ob->query("shen") < 0 )
	{
		command( "say �ø���������������Ϊ��������" );
		command( "expell " + ob->query("id"));
		ob->delete_skill("lonely-sword");
		ob->delete("can_perform/lonely-sword");
		me->delete( "students/"+std_id );
		me->set( "pending", std_id );

	}
	else if ( (int)ob->query_skill("zixia-shengong", 1) < 50 )
	{
		command( "say ��˵�����ؽ����������㾹Ȼ���������Ӳ��ɽ�Ҳ��" );
		command( "expell " + ob->query("id"));
		ob->delete_skill("lonely-sword");
		ob->delete("can_perform/lonely-sword");
		me->delete( "students/"+std_id );
		me->set( "pending", std_id );
	}
	save_data();
	return 1;
}

int improve_sword(object ob)
{
	int my_sword, add_level;
	
	if (!userp(ob)) return 0;
	
	my_sword = ob->query_skill("sword", 1);
	command( "say "+RANK_D->query_respect(ob)+"��Ȼһ�����������ҿ�ν��Ե������ָ����һЩ�����ɡ�");
	message_vision( "�����￪ʼΪ$N��˵���������ľ��塣\n", ob );

	if ( my_sword < 100 )
	{
		add_level = my_sword + 20;
		tell_object( ob, "��Ļ������������˶�ʮ����\n");
	}
	else if ( my_sword < 120 )
		{
			add_level = my_sword + 10;
			tell_object( ob, "��Ļ�������������ʮ����\n");
		}
		else if ( my_sword < 150 )
			{
				add_level = my_sword + 5;
				tell_object( ob, "��Ļ��������������弶��\n");
			}
			else
			{
				message_vision( "���������$N���ȵء���������һ����\n", ob );
				command( "say "+RANK_D->query_respect(ob)+"�Ľ�����Ȼ�������ң����಻ʤ�����\n");
				tell_object( ob, "��Ļ��������ѳ�¯����֮������������ûʲô��ָ��������ˣ�\n");
				ob->set("fengtaugh", 1);
				return 1;
			}

	ob->set_skill("sword", add_level);
	ob->set("fengtaugh", 1);
	if(ob->query("combat_exp") > 100000 && userp(ob) )
		ob->add("combat_exp", 15000);

	return 1;
}

void attempt_apprentice(object ob)
{
	object ob1, room, me = this_object();
	mapping no_status, student_stat, skl = ob->query_skills();
	string mengzhu, *noname, *sk;
	int i;


	if ( mapp(no_status = me->query("no_accept")) )
	{
		noname = keys(no_status);
		for (i=0; i<sizeof(no_status); i++)
		{
			if ( ob->query("id") == noname[i] )
			{
				command("say ������Զ���������������ʦ����ļһ�ģ�");
				return;
			}
		}
	}
	
	if ( (string)ob->query("id") == me->query("pending") )
	{
		command("say �Ϸ����ڲ�������Ϊͽ���㻹���߰ɡ�");
		return;
	}
	if ( mapp(student_stat = me->query("students")) &&
		sizeof(student_stat) >= 5 )
	{
		command("say �Ϸ�������ͽ�������յ����ˡ�");
		return;
	}
	if ( (string)ob->query("gender") == "����" )
	{
		command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
		return;
	}
	if ((string)ob->query("class")=="bonze")
	{
		command ("say �Ϸ��ճ�����Ϊͽ������ذɡ�");
		return;
	}
	if ((string)ob->query("party/party_name") == HIC"ؤ��"NOR )
	{
		command("say " + RANK_D->query_respect(ob) + "����ؤ�ﲻ�ٺô����α��Ѱ��԰���Ϊʦ�أ�");
		return;
	}       
	if ( (int)ob->query_int() < 33 )
	{
		command("say " + RANK_D->query_respect(ob) + "���ʲ�����ѧ���˶��¾Ž���");
		return;
	}
	if ( (int)ob->query("shen") < 100000 )
	{
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say "+RANK_D->query_respect(ob)+"���в�����ˡ�Ҳ������㡣");
		return;
	}
	if ( (int)ob->query_skill("sword", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"�Ļ���������Ϊ������ˡ�Ҳ������㡣");
		return;
	}
	if ( (int)ob->query_skill("strike", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"�Ļ����Ʒ���Ϊ������ˡ�Ҳ������㡣");
		return;
	}
	if ( (int)ob->query_skill("dodge", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"�Ļ����Ṧ��Ϊ������ˡ�Ҳ������㡣");
		return;
	}
	if ( (int)ob->query_skill("parry", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"�Ļ����м���Ϊ������ˡ�Ҳ������㡣");
		return;
	}
	if ( (int)ob->query_skill("force", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"�Ļ����ڹ���Ϊ������ˡ�Ҳ������㡣");
		return;
	}
	if ( (int)ob->query_skill("zixia-shengong", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"����ϼ����Ϊ�������ҵ�Ҫ��ˡ�Ҳ������㡣");
		return;
	}

	sk = keys(skl);
	i = sizeof(sk);
	while (i--)
	{
		if (sk[i] != "lonely-sword" && sk[i] != "huashan-sword" &&
			SKILL_D(sk[i])->valid_enable("sword"))
		{
			command("say ���¾Ž���Ҫּ������������ð�ԭ����ѧ�Ľ�����ȫ��ȴ������ͻ�ƽ������档");
			command("say "+RANK_D->query_respect(ob)+"���д˾��ľ�����ѧ֮"+to_chinese(sk[i])+"��");
			return;
		}
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if (ob->is_apprentice_of(me))
	{
		ob->set("title",HIY+BLINK+"��"+NOR+HIC+"�¶�����"+HIY+BLINK+"��"+NOR);
		command("chat ���������¾Ž��������д����ˣ�"+ob->name()+"����Ϊ�ҵ��ӣ����λͬ�������ա�");
		me->set("students/"+(string)ob->query("id"), (int)ob->query("normal_die")+1);
		if ( stringp(me->query("pending")) )
		{
	  		me->delete("pending");
		}
		save_data();
	}
}

int accept_fight(object ob)
{
	object me = this_object();

	int my_max_qi = me->query("max_qi");
	if ( me->query("qi")*100 / my_max_qi <= 80 )
	{
		return 0;
	}

	remove_call_out("auto_perform");
	call_out("auto_perform", 1);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say �Ϸ�������Թ�޳𣬺���ʹ�¶��֣����Ϸ�Ϊ�������");
	remove_call_out("auto_perform");
	call_out("auto_perform", 1);	

	return 1;
}

int auto_perform()
{
	object me = this_object();
        object ob = me->select_opponent();
	object weapon, my_weapon;
	string action;

	if ( !me->is_fighting() )
	{
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }
	else
	{
		if ( objectp(my_weapon=me->query_temp("weapon")) )
		{
			action = "sword.po";
			remove_call_out("auto_perform");
			call_out("auto_perform", 1+random(5));
			return perform_action(action);
		}
		else if ( !me->query_temp("leidong") )
			{
				remove_call_out("auto_perform");
				call_out("auto_perform", 1+random(5));
				return perform_action("cuff.leidong");
			}
			else 
			{
				remove_call_out("auto_perform");
				call_out("auto_perform", 1+random(5));
				return perform_action("strike.wuji");
			}
	}
}

string ask_skill1()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/po"))
		return "�㲻���Ѿ�ѧ������";

	if (me->query("family/master_id")!= "feng qingyang")
		return "����ҵ��ӣ��ι��д�һ�ʡ�";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"+
		HIG "�����˷�����Ľ̵����ľ���ã����"
                        "����Ǳ�ܲ����ˡ�" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"HIY "�����˷�����Ľ̵��������ĵá�" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform" : "po",		//pfm�Ĵ���
					"name"	  : "�ƽ�ʽ",		//pfm������
					"sk1"	  : "lonely-sword",	//��Ҫ���书��id
					"lv1"	  : 50,					//��Ҫ���书�ĵȼ�
					"sk2"	  : "sword",		//��Ҫ�书sk2��id
					"lv2"	  : 50,					//��Ҫ�书sk2 �ĵȼ�
					"neili"	  : 500,					//��Ҫ�����ڹ��ȼ�
					]));
}
string ask_skill2()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/poqi"))
		return "�㲻���Ѿ�ѧ������";

	if (me->query("family/master_id")!= "feng qingyang")
		return "����ҵ��ӣ��ι��д�һ�ʡ�";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"+
		HIG "�����˷�����Ľ̵����ľ���ã����"
                        "����Ǳ�ܲ����ˡ�" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"HIY "�����˷�����Ľ̵��������ĵá�" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform"	: "poqi",		//pfm�Ĵ���
					"name"		: "����ʽ",		//pfm������
					"sk1"		: "lonely-sword",	//��Ҫ���书��id
					"lv1"		: 100,			//��Ҫ���书�ĵȼ�
					"sk2"		: "sword",		//��Ҫ�书sk2��id
					"lv2"		: 100,			//��Ҫ�书sk2 �ĵȼ�
					"neili"		: 500,			//��Ҫ�����ڹ��ȼ�
					]));
}
string ask_skill3()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/zongjue"))
		return "�㲻���Ѿ�ѧ������";

	if (me->query("family/master_id")!= "feng qingyang")
		return "����ҵ��ӣ��ι��д�һ�ʡ�";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"+
		HIG "�����˷�����Ľ̵����ľ���ã����"
                        "����Ǳ�ܲ����ˡ�" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"HIY "�����˷�����Ľ̵��������ĵá�" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform"	: "zongjue",		//pfm�Ĵ���
					"name"		: "�ܾ�ʽ",		//pfm������
					"sk1"		: "lonely-sword",	//��Ҫ���书��id
					"lv1"		: 20,			//��Ҫ���书�ĵȼ�
					"sk2"		: "sword",		//��Ҫ�书sk2��id
					"lv2"		: 100,			//��Ҫ�书sk2 �ĵȼ�
					"neili"		: 500,			//��Ҫ�����ڹ��ȼ�
		]));
}
string ask_skill4()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/pozhong"))
		return "�㲻���Ѿ�ѧ������";

	if (me->query("family/master_id")!= "feng qingyang")
		return "����ҵ��ӣ��ι��д�һ�ʡ�";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"+
		HIG "�����˷�����Ľ̵����ľ���ã����"
                        "����Ǳ�ܲ����ˡ�" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "���¾Ž�Ҫּ���ڡ��򡹣����ɾ��಻���������ϵл��ȣ�������ʤ��\n"HIY "�����˷�����Ľ̵��������ĵá�" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform"	: "pozhong",		//pfm�Ĵ���
					"name"		: "����",		//pfm������
					"sk1"		: "lonely-sword",	//��Ҫ���书��id
					"lv1"		: 80,			//��Ҫ���书�ĵȼ�
					"sk2"		: "sword",		//��Ҫ�书sk2��id
					"lv2"		: 50,			//��Ҫ�书sk2 �ĵȼ�
					"neili"		: 50,			//��Ҫ�����ڹ�
					]));
}
int save_data()
{
	string str;
	mapping mydata;
	string *kdata;
	string *temp;
	int i;
	
	str = "students��";
	mydata = this_object()->query("students");
	if (mapp(mydata))
	{
		str += keys(mydata)[0];
		for (i=1;i<sizeof(mydata);i++)
		{
			str += "��";
			str += keys(mydata)[i];
		}
		str += "->";
		str += mydata[keys(mydata)[0]];
		for (i=1;i<sizeof(mydata);i++)
		{
			str += "��";
			str += mydata[keys(mydata)[i]];
		}
	}
	str += "\n";
	str += "pending��";
	if (stringp(this_object()->query("pending")))
		str += this_object()->query("pending");
	str += "\n";
	str += "no_accept��";
	mydata = this_object()->query("no_accept");
	if (mapp(mydata))
	{
		str += implode(keys(mydata),"��");
	}
	str += "\n";
	write_file(FENG,str,1);
	return 1;
}
int load_data()
{
	string str,*lines;
	mapping mydata;
	string *kdata,*kvalue;
	int i,j;
	string k,v,v1;
	int temp;
	
	str = read_file(FENG);
	if (!stringp(str)) return 0;
	lines = explode(str,"\n");
	for(i=0;i<sizeof(lines);i++)
	{
		sscanf(lines[i],"%s��%s",k,v);
		switch(k)
		{
			case "students":
				if (!stringp(v)) continue;
				sscanf(v,"%s->%s",v,v1);
				if (!stringp(v)) continue;
				if (!stringp(v1)) continue;
				kdata = explode(v,"��");
				kvalue= explode(v1,"��");
				for (j=0;j<sizeof(kdata);j++)
				{
					if (!stringp(kvalue[j])) kvalue[j] = "1";
					this_object()->set("students/"+kdata[j],kvalue[j]);
				}
				break;
			case "pending":
				if (!stringp(v)) continue;
				this_object()->set("pending",v);
				break;
			case "no_accept":
				if (!stringp(v)) continue;
				kdata = explode(v,"��");
				for(j=0;j<sizeof(kdata);j++)
				{
					this_object()->set("no_accept/"+kdata[j],1);
				}
				break;
			default:
				continue;
		}
	}
	return 1;
}