// Room: /d/nanshaolin/gygu.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","��Ԫ��");
	set("long", @LONG
�߳�ʯ�ң�ֻ����һ���֮�ڡ�ǰ��һ���߷���·���εض���ֱ
����롣���ܷ��Ͷ���������Ҿ�������ڲ���ʮĶ��Բ���棬������ʯ��
���겻ͬ����Ƥ���ף�����֦�������ٷ��ȥ��
LONG );
	set("exits", ([
		"southeast" : __DIR__"xclang",
	]));
	set("outdoors","nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_chop","kan");
}
int do_chop(string arg)
{
	object weapon, me=this_player();
	int lvl, exp;

	lvl = me->query_skill("ranmu-blade", 1);
	exp = me->query("combat_exp");
	weapon=me->query_temp("weapon");
	if (!arg) return 0;
	if (arg!="tree") return 0;
	if (!(me->query("pass_xin"))) return 0;
	if (!weapon || weapon->query("id") != "chai dao")
		return notify_fail("��Ҫ�ò�������\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����ú��ۣ�ȫ��û������\n");
	if ((int)me->query("neili",1) < 100)
		return notify_fail("�������������\n"); 
	message_vision (RED"$Nʹ���񵶶�׼�±߹��ɣ�һ������ȥ��\n��ľ���ͣ���������֮�£������Ľ�������\n�ٰ�ȼ��֮����\n" NOR,me);
	me->receive_damage("qi", 50);
	me->add("neili", -50);
	if (lvl*lvl*lvl/10 < exp)
	{
		me->improve_skill("ranmu-blade", ((int)me->query_skill("blade",1))/4);
	}
	return 1;
}

