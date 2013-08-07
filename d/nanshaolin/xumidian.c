// Room: /d/nanshaolin/xumidian.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", CYN"���ֵ�"NOR);
	set("long", @LONG
һ����ķ���ıڿյ����ģ�������һ����ʯ���磬����һ��
�������Ƶ��շ壬�������ƣ����������һö���ӡ�����ȡ�������
����֮��ʣ�����Ϊ�ɽ�����֮���������֮�С�����ǰ���ż���
���ţ���λɮ�����Զ������練�����ӣ������ڹ���
LONG );
	set("exits", ([
		"east" : __DIR__"dabeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
}

void init()
{
	this_player()->set_temp("ns_times", 10);
	add_action("do_neishi", "neishi");
}

int do_neishi()
{
	object ob, me = this_player();
	int lvl = me->query_skill("force", 1), exp = me->query("combat_exp");

	me->add_temp("mx_times", -1);	
	message_vision("$N��ϥ���±�Ŀ�������ص��������ڹ���\n", me);
	if ((int)me->query("jing")<20)
	{
		write(RED"��̫���˾����޷����С�\n"NOR);
		return 1;
	} 
	if (lvl >= 30 && lvl <= 100 && present("xisui", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("force", me->query("int"));
		tell_object(me, RED"�����Ӿ���һ����Ϣ�����ǣ��м�����Ԫ��ʯ��ֱͨ���ϡ�\n����һ��С�������������������С�\n"NOR);
	}
	else tell_object(me,RED"��Խ��Խ��Ϳ����Ϣ�Ҵܣ�ֻ��վ��������\n"NOR);
	return 1;
} 

int valid_leave(object me, string dir)
{
	if(me->query_temp("mx_times") >= 0 ) me->delete_temp("mx_times");
	return ::valid_leave(me, dir);
}
