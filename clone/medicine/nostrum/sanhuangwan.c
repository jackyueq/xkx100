// sanhuangwan.c ���Ʊ�����

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"���Ʊ�����"NOR, ({"sanhuang baolawan", "wan"}));
	set("unit", "��");
	set("vegetable", 104);
	set("nostrum", 51);
	set("level", 140);
	set("value", 10000);
	set("long", "����һ�����Ʊ����裬����ơ��ٻơ��ۻ���ζ��ҩ���Ƴɡ�\n");
	set("pour_type", "1");
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
		me->query("eff_qi") >= me->query("max_qi") )
	{
		message_vision("$Nû��Ҫ�����Ʊ����衣\n",me);
	}
	else
	{
		me->receive_curing("jing", 50);
		me->receive_curing("qi", 100);
		message_vision("$N����һ�����Ʊ����裬�е�����һ�����������ֱ��ȫ�����������\n",me);
		destruct(this_object());
	}
	return 1;
}
