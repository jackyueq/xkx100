// jujingdan.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"����۾���"NOR, ({"jujing dan", "dan"}));
	set("unit", "��");
	set("vegetable", 68);
	set("nostrum", 14);
	set("level", 80);
	set("long", "����һ���䵱���������õĵ�ҩ��\n");
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
	me->set("qi",me->query("eff_qi"));
	message_vision("$N����һ������۾������پ����������Ѫ��ʢ��\n",me);

	destruct(this_object());
	return 1;
}
