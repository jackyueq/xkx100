// sheerkou.c �߶���
#include <ansi.h>
inherit ITEM;

#define max_poison 24
#define least_poison 8

void init()
{
	add_action("do_shot","shot");
}

void create()
{
	set_name(HIM"�߶���"NOR, ({ "sheer kou", "sk" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("value", 0);
		set("material", "steel");
		set("long", "���Ǵ�˵�й��϶����صİ���--�߶��ڡ�\n");
	}
	setup();
}

int do_shot(string arg)
{
	object obj,weapon;
	object me = this_player();
	int lv1,lv2,lv3,lv4,damage;
	int tired;

	if (environment(me)->query("no_fight"))
		return notify_fail("�����ֹս����\n");
	if( !arg)
		return notify_fail("��Ҫ����˭��\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("����û������ˣ�\n");
	if(!present(this_object(), me))
		return notify_fail("����û������ˣ�\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if (obj == me)
		return notify_fail("���Լ��¶��֣����벻������\n");

	tired = obj->query("total_tired");
	message_vision(HIM "$N��һ�һ�ɷۺ�ɫ��������$n��Χ�����У�$nһ������֮�£�����о���������\n"+"���������������ȿֺ�ز������Լ���\n" NOR, me, obj);
	obj->apply_condition("snake_poison",random(max_poison) + random(least_poison * tired));

	destruct(this_object());
	return 1;
}
