//fen.c

inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "use");
}

void create()
{
	set_name("�ߵ���", ({ "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�������˵ġ��ߵ��ۡ���\n");
		set("value", 2000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if ((int)this_player()->query("eff_qi") >=
		(int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ���ߵ��ۡ�\n");
	if(random(2)==0)
	{
		message_vision("$N����һ���ߵ��ۣ��������������ۣ������ϵ�����\n" , me);
	}
	else
	{
		me->add("qi",30);
		me->add("eff_qi",20);
		message_vision( "$N����һ���ߵ��ۣ��پ�������ӿ���������Щ��\n" , me);
	}
	destruct(this_object());
	return 1;
}
