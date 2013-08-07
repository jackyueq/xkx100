// shengjingdan.c ������

inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIG"����������"NOR, ({"shengjing dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ű���ɫ�ĵ�ҩ������ȫ���챦��\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
	}
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

	if ( (int)me->query_condition("quanzhen_drug" ) > 0 )
		return notify_fail("���Ƿ������ҩ��ŷ�ʳ�˵�ҩ�����ȫ����Ѫδ��λ�����˳Ե�ҩ��\n");

	if ( me->query_skill_mapped("force") != "xiantian-qigong" )
	{
		me->add("max_jingli", -10);
		message_vision(HIR "$N����һ��������������ֻ���ø�ʹ�����ȫ���类������Ŀ��顣ԭ���˵������������ڹ������������Ԫ��\n" NOR, me);
		me->start_busy(10);
	}
	else
	{
		me->start_busy(2);
		if ( jingli_limit <= taoism_limit  )
		{
			me->add("max_jingli", 1);
			message_vision(HIG "$N����һ��������������ֻ�������ھ���ԴԴ������ȫ���ʱ�����泩�ޱȣ�\n" NOR, me);
		}
		else
			message_vision(HIG "$N����һ��������������Ҳû������ʲô�о���\n" NOR, me);

		me->apply_condition("quanzhen_drug", 50);
	}
	destruct(this_object());
	return 1;
}

