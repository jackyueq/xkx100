//box.c �ľ�����
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_open", "open");
}

void create()
{
	set_name(MAG"�ľ�����" NOR, ({"li he", "box"}));
	set("unit", "��");
	set("value", 50000);
	set("long", 
"���ǡ�������һ�١���ѩ��רΪ�»�򸾶�������У�
�ľ�Ƶĺ������ž��µĻ��ƣ���ɫ���㡣\n");
	set("gift", 1);

	setup();
}

int do_open(string arg)
{
	object me,gift1;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="box"||arg=="li he")
	{
		if(query("gift") == 1)
		{
			message_vision(HIY "$N�������У���ǰһ�����ۣ��ö�ϲ�ǣ��úó�Ŷ��\n" NOR, me);
			gift1 = new("/d/city/npc/obj/xitang");
			gift1->move(me);
			set("gift", 0);
			me->start_busy(1);
		}
		else message("vision",HIC"����Ѿ����˴򿪹��ˣ�����տյ�ʲôҲû�С�\n" NOR,me);
		return 1;
	}
}

void owner_is_killed()
{
	destruct(this_object());
}
