// hua3.c

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR "�ϳ���" NOR, ({"hua3","duanchang"}));
	set("unit", "��");
	set("long", "����һ��ϳ�����ͨ��ͨ�죬�������Σ������쳣��\n");
	set("no_get", "��������ҽ�ǰ��\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(random(2)==0) this_player()->unconcious();
	else this_player()->die();
	destruct(this_object());
	return 1;
}
