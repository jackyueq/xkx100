// Room: /heizhao/shiliang1.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
˳��ɽ·��ǰ��ȥ���в���ʱ��ɽ·�͵��˾�ͷ��ǰ��������
Լ�����ʯ�������������ɽ��֮�䣬�������֣���������������
ʯ��������ȣ���˵���ߣ�ֻ��һ��Ҳ���⵨ս�ľ���
LONG );
	set("outdoors", "taoyuan");
	set("exits", ([
		"southdown"  : __DIR__"shanding",
		"north"      : __DIR__"shiliang2",
	]));
	set("coor/x", -5020);
	set("coor/y", -1250);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv, ob;
	int i;

//	if(wizardp(me)) return 1;

	inv = all_inventory(me);
	if( !sizeof(inv) )
	{
		message_vision(HIW "$N��ʯ���ϻ���һ�£���������������Ԩ��\n" NOR,me);
		return notify_fail("");
	} else
	{
		switch( random(5) )
		{
			case 0: 
				for (i = 0; i < sizeof(inv); i++ )
				{
				if(inv[i]->query("id")=="huangbu xiaonan")
					{
message_vision(HIM "$N��ʯ����һ�Σ����ϵ�"+inv[i]->name()+"������������Ԩ֮�У�\n" NOR,me);
						destruct(inv[i]);
					}
				}
				break;
			case 1: 
message_vision(HIR "$N��ʯ���ϻ������£�һ��µ������Ԩ��\n" NOR,me);
				me->move(__DIR__"shanlu6");
message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
				return notify_fail(HIR"���ʯ���Ϲ�������ֻ���û�����ʹ��\n"NOR);
				break;
			default: 
message_vision(HIW "$N��ʯ���ϻ���һ�£���������������Ԩ��\n" NOR,me);
				break;
		}
        }
	return 1;
}