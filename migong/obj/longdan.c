
#include <ansi.h>


inherit ITEM;

void create()

{
	set_name(HIG "����" NOR, ({ "dan", "long dan", "longdan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���������ڵ���\n");
                set("value", 10000);
		set("unit", "��");
	}
}


void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        
me = this_player();
        message_vision("$N����һ������" + this_object()->name() +
                       "��\n", me);
        if (random(20) > 11)
        {
                message_vision("$Nֻ�������ƺ���ǿ�ˡ�\n", me);
                me->add("max_neili", 1);
 
        } else
        if (random(20) < 9)
        {
               message_vision("$Nֻ��������ʢ��\n", me);

      me->add("max_jingli", 1);
   } else
        {
                      message_vision("$Nʲô�о�Ҳû�С�\n", me);                }

              destruct(this_object());
	return 1;
}
