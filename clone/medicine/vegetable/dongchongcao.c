// dongchongcao.c �����

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIB"�����"NOR, ({"dongchong cao", "cao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIB"����һ���ļ��Ӷ����������е��������ϳ����Ķ����Ĳݡ������˷�������Ч��\n"NOR);
		set("value", 2500);
	}
	set("pour_type", "1");
	setup();
}

int do_fu(string arg)
{
	string what = query("cure");
	int howmuch = query("amount");
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣�������С�ı�����ˡ�\n");

	if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
		return notify_fail("����������û���ܵ��κ��˺���\n");
	else {
		me->receive_curing("qi", 150);
		message_vision("$N��һ�궬��ݷŽ����н��飬С�ķ����˿��ϣ���ɫ�������ö��ˡ�\n", me);
		destruct(this_object());
		return 1;
	}
}

