//bing5.c ���ñ�
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL "���ñ�" NOR, ({"bing5", "duitangbing"}));
	set("unit", "��");
	set("long", "����һ���ѳ��Ķ��ñ���\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (query("owner") != me->query("id"))
	{
		write(HIR"��ֻ�ܳ��Ը�Ӯ���ı���\n"NOR);
		return 1;
	}
	if(arg=="bing5"||arg=="duitangbing")
	{
		me->add("combat_exp",868);
		me->add("potential",268);
		me->add("score",1000);
		message_vision(HIY "$N�������ڳ���һ��$n��\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
