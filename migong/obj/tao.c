inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIR"����"NOR, ({"xian tao", "tao"}));
	set("unit", "ֻ");
	set("long", "�������ؾ������������ң���Ϊ���\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="tao")
	{
		me->add("max_neili",5);
		me->set("neili",me->query("max_neili"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("eff_qi"));
                message_vision("$N����һ�����ң�ֻ���þ���������Ѫ��ӯ����������ԴԴ����!\n",me);

		destruct(this_object());
	}
	return 1;
}
