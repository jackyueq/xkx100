// yulusan.c ��¶����ɢ

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIG"��¶����ɢ"NOR, ({"yulu qingxinsan", "yulu", "san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 11);
		set("nostrum", 22);
		set("level", 130);
		set("long","����һ�����̾�Ө����¶����ɢ����˵��Ľ�����ҵ���ҩ����߹�������Ч�ޱȡ�\n");
		set("value", 10000);
		set("no_drop", "�������������뿪�㡣\n");
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;
	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	me->start_busy(2);
	if ( me->query_skill_mapped("force") != "shenyuan-gong" )
	{
		me->add("max_neili", -10);
		message_vision(HIR "$N����һ����¶����ɢ��ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
//		me->unconcious();
		me->start_busy(10);
	}
	else
	{
		if ( (int)me->query_condition("bonze_drug" ) > 0 )
		{
			me->add("max_neili", -1);
			message_vision(HIR "$N����һ����¶����ɢ��ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
		}
		else if ( neili_limit <= force_limit  )
		{
			me->add("max_neili", 1);
			message_vision(HIG "$N����һ����¶����ɢ��ֻ������������ԴԴ���������Ϲ���������\n͸ʮ����¥���鲼��������ȫ������Ȼ��� !\n" NOR, me);
		}
		me->apply_condition("bonze_drug", 60);
	}
	destruct(this_object());
	return 1;
}

