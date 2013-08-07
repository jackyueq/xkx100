// xiongdan.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("destdan");
	call_out("destdan", 10);
}

void destdan()
{
	object ob;
	message_vision("$N�������紵�ţ�һ��Ͳ��������ˡ�\n",this_object());
	ob = new("/clone/medicine/vegetable/xiongdan");
	ob->move(environment(this_object()));
	destruct(this_object());
}

void create()
{
	set_name(HIG"�����ܵ�"NOR, ({"dan", "xiong dan"}));
	set("unit", "��");
	set("long", "����һ������ɫ�������ܵ����������ڵģ�ʮ�����ˡ�\n");
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

	if ( neili_limit <= force_limit ) me->add("max_neili", 2);
	me->set("neili", me->query("max_neili"));
	me->set("qi", me->query("eff_qi"));
	message_vision("$N����һ�������ܵ���ֻ���þ���������������ԴԴ��������Ѫ��ӯ��\n",me);

	destruct(this_object());
	return 1;
}
