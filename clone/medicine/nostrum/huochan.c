// huochan.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("destguo");
	call_out("destguo", 10);
}
void destguo()
{
	message_vision("$Nȫ��������ڣ�һ�����ͷ�����ˡ�\n",this_object());
	destruct(this_object());
}

void create()
{
	set_name(HIR"���"NOR, ({"huo chan", "chan"}));
	set("unit", "ֻ");
	set("long", "����һֻ����������ɽ���Ļ�󸣬����Ͷ�����Ŀ�ĺ�⡣\n");
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
	if ( neili_limit <= force_limit ) me->add("max_neili", 5);
	me->set("neili",me->query("max_neili"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("eff_qi"));
	message_vision(HIY "$N����һֻ��󸣬ֻ��һ���������ʶ��£��ض���ֱ�����أ�һ������ԴԴ�������뵤�\n"NOR,me);
	destruct(this_object());
	return 1;
}
