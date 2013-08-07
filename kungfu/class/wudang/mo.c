// mo.c Ī����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init();
int accept_object(object who, object ob);

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
	set_name("Ī����", ({ "mo shenggu", "mo" }));
	set("nickname", "�䵱����");
	set("long","���������������С���ӡ��䵱����֮ĩ��Ī���ȡ�\n��һ���ɸɾ����Ļ�ɫ���ۡ�\n�����ױ������ϳɣ�Ƣ���ֺ�ֱˬ�����ÿ�����ΰ��������Ũ�ס�\n�书������ޡ������һ��\n");
	set("gender", "����");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 26);

	set("max_qi", 1800);
	set("max_jing", 800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jingli", 1800);
	set("max_jingli", 1800);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 60000);
	set("wudang/raozhi", 1);
	set("first_ask", 1);
	set("set_gocatch", 1);

	set_skill("force", 80);
	set_skill("taiji-shengong", 90);
	set_skill("dodge", 90);
	set_skill("tiyunzong", 120);
	set_skill("unarmed", 80);
	set_skill("taiji-quan", 120);
	set_skill("parry", 90);
	set_skill("sword", 90);
	set_skill("taiji-jian", 120);
	set_skill("liangyi-jian", 120);
	set_skill("wudang-quan", 120);
	set_skill("wudang-jian", 120);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("chat_chance", 20);
	set("chat_msg", ({
	"Ī��������˵������ʯ����ڿ��Դ����ջ�ġ�\n",
	"Ī����б����һ�ۣ�����аħ����Ͳ�����ڵ��ˡ�\n",
	"Ī�����Ժ���˵����ֻ�����䵱�������µ����ڡ�\n",
	"Ī���ȶ�����������������Ա�������Ϊ�������֣�һ��Ҫѧ���¾���\n"
	"Ī����˵��: ��֪�������ϵ�����Ϊʲô���������һ���䵱������\n",
	"Ī����˵��: ��Ϊ�䵱����Ӧʱʱ������Ϊ�ȣ���Ҫ�мǰ���\n",
	"Ī����˵��: ��Ϊ����֮�������Լ��ú�������ɡ� \n",
	"Ī����˵��: �����Ǹ�������֪������ȥ�ˣ��ϴ��ڶ����治Ӧ�������ӵ���\n"
	"Ī����˵��: �´��ټ�������һ���������������ˡ� \n",
	}));
	set("inquiry", ([
		"��ָ�ὣ" : (: ask_me :),
		"raozhi"   : (: ask_me :),
		"������"   : (: ask_me1 :),
		"qingshu"  : (: ask_me1 :),
		"teach"    : (: ask_me2 :),
		"ָ��"     : (: ask_me2 :),
		"ʯ��"     : "��ʯ����ڿ��Դ����ջ�ġ�",
		"���"     : "�����һ��Ҫע�����ܵġ�",
		"������"   : "�Ҷ�ʦѧ�����ˣ����������ĵ�ѧ�ķ���"
	]));

	create_family("�䵱��", 2, "����");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
void init()
{
	object ob, me = this_player();
	
	::init();
	
	if(present("song qingshu", environment(me)))
	{
		command("sigh qingshu");
		call_out("qingshustory", 1, ob);
	}
	if( interactive(ob = this_player()) &&
		ob->query("family/family_name") == "�䵱��" )
		call_out("greeting", 1, ob);
}

void greeting(object me)
{
	command("nod " + me->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob, *obs, me = this_player();
       		                
        if (me->query("can_fight") ) 
   	{
		add_action("do_fight", "fight");
		command ("ok");
		me->delete("can_fight");
		me->set("can_teach", 1);   
		me->set("fight_mo", 1);
		command("fight " + me->query("id"));
		return "��Ȼ�����ץ���˱�����ͽ�����ҿ�����Ե��������������������ְɡ�";
	}
        if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
	{ 
		return RANK_D->query_respect(this_player()) +"����Ҫ�������䵱�ɣ�";
	}
        if (query("first_ask") < 1)
	{
		command ("smile");	
		return "����ָ�ὣ�������䵱�ɵľ�����";
	}
  	add("first_ask", -1);
        me->set("know_raozhi", 1);
        command ("hehe");
	return "��·����ָ�ὣ��ȫ���Ի���������佣�У�ʹ������˸�޳����������Ե��ܡ�";
}

string ask_me1()
{
	mapping fam; 
	object ob, qingshu, *obs, me = this_player();
        
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
	{ 
		command ("hmm");               	
		return RANK_D->query_respect(this_player())+"�� ���������ʲô��ϵ��";
	}	
        if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�䵱��")
	{ 
		command ("hmm");               	
               	return RANK_D->query_respect(this_player())+"�� �벻Ҫ�����Ǹ�������";
	}
	if (query("set_gocatch") < 1)
	{
		command ("hmm");	
		return "�Ҳ����������Ǹ�������";
	}
  	add("set_gocatch", -1);
        me->set("set_gocatch", 1);
        command ("sigh ");
        return "�ϴβ�С�ı��Ǹ����������ˣ�����ʦ�Ų��ҡ�ֻ��ϧ�Դ��ϴ��ڶ��ұ������ߺ�һֱ�Ҳ�������";
}

int do_fight(string arg)
{
	int i;
	object ob, *inv, me = this_player();

	if ( !arg ) return 0;
	ob = present(arg, environment());
	if (!objectp(ob)) return 0;
	if (me->query("fight_mo", 1)) 
	{       
		tell_object(me,HIR "�����Ҫ��Ī���������ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
		message("vision", HIR"�����Ҫ��Ī���������ಫ������Ҳ���������һ�� kill ָ�\n������Ī������ɱ��" + me->name() +"\n"NOR, environment(), this_object() );
		fight_ob(this_player());
		add_action("do_halt", "halt");	
		add_action("do_kill", "kill");
		me->delete("fight_mo");
		me->set("halt_mo", 1);
		return 1;
	}
}

int do_halt()
{
	object obj=this_object(), ob = this_player();

	if ( ob->query("halt_mo", 1) )
	{
		ob->delete("halt_mo");
		command("sigh"); 
		command("halt");
		command("say ��Ȼ��ˣ����߰ɡ���û��ʲô�ý���ġ�");
		return 1;
	}
}

int do_kill(string arg)
{
	int i;
	object ob, *inv, me = this_player();

	if ( !arg ) return 0;
	ob = present(arg, environment());
	if (!objectp(ob)) return 0;
	if ((string)(me->query("family/family_name")) == "�䵱��" &&
		ob->query("id") == "mo shenggu" )
	{
		message_vision("$N��ɱ��$n��\n$n������$N�������ұ�ͬ�ţ�ȴΪ�����຦���ң�\n$n������$N�����������ѧ������ָ�ὣ����\n$n��$N�ܲ����⣡\n" , me, ob);
		command ("sigh");
		command ("disapp");
		ob->delete("halt_mo");
		me->delete("can_fight");       
		me->add("wudang/offerring", -20);
		return 0;    
	}
}

int accept_object(object who, object ob)
{
	object obn;

	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, who) ) return notify_fail("��û�����������");
	if (who->query("know_raozhi") < 1) 
		return notify_fail("����ô������Ū�������ˣ�");
	if (who->query("set_gocatch") < 1) 
		return notify_fail("�����ʲô��");
	if (  (string)ob->query("id") == "song qingshu" )
	{		
		who->delete("set_gocatch");
		who->add("can_fight", 1);
		who->add("wudang/offerring", 10);
		command	("thumb");
		command("touch " + (string)who->query("id")); 
		command("say" + RANK_D->query_respect(who) + "лл�����ץ���������ͽ�� \n");
		return 1;
	}
        command("? " + who->query("id"));
        return 0;
}

string ask_me2()
{
	mapping fam; 
	object ob, qingshu, *obs, me = this_player();
 
	if ((int)me->query("can_teach", 1) < 1)
	{
		command ("hmm");
		return "�������ʲô��";
	}
	if ((int)me->query_skill("sword", 1) < 180)	
	{
		me->delete("can_teach");
		command ("hmm");	
		return "��Ľ�������̫ǳ��������ѧ����ָ�ὣ��";
	}
	if ((int)me->query_skill("force", 1) < 180)	
	{
		me->delete("can_teach");
		command ("hmm");	
		return "����ڹ����̫ǳ��������ѧ����ָ�ὣ��";
	}
	me->set("wudang/raozhi", 1); 
	me->add("wudang/offerring", 10);        
	me->delete("can_teach");
	command ("ok");
	command ("say" + "���֪��Ʒ��������ģ�����Ҫѧ�ҾͰѡ���ָ�ὣ����������ɣ�\n");
	if (!me->query("perform/raozhi"))
	{
		me->set("perform/raozhi",1);
		me->add("perform/number",1);
	}
	return HIW"��ϲ��ѧ���ˡ���ָ�ὣ����\n"NOR;
}

