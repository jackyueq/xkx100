// Last Modified by winder on Sep. 12 2001
// chen-jialuo.c �¼���

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_me();
string ask_ling();
int count=1;

void create()
{
	set_name("�¼���", ({ "chen jialuo", "chen" }));
	set("title", HIR"�컨��"HIG"�ܶ���"NOR);
	set("nickname", HIY"��������"NOR);
	set("long","���������������ĺ컨����ܶ����¼��塣\n��һ���ɸɾ�������ɫ���ۡ�\n��һ��ģ��ֱ�Ǹ������˼ҵ������ӵܣ���������Ŀ�����ǣ���ɷ���������ţ�����˹�ġ�����ٲȻ�Ǹ���鹫�ӡ�\n");
	set("gender", "����");
	set("age", 22);
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali",100);
	set("combat_exp", 3000000);
	set("score", 700000);

	set_skill("force", 200);
	set_skill("honghua-shengong", 200);
	set_skill("dodge", 200);
	set_skill("youlong-shenfa", 300);
	set_skill("hand", 200);
	set_skill("benlei-shou", 300);
	set_skill("cuff", 200);
	set_skill("baihua-cuoquan", 300);
	set_skill("strike", 200);
	set_skill("heisha-zhang", 300);
	set_skill("throwing", 200);
	set_skill("wuying-feidao", 300);
	set_skill("blade", 200);
	set_skill("qiuge-dao", 300);
	set_skill("sword", 200);
	set_skill("luohua-jian", 300);
	set_skill("zhuihun-jian", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("hand", "benlei-shou");
	map_skill("strike", "heisha-zhang");
	map_skill("throwing", "wuying-feidao");
	map_skill("sword", "luohua-jian");
	map_skill("blade", "qiuge-dao");
	map_skill("parry", "luohua-jian");
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("hand", "benlei-shou");

	set("inquiry", ([
		"�컨��" : (: ask_me :),
	]));
	set("chat_chance", 5);	 // ����������� 25%
	set("chat_msg", ({
		"�¼���̾��һ����������....�벻��Ǭ¡�������ֵܣ��������Ǻã�\n",
		"�¼������˵�������Ǻ��˵Ľ�ɽ��һ��Ҫ���������ж������\n",
		"�¼���˵������λ�ֵܣ���Ҫ�������Ǻ컨����\n",
	}) );
	set("no_get",1);
	set("chat_chance_combat", 50); // ս���������������
	set("chat_msg_combat", ({
		"�¼���˵����������ң�׷�����ĺ����Ҷ�Ҫɱ���㣡\n",
		(: perform_action, "sword.beng" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("�컨��", 2, "�ܶ���");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(__DIR__"obj/yaodai")->wear();
	carry_object(__DIR__"obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 50000)
	{
		command( "say �컨���н��Ǹ����ҵ��ĺú��ӣ�����С��Ҳ������ô��");
		command("say ��Ҫ����컨��"+RANK_D->query_respect(ob) + "����ȥɱ�����幷��˵��");
		return;
	}
	command("say ���¶�"+RANK_D->query_respect(ob)+"�������Ѿã��ӽ�������Ǿ���һ�����ˣ�");
	command("recruit " + ob->query("id"));
}

void init()
{
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="chen jialuo")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���컨�����������㣡\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
	add_action("do_say", "say");
        add_action("do_qiecuo","qiecuo");
}

void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "�컨��")&&(!me->query_skill("honghua-shengong",1))&&(me->query("combat_exp")>500000))
        {
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + me->query("id"));
        }
        
}

int do_say(string arg)
{
	if( !arg || arg=="" ) return 0;
 
	if( arg=="��Ҷ�컨����ź") 
	{
		write("�¼���˵��������Ӣ����һ�ҡ�\n");
		message("vision", "�¼����������ԭ�����Լҵ��֣���֪�кμ��̣�\n", this_player());
		set("inquiry", ([
			"�컨��" : (: ask_ling :),
		]));
	}
}
string ask_me()
{
	return RANK_D->query_respect(this_player())+ "���Һ컨�������µ�һ��ר���幷���ԣ���...��...";
}
string ask_ling()
{
	object ob,me;

	if (count == 0) return "�컨���Ѿ�����ȥ�ˣ�\n";
	message_vision(HIR"�¼���˵��������Ҫ�컨���𣿣��Ƚ������У�\n"NOR,this_player());
	ob = this_object();
	me = this_player();
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );

	me->set_temp("fighter", 1);
	ob->fight_ob(me);
	me->fight_ob(ob);
	command("halt");

	if (( (int)me->query("qi")*100 / (int)me->query("max_qi") ) >= 30 )
	{
		ob = new(__DIR__"obj/honghua-ling");
		ob->move(this_player());
		count=0;
		message_vision(HIY"�¼��彻��$Nһ֧�컨�\n"NOR, me);
		return "�ã����Ǻ컨��ֵ���Ҫ�úñ��ܣ�\n";
	}
	else return "�������书�����ƹܺ컨�";	
}

