// baixianwan.c ������

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"������"NOR, ({"baixian wan", "wan"}));
	set("unit", "��");
	set("vegetable", 36);
	set("nostrum", 25);
	set("level", 70);
	set("pour_type", "1");
	set("long", "����һ�������裬����ȥ�������ģ���͸�����⣬��֪�����˻�...\n");
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

	message_vision(HIG"$N����һ�������裬ֻ����������Ѫ���ڣ���...���Դ�ҩ�ˣ�����\n" NOR, me);
	me->set("qi", 10);
	me->set("jing", 10);
	destruct(this_object());
	return 1;
}
