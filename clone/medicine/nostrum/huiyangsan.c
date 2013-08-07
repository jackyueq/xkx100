// huiyangsan.c ��������ɢ

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(RED"��������ɢ"NOR, ({"huiyangjiulong san", "san"}));
	set("unit", "��");
	set("vegetable", 14);
	set("nostrum", 46);
	set("level", 90);
	set("long", "����һ����������ɢ��������ɵ�����ʥҩ��\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ( me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") &&
		me->query("neili") >= me->query("max_neili"))
	{
		message_vision("$Nû��Ҫ�Ի�������ɢ��\n",me);
	}
	else
	{
		me->receive_recuring("jing", 200);
		me->receive_recuring("qi", 300);
//		me->set("neili", me->query("max_neili"));
		me->add("neili",150);
		message_vision("$N����һ����������ɢ���е�ȫ��һ��ů����ģ�ʮ�������\n",me);
		destruct(this_object());
	}
	return 1;
}
