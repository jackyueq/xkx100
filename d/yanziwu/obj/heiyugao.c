inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIC "���������" NOR, ({"heiyugao"}));
	set("unit", "��");
	set("long", "����һ��ǧ�꼫�������Ƶĵĺ�������࣬��˵������������\n");
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
	this_player()->set_temp("nopoison", 1);
	this_player()->receive_curing("jing", 200);
	this_player()->recieve_curing("qi", 200);
	tell_object(this_player(), HIG "��ֻ��һ���������߾�������ѭ����һ�����죬������������ˣ�\n" NOR );
	destruct(this_object());
	return 1;
}
