// chuidutong.c ����Ͳ
#include <ansi.h>
inherit ITEM;

#define max_poison 15
#define least_poison 5

void init()
{
	add_action("do_shot","shot");
}

void create()
{
	set_name(HIW"����Ͳ"NOR, ({ "chuidu tong", "ct" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "֧");
		set("value", 0);
		set("material", "steel");
		set("long", "����һ֧���������Ͳ����֪����ʲô�õġ�\n");
	}
	setup();
}

int do_shot(string arg)
{
	object obj,weapon;
	object me = this_player();
	int lv1,lv2,lv3,lv4,damage;
	string skill_type;
	int tired;

	if( !arg) return notify_fail("��Ҫ����˭��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ����˭��\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("����û������ˣ�\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if (obj == me) return notify_fail("���Լ��¶��֣����벻������\n");

	message_vision(HIW "$N�Ѵ���Ͳ�ŵ���ߣ�����$n����һ����$nֻ����һ��ͷ���ۻ���վ�����ȣ������ж��ˣ�\n" NOR, me, obj);
	tired = obj->query("total_tired");
	obj->apply_condition("xx_poison",random(max_poison) + random(least_poison * tired));
	destruct(this_object());
	return 1;
}

