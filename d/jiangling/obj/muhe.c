//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"ľ��"NOR, ({"mu he", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"��ľ�й��ӵ��ţ������ģ�����Ҳ����ʲô��������¡�\n"NOR);
		set("unit", "��");
		set("open_count", 1);
		set("weight", 20000);
	}
}

void init()
{
	add_action("do_open","open");
}
int do_open()
{
	object ob, me = this_player();
	if (query("open_count") > 0 && uptime() > 300)
	{
		add("open_count", -1);
		ob = new(WEAPON_DIR"treasure/yuewang-jian");
		if ( ob->violate_unique() )
		{
			destruct( ob );
  		ob = new(__DIR__"muhe1");
	  	ob -> move(me);
	  	destruct(this_object());
			message_vision("ľ����ʲôҲû�У�$N����̾�˿�����\n",me);
			return 1;
		}
		message_vision(HIR "$N���ִ�ľ�У�ֻ���������������澹�ǰѾ���������\n" NOR, this_player());
		ob -> move(me);
		ob = new(__DIR__"muhe1");
		ob -> move(environment(this_object()));
		destruct(this_object());
		return 1;
	}
	ob = new(__DIR__"muhe1");
	ob -> move(me);
	destruct(this_object());
	return notify_fail("ľ���Ѿ������˴򿪹��ˡ�\n");
}