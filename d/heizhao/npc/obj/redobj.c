// item: redobj.c

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(HIR"�첼С��"NOR, ({"hongbu xiaonan", "xiaonan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ�첼С�ң���֪����ʲô�ô���\n");
		set("unit", "ֻ");
		set("value", 1);
	}
}

void init()
{
	add_action("do_chaikai", "chaikai");
}
int do_chaikai(string arg)
{
	object bu, me = this_player();
	string message;
	int col;

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N�𿪺첼С�ң�̯���������ź첼��\n", me);
	bu = new(__DIR__"redcloth");
	bu->move(me);
	destruct(this_object());
	return 1;
}

