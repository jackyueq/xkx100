// xuming8wan.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"��������"NOR, ({"xuming bawan", "bawan", "8wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("vegetable", 86);
		set("nostrum", 121);
                set("no_sell",1);
		set("level", 160);
		set("long","���ǻ���һʮ����ʱ�⣬�ɼ�ǧ���˲Ρ����ߡ���֥��¹�ס����ڡ���֬���ܵ������ߡ������������֮����ҩ�������ɹ���Ƴɰ˿����������ġ��������衱���еļ������еļ��࣬�е�����絶��е���������ˡ�ֻҪ�̷����⡰�������衱�����۶����������ˣ���Ȼ����������\n");
		set("value", 0);
	}
	set("pour_type", "1");
	setup();
}

int init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	remove_call_out("destwan");
	call_out("destwan", 60);
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if( !wizardp(me) &&
		(!me->query("dietime") || time()-me->query("dietime") > 600))
	{
		write("�����ڲ��˳����������ˡ�\n");
		return 1;
	}
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	message_vision("$N����һ��" + name() + "��\n", me);
	log_file("eat_dan", sprintf("[%s] %s eat xuming8wan \n", ctime(time()), geteuid(me)));
	me->delete("dietime");
	me->reincarnate();
	me->add("combat_exp",(int)(me->query("combat_exp") / 49));
	me->add("potential",me->query("potential")-me->query("learned_points"));
	//me->add("max_neili", 2);
//	me->set("shen", 0);
//	me->set("score", 0);
//	me->set("meili", 0);
//	me->set("weiwang", 0);
        if ((int)me->query("score")<5000 ) me->set("score", 0);
         else me->add("score", -5000);
	me->skillreincarnate();
	me->start_busy(10);
	destruct(this_object());
	return 1;
}

void destwan()
{
	message_vision("$N�����ɺԻ��ɻң�һ���Ʈ�������ʧ�ˡ�\n",this_object());
	destruct(this_object());
}

