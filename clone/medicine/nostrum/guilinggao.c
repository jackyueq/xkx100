// gao.c ���߸�

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"���߸�"NOR, ({"guiling gao","gao"}));
	set_weight(3000);
	set("unit", "��");
	set("long", "����һ�����ڹ�׺��������óɵĹ��߸࣬�����������١�\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int taoism_limit, jingli_limit;
	object me = this_player();

	taoism_limit = me->query_skill("taoism", 1)*10;
	jingli_limit = me->query("max_jingli");
	
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	me->start_busy(2);
	if ( jingli_limit <= taoism_limit && jingli_limit < 500 )
	{
		write(YEL"�������һ����߸ֻ࣬���þ�����֮��������ֱ�����ڶ�����\n"NOR);
		me->add("max_jingli",20);
		me->add("jingli",20);
	}
	else write("�������һ����߸࣬���Ǻ���ûʲô�á�\n");

	destruct(this_object());
	return 1;
}

