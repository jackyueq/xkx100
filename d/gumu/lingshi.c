// Room: /d/gumu/lingshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"����"NOR);
	set("long", @LONG
ֻ���տտ�����һ�������ϲ��з������ʯ�ס�����ϸ����������
ʯ�׹׸������ܸ��ţ�ԭ���ǹ�Ĺ����ʦ�ֳ�Ӣ��С��Ůʦ���İ���֮
����������ߵĹ׸�(guangai)ȴֻ����һ�룬Ҳ��֪��������ʬ�塣
LONG	);

	set("exits", ([ 
		"out" : __DIR__"shishi5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -40);
	set("coor/z", 80);
	setup();
}

void init()
{
	add_action("do_tui", "tui");      
	add_action("do_tang","tang");
}

int do_tui(string arg)
{
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg =="guangai")
	{
		message_vision(YEL"$Nʹ���ƿ��˹׸ǡ�\n"NOR,me);
		me->set_temp("marks/ʯ��", 1);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_tang(string arg)
{
	object me=this_player();       

	if (!me->query_temp("marks/ʯ��")) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg =="guan")
	{
		me->delete_temp("marks/ʯ��");
		me->move(__DIR__"shiguan");
		message_vision(HIY"$N�ɽ���ʯ�ף���������ת���ŵء�\n"NOR,me);
		return 1;
	}
	return notify_fail("�����������\n");
}
