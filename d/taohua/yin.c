// Room: /d/taohua/yin.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "��");
	set("long", @LONG
���������ǲ����������̫����һ�ˣ������Ժڰ�Ϊ����������Ϊ
�������Ե������Ϊ����������ɽ֮��ˮ֮��Ϊ����
LONG
	);
	set("exits", ([ 
		"southwest" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8530);
	set("coor/y", -4670);
	set("coor/z", 10);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) {
		local = localtime(time());
		if (local[LT_MDAY] < 16)
			me->set_temp("liangyi", 1);
		else
			me->set_temp("liangyi", -1);
	}
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}
