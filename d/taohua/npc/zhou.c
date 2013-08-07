// Last Modified by winder on Nov. 17 2000
// zhou.c �һ����ܲ�ͨ

#include <skill.h>;
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

int ask_jieyi();
int ask_jiuyin();
int ask_hubo();
int do_draw(string arg);
int do_fangyuan();
int do_learn(string arg);
string ask_skill1();

void create()
{
	set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "botong" }) );
	set("nickname",	"����ͯ");
	set("title", "ȫ���ɵ�һ������");
	set("long", 
		"����ͷ������ֱ�����أ���ü���룬������Ͷ�������ס�ˡ�\n"
		"���뷢��Ȼ����δȫ�ף�ֻ�ǲ�֪�ж����겻�꣬����Ұ��һ��ë���׵��������ˡ�\n"
		"���ľ�ֹ���红ͯһ����\n");
	set("gender", "����" );
	set("age", 48);
	set("attitude", "peaceful");
	set("apprentice", 1);
	set("str",28);
	set("int",25);
	set("con",27);
	set("dex",29);
	set("max_qi", 4000);
	set("max_jing", 2500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2200000);
	set("score", 500000);

	set_skill("hubo", 250);
	set_skill("force", 200);
	set_skill("xiantian-qigong", 200);
	set_skill("dodge", 200);
	set_skill("jinyan-gong", 190);
	set_skill("unarmed", 200);
	set_skill("kongming-quan", 200);
	set_skill("cuff", 200);
	set_skill("chunyang-quan", 200);
	set_skill("strike", 200);
	set_skill("haotian-zhang", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("quanzhen-jian", 200);
	set_skill("taoism", 50);
	set_skill("literate", 100);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "jinyan-gong");
	map_skill("unarmed", "kongming-quan");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "haotian-zhang");
	map_skill("sword", "quanzhen-jian");
	map_skill("parry", "quanzhen-jian");
	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "haotian-zhang");

	set("rank_info/respect", "����ͯ");
	set("shen_type", 1);
	create_family("ȫ���", 1, "����");
	set("class", "taoist");
	set("no_get",1);

	set("inquiry", ([
		"name"    : "�����ܲ�ͨ�ͺ��ˡ�",
		"rumors"  : "�ұ��Ǹ�����а��������ʮ���꣬ÿ�����һ���������ͷ���",
		"��а"    : "�ǻ�ҩʦ����޳ܵļһƭ���ҵľ�....ȥ����",
		"��ҩʦ"  : "����޳ܵļһƭ���ҵľ�....ȥ����",
		"����ͨ"  :"�ҵ�ʦ���������书��ߵģ���һ�λ�ɽ�۽�ʱ����Ϊ��һ���֡�",
		"������"  :"�ҵ�ʦ���������书��ߵģ���һ�λ�ɽ�۽�ʱ����Ϊ��һ���֡�",
		"�ܲ�ͨ"  : "������ʲô����",
		"����"    : "���Ż���ԧ��֯����˫��....",
		"����"    : "���Ż���ԧ��֯����˫��....",
		"�λ�ү"  : "����ͯ���¶Բ�������û���ټ����ˡ�",
		"������"  : "����ͯ���¶Բ�������û���ټ����ˡ�",
		"�ϵ�"    : "����ͯ���¶Բ�������û���ټ����ˡ�",
		"����ͯ"  : "�Ҿ��ǰ���������ʲô����",
		"����ȭ"  : "����ȭ����ʮ��·���ھ��ǣ��������ɡ���ͨ���Ρ�������Ū��ͯӹ���档",
		"kongming-quan": "����ȭ����ʮ��·���ھ��ǣ��������ɡ���ͨ���Ρ�������Ū��ͯӹ���档",
		"����"    : "�Ǽ�����ǰ������������Ǹ�С������",
		"����"    : "�����ҵĽ����ֵܣ�����Ȼɵ���ĳ����á�",
		"�һ���"  : "��������һ����������Ǹ�С������������������ģ�������������ܲ�����ȫ�ˡ�",
		"��"      : "��Ҫ������",
		"fang"    : "��Ҫ������",
		"Բ"      : "ԲҪ��Բ��",
		"yuan"    : "ԲҪ��Բ��",
                "�����澭" : "�������澭�������Ҵ��ϣ����б���ɱ���һ���ұƳ�ɽ���Ϳ���ȡ�ߣ�\n",
		"˫�ֻ���": (: ask_hubo :),
		"���һ���": (: ask_hubo :),
		"hubo"    : (: ask_hubo :),
		"����"    : (: ask_jieyi :),
		"���"    : (: ask_jieyi :),
		"jiebai"  : (: ask_jieyi :),
		"jieyi"   : (: ask_jieyi :),
		"����"    : (: ask_skill1 :),
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	return;
}

void init()
{
	object ob = this_player();

	add_action("do_fangyuan","fangyuan");
	add_action("do_draw","draw");
	add_action("do_draw","hua");
 	add_action("do_learn","learn");
 	add_action("do_learn","xue");
	::init();
	if (ob->query("family/family_name") == "ȫ���")
	{
		command("angry " + ob->query("id"));
		command("say ��ô�㵽����������ң��������Ҿ�ȥ�ʹ���˵��������ƨ�ɡ�");
	}
}

void kill_ob(object me)
{
	command("chat* crazy " + me->query("id"));
	::kill_ob(me);
}

void unconcious()
{
	command( "chat* ̾��������ͯ������Ҫ�����ˣ�������������ֻ���ܣ���Щ��ͷ���޳���һ���Ƶ�Ī�������ɫ��䡣");
	::unconcious();
}

int accept_object(object who, object ob)
{
	if (ob->query("id") == "du she")
	{
		message_vision("$N�ó�һ������������ͯ����ǰ���˻Σ�����������\n����ͯ�ŵ�����������������⣡���ܱߺ������͸�ˣ�����ͯ�ⷬ�����ˣ�\n\n\n��������Զȥ�����ڲ������š�\n" ,who);
		destruct(this_object());
		return 0;
	}
	return 0;
}

int ask_jieyi()
{
	object ob=this_player();

	if (ob->query("zhou/jieyi"))
	{
		command("? " + ob->query("id"));
		command("say �������ǽ�ݹ�����");
		return 1;
	}
	if (ob->query("age") < 16)
	{
		command( "say �ұ���Ҳ�������ݣ����ֵ������Ǵ��ס�");
		return 1;
	}
	if (ob->query("gender") != "����" && ob->query("gender") != "Ů��")
	{
		if (ob->query("age") > 48) 
			command( "say �ұ���Ҳ�������ݣ����ǲ�֪���ֵ���ƻ��ǽ����ƣ�");
		else
			command( "say �ұ���Ҳ�������ݣ����ǲ�֪���ֵ���ƻ���������ƣ�");
		command("laugh");
		return 1;
	}
	if (ob->query("int") > 25)
	{
		command("shake");
		command("say ������˹��龫������׼����ʲô�����ء�");
		return 1;
	}
	if ((int)ob->query("shen") <= -1000)
	{
		command("shake");
		command("say ����Ȼ������㣬��ʦ��̻岻����������а֮������Ҫ����ġ�");
		return 1;
	}
	command("nod " + ob->query("id"));
	if (ob->query("gender") == "����")
	{
		command("say �ðɣ����Ҿͽ��Ϊ�ֵܰɡ�");
	}
	else if (ob->query("gender") == "Ů��")
		{
		if (ob->query("age") > 48) 
			command("say �ðɣ����Ҿͽ��Ϊ��ܰɡ�");
		else
			command("say �ðɣ����Ҿͽ��Ϊ���ðɡ�");
		}
	message_vision("�ܲ�ͨ��$N�����������˵����������ͯ�ܲ�ͨ��������" + ob->name()+"���������պ��и��������ѹ���������Υ�����ģ������书ȫʧ����С��СèҲ�򲻹�����\n", ob);
	ob->set("zhou/jieyi", 1);
	return 1;
}

int ask_hubo()
{
	object ob=this_player();
	int hubo;

	if( !ob->query("zhou/jieyi"))
	{
		write("�ܲ�ͨ��ֵؿ����㣬�ʵ�������˭ѽ��\n");
		return	1;
	}
	if (ob->query("double_attack"))
	{
		command("? " + ob->query("id"));
		command("say �㲻���Ѿ�ѧ������");
		return 1;
	}
	hubo = ob->query_temp("zuoyou_hubo");
	if (hubo == 22)
	{
		command("say ��������һ�Σ�");
		return 1;
	}
	if (hubo == 1)
	{
		command("say ��������Ϳ����");
		return 1;
	}
	if (hubo > 1 && hubo <= 21)
	{
		command("say ��ô����������ɣ����������Ů����������͸��һ���Ķ�������ʮ�߰˸��ϣ��������Ź�������ʼ��ѧ���ᣡ");
		return 1;
	}
	if (ob->query_skill("force") < 100 ||
		ob->query("max_neili") < 500 ||
		ob->query("combat_exp") < 10000)
	{
		command("say �㻹���ȴ����ѧ������˵�ɡ�");
		return 1;
	}
	command("say ���Ź��������ڶ�������֮ʱ��������������˵�����ѵ�������˵����Ҳ����֮�����е���һѧ��ᣬ�е���һ����Ҳѧ���ˣ�Խ�Ǵ�����Խ�ǲ��ɡ�");
	command("say �����������һ�Σ����ֻ���(fang)�����ֻ�Բ(yuan)��");
	ob->set_temp("zuoyou_hubo", 1);
	return 1;
}

int do_fangyuan()
{
	object ob=this_player();
	int hubo;

	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");
	hubo = ob->query_temp("zuoyou_hubo");
	if (!hubo) return 0;
	if (hubo < 21)
	{
		message_vision("$N�������ʳָ�ڵ��ϻ��������������ķ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 21)
	{
		message_vision("$N�������ʳָ�ڵ��ϻ��������������ķ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
		command("haha " + ob->query("id"));
		command("say ��ô������һ�±�첻����");
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 22)
	{
		if (ob->query("cps") >= 20)
		{
			message_vision("$N΢΢һЦ��������һ���ĵؿ���������������˫����ָ�����ֻ���һ�����飬���ֻ���һ��ԲȦ������������Բ�߻�Բ��\n", ob);
			say( "�ܲ�ͨ���һ�������˰��βŵ������ⶨ�������̥��ѧ���ı��죬�Ǳ��װ��ˡ���\n");
			message_vision("�ܲ�ͨ����������������������ޱȵ��湦��һ���Զ����̸���$N��\n", ob);
			ob->delete_temp("zuoyou_hubo");
			if (ob->query_skill("force") < 100 ||
				ob->query("max_neili") < 500)
				message_vision("��ϧ$N��Ϊ�ڹ���Ϊ���ޣ����ڻ���û����⡣\n", ob);
			else
			ob->set("double_attack", 1);;
			return 1;
		}
		message_vision("$N���������ʳָ�ڵ��ϻ����������������Ծ��Ƿ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
		message_vision("$N���ڷ����Լ���һ����Ҳ���������Ź����ˡ�\n", ob);
		ob->delete_temp("zuoyou_hubo");
		command("disapp " + ob->query("id"));
		return 1;
	}
	return 0;
}

int do_draw(string arg)
{
	object ob=this_player();

	if (!ob->query_temp("zuoyou_hubo")) return 0;
	if (arg == "fang" || arg == "��" || arg == "yuan" || arg == "Բ")
		return notify_fail("�ܲ�ͨŭ��������ͬʱ����Բ��\n");
	if (arg == "fang yuan" || arg == "��Բ") return do_fangyuan();
	return 0;
}

int do_learn(string arg)
{
	object me=this_player();
	string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, rand;

	if (me->is_busy()) return 0;
	if (!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
	{
		write("�ܲ�ͨ���������ֽ�Ӧ���� learn zhou ������\n");
		return 1;
	}
//	if (skill == "hubo") return 1;
	if (teacher != "zhou" && teacher != "botong") return 0;
	if( me->is_fighting() ) return 0;
	if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
		write("��Ҫ��˭��̣�\n");
		return 1;
	}
	if( !living(ob) )
	{
		write("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
		return 1;
	}
	if( !me->query("zhou/jieyi"))
	{
		write("�ܲ�ͨ��ֵؿ����㣬�ʵ�������˭ѽ��\n");
		return 1;
	}
	if (skill != "kongming-quan" && skill != "hubo")
	{
		write("���������±����ұ���ѧ�ˡ�\n");
		return 1;
	}
	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
	{
		write("����"+to_chinese(skill)+"�ϵ������Ѿ���������ͯ�ˣ�\n");
		return 1;
	}
	if( me->query_skill("qimen-wuxing"))
    {
    write("�����ѧ̫�࣬һʱ�޷����"+to_chinese(skill)+"��\n");
		return 1;
	}
	if( !SKILL_D(skill)->valid_learn(me) )
	{
		write("������ʲ��ʺ�ѧϰ"+to_chinese(skill)+"��\n");
		return 1;
	}
	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	rand = random(20);
	if (rand == 4) gin_cost *= 2;
	else if (rand == 15) gin_cost += 4;
	if(me->query("potential") - me->query("learned_points") < 1)
	{
		write("���Ǳ���Ѿ����ӵ������ˣ�û�а취��ѧ�ˡ�\n");
		return 1;
	}

	message_vision("$N��$n����йء�"+to_chinese(skill)+"�������⡣\n", me, ob);
	if( (int)me->query("jing") > gin_cost )
	{
		if(skill == "kongming-quan")
		{
			write( "�ܲ�ͨ��������ӡ����¾������о仰��������ֲ��Ϊ���������ޣ�����֮�á��仧���Ϊ�ң������ޣ�����֮�á���\n");
			write("�ܲ�ͨ���ھ����������ȱ�����ò��ף���ӯ���壬���ò��\n");
		}
		else
		{
			write( "�ܲ�ͨ����������Ķ��ã��������⣬������֮����\n");
		}
		if( (string)SKILL_D(skill)->type()=="martial" &&
			my_skill * my_skill * my_skill / 10 >
			(int)me->query("combat_exp") )
		{
			write("Ҳ����ȱ��ʵս���飬�������ͯ�Ľ��������޷���ᡣ\n");
		} 
		else
		{
			if (rand == 13)
			{
				write( "��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
				write("�����ʲô��ûѧ����\n");
				return 1;
			}
			else if (rand == 5)
			{
				write( "�ܲ�ͨ���������䣬��Ȼ���ͷ�������������������������ĸ��˴�ܿɺã���\n");
				write("�����ֻ��������ˣ��һ��\n");
				return 1;
			}
			else if (rand == 4)
			{
				write( "��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
				write("����㻨�˱�ƽ����һ���ľ�����\n");
			}
			else if (rand == 15)
			{
				write( "��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
				write("����㻨�˱�ƽ����ö�ľ�����\n");
			}
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("����������ͯ��ָ�����ԡ�" + skill_name + "����һ���ƺ���Щ�ĵá�\n");
			else
				write("����������ͯ��ָ�����ƺ���Щ�ĵá�\n");
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} 
	else {
		gin_cost = me->query("jing");
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}
	me->receive_damage("jing", gin_cost );
	return 1;
}
string ask_skill1()
{
	object me = this_player();
	object zhou = this_object();
	
	if (me->query("can_perform/kongming-quan/kongming"))
		return "�����������������������档";

	if (!me->query("zhou/jieyi"))
		return "����˭������ô����ʶ�㣿";

	return teach_perform(this_player(),this_object(),([
                                "perform" : "kongming",				//pfm�Ĵ���������
	                              "name"		: "����",		//pfm������
                                "sk1"			: "kongming-quan",//��Ҫ���书��id
                                "lv1"			: 150,					//��Ҫ���书�ĵȼ�
                                "sk2"			: "unarmed",		//��Ҫ�书sk2��id
	                              "lv2"			: 150,					//��Ҫ�书sk2 �ĵȼ�
	                              "neili"		: 1000,					//��Ҫ��������
	                              "free"		: 1, 						//free=1����Ҫͬһ����
  	                            "shen"		: 50000,					//��Ҫ��shen
	                            "msg1"		: HIY "$N" HIY "ץ��ץͷ��������Ը���ֹ������䣬��"
                     "��˵������С�ӣ��Ұѿھ�˵��������Ȼ������Լ���ȥ"
                     "���������������ˡ���˵���һ�ѽ�$n" HIY "鱵����"
                     "����$n" HIY "�������󹾹�˵�˰��졣" NOR,
	                            "msg2"		: "���ˣ����ˣ�����߰ɡ�",
										
																]));
}