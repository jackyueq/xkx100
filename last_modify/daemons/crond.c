// /adm/daemons/crond.c

// Created by Constant Jan 4 2001

#include <globals.h>

inherit F_DBASE;

void init_cron();

void create()
{
        seteuid( ROOT_UID );
        set("channel_id", "任务精灵");
        init_cron();
}

void init_cron()
{
        mixed *local;

        call_out("init_cron", 60);

        local = localtime(time());

        if (!((local[1]) % 60)) {
                TASK_D->init_dynamic_quest(1);
                CHANNEL_D->do_channel( this_object(), "sys", "全部使命已重新分配。" );
        } else if (!((local[1]) % 19)) {
		TASK_D->init_dynamic_quest(0);
		CHANNEL_D->do_channel( this_object(), "sys", "部分使命已重新分配。" );
	}
}
