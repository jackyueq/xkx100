inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "ѩ��" NOR, ({"xue lian", "lian"}));
        set("unit", "��");
        set("value", 250000);
	set("long", "����һ��ǧ���ѵ�һ����ѩ������˵�ܽ�ٶ���\n");
        setup();
}

int do_eat(string arg)
{
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="lian") 
	{
		this_player()->set_temp("nopoison", 1);
		this_player()->set("eff_jing",this_player()->query("max_jing"));
		this_player()->set("jing",this_player()->query("max_jing"));
		
		tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
		destruct(this_object());
	}
	return 1;
}
