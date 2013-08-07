// Room: /d/nanshaolin/kuhuiping.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"���ƺ"NOR);
	set("long", @LONG
������һ��ԭ�����Լ�����һ���±�֮�ϣ���������вع��֣���
���������ɣ������޼ʡ��ұڼ���ż�����Ұ�����������١��ұ���
�����Ӳ������������쳣�վ��������ʦ���긺��˽�����³��ߣ�����
�Դ��ܾ���ȥ����������������һ�ɡ���˵������ɮ�ѽ��ܾ��¾�����
�˴����޳�·��ֻ�൱�����ʹ�������Ұ�����������ˡ�
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("outdoors","nanshaolin");
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_pan","pan");
}
int do_pan(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("leg", 1), exp = me->query("combat_exp");
	if (arg!="teng") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"˫����ס�����٣���Ұ����ȥ��\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"������������ֻ��סһ�±䱻ˤ�ѡ�\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"�㾭�鲻�㣬ֻ��סһ�±䱻ˤ�ѡ�\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"��˫����δ�ʵ��������ѽ�����Ʈ����С����\n"NOR);
		return 1;
	}
	if (lvl >= 30 && lvl <= 100&&arg=="teng" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("leg", (me->query("int"))*3/2);
		write(HIR"��˫��һ������ס�����٣�ȫ���������������С�������Ծ��������о�����\n"NOR);
		return 1;
	}
}

