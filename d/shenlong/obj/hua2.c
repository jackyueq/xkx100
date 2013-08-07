// hua2.c ������
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"hua2", "wuming"}));
	set("unit", "��");
	set("long", "����һ������С����������С��ȴʮ��������\n");
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;
	object me = this_player();
	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if ( neili_limit <= force_limit  )
		me->add("max_neili", 1);
	me->unconcious();
	destruct(this_object());
	return 1;
}

