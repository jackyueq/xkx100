// shouwu.c ������

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name("������", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó������εĺ����ڡ�\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

//	this_player()->add("max_neili", 10);
	this_player()->set("eff_qi", this_player()->query("max_qi"));
	message_vision("$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n", this_player());
	destruct(this_object());
	return 1;
}

