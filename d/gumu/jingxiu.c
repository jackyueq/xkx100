// Room: /d/gumu/jingxiu.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short",HIC"ʯ��"NOR);
	set("long", @LONG
�˵ع������Ӵ�������֮�á����Ͻ��м������ţ�������Ĺ������
�ڱ�Ŀ���������ʯǽ( qiang)�Ͽ��Ų�������, ��ϸһ����ԭ����
��¼�������徭�ȹż�����������Ĺ�������������
LONG	);

	set("exits", ([
		"south" : __DIR__"mudao21",
	]));
	set("item_desc", ([
		"qiang" : "ǽ��д���˸��ֹż����֡�\n",
	]));
	set("coor/x", -3190);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{ 
	add_action("do_think", "think");
	add_action("do_think", "lingwu");
}

int do_think(string arg)
{
	mapping fam;
	object me = this_player();

	if ( !living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
	if (arg == "qiang" || arg == "wall")
	{
		if ((int)me->query("jing") < 20 )
			return notify_fail("����ú���,����˯����\n");
		if ( me->query_skill("literate", 1) > 140)
			return notify_fail("���Ѿ���ȫ������ǽ�ϵ����֡�\n");
		if ( me->query_skill("literate", 1) > 10 &&
			me->query_skill("literate", 1) > me->query("combat_exp")/1000)
			return notify_fail("��ľ��鲻�������ܶ���ǽ�ϵ����֡�\n");
		if (me->query("potential", 1) - me->query("learned_points") < 1)
			return notify_fail("��ûǱ���ˣ������ټ�����ϰ�ˡ�\n");
		me->add("learned_points", 1);
		me->receive_damage("jing", 5 + random(10));
		me->improve_skill("literate", random(me->query_int()));
		write("�����ʯ�ڣ��·���������\n");
		return 1;
	}
	return notify_fail("��Ҫ����ʲô��\n");
}

