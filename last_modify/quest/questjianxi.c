// /clone/quest/questjianxi.c
//last modified by sega 13/4/2000
// Modified by Zeratul Jan 5 2001

//修改成不能帮忙杀
#include <dbase.h>
#include <login.h>
#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
int ask_me(object who);
string * name_msg = ({
	"流氓",
	"进香客",
	"挑夫",
	"家丁",
	"官兵",
	"卖花姑娘",
	"趟子手",
	"小贩",
	"刀客",
	"剑客",
	"游方和尚",
	"江湖豪客",
});

string * long_id = ({
	"liu mang",
	"jinxiang ke",
	"tiao fu",
	"jia ding",
	"guan bing",
	"flower girl",
	"tangzi shou",
	"xiao fan",
	"dao ke",
	"jian ke",
	"seng ren",
	"jianghu haoke",
});

void create()
{
	int i;
	i = random(sizeof(name_msg));
	set_name(name_msg[i], ({ long_id[i] }) );
	set("gender", random(2)>0 ? "女性" : "男性" );
	set("attitude", "friendly");
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("inquiry", ([
		"奸细"    : (: ask_me :),
		"jian xi" : (: ask_me :),
		"jianxi"  : (: ask_me :),
	]) );
	set("no_steal", 1);
	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
int ask_me(object who)
{
	object ob = this_object(), me = this_player();

	if( this_object()->query("owner") == me->query("id"))
	{
		fight_ob(me);
		message_vision(HIY"$N眼中突然闪过惊惧的目光，双眼冒火般瞪着$n，大声喊道："+RANK_D->query_self_rude(ob)+"就是"+ob->query("fname")+"！"+RANK_D->query_rude(me)+"！纳命来吧！\n"NOR, ob, me);

		ob->set("title", "奸细");
		ob->set("name", ob->query("fname"));
	}
	else
		message_vision(HIY"$N眼中寒光一闪，马上又变得漠然了，只是奇怪地看着$n。\n"NOR, ob, me);
	return 1;
}

void init()
{
	 add_action("do_hit","hit");
	 add_action("do_hit","kill");
	 add_action("do_hit","touxi");
	 add_action("do_hit","ansuan");
	 add_action("do_hit","steal");
}

int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	if (!arg || (arg != ob->query("id") && arg != "jianxi") )
		return 0;

	if (!(me->query("quest/thief/name")==ob->query("name")))
	{
		if (userp(me) )    
		{
			tell_object(me,HIW"不是你要抓的人，凑什么热闹！\n"NOR);
			return 1;
		}
		else return 0;
	}

}

