// cao.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
void create()
{
	set_name(HIG"���Ĳ�"NOR, ({"fuxin cao","cao"}));
	set("unit", "��");
	set("long", "����һ���޸�С�ݣ����ú�С��ȴ����һ���������ٵĸо���\n");
	set("pour_type", "1");
	setup();
}
int do_eat(string arg)
{
	int force_limit, neili_limit;
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	message_vision(HIG "���Ը��Ĳݻ����簾�����ٺȰɡ�\n" NOR, me);
	force_limit = me->query_skill("force",1)*10;
	neili_limit = me->query("max_neili");
	if ( neili_limit <= force_limit )
	{
		me->add("max_neili",5);
		me->start_busy(20);
	}
	message_vision(HIG "$N����һ�긯�Ĳݣ���Ȼ���е������...\n" NOR, me);
	destruct(this_object());
	return 1;
}
