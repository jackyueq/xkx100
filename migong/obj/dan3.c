inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIR"������"NOR, ({"huolong dan", "dan"}));
	set("unit", "��");
	set("long", "����һ�Ż��������Ծõ��ڵ���\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="dan")
	{
		me->add("max_neili",80);
                		
                message_vision(HIR"$N����һ�Ż�������ֻ��һ�ɻ���֮��ֱ�嵤���������ԴԴ����!\n"NOR,me);

		destruct(this_object());
	}
	return 1;
}
