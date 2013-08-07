// grass.c
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name("�ϳ���", ({"duanchang cao", "cao", "duanchang"}));
	set_weight(25);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIM"\n����һ������ɫ��С�ݣ�ɢ����һ�ɶ����������Ż��\n"NOR);
		set("unit", "��");
		set("value", 100);
	}
	setup();
}

int init()
{
	add_action("do_eat", "fu"); 
	add_action("do_eat", "eat"); 
}

int do_eat(string arg)
{
	object me = this_player();
	int damage;

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(!id(arg)) return notify_fail("��Ҫʲô��\n");

	message_vision("$N����һ��" + name() + "��\n", me);	
	tell_room(environment(me),HIR+me->name()+"ͻȻ¶���ǳ�ʹ������ӣ�ȫ������졣\n" NOR, ({ me }));
	tell_object(me, HIR "�㸹���͵�һ�������ű�һ�����ʹ������\n" NOR);
	message_vision(RED"$N���ء��ۡ���һ�����³�һ���Ѫ����\n"NOR,me);

	damage = me->query_con()*10;
	damage = me->query_skill("force") + damage;

	me->receive_wound("jing", damage);
	me->receive_wound("qi", damage*2);
	me->add("neili", - damage*4);
	me->add("jingli", - damage*2);
	if ((int)me->query_condition("qinghua_poison") > 3)
		me->apply_condition("qinghua_poison", me->query_condition("qinghua_poison") -1 );
	if ((int)me->query_condition("qinghua_poison") == 2) 
		me->apply_condition("qinghua_poison", 1);

	destruct(this_object());
	return 1;
}
