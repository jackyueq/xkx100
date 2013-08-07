// /clone/quest/questman.c
// Modified by Zeratul Jan 5 2001

#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
void create()
{
	set_name("  ", ({ "betrayer", "pan tu" }));
	set("attitude", "friendly");

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("no_steal", 1);

	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
	 add_action("do_hit","hit");
	 add_action("do_hit","steal");
	 add_action("do_hit","kill");
	 add_action("do_hit","touxi");
	 add_action("do_hit","ansuan");
}

int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	if (!arg || (arg != ob->query("id") && arg != "betrayer") ) return 0;
	if( this_object()->query("owner") == me->query("id")) return 0;
	if (!(me->query("quest/betrayer/name")==ob->query("name")))
	{
		if (userp(me) )    
		{
			tell_object(me,HIW"������Ҫץ���ˣ���ʲô���֣�\n"NOR);
			return 1;
		}
		else return 0;
	}
}

