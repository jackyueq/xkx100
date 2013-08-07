//laoban.c �ϰ�
#include <ansi.h>
inherit NPC;
string do_ask();
string do_tool();
string do_abort();
string do_finish();

void create()
{
	set_name("�ϰ�",({"lao ban","lao"}));
	set("long","�����ǻ�ɽ��ʯ�����ϰ壬һ���ܾ��������ӣ�����
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
	
	if (me->query_str()<18 || me->query("combat_exp")<5000)
	return ("����λ"+RANK_D->query_respect(me)+"Ҳ̫�����˰ɣ��������ҿɸ������𡣡�\n");
	if (me->query_temp("caishi/count")>=1)
	return ("����λ"+RANK_D->query_respect(me)+"�����Ѿ��й������𣿲������ͷ����ɡ���\n");
	titles=replace_string( me->query("title"), HIW" ��ʯ����"NOR, "");
	me->set("title",titles);
	me->add("title",HIW" ��ʯ����"NOR);
	me->set_temp("caishi/count",1);
	return("���ðɣ���λ"+RANK_D->query_respect(me)+"���������úøɰɣ���\n");
}

string do_tool()
{
	object me=this_player();
	object ob;
	if (present("hammer",me))
		return ("����λ"+RANK_D->query_respect(me)+"�������Ѿ��й����ˡ�\n");
	ob=new("/clone/weapon/hammer");
	ob->move(me);
	message_vision("�ϰ��$Nһ��������\n",me);
	return ("����λ"+RANK_D->query_respect(me)+"��ѹ����պã���Ū���ˡ���\n");
}

string do_abort()
{
	object me=this_player();
	string titles;
	if (me->query_temp("caishi/count")<1)
		return ("����λ"+RANK_D->query_respect(me)+"��û������������������ҵİɡ���\n");
	titles=replace_string( me->query("title"), HIW" ��ʯ����"NOR, "");
	me->delete_temp("caishi/count");
	me->delete_temp("caishi/finish");
	return("����ʵ��ݹ�Ҳ�ܲ���ģ����ǿ�ϧ����\n");
}

string do_finish()
{
	object me=this_player();
	object ob;
	string titles;
//      if (!strsrch(me->query("title"),HIW"��ʯ����"NOR))
	if (me->query_temp("caishi/count")<1)
		return ("����λ"+RANK_D->query_respect(me)+"ʲôʱ�����������°�����\n");
	if (!me->query_temp("caishi/finish") )
		return ("����λ"+RANK_D->query_respect(me)+"����Ҫ�к��ģ��������ͳ������!\n");
	else 
	{
		titles=replace_string(me->query("title"),HIW" ��ʯ����"NOR, "");
		me->delete_temp("caishi/count");
		me->delete_temp("caishi/finish");	       
//		me->add("potential",2+random(2));
//		me->add("combat_exp",5+random(7));
		me->delete_temp("caishi/finish");
		me->set("title",titles);
		ob=new("/clone/money/silver");
		ob->set_amount(10);
		ob->move(me);
		return("���ţ���λ"+RANK_D->query_respect(me)+"�ɵ����ǲ���������Ĺ�Ǯ�����պ��ˡ���\n");
	}
}
