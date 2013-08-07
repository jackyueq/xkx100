 //liwenxiu.c ������

#include <ansi.h>

inherit NPC;
int ask_supu();
int ask_parent();
int ask_gaochang();
void dest(object ob);

void create()
{
	set_name("������", ({ "li wenxiu", "li", "wenxiu" }));
	set("gender", "Ů��");
	set("age", 18);
	set("long", "�������崿���㣬��ȻһЦ������������Ȼ�Ķ���\n");

	set("combat_exp", 100000);
	set("shen_type", 1);
	set("per", 28);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);
	set("map_count", 1);

	set_skill("force", 40);
	set_skill("sword", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	set("inquiry", ([
		"����" : (: ask_supu :),
		"supu" : (: ask_supu :),
		"��ĸ" : (: ask_parent :),
		"parent" : (: ask_parent :),
		"�߲���ͼ" : (: ask_gaochang:),
		"�߲��Թ�" : (: ask_gaochang :),
		"map" : (: ask_gaochang:),
	]) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_supu()
{
	say("��������Ȼ��˵�������Ҷ�ʱ�Ļ�飬�����ںͰ�����һ���ˣ�\n");
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int ask_parent()
{
	object map;
	object me = this_player(); 
	if ((int)this_player()->query_temp("marks/��1"))
	{
		say("���������ʵ�˵�����ҵĸ�ĸ�Ǳ����˺����ģ������������Ǽҵĸ߲���ͼ��\n��һ��Ҫ���г��ˣ�Ϊ�Ҹ�ĸ����\n");
		me->set_temp("marks/��2", 1);
		return 1;
	}
	else
	{
		say("������˵������ĸ֮�𣬲������졣\n");
		return 1;
	}
}

int ask_gaochang()
{
	object map, me = this_player(), ob = this_object();
	int exp,pot,score;
	if (query("map_count") < 1)
	{
		say("������һ㶣�æ������ͼ����û˵��ʲô��ͼ����\n");	
		return 1;
	}
	if ((int)me->query_temp("marks/��2"))
	{
//		say( "������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ�\n���ҾͰѵ�ͼ�͸���ɡ��㿴���߲��Թ�������ʲô��\n");
//  	map=new("/d/gaochang/obj/map");
//		map->move(me);
//		add("map_count", -1);
		say( "������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ�\n�ҰѸ߲���ͼ�������ˣ���ȥ�����ɡ�\n");
    me->set_temp("marks/��3",1);
	}
	else
	{
		message("vision", HIY"�����㲪Ȼ��ŭ���ȵ�����Ҳ�����Ҹ�ĸ�ĸ߲���ͼ�����Ҹ���ƴ�ˣ�\n"NOR, environment(), this_object() );
		ob->kill_ob(me);
		me->delete_temp("marks/��1");
		me->delete_temp("marks/��2");
	}
	return 1;
}
int accept_object(object me,object ob)
{
	object li=this_object();
	object map;
	int exp,pot,score;
	if (!me->query_temp("marks/��3"))
	{
		command("shake");
		command("say ��үү˵���ܱ��˵�̰ͼ���");
    return 0;
	}
  if (ob->query("id")=="shou juan"&& ob->query("blood_soaked")>=2)
  {
  	call_out("dest",0,ob);
  	if (!ob->query("owner") || ob->query("owner")!=me->query("id"))
  	{
  		message_vision("$N��Ȼ��ŭ��������͵��������־\n",li);
  		me->fight_ob(li);
  		li->kill_ob(me);
  		return 1;
  	}
    message_vision("$N���У��ⲻ���Ǹ߲���ͼ��\n",li);
    map=new(__DIR__"obj/map");
		map->move(me);
		ob=new(__DIR__"obj/shoujuan2");
		ob->move(me);
		li->add("map_count", -1);
	  if (!me->query("skybook/baima/map"))
  	{
  	 me->set("skybook/baima/map",1);
  	 exp=500+random(1000);
     pot=exp/2;
     score=pot/2;
     me->add("combat_exp",exp);
     me->add("potential",pot);
     me->add("score",score);
     	tell_object(me,HIC"��ɹ��õ��˸߲���ͼ��\n�����������������"+
     	         chinese_number(exp)+"�㾭�顢"+
               chinese_number(pot)+"��Ǳ���Լ�"+
               chinese_number(score)+"�㽭��������\n\n"NOR);
  	}	
  	return 1;
  }
  return 0;
}
void dest(object ob)
{
	destruct(ob);
}