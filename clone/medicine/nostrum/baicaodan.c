// baicaodan.c �ٲݵ�

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIG"�ٲݵ�"NOR, ({"baicao dan", "dan"}));
	set("unit", "��");
	set("vegetable", 36);
	set("nostrum", 25);
	set("level", 70);
	set("pour_type", "1");
	set("long", "����һ������͸���İٲݵ������ǿɰ���\n");
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

	if ( me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi"))
	{
		message_vision("$Nû��Ҫ�԰ٲݵ���\n",me);
	}
	else
	{
		me->receive_curing("jing", 50);
		me->receive_curing("qi", 100);
		message_vision("$N����һ���ٲݵ���������򣬽�������������\n",me);
		destruct(this_object());
	}
	return 1;
}
