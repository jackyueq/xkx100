// Obj: /d/lingxiao/obj/guaishexue.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ITEM;

int do_drink(string);
void init();

void init()
{
	add_action("do_drink", "drink");
	remove_call_out("decay");
	call_out("decay", 180);
}

void create()
{
	set_name( HIR "����Ѫ" NOR , ({"she xue", "blood"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ܹ��ߵ�ѪҺ�������ȳ��������������͵ġ�\n");
		set("value", 1000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);
	set("no_put",1);
	setup();
}

int do_drink(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;
	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
 
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ȣ�С�ı�Ǻ���ˡ�\n");

	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 5);
		message_vision( HIR"$Nֻ��һ�����ߴ��ʺ�ֱͨ�����У�Ȼ���������һ�Ż������������\n" NOR, me);
	}
	destruct(this_object());
	return 1;
}

void decay()
{
	object where = environment(this_object());
	if ( interactive(where) )
		message("vision", MAG"���ž��һ�����ˣ���Ѫ����Ū����һ�������ȳ���\n"NOR, 
			where); 
	else
		message("vision", MAG"���ž��һ�����ˣ���Ѫ����һ�ء�\n"NOR,
			where);
	destruct(this_object());
}