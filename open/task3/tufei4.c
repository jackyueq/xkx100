// tufei4.c
#include <ansi.h>;
inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
	set_name("���뻨��", ({ "picture"}) );
	set("gender", "����" );
	set("age", 34);
	set("long",
	"����һλ����һƷ���о�ѡ�����ĸ��֣����ǵ��书������ͻ��һ�����֡�\n");
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_neili", 5000);
	set("jiali", 500);
	set("combat_exp", 4000000);
	set("attitude", "friendly");
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("title", "");
	set_skill("dodge", 500);
	set_skill("unarmed",500);
	set_skill("parry", 500);
	set_skill("force",500);
	set_skill("hammer", 500);
	set_skill("hand", 500);
	set_skill("cuff", 500);
	set_skill("literate", 500);
	set_skill("changquan", 500);
	set_skill("sanshou", 500);
	set_skill("xiaowuxiang", 500);
	set_skill("riyue-lun", 500);
	set_skill("shenkong-xing", 500);

	set("no_see", 1);
	set_weight(5);
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("hammer", "riyue-lun");
	map_skill("parry", "riyue-lun");
	map_skill("hand", "sanshou");
	map_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
//	(: perform_action, "sword.chan" :),
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
		set_skill("dodge", maxskill*2/3);
		set_skill("unarmed", maxskill);
		set_skill("parry", maxskill);
		set_skill("hammer", maxskill);
		set_skill("force", maxskill);
		set_skill("cuff", maxskill);
		set_skill("hand", maxskill);
		set_skill("riyue-lun", maxskill);
		set_skill("changquan", maxskill*2/3);
		set_skill("sanshou", maxskill*2/3);
		set_skill("shenkong-xing", maxskill);
		set_skill("xiaowuxiang", maxskill);
		if (!present("fa lun",obj))
			carry_object("/d/xueshan/obj/falun")->wield();
		obj->set("title","һƷ��ɱ��");
		obj->set_weight(500000);
		set_name("����ϸ��", ({ "xi zuo","xz"}) );
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
//int active_died()
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

