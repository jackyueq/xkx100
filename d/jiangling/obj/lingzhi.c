//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIG"��֥"NOR, ({"lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����֥���Ǻ���������������ҩ��\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(arg=="lingzhi") 
	{
		me->set("jing",me->query("max_jing"));
		me->set("qi",me->query("max_qi"));
		message_vision(HIG"$N����һ����֥����ʱ���û�������˻�����\n"NOR,me);
		me->start_busy(1);
		destruct(this_object());
	}
	return 1;
}

