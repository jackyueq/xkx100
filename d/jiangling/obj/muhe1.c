//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"ľ��"NOR, ({"mu he", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"��ľ�й��ӵ��ţ������ģ�����Ҳ����ʲô��������¡�\n"NOR);
		set("unit", "��");
		set("open_count", 0);
		set("weight", 20000);
	}
}

void init()
{
	add_action("do_open","open");
}

int do_open()
{
	return notify_fail("ľ���Ѿ������˴򿪹��ˡ�\n");
}
