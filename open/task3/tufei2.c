// tufei2.c
#include <ansi.h>;
inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
	set_name("�Ի�����", ({ "picture"}) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"�����Ǵ�����������Ӱ��͵���ٸ�ͨ�������Ҫ����\n");
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_neili", 5000);
	set("dex", 30);
	set("jiali", 500);
	set("combat_exp", 4000000);
	set("attitude", "friendly");
	set("title", "");
	set("str", 20);
	set("con", 20);
	set("int", 20);
	set_skill("dodge", 500);
	set_skill("unarmed",500);
	set_skill("parry", 500);
	set_skill("force",500);
	set_skill("hand", 500);
	set_skill("cuff", 500);
	set_skill("staff", 500);
	set_skill("literate", 500);
	set_skill("yunlong-shengong", 500);
	set_skill("dagou-bang", 500);
	set_skill("changquan", 500);
	set_skill("sanshou", 500);
	set_skill("xiaoyaoyou", 500);

	set("no_see", 1);
	set_weight(5);
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("staff", "dagou-bang");
	map_skill("parry", "dagou-bang");
	map_skill("hand", "sanshou");
	map_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
//	(: perform_action, "blade.duan" :),
		(: exert_function, "recover" :),
	}) );
	setup();
}

void init()
{
	object ob,obj;
	mapping skl;
	string *skillname;
	int maxskill,j;
//      ::init();
	if( interactive(ob = this_player()) && !this_object()->query_temp("bt_in
ited"))
	{
		
	   skl = ob->query_skills();
	   maxskill =10;
	   if (sizeof(skl))
	     { 
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (maxskill < skl[skillname[j]])
				maxskill = skl[skillname[j]];
		}
	     }
		this_object()->set_temp("bt_inited",1);
		obj=this_object();
//	        maxskill=query("maxskill");
		set_skill("dodge", maxskill*3/2);
		set_skill("unarmed", maxskill);
		set_skill("parry", maxskill);
		set_skill("staff", maxskill);
		set_skill("force", maxskill);
		set_skill("cuff", maxskill/2);
		set_skill("hand", maxskill/2);
		set_skill("dagou-bang", maxskill);
		set_skill("changquan", maxskill/2);
		set_skill("sanshou", maxskill/2);
		set_skill("xiaoyaoyou", maxskill*3/2);
		set_skill("yunlong-shengong", maxskill);
		if (!present("tiegun",obj))
			carry_object("/d/xingxiu/obj/tiegun")->wield();
		obj->set("title","̤ѩ�޺�");
		obj->set_weight(500000);
		set_name("��Ӱ��͵", ({ "shen tou","st"}) );
		if (ob->query("id") == obj->query_temp("bt_ownname"))
			obj->kill_ob(ob);
		remove_call_out ("destroy_npc");
		call_out ("destroy_npc", 900); // 15 min
	}
}
void destroy_npc()
{
	message_vision("" + (string)this_object()->query("name") + "��Ȼ���˸����£������������⣬����һ�Σ���ʱ����çç�˺�֮�С�\n", environment(this_object()));
	destruct(this_object());
}
// int active_died()
void die()
{
	object ob,me;
	string own;
	message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
	ob = this_object();
	own = ob->query_temp("bt_ownname");
	if(own) me = find_player(own);
	if ( me && ob->query_temp("last_damage_from")==me)
	{
		if (ob->query_temp("bt_npc")==me->query_temp("bt/npc"))
			me->set_temp("bt/finish",1);
	}
	destruct(this_object());
}


