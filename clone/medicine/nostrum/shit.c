// shit.c ��ʺ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(YEL"��ʺ"NOR, ({"shit"}));
	set("unit", "��");
	set("value", 0);
	set("long", "����һ�ѳ���ʺ����֪����˭���ġ�\n");
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

	if(arg=="shit") 
		return notify_fail("����Ҳ�ܳԣ���������������\n");
	me->start_busy(2);
	return 1;
}
