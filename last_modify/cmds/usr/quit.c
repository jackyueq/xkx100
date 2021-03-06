// /cmds/usr/quit.c
// Modified by Zeratul Jan 5 2001

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "离线指令");
	set("id", "quit");
	set("channel_id", "离线精灵");
}

int main(object me, string arg)
{
	int i, t, e, p;
	string ct, ce, cp;
	object *inv, link_ob, ob;

	if( time() - me->query("last/lastquit") < 30 && !wizardp(me))
		return notify_fail("你离上次离开游戏的时间间隔不足，暂时无法离开游戏。\n");
	if( LOGIN_D->get_madlock()) 
		return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");
	if( me->is_busy()) return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("身上带的东西太多了，离不开游戏了。\n");

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				// Added by zeratul 2001-1-1
				if ( stringp( inv[i]->query( "money_id" ) ) )
					destruct( inv[i] );
				else
					DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
// 巫师隐身退出时不记 last_login
		if(wizardp(me) && me->query("env/invisibility") )
		{}
		else
		{
			link_ob->set("last_on", time());
			link_ob->set("last_from", query_ip_name(me));
			link_ob->save();
		}
		destruct(link_ob);
	}
	t=time()-me->query_temp("nowtime");
	e=me->query("combat_exp")-me->query_temp("nowexp");
	p=me->query("potential")-me->query_temp("nowpot");
	ct=chinese_number(t/3600)+"小时"+chinese_number(t%3600/60)+"分钟"+chinese_number(t%60)+"秒";
	ce=chinese_number(e);
	cp=chinese_number(p);
	log_file( "USAGE", sprintf("%s (%s) logout with %d second, %d exp, %d pot.\n", me->query("name"), me->query("id"), t, e, p));

	write("你共停留了"+ct+"，长了"+ce+"经验，和"+cp+"点潜能。\n");
	write("欢迎下次再来！\n");

	message("system", me->name() + "离开游戏。\n", environment(me), me);
	CHANNEL_D->do_channel(this_object(), "sys",
me->name() + "(" + me->query("id") + ")离开游戏了。
共停留了"+ct+"，长了"+ce+"点经验，和"+cp+"点潜能。共清除 "+reclaim_objects()+" 个变数。\n");
	me->set("last/lastquit", time());
	me->save();

//************* Added these for update topten ***********
        if( userp(me) )
                if( !wizardp(me) )
                {
                        ob=new("/clone/topten/magic-rice");
                        ob->movein(me);
                        ob->savetopten(me);
                        destruct( ob );
                }
//************* End of added ******************

	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit | exit

当你(你)想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
