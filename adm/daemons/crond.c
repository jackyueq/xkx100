// /adm/daemons/crond.c

// Created by Constant Jan 4 2001

#include <globals.h>

inherit F_DBASE;

void init_cron();

void create()
{
        seteuid( ROOT_UID );
        set("channel_id", "������");
        init_cron();
}

void init_cron()
{
        mixed *local;
	int minutes;

        call_out("init_cron", 60);

        local = localtime(time());

	minutes = local[1] + local[2] * 60;

	if (!(minutes % 150)) {
//      if (!((local[1]) % 30) && !(local[2] % 3)) {
                TASK_D->init_dynamic_quest(1);
                CHANNEL_D->do_channel( this_object(), "sys", "ȫ��ʹ�������·��䡣" );
        } else if (!(minutes % 30)) {
		TASK_D->init_dynamic_quest(0);
		CHANNEL_D->do_channel( this_object(), "sys", "����ʹ�������·��䡣" );
	}
}
