// shanshen.c ��ɽ��

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��ɽ��", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ�����ɽ����\n");
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
	this_player()->add("max_qi", 100);

	message_vision("$N����һ����ɽ����ֻ���û���һ����������ð��������\n", this_player());
	destruct(this_object());
	return 1;
}


