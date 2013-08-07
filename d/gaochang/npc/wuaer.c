// wuaer.c �߶�����

#include <ansi.h>

inherit NPC;
int ask_baozang();
int ask_back();
int ask_wuaer();

void create()
{
	set_name("�߶�����", ({ "wuaer laqi", "wuaer"}));
	set("gender", "����");
	set("age", 45);
	set("long", "������װ��Ū����߶����롣�����ݿ��£����ڳ��ڲ������⣬Ƥ���Ұס�\n");

	set("combat_exp", 150000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"����" : (: ask_baozang :),
		"��ȥ" : (: ask_back :),
		"�߶�����" : (: ask_wuaer :),
		"������" : "�߶�����˵��������һ���ù����ʱ���ټ�������\n",
	]) );


	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_back()
{    
	object ob;
	object me=this_player();
	if ( present("map", me))
	{
		say("�߶�����˵�����ðɣ�����������ȥ���߲��Թ����Ժ���Ҳ��Ҫ���ˡ��´����Ҿ�Ҫɱ���㡣\n");
		me->move("/d/gaochang/entrance");
		return 1;
	}
	else
	{
		say("�߶�����ߵ��������������ܣ���������һ���Ӱ�!\n");
		return 1;
	}
	return 1;
}

int ask_baozang()
{
	say("�߶�����˵�����߲��Թ�һ�����У���һ����������ס�ġ�˵�������ó�һ��·��\n");
	return 1;
}    
int ask_wuaer()
{
	message("vision", HIY "�߶����벪Ȼ��ŭ���ȵ�����Ҳ��ֱ���ҵ����֣�����Ҫɱ���㣡\n" NOR, environment(), this_object() );
	this_object()->kill_ob(this_player());
	return 1;
}

