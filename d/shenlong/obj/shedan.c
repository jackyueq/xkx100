inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name("���ߵ�", ({"fushe dan","dan"}));
        set("unit", "ö");
	set("long", "����һö���ĸ��ߵ���\n");
	set("value", 500);
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
this_player()->unconcious();
destruct(this_object());
return 1;
}
