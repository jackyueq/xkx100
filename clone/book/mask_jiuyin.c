// /clone/book/mask_jiuyin.c �����پ�

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

int do_du(string arg);

void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}

void create()
{
	set_name(YEL"�����پ�"NOR, ({ "mask_jiuyin", "jiuyin-jiajing" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "paper");
		set("no_drop", "��ò������õ��ֵı���������ö�ô��\n");
		set("no_put", "��ô����Ķ�������Ҫ�����ҷš�\n");
		set("long", "�����������������������ġ������澭������ǧ��Ҫ����Ŷ��:P \n");
	}
}

int do_du(string arg)
{
	if (!arg && arg != "mask_jiuyin" && arg != "jiuyin-jiajing")
		return notify_fail("��Ҫ��ʲô��\n");
	if (!present(this_object(), this_player())) return 0;

	return notify_fail("û���˽��;��壬���Լ��ܿ��ö�ô��\n");
}

