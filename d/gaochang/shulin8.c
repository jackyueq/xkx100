inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "�߲��Թ�");
        set("long", @LONG
������������ĳ�������ǰ����������������Թ�֮
�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�����ϸ����������
���׺�ǰ������·�϶��е������㼣�����ƺ���ʧ�˷�����
ûͷ��Ӭ�㵽���Ҵ���
LONG);
        set("exits", ([
                "west" : __DIR__"shulin7",
                "east" : __DIR__"shulin14",
                "south" : __DIR__"shulin" + (random(10) + 2),
                "north" : __DIR__"shulin" + (random(10) + 2),
        ]));

        set("outdoors", "gaochang");
        setup();
  //      replace_program(ROOM);
}
void init()
{
        object me = this_player();

        if (userp(me) && random(2) == 0)
				{
        	message_vision(HIR "\n$N"HIR"һ��С�Ĵ����˻��ء�\n\n"+
        											"$N"HIR"ֻ����ͷ��һ����죬һ���ʯ��ͷ���¡�\n\n\n"+
        											"$N"HIR"һ���ҽУ�ʹ�ü���ʧȥ��֪��......\n\n" NOR, me);
        	me->receive_damage("jing",240,"����ʯ������");
        	me->receive_damage("qi",480,"����ʯ������");
        	if (me->query("qi")<0 && me->query("jing")<0)
						{
            me->set_temp("die_reason", "����ʯ������");
						me->die();
						} 
					else if (me->query("qi")<0 || me->query("jing")<0)
						{
							me->unconcious();
						}
				}
}