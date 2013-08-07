// /d/city/obj/bing6.c 状元饼

inherit ITEM;
#include <ansi.h>

mapping attr = ([
	"str" : "膂力",
	"con" : "根骨",
	"dex" : "身法",
	"sta" : "耐力",
	"kar" : "福缘",
	"cps" : "定力",
	"per" : "容貌"
]);
	
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(RED "状元饼" NOR, ({"bing6", "chuangyuanbing"}));
	set("unit", "个");
	set("long", "这是一个唯一的状元饼。\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	setup();
}

int do_eat(string arg)
{
	int i;
	object me=this_player();
	
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (!wizardp(me) && query("owner") != me->query("id"))
	{
		write(HIR"你只能吃自个赢来的饼。\n"NOR);
		return 1;
	}
	if(arg=="bing6"||arg=="chuangyuanbing")
	{
		me->add("combat_exp",1968);
		me->add("potential",88);
		i = random(4);
		me->add(keys(attr)[i], 1);
		message_vision(HIY "$N三口两口吃下一块$n。\n" NOR, this_player(), this_object());
		tell_object(me, "你的"HIY + values(attr)[i] + NOR"提升了。\n");
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}

