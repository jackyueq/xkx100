// Obj: /d/guiyun/obj/shedan.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("���ߵ�", ({"shedan", "dan"}));
	set("unit", "ֻ");
	set("long", "����һֻ��ӨӨ�Ķ��ߵ������Ʊ���ҩ��ԭ�ϡ�\n");
	set("value", 800);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	return notify_fail("����������\n");
}

