// xiang.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("������", ({"xiang"}));
	set_max_encumbrance(5000);
	set("weight", 100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ�����䣬������Щʲô��������ͷ��\n");
		set("unit", "ֻ");
		set("open_count", 1);
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
}

void init()
{
	add_action("do_open","open");
	add_action("do_open","unlock");
}

int do_open(string arg)
{
	object ob, me = this_player(), obj = this_object();
	if(!arg || arg != "xiang")
		return notify_fail("��Ҫ��ʲô��\n");
	if( !present("tie key", me))
		return notify_fail("���˲��������������\n");
  if (me->is_busy())
  	return notify_fail("��������æ���ء�\n");
	if (query("open_count") > 0)
	{
		message_vision("$N��һ��Կ�״��˴����䡣\n", me);
		add("open_count", -1);

		ob = new("/clone/book/qing9da");
		ob -> move(obj);
		ob = new("/clone/money/gold");
		ob -> move(obj);
		ob = new("clone/jewelry/yubei");
		ob -> move(obj);
		ob = new("clone/jewelry/yudai");
		ob -> move(obj);
		ob = new("clone/jewelry/yufa");
		ob -> move(obj);
		ob = new("clone/jewelry/yujie");
		ob -> move(obj);
//		ob = new("clone/jewelry/yuruyi");
//		ob -> move(obj);
//		ob = new("clone/jewelry/yushou");
//		ob -> move(obj);
		ob = new("clone/jewelry/yuzhan");
		ob -> move(obj);
		me->start_busy(random(9) + 5);
		return 1;
	}
	else return notify_fail("�������Ѿ����ˡ�\n");
}
