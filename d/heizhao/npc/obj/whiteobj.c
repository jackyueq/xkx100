// item: whiteobj.c

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(HIW"�ײ�С��"NOR, ({"baibu xiaonan", "xiaonan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ�ײ�С�ң�������Դ򿪵ġ�\n");
		set("unit", "ֻ");
		set("value", 1);
	}
}
void init()
{
	add_action("do_dakai", "dakai");
}
int do_dakai(string arg)
{
	object bu, me = this_player();
	string message;
	int col;

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N�𿪰ײ�С�ң�̯���������Űײ���\n", me);
	bu = new(__DIR__"whitecloth");
	bu->move(me);
	destruct(this_object());
	return 1;
}

