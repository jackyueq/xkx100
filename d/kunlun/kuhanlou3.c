// Room: /d/kunlun/kuhanlou3.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_out(string arg);

void create()
{
	set("short", "�ຮ¥����");
	set("long", @LONG
�ܿ�͵��˿ຮ¥���㡣������Կ���ɽ���Լ����ߵ��������ɽ
�壬���ܵ�ɼ�����ҡ�ڣ�����������������������ɽ���������������
Զ���ľ�ɫ�������������������ʱ����һ��Ī����į�ĸо���������
�Ĳ���ʮ�ּ򵥡����⿴���и��ܴ�ĺ�ľ��̨(out)��
LONG );
	set("exits", ([
		"down" : __DIR__"kuhanlou2",
	]));
	set("item_desc", ([
		"out" : "��ͻȻ����һ��������ȥ����������ôҲ���Ʋ�ס��\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40130);
	set("coor/z", 110);
	setup();
}

void init()
{
	object me = this_player();

	if (((int)me->query_temp("count")==2)
		&& (int)me->query_skill("dodge", 1) >= 30
		&& (int)me->query_skill("dodge", 1) <= 101)
	{
		me->receive_damage("jing", 30);
		me->improve_skill("dodge", me->query("int"));
	}
	me->start_busy(random(3));
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	int i, jing_cost, qi_cost;

	me = this_player();
	i = (int)me->query_skill("dodge") + random(200);
	jing_cost = 600 / (int)me->query("int");
	qi_cost = 500 / (int)me->query("int");
	if(((int)me->query("jing") < jing_cost) ||
		((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N���ϴ�̨��һ������������ȥ��\n", me);
	me->move(__DIR__"houyuan");
	message_vision("ֻ�����须��һ��$N��¥������������\n", me);
	me->set_temp("last_damage_from", "��¥��������ˤ");

	if ( i < 60)
		me->die();
	else if( i < 120)
		me->unconcious();
	else {
		message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
		if( i > 250
			&& me->query_skill("dodge", 1) < 120 )
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", jing_cost );
		me->receive_damage("qi", qi_cost );
	}
	return 1;
}
