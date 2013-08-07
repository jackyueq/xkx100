//laoban.c �ϰ�
#include <ansi.h>
#define MIN_EXP 20000
#define MAX_EXP 60000
inherit NPC;
string do_ask();
string do_tool();
string do_abort();
string do_finish();

void create()
{
	set_name("�ƹ�",({"zhang gui","boss"}));
	set("long","�����ǻ�ɽ��ʯ�����ƹ�һ���ܾ��������ӣ�����
���������̣�С�۾��з��ţ�͸���ϻ����������㡣\n");
	set("gender","����");
	set("title",CYN"��ʯ��"NOR);
	set("age",50);
	set("inquiry",([
	      "����" : (:do_ask:),
	      "��ʯ" : (:do_ask:),
	      "work" : (:do_ask:),
	      "����" : (:do_tool:),
	      "tool" : (:do_tool:),
	      "����" : (:do_abort:),
	      "abort" : (:do_abort:),
	      "����" : (:do_finish:),
	      "finish" : (:do_finish:),
	]) );
	set("per",18);
	set("kar",22);
	
	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

string do_ask()
{
	object me=this_player();
	string titles;
	object room;
	object *inv;
	int i;
	
	if (me->query("combat_exp")>=MAX_EXP)
		return("�������Ͳ�Ҫ����С���ǽ����˰ɡ�");
	if (me->query_str()<18 || me->query("combat_exp")<MIN_EXP)
	return ("����λ"+RANK_D->query_respect(me)+"Ҳ̫�����˰ɣ��������ҿɸ������𡣡�");
	if (me->query_temp("caishi/count")>=1)
	return ("����λ"+RANK_D->query_respect(me)+"�����Ѿ��й������𣿲������ͷ����ɡ���");
	room = find_object("/d/huashan/caishi");
	if (!room) room = load_object("/d/huashan/caishi");
	inv = all_inventory(room);
	for (i=0;i<sizeof(inv);i++)
	{
		if (inv[i] != me 
		&& (query_ip_name(inv[i])==query_ip_name(me))
		&& inv[i]->query_temp("caishi/count"))
		return "����Ъ����ɣ������Ѿ����˰�æ�ˡ�";
	}
	titles=replace_string( me->query("title"), HIW"ʯ��"NOR, "");
	me->set("title",titles);
	me->add("title",HIW"ʯ��"NOR);
	me->set_temp("caishi/count",1);
	return("���ðɣ���λ"+RANK_D->query_respect(me)+"���������úøɰɣ���");
}

string do_tool()
{
	object me=this_player();
	object ob;
	if (present("hammer",me))
		return ("����λ"+RANK_D->query_respect(me)+"�������Ѿ��й����ˡ�");
	ob=new(__DIR__"obj/hammer");
	ob->move(me);
	message_vision("�ϰ��$Nһ��������\n",me);
	return ("����λ"+RANK_D->query_respect(me)+"��ѹ����պã���Ū���ˡ���");
}

string do_abort()
{
	object me=this_player();
	string titles;
	if (me->query_temp("caishi/count")<1)
		return ("����λ"+RANK_D->query_respect(me)+"��û������������������ҵİɡ���");
	titles=replace_string( me->query("title"), HIW"ʯ��"NOR, "");
	me->delete_temp("caishi/count");
	me->delete_temp("caishi/finish");
	return("����ʵ��ݹ�Ҳ�ܲ���ģ����ǿ�ϧ����\n");
}

string do_finish()
{
	object me=this_player();
	object ob1;
	string titles;
	int add_exp,add_pot,add_score;
//      if (!strsrch(me->query("title"),HIW"ʯ��"NOR))
	if (me->query_temp("caishi/count")<1)
		return ("����λ"+RANK_D->query_respect(me)+"ʲôʱ�����������°�����");
	if (!me->query_temp("caishi/finish") )
		return ("����λ"+RANK_D->query_respect(me)+"����Ҫ�к��ģ��������ͳ������!��");
	else 
	{
		titles=replace_string(me->query("title"),HIW"ʯ��"NOR, "");
		me->delete_temp("caishi/count");
		me->delete_temp("caishi/finish");	       
//		me->add("potential",2+random(2));
//		me->add("combat_exp",5+random(7));
		me->delete_temp("caishi/finish");
		me->set("title",titles);
		add_exp=60+random(20);
		add_pot=30+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_pot);
		ob1->move(me);	
		tell_object(me,HIW"��õ���:"
			+ chinese_number(add_exp) + "��ʵս���飬"
			+ chinese_number(add_pot) + "��Ǳ�ܣ�"
			+ chinese_number(add_score) + "�㽭��������\n"NOR);
		return("���ţ���λ"+RANK_D->query_respect(me)+"�ɵ����ǲ���������Ĺ�Ǯ�����պ��ˡ���");
	}
}
