// Last Modified by winder on Sep. 12 2001
// xuezhonglian.c ѩ����

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW "ѩ����" NOR, ({"xuezhong lian", "lian"}));
	set("unit", "��");
	set("long","����һ��������ѩɽ�ϵ�ѩ��������׵Ļ����ϸ��ż��ž�Ө��¶�飬��ɢ���ŵ��������㡣\n");
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

	if ( neili_limit > force_limit ) me->add("max_neili", -10);
	me->add("max_neili", random(10));
	message_vision( HIG"$N����һ��"NOR, me);
	message_vision( HIW"ѩ����"NOR, me);
	message_vision( HIG"����ʱ������̨һ�壬һ������ֱ���ζ�������ͷ��ð��˿˿������\n"NOR, me);
	destruct(this_object());
	return 1;
}
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("destlian");
	call_out("destlian", 10);
}
void destlian()
{
	message_vision("$N�����ɿ�ή����һ����ܻ���ʧ���ˡ�\n", this_object());
	destruct(this_object());
}

