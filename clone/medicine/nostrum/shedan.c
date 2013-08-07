// shedan.c ���ߵ�
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("decay");
	call_out("decay", 180);
}

void create()
{
	set_name(HIG"���ߵ�"NOR, ({"dan", "she dan"}));
	set("unit", "��");
	set("long", "����һ�����ߵ�������������\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int taoism_limit, jingli_limit;
	object me = this_player();

	taoism_limit = me->query_skill("taoism", 1)*10;
	jingli_limit = me->query("max_jingli");
	
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ( jingli_limit <= taoism_limit ) me->add("max_jingli", 1);
	me->set("qi", me->query("eff_qi"));
	message_vision("$N����һ�����ߵ���ֻ���ö���Ŀ��������������\n",me);
	destruct(this_object());
	return 1;
}

void decay()
{
	object where = environment(this_object());
	if ( interactive(where) )
		message("vision", BLU"���ߵ�ž��һ�����ˣ�Ū����һ�������ȳ���\n"NOR, 
			where); 
	else
		message("vision", BLU"���ߵ�ž��һ�����ˣ���Ѫ����һ�ء�\n"NOR,
			where);
	destruct(this_object());
}
