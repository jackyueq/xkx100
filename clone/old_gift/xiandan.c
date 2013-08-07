// Last Modified by winder on Apr. 25 2001
// xiandan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "�ɵ�" NOR, ({ "dan", "xian dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��԰԰���ɵ�����˵���˿�����ǿ������\n");
		set("value", 10000);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

	if (! id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	me = this_player();
	message_vision("$Nһ������������һ��" + this_object()->name() +
		       "��\n", me);
	if (me->query("gift/xiandan") >= 5)
	{
		message_vision("$N��Ȼ�����ۡ�������һ�ء�\n", me);
		tell_object(me, "���������ǳ��Ŀࡣ\n");
	} else
	if (random(5) == 0)
	{
		tell_object(me, "��������ú���ûʲô���á�\n");
	} else
	{
		tell_object(me, HIG "һ�ɻ�����Ȼ����������"
			    "��ͷʹ���ѣ�ǡ�ڴ�ʱһ������֮����Ȼ���𣬶ٸ���̩�ޱȡ�\n");
		me->add("int", 1);
	}

	me->add("gift/xiandan", 1);
	destruct(this_object());
	return 1;
}
