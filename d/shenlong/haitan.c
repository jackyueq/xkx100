//  /d/shenlong/haitan.c ��̲
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��̲");
	set("long", @LONG
����������ľ�Դ䣬�����ĺ�̲��������ͷ������ѩ�׵�ϸɳ����
��һƬ�ž���������һ�������������Ǵ󺣣�����·���һ��ɽ�壬��
������������ͷ�ĺ�̲�����ϵĿ����ƺ��������ƣ���ʪ�ĺ����д���
һ���ȳ����ּ�����һ�����صĻ��㣬������ʮ�ֹ��졣
LONG
	);
	set("exits", ([
		"east"  : __DIR__"shanlu1",
		"west"  : __DIR__"beach",
		"south" : __DIR__"haitan",
		"north" : __DIR__"haitan",
	]));
	set("outdoors", "shenlong");

	setup();
}

void init()
{
	object me = this_player();
	int damage;

	if( interactive(me = this_player()) &&
		!(me->query("sg/spy") ||
		me->query("family/family_name") == "������") &&
		random((int)me->query_skill("dodge")) < 80 )
	{
		message_vision( HIR "$N����ǰͻȻ����һ���޵׵���Ԩ...$N����������֮�С�\n" NOR, me);
		message_vision( HIR "�����еĸְ�ͻȻð���������ĸ��룬�����������$N��������...\n" NOR, me);
		damage = 100000 / ( 100 + (int)me->query_skill("force"));
		me->receive_wound("qi", damage + random(damage), "��������");
		me->receive_damage("qi", damage + random(damage), "��������");
		me->apply_condition("snake_poison", 50 + random(50) +
		me->query_condition("snake_poison"));
	}
}

