// baby.c
#include <ansi.h>;
inherit NPC;
inherit F_SAVE;

void try_move();

string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});
string query_save_file();
int do_save();
int do_do(string msg);
void improve_npcskill(string skill, int amount, int weak_mode);
int exercising(object me);
int halt_exercise(object me);
void update_me();
void create()
{
	seteuid(getuid());
	if (!restore())
	{
		set_name("����", ({"xiao baobao","baby"}) );
		set("gender", "Ů��");
		set("age", 1);
		set("attitude", "friendly");
		set("long","һ���Ա�����\n");
		set("combat_exp", 1);
		set("parents",({"dad","mom"}));
   
		set("chat_chance", 2);
		set("chat_msg", ({
			(: random_move :)
		}));

		set("is_baby",1);
		setup();
	}
}

void init()
{
	add_action("do_kill",({"kill","fight","hit","steal"}));
	add_action("do_get","get");
	add_action("do_drop","drop");
	if(member_array(this_player()->query("id"), this_object()->query("parents"))>-1)
	{
		add_action("do_save","bsave");
		add_action("do_teach","bjiao");
		add_action("do_teach","bteach");
		add_action("do_practice","blian");
		add_action("do_practice","bpractice");
		add_action("do_exercise","bdazuo");
		add_action("do_exercise","bexercise");
		add_action("do_learn","blearn");
		add_action("do_learn","bxue");
		add_action("do_study","bstudy");
		add_action("do_study","bdu");
		add_action("do_do","do");
		this_object()->set_leader(this_player());
	}

	remove_call_out("try_move");
	call_out("try_move",1);
}
void unconcious()
{

/*        message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,
this_object());

	 this_object()->disable_player(" <���Բ���>");

        set("jing", 0);
        set("qi", 0);

        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");
*/
	add("die",1);
	set("eff_jing", query("max_jing"));
	set("jing",     query("max_jing"));
	set("eff_qi",   query("max_qi"));
	set("qi",       query("max_qi"));
	save();
	::die();
}

void try_move()
{
	if(random(20)==0)
	{
		remove_call_out("random_move");
		call_out("random_move",5);
	}
}

int do_drop(string arg)
{
	object me=this_object(),who=this_player(),env;
	if(!arg) return 0;
	env = environment(who);
	if(present(arg,who)!=me) return 0;
	if(me->move(env))
	{
		message_vision("$N��$n�ӻ������������\n",who,me);
		return 1;
	}
	return 0;
}

int do_get(string arg)
{
	object me=this_object(),who=this_player(),env;

	if(!arg) return 0;
	env = environment(who);
	if(present(arg,env)!=me) return 0;
	if(member_array(who->query("id"), me->query("parents"))>-1)
	{
		if(me->move(who)) message_vision("$N��������$n����������§�ڻ��\n",who,me);
		else message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n",who,me);
	}
	else message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����\n",who,me);
	return 1;
}

int do_kill(string arg)
{	
	object me,who;
	string name,verb,what,obj;
	if (!arg) return 0;
	verb=query_verb();
	me=this_player();
   
	if(verb=="steal")
	{
		if(sscanf(arg, "%s from %s", what, obj)!=2 ) return 0;
	}
	else obj=arg;

	if(!objectp(who=present(obj,environment(me))) 
		|| !living(who)) return 0;
	if(who==this_object())
	{
		switch(verb)
		{
			case "kill":
			case "touxi":
			case "ansuan":
				tell_object(environment(this_object()),who->query("name")+"ƴ���ؿ����������������������"+me->query("name")+"Ҫɱ�ң����������ѽ��\n");
				break;
			case "hit":
				tell_object(environment(this_object()),who->query("name")+"������������������������"+me->query("name")+"�۸��ң����������ѽ��\n");
				break;
			case "fight":
				tell_object(environment(this_object()),who->query("name")+"�����������������������"+me->query("name")+"Ҫ���ҵ��ǳԣ����������ѽ��\n");
				break;
			case "steal":
				tell_object(environment(this_object()),who->query("name")+"�����������������������"+me->query("name")+"Ҫ͵���ҵ��ǣ�\n");
				break;
			case "beg":
				tell_object(environment(this_object()),who->query("name")+"С��һ������������������������"+me->query("name")+"Ҫƭ�ҵ��ǳԣ�\n");
				break;
		}
	}
//	command(verb);
	return 0;
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb)
	{
		case "kick":
			command("say �������������"  + ob->query("name") + "����Ү��");
			command("kick " + ob->query("id"));
			break;
		case "slap":
			command("say �������������"  + ob->query("name") + "����Ү����ʹ����������");
			command("slap " + ob->query("id"));
			break;
		case "hit":
			command("pain " + ob->query("id"));
			break;
		case "bite":
			command("face " + ob->query("id"));
			break;  
		case "papaya":
			command("angry");
			break;  
	}
}

void relay_whisper(object me, string msg)
{
	if (member_array(me->query("id"),query("parents"))==-1)
	{
		message_vision((string)this_object()->query("name")
			+ "�ɻ�ؿ���$N��\n", me);
		return;
	}

	//note, do not allow the order contain "chat", "tell"...
	//may need disable more later...
	if( strsrch(msg, "chat") != -1 || strsrch(msg, "tell") != -1 ||
		strsrch(msg,"follow")!= -1 || strsrch(msg,"apprentice")!= -1 ||
		strsrch(msg, "recruit") != -1 )
		return;

	if (msg)
	{
		remove_call_out ("relaying");
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying(string msg)
{
	command (msg);
}

int do_do(string msg)
{
	string act, sth;
	if (!msg || sscanf(msg, "%s %s",act,sth) != 2)
		return notify_fail("��Ҫ���㺢�Ӹ�ʲô��\n");

	if(
	// ���û�ϵͳ���
	act!="nick" &&
// ������̽�����
	act!="follow" && //new
  act!="ask" && 	//new
	act!="drop" &&	//new
	act!="halt" && //new
	act!="put" && //new
	act!="ride" && //new
	act!="unride" && //new
	act!="hit" &&
	act!="fight" && 
	act!="kill"	&& 
	act!="say" && 
	act!="chat" && 
	act!="chat*" && 
	act!="go" && 
	act!="give" && 
	act!="wear" && 
	act!="remove" && 
	act!="get" && 
	act!="eat" && 
	act!="drink" && 
	act!="wield" && 
	act!="unwield" && 
// ���书�������
	act!="abandon" && 
	act!="apprentice" && 
	act!="bei" && 
	act!="du" &&  //bdu����ʵ��
	act!="enable" && 
	act!="enforce" && 
	act!="exert" && 
	act!="fangqi" && 
	act!="jiali" && 
	act!="jifa" && 
	act!="learn" && 
	act!="perform" && //new
	act!="yong" && //new
	act!="prepare" && 
	act!="study" && // bdu����ʵ��
	act!="xue" && 
	act!="yun" && 
	act!="bai" &&
	act!="order"  //new ��������
	)
		return notify_fail("Ŀǰ��ʱ���ܽ��㺢�Ӹ����£�\n");

	command (msg);
	return 1;
}

string query_save_file()
{ 
	string id;

	if( !stringp(id = query("saveid")) ) return 0;
	return DATA_DIR + "baby/" + id[0..0] + "/" + id;
}

int do_save()
{
	save();
	write(this_object()->query("name")+"������ϡ�\n");
	return 1;
}

int do_teach(string skill)
{
	object ob=this_object(), me=this_player();
	string skill_name, obname=ob->query("name");
	int student_skill, my_skill, jing_cost, grade, student_combat_exp;

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if(!skill) return notify_fail("��Ҫ��"+obname+"ʲô���ܣ�\n");
	if( me->is_fighting() )
		return notify_fail("���Լ��������������пս̺��ӣ�\n");
	if( !living(ob) )
		return notify_fail("��....����Ȱ�"+obname+"Ū����˵��\n");
	if (ob->is_busy())
		return notify_fail(obname + "������æ���ء�\n");
	if( ob->is_fighting() )
		return notify_fail("û����"+obname+"�������ˣ������Լ����֣�\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("������㻹�����أ�\n");

	if( ob->prevent_learn(me, skill) )
		return 0;

	student_skill = ob->query_skill(skill, 1);

	if( my_skill <= student_skill )
		return notify_fail("�����"+obname+"�ĳ̶��Ѿ����������ˡ�\n");

	if( !SKILL_D(skill)->valid_learn(ob) ) 
		return notify_fail("��"+obname+"Ŀǰ��������û�취ѧϰ���ּ��ܡ�\n");

	jing_cost = 100 / ((int)me->query("int") + (int)ob->query("int"));

	if( !student_skill )
	{
		jing_cost *= 2;
		ob->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٽ��ˡ�\n");

	if( (int)ob->query("learned_points") >= (int)ob->query("potential") )
		return notify_fail(obname+"��Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");

	printf("����%s�����йء�%s�������ʡ�\n", obname, to_chinese(skill));

	if( (int)me->query("jing") > jing_cost )
	{
		if( userp(me) ) me->receive_damage("jing", jing_cost );
	} else {
		write("������̫���ˣ�û�а취�ٽ�"+obname+"��\n");
		return 1;
	}
		
	student_combat_exp = (int)ob->query("combat_exp");

/*	if(student_combat_exp < 10000)
		grade = 1;
	else if(student_combat_exp < 100000)
		grade = 3;
	else if(student_combat_exp < 1000000)
		grade = 8;
	else
		grade = 14;
*/
	if((int)ob->query("jing") > jing_cost)
	{
		if( (string)SKILL_D(skill)->type()=="martial" && student_skill * student_skill * student_skill / 10 > student_combat_exp)
		{
			tell_object(me, "Ҳ����ȱ��ʵս���飬"+obname+"����Ľ��������޷���ᡣ\n");
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(student_skill))

				tell_object(me, obname+"�������ָ������"+skill_name+"��һ���ƺ���Щ�ĵá�\n");
			else
				tell_object(me, obname+"�������ָ�����ƺ���Щ�ĵá�\n");
             
   			me->add("learned_points", 1);
			ob->add("learned_points", 1);

//			if ( grade < 1 ) grade = 1;
			ob->improve_npcskill(skill, 100);
		}
	}
	else
	{
		jing_cost = ob->query("jing");
		tell_object(me,obname+"����̫���ˣ����ʲôҲû��ѧ����\n");
	}
	ob->receive_damage("jing", jing_cost );
	return 1;
}

void improve_npcskill(string skill, int amount, int weak_mode)
{
	int spi;
	object ob=this_object();
	string obname=ob->query("name");

	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(ob) )
	{
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	spi = 30;
	if( sizeof(learned) > spi )
		amount /= sizeof(learned) - spi;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( (!weak_mode || !userp(ob))
		&& learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) )
	{
		skills[skill]++;
		learned[skill] = 0;
		tell_object(this_player(), HIC+obname+"�ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(ob);
	}
}

int do_practice(string skb)
{
	object ob=this_object(), me=this_player();
	string sknm, obname = ob->query("name");
	int sk, skbasic;

	seteuid(getuid());

        if(ob->is_busy())
                return notify_fail(obname+"������æ���ء�\n");
	if(ob->is_fighting())
		return notify_fail(obname+"����ս�����ˣ�ѧ��ʵս����Ҳ�á�\n");
	if( !skb) return notify_fail("��Ҫ��"+obname+"��ϰʲô��\n");
	if( !stringp(sknm = ob->query_skill_mapped(skb)) )
		return notify_fail("��ֻ����"+obname+"��ϰ�� enable ָ�������⼼�ܡ�\n");

	skbasic = ob->query_skill(skb, 1);
	sk = ob->query_skill(sknm, 1);
	if( sk < 1 )
		return notify_fail(obname+"����û��ѧ������ܰɣ�\n");
	if( skbasic < 1 )
		return notify_fail(obname+"���ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skbasic/2 <= sk/3 )
		return notify_fail(obname+"�Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
	if( !SKILL_D(sknm)->valid_learn(ob) ) 
		return notify_fail("��"+obname+"Ŀǰ��������û�취ѧϰ���ּ��ܡ�\n");
	if( SKILL_D(sknm)->practice_skill(ob) )
		return notify_fail("��"+obname+"Ŀǰ��������û�취��ϰ���ּ��ܡ�\n");
	notify_fail(obname+"���ڲ�����ϰ����ܡ�\n");
	if( !SKILL_D(sknm)->valid_learn(ob) ) return 0;

	notify_fail( obname+"������ϰ"+to_chinese(sknm)+"�����ǲ�û���κν�����\n");
	if (sk*sk*sk/10 > (int)ob->query("combat_exp")) 
	{
		return notify_fail("Ҳ����ȱ��ʵս���飬��ϰ��û��������\n");
		return 1;
	}

	ob->receive_damage("qi", 10);
	write(HIC + obname+"���Ű�" + to_chinese(sknm) + "����һ�ˡ�\n"NOR);
	ob->improve_npcskill(sknm, skbasic * 2);
	write(HIY + obname + to_chinese(sknm) + "�����ˣ�\n" NOR);
	return 1;
}

int do_exercise(string arg)
{
	int exercise_cost;
	object ob=this_object();
	string obname=ob->query("name");

	seteuid(getuid());

	if (ob->is_busy() || ob->query_temp("pending/exercising"))
		return notify_fail(obname+"������æ���ء�\n");
	if( ob->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");
	if( !stringp(ob->query_skill_mapped("force")) )
		return notify_fail("���������"+obname+"ѡ��Ҫ�õ��ڹ��ķ���\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail(obname+"Ҫ��������������\n");
	if (exercise_cost < 10)
		return notify_fail(obname+"���ڹ���û�дﵽ�Ǹ����磡\n");
	if( (int)ob->query("qi") < exercise_cost )
		return notify_fail(obname+"���ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

	if( (int)ob->query("jing") * 100 / (int)ob->query("max_jing") < 70 )
		return notify_fail(obname+"���ھ��������޷�������Ϣ��������\n");
	write(obname+"�����������ù���һ����Ϣ��ʼ������������\n");

	ob->set_temp("pending/exercise", 1);
	ob->set_temp("exercise_cost", exercise_cost);
	message_vision("$N��ϥ���£���ʼ����������\n", ob);
	ob->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object ob)
{
	int exercise_cost = (int)ob->query_temp("exercise_cost");
	int neili_gain = 1 + (int)ob->query_skill("force") / 10;
	int max_neili_gain = (int) random(ob->query("max_neili") /500);
	int taixuan;
	object where=environment(ob);
	string obname=ob->query("name");

	if (exercise_cost < 1)
		return 0;
	ob->add("neili", neili_gain);
	ob->set_temp("exercise_cost", exercise_cost -= neili_gain);
// ����������
	if(where->query("xuanbing"))
		ob->add("qi", (int)neili_gain/3);
// ̫����
	if ((int)ob->query_skill("taixuan-gong",1))
	{
		taixuan = (int)ob->query_skill("taixuan-gong",1);
		if(taixuan > 10)
			ob->add("qi", (int)neili_gain * taixuan / 400);
	}
// ���վ�
	if ((int)ob->query_skill("shenzhao-jing",1))
	{
		taixuan = (int)ob->query_skill("shenzhao-jing",1);
		if(taixuan > 10)
			ob->add("qi", (int)neili_gain * taixuan / 400);
	}

	if(living(ob))
	ob->add("qi", -neili_gain);
	
	if (exercise_cost > 0)
		return 1;

	ob->set_temp("pending/exercise", 0);
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", ob);
	if ((int)ob->query("neili") < (int)ob->query("max_neili") * 2)
		return 0;
	else
	{
		if((int)ob->query("max_neili")>(int)ob->query_skill("force")*10)
		{
			write(obname+"������Ϊ�ƺ��Ѵﵽ��ƿ����\n");
			ob->set("neili", (int)ob->query("max_neili"));
			return 0;
		}
		else {
			if (max_neili_gain>2) max_neili_gain=2;
			ob->add("max_neili", 1+max_neili_gain);
			ob->set("neili", (int)ob->query("max_neili"));
			message_vision(HIC"$N�����������ˣ���\n"NOR, ob);
			return 0;
		}
	}
}

int halt_exercise(object ob)
{
	if ((int)ob->query("neili") > (int)ob->query("max_neili") * 2)
		ob->set("neili", (int)ob->query("max_neili") * 2);
	ob->set_temp("pending/exercise", 0);
	return 1;
}
int do_study(string arg)
{
	object book, ob = this_object();
	string zhao_name, obname = ob->query("name");
	mapping skill;
	int my_skill, cost, i, success=0;

	if(!arg) return notify_fail("��Ҫ"+obname+"��ʲô��\n");
        if(ob->is_busy())
                return notify_fail(obname+"������æ���ء�\n");
	if(ob->is_fighting() )
		return notify_fail(obname+"�޷���ս����ר�������ж���֪��\n");
	if(!objectp(book = present(arg, ob)) )
		return notify_fail(obname+"û�Ȿ��ɶ�����\n");
	if( !mapp(skill = book->query("skill")) )
		return notify_fail(obname+"�޷�����������ѧ���κζ�����\n");
	if( !ob->query_skill("literate", 1) )
		return notify_fail(obname+"�Ǹ���ä����ѧ���Ļ��ɡ�\n");

	message("vision", obname+"��ר�ĵ��ж�"+book->name()+"��\n", environment(ob), ob);
	if( (int)ob->query("combat_exp") < skill["exp_required"] )
	{
		message_vision(HIC"$N��ʵս���鲻�㣬����ô��Ҳû�á�\n"NOR,ob);
		return 1;
	}

	notify_fail("��"+obname+"Ŀǰ����������û�а취ѧ������ܡ�\n");
	if( !SKILL_D(skill["name"])->valid_learn(ob) ) return 0;

	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)ob->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if( ob->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
		message_vision(HIR"$N�ж���һ��������Ƿ���������˵�Ķ�̫ǳ�ˣ�û��ѧ���κζ�����\n"NOR, ob);
		return 1;
	}
	if( ob->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
		message_vision(HIR"$N�ж���һ��������Ƿ���������˵�Ķ�̫����ˣ������ջ�\n"NOR, ob);
		return 1;
	}

	if( !ob->query_skill(skill["name"],1)) ob->set_skill(skill["name"], 0);

	my_skill = ob->query_skill(skill["name"], 1);

	if( (int)ob->query("jing") > cost )
	{
		if( (string)SKILL_D(skill["name"])->type()=="martial"
		&& my_skill*my_skill*my_skill/10 > (int)ob->query("combat_exp"))
		{
			message_vision("Ҳ����ȱ��ʵս���飬$N��$n������˵�Ķ��������޷���ᡣ\n", ob, book);
		}
		else
		{
			if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
			printf(obname+"�ж����й�%s�ļ��ɣ��ԡ�%s����һ���ƺ���Щ�ĵá�\n", 
				to_chinese(skill["name"]), zhao_name);
			else
			printf(obname+"�ж����й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill["name"]));
			ob->improve_npcskill(skill["name"], (int)ob->query_skill("literate", 1)/5+1);
		}
	} else {
		cost = ob->query("jing");
		return notify_fail(obname+"���ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
	}
	ob->receive_damage("jing", cost);

	return 1;
}

int do_learn(string arg)
{
	object obt, ob = this_object();
	string skill, teacher, master, skill_name, obname=ob->query("name");
	int master_skill, my_skill, jing_cost, pertimes;

	if( ob->is_busy()) return notify_fail(obname+"������æ���ء�\n");
	if(!arg || (sscanf(arg, "%s %s", teacher, skill) !=2 ))
		return notify_fail("ָ���ʽ��blearn | bxue <ĳ��> <����>\n");
	if( ob->is_fighting() )
		return notify_fail("��"+obname+"����ĥǹ������������\n");
	if( !(obt = present(teacher, environment(ob))) || !obt->is_character())
		return notify_fail("��"+obname+"��˭��̣�\n");
	if( !living(obt) )
		return notify_fail("��....���Ȱ�"+obt->name()+"Ū����˵��\n");

	if( !ob->is_apprentice_of(obt) && !(obt->recognize_apprentice(ob)) )
	{
		return notify_fail(obt->name()+reject_msg[random(sizeof(reject_msg))] );
	}

	if( !master_skill = obt->query_skill(skill, 1) )
		return notify_fail("�����"+obname+"���±����ұ���ѧ�ˡ�\n");

	notify_fail(obt->name()+"��Ը���"+obname+"����ܡ�\n");
	if( obt->prevent_learn(ob, skill) ) return 0;

	my_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("�����"+obname+"�ĳ̶��Ѿ�����"+obname+"��ʦ���ˡ�\n");
	if( my_skill >= (int)(master_skill - ob->query("betrayer")*2))
		return notify_fail(obt->name()+"������üͷ����������"+obname+"��ȥ����ʦ������\n");
	notify_fail("��"+obname+"Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if( !SKILL_D(skill)->valid_learn(ob) ) return 0;
	jing_cost = 100 / (int)ob->query("int");
	if( !my_skill )
	{
		jing_cost *= 2;
		ob->set_skill(skill,0);
	}
	if( (ob->query("potential") - ob->query("learned_points")) < 1)
		return notify_fail(obname+"��Ǳ�ܲ���ѧϰ�ˡ�\n");
	printf(HIC+obname+"��%s������йء�%s�������ʡ�\n"NOR, obt->name(), to_chinese(skill));

	if( obt->query("env/no_teach") )
		return notify_fail("����"+obt->name()+"���ڲ���׼���ش�"+obname+"�����⡣\n");

	tell_object(obt, sprintf("%s��������йء�%s�������⡣\n",
		obname, to_chinese(skill)));

	if( (int)obt->query("jing") > jing_cost/5 + 1 )
	{
		if( userp(obt) ) obt->receive_damage("jing", jing_cost/5 + 1);
	} else
	{
		write("����"+obt->name()+"��Ȼ̫���ˣ�û�а취��"+obname+"ʲ�ᡣ\n");
		tell_object(obt, "������̫���ˣ�û�а취��"+obname+"��\n");
		return 1;
	}
		
	if( (int)ob->query("jing") > jing_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill*my_skill*my_skill/10 > (int)ob->query("combat_exp"))
		{
			return notify_fail("Ҳ����ȱ��ʵս���飬"+obname+"��"+obt->name()+"�Ļش������޷���ᡣ\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 			printf(obname+"����%s��ָ�����ԡ�%s����һ���ƺ���Щ�ĵá�\n", obt->name(), skill_name);
			else
				printf(obname+"����%s��ָ�����ƺ���Щ�ĵá�\n", obt->name());
			ob->add("learned_points", 1);
			ob->improve_npcskill(skill, random(ob->query_int()));
		}
	} else
	{
		if (jing_cost > ob->query("jing"))
			jing_cost = ob->query("jing");
		return notify_fail(obname+"����̫���ˣ����ʲôҲû��ѧ����\n");
	}
	ob->receive_damage("jing", jing_cost);
	return 1;
}
void update_me()
{
	object obj=this_object();
	obj->set("max_qi",100+obj->query("max_neili")/4);
	obj->set("max_jing",100+obj->query("max_jingli")/4);
}
