// dongshang.c ���

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_mo", "mo");
}

void create()
{
	set_name(HIC"���"NOR, ({"quchuang fen", "quchuangfen","fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ƶ�����ҩ�ۣ�ͿĨ(mo)�ڻ������̼�Ч��\n");
		set("value", 2000);
	}
	setup();
}

int do_mo(string arg)
{
	object me = this_player();
	if (!id(arg))
		return 0;
	if (me->is_busy() )
		return notify_fail("�𼱣���������\n");
	if (!me->query_condition("ill_dongshang"))
	{
		write("��������û�б����ˣ����Ķ�Ĩҩ��\n");
		return 1;
	} else {
		me->clear_condition("ill_dongshang");
		message_vision("$N�����Ĩ�ڶ��˵ĵط���������ȥ�˲��١�\n", me);
		me->start_busy(2);
		destruct(this_object());
		return 1;
	}
}
